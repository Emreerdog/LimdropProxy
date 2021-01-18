#include "maincontroller.h"
void maincontroller::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
	req->addHeader("fromProxy", "true");
	std::string forwardString = "http://192.168.1.21";
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
	//auto resp = HttpResponse::newRedirectionResponse(forwardString);
	drogon::app().forward(req, std::move(callback), forwardString, 0);
}
