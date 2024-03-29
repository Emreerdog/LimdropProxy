#include "maincontroller.h"
#include <drogon/HttpClient.h>

void maincontroller::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
	req->addHeader("fromProxy", "true");
	std::string forwardString = "http://34.91.236.118";
	auto sessionPtr = req->session();
	
	if(sessionPtr->find("isLoggedIn")){
		std::string id = sessionPtr->get<std::string>("id");
		std::string name = sessionPtr->get<std::string>("name");
		std::string surname = sessionPtr->get<std::string>("surname");
		std::string email = sessionPtr->get<std::string>("email");

		req->addHeader("isLogged", "true");
		req->addHeader("id", id);
		req->addHeader("name", name);
		req->addHeader("surname", surname);
		req->addHeader("email", email);	
	}
	else{
		std::string reserveNum = req->getCookie("rsv_num");
		if(reserveNum != ""){
			std::cout << "database action" << std::endl;
			auto clientPtr = drogon::app().getDbClient();
        		std::string totalQuery = "SELECT id, name, surname, email, is_logged FROM reserved_acc WHERE rsv_num='" + reserveNum + "'";
        		auto f = clientPtr->execSqlAsyncFuture(totalQuery);
			auto r = f.get();
			for(auto row : r){
				std::string _id = row["id"].as<std::string>();
				std::string _name = row["name"].as<std::string>();
				std::string _surname = row["surname"].as<std::string>();
				std::string _email = row["email"].as<std::string>();	

				sessionPtr->insert("id", _id);
				sessionPtr->insert("name", _name);
				sessionPtr->insert("surname", _surname);
				sessionPtr->insert("email", _email);
				sessionPtr->insert("isLoggedIn", "true");

				req->addHeader("isLogged", "true");
                		req->addHeader("id", _id);
                		req->addHeader("name", _name);
                		req->addHeader("surname", _surname);
                		req->addHeader("email", _email);
			}
		}
	}
	//auto resp = HttpResponse::newRedirectionResponse(forwardString);
	drogon::app().forward(req, std::move(callback), forwardString, 0);
}
