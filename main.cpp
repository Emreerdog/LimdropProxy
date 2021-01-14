#include <drogon/drogon.h>

int
main(int argc, char *argv[])
{

    //drogon::app().addListener("192.168.1.27", 443, true, "/etc/ssl/certs/drogon-selfsigned.crt", "/etc/ssl/private/drogon-selfsigned.key"); 
    drogon::app().addListener("192.168.1.41", 80);
    drogon::app().createDbClient("postgresql", "192.168.1.40", 5432, "limdrop", "anil", "mt98mxb9r2");
    drogon::app().enableSession();
    drogon::app().enableReusePort(true);
    auto resp = drogon::HttpResponse::newHttpResponse();
    resp->setBody("404");
    drogon::app().setCustom404Page(resp);

    //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();

    std::cout << "Program terminated" << std::endl;
    return 0;
}
