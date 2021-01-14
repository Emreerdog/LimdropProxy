#include <string>
#include <vector>
#include <stdarg.h>

class SequentialPatternFiller {
public:
    std::string fillOnFile(std::string file, std::string outterKey, std::vector<std::string> text, std::string element, bool containsAttribute=false, std::string classname="", std::string id="");
    std::string fillOnString(std::string str, std::string outterKey, std::vector<std::string> text, std::string element, bool isForm=false, bool containsAttribute=false, std::string classname="", std::string id="", std::string method="", bool sendfile=false);
};

class ManualPatternFiller {
public:
    ManualPatternFiller(int PatternCount, ...);
    std::string fillPatterns(std::string fname, ...); // Returns the pattern filled string
    std::string fillPatternsOnString(std::string str, ...);

private:
    std::vector<std::string> keywords;
    int _PatternCount = 0;
};
