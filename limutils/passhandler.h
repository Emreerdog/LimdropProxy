#include <string>
#include <utility>

void helloguys();

enum Mode
{
    PS_ENCRYPT,
    PS_DECRYPT
};

class PasswordHandler {
public:
    PasswordHandler(std::string pass, Mode PS_MODE); 
    void MakeLRpair(unsigned long L, unsigned long R);
    void EncryptPass();
    std::pair <unsigned long, unsigned long> GetLRpair();
private:
    bool IsPassValid();
    bool IsPassValidLength();
    bool IsPassContainsSpace();
    std::string _pass;
    std::pair <unsigned long, unsigned long> LRPair;
    Mode _PS_MODE;
};
