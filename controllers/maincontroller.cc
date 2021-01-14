#include "maincontroller.h"
void maincontroller::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
	auto resp = HttpResponse::newNotFoundResponse();
	callback(resp);
}
