#include <drogon/drogon.h>
#include <limutils/pyutils.h>

int
main(int argc, char *argv[])
{
    //drogon::app().addListener("192.168.1.27", 443, true, "/etc/ssl/certs/drogon-selfsigned.crt", "/etc/ssl/private/drogon-selfsigned.key"); 
    drogon::app().addListener("10.164.0.8", 80);
    drogon::app().createDbClient("postgresql", "34.90.45.70", 5432, "limdrop", "anil", "mt98mxb9r2");
    drogon::app().enableSession(0);
    auto resp = drogon::HttpResponse::newHttpResponse();
    resp->setBody("404");
    drogon::app().setCustom404Page(resp);
	
    Py_Initialize();
    if (!LimPY_Inits::connectMailServer()) {
        std::cout << "SMTP connection not established" << std::endl;
    } 
    else{
	std::cout << "Running drogon" << std::endl;
    	drogon::app().run();
    }
    
    
    Py_FinalizeEx();
    std::cout << "Program terminated" << std::endl;
    return 0;
}
