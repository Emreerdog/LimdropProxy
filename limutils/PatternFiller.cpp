#include <iostream>
#include <fstream>
#include "PatternFiller.h"

std::string SequentialPatternFiller::fillOnFile(std::string file, std::string outterKey, std::vector<std::string> text, std::string element, bool containsAttribute, std::string classname, std::string id)
{
    std::string tempFname = file;
    std::string fileIter;

    std::ifstream htmlfile(tempFname);
    std::string fileContent;
    if (htmlfile.is_open()) {
        while (std::getline(htmlfile, fileIter))
        {
            fileContent += fileIter;
            fileContent += "\n";
            // Fill the fileContent
        }
        htmlfile.close();
    }
    else {
        htmlfile.close();
        return std::string("File doesn't exists");
    }

    const char* marker = "#$";
    std::string verifiedPattern = "";
    std::string outterPart;
    std::string lastPart = "</" + element + ">";
    // Check if string contains the marker
    // If it doesn't append that marker at the beginning of the string
    if (outterKey.find(marker) == std::string::npos) {
        verifiedPattern = marker + outterKey;
    }
    else {
        verifiedPattern = outterKey;
    }

    if (containsAttribute) {
        outterPart = "<" + element + " class='" + classname + "' " + "id='" + id + "'>";
    }

    else {
        outterPart = "<" + element + ">";
    }
    outterPart += "\n";
    std::vector<std::string>::iterator It;
    for (It = text.begin(); It != text.end(); It++) {
        outterPart += *It + "\n";
    }

    outterPart += lastPart;
    size_t patternLoc = fileContent.find(verifiedPattern);
    std::string result = fileContent.replace(patternLoc, verifiedPattern.length(), outterPart);
    text.clear();

    return result;
}

std::string SequentialPatternFiller::fillOnString(std::string str, std::string outterKey, std::vector<std::string> text, std::string element, bool isForm, bool containsAttribute, std::string classname, std::string id, std::string method, bool sendfile)
{
    const char* marker = "#$";
    std::string verifiedPattern = "";
    std::string outterPart;
    std::string lastPart = "</" + element + ">";
    // Check if string contains the marker
    // If it doesn't append that marker at the beginning of the string
    if (outterKey.find(marker) == std::string::npos) {
        verifiedPattern = marker + outterKey;
    }
    else {
        verifiedPattern = outterKey;
    }

    if (containsAttribute) {
	    if(isForm){
	    	outterPart = "<" + element + " action='" + classname + "' " + "method='" + method;
	       if(sendfile){
	       	outterPart += "' enctype='multipart/form-data'>";
	       }	
	       else{
	       	outterPart += "'>";
	       }
	    }
	    else{
	   	 
        	outterPart = "<" + element + " class='" + classname + "' " + "id='" + id + "'>";
	    }
    }

    else {
        outterPart = "<" + element + ">";
    }
    outterPart += "\n";
    std::vector<std::string>::iterator It;
    for (It = text.begin(); It != text.end(); It++) {
        outterPart += *It + "\n";
    }

    outterPart += lastPart;
    size_t patternLoc = str.find(verifiedPattern);
    std::string result = str.replace(patternLoc, verifiedPattern.length(), outterPart);
    text.clear();

    return result;
}

// Insert patterns without #$ marker
ManualPatternFiller::ManualPatternFiller(int PatternCount, ...)
{
    _PatternCount = PatternCount;

    va_list patterns;
    va_start(patterns, PatternCount);

    for (int i = 0; i < PatternCount; i++) {

        // Adds keywords to vector of keyword strings
        const char* pattern = va_arg(patterns, const char*);
        keywords.push_back(std::string("#$" + std::string(pattern)));
    }
}

// NOTE !!!
// Pattern count and count of pattern filling arguments should match
std::string ManualPatternFiller::fillPatterns(std::string fname, ...)
{
    std::string tempFname = fname;
    std::string fileIter;

    std::ifstream htmlfile(tempFname);
    std::string fileContent;
    if (htmlfile.is_open()) {
        while (std::getline(htmlfile, fileIter))
        {
            fileContent += fileIter;
            fileContent += "\n";
            // Fill the fileContent
        }
        htmlfile.close();
    }
    else {
        htmlfile.close();
        keywords.clear();
        return std::string("File doesn't exists");
    }

    va_list patterns;
    va_start(patterns, fname);

    for (int i = 0; i < _PatternCount; i++) {
        size_t checknpos = fileContent.find(keywords[i]);
        if (checknpos != std::string::npos) {
            const char* replaced = va_arg(patterns, const char*);
            fileContent.replace(checknpos, keywords[i].length(), replaced);
        }
        else {
            std::cout << "Pattern " << keywords[i] << " couldn't found on file operation terminated." << std::endl;
            keywords.clear();
            return std::string("Patter couldn't found");
        }
    }

    keywords.clear();
    return fileContent;

}


std::string ManualPatternFiller::fillPatternsOnString(std::string str, ...){

    va_list patterns;
    va_start(patterns, str);

    std::string tempStr = str;
    for (int i = 0; i < _PatternCount; i++) {
        size_t checknpos = tempStr.find(keywords[i]);
        if (checknpos != std::string::npos) {
            const char* replaced = va_arg(patterns, const char*);
            tempStr.replace(checknpos, keywords[i].length(), replaced);
        }
        else {
            std::cout << "Pattern " << keywords[i] << " couldn't found on file operation terminated." << std::endl;
            keywords.clear();
            return std::string("Patter couldn't found");
        }
    }

    keywords.clear();
    return tempStr;
}
