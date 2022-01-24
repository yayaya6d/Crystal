#include <fstream>
#include <string>
#include <exception>
#include "config_parser.hpp"


namespace Crystal { namespace base {
    std::unordered_map<std::string, std::any> ConfigParser::LoadConfig(const std::string& filePath, Logger* logger) {
        std::unordered_map<std::string, std::any> configs;

        std::ifstream infile(filePath);
        if (infile.is_open() == false) {
            return configs;
        }

        int line = 1;
        std::string buf;
        while (std::getline(infile, buf)) {
            auto config = GetConfig(buf);
            if (config.first != "") 
                configs[config.first] = config.second;
            else if (logger != nullptr) {
                logger->log(Warn, "", "Something wrong when load config in line: " + line);
            }
            line++;
        }
        
        infile.close();

        return configs;
    }

    std::pair<std::string, std::any> ConfigParser::GetConfig(const std::string& config) {
        // split by "="
        int colonPos = config.find('=');
        if (colonPos == std::string::npos) {
            return  std::pair<std::string, std::any>();
        }

        std::string key = ConvertToKey(config.substr(0, colonPos));
        std::any val = ConvertToValue(config.substr(colonPos + 1));

        return std::pair<std::string, std::any>(key, val);
    }

    std::string ConfigParser::ConvertToKey(const std::string& str) {
        // remove space that behind and in front of str.
 
        int firstPos = 0;
        while (firstPos < str.length() && str[firstPos] == ' ') {
            firstPos++;
        }

        int lastPos = str.length() - 1;
        while (lastPos >= 0 && str[lastPos] == ' ') {
            lastPos--;
        }

        if (firstPos >= lastPos) {
            return "";
        }

        return str.substr(firstPos, lastPos - firstPos + 1);
    }

    std::any ConfigParser::ConvertToValue(const std::string& str) {
        // remove space that behind and in front of str, we can use ConvertToKey directly.

        std::string newStr = ConvertToKey(str);
        if (newStr.empty()) {
            return "";
        }

        if (newStr.front() == '"' && newStr.back() == '"') {
            std::string tmp = newStr.substr(1, newStr.length() - 2);
            return tmp;
        }
        try {
            int num = std::stoi(newStr);
            return num;
        }
        catch (std::exception e) {
            return "";
        }
    }
}}