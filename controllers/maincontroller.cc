#include "maincontroller.h"
void maincontroller::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
	std::string forwardString = "http://192.168.1.21";
	std::cout << req->getPath() << std::endl;
	auto sessionPtr = req->session();
	std::string key1 = "Access-Control-Allow-Origin";
	std::string val1 = "*";
	req->addHeader(key1, val1);
	//auto resp = HttpResponse::newRedirectionResponse(forwardString);
	drogon::app().forward(req, std::move(callback), forwardString, 0);
}
