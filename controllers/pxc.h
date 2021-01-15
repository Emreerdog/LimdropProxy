#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
class pxc:public drogon::HttpController<pxc>
{
  public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;
    METHOD_ADD(pxc::showPage,"/.*");//path is /pxc/{arg2}/{arg1}
    //METHOD_ADD(pxc::your_method_name,"/{1}/{2}/list",Get);//path is /pxc/{arg1}/{arg2}/list
    //ADD_METHOD_TO(pxc::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void showPage(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback);
    // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
};
