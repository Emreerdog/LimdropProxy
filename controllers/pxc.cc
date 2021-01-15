#include "pxc.h"


void pxc::showPage(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback){
//
	std::string forwardString = "http://192.168.1.21";
	std::string currentPath = req->getPath();
	std::string newPath;
	std::string::iterator It;
	bool isFirst = false;
	for (It = currentPath.begin() + 1; It != currentPath.end(); It++) {
		if (*It == '/') {
			isFirst = true;
		}

		if (isFirst) {
			newPath.push_back(*It);
		}
	}

	req->setPath(newPath);
	auto sessionPtr = req->session();
	//auto resp = HttpResponse::newRedirectionResponse(forwardString);
	drogon::app().forward(req, std::move(callback), forwardString, 0);
}
//add definition of your processing function here
