#pragma once
#include <drogon/HttpController.h>

using namespace drogon;
class accountops:public drogon::HttpController<accountops>
{
  public:

    METHOD_LIST_BEGIN
    
    METHOD_ADD(accountops::createAccount, "/signup?email={1}&name={2}&surname={3}&pass={4}&passCheck={5}&terms={6}&receiveMail={7}", Post);
    METHOD_ADD(accountops::loginAccount, "/login?email={1}&pass={2}", Post);
    
    METHOD_LIST_END
    void createAccount(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string email, std::string name, std::string surname, std::string pass, std::string passCheck, std::string terms, std::string receiveMail);
    void loginAccount(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, std::string email, std::string pass);		
};
