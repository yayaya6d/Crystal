#ifndef ConfigParser_H
#define ConfigParser_H

#include <any>
#include <unordered_map>
#include "logger.hpp"

namespace Crystal { namespace core {
class ConfigParser {
public:
    ConfigParser() {}
    ~ConfigParser() {}
    std::unordered_map<std::string, std::any> LoadConfig(const std::string& filePath, Logger* logger);
private:
    std::pair<std::string, std::any> GetConfig(const std::string& config);
    std::string ConvertToKey(const std::string& str);
    std::any ConvertToValue(const std::string& str);
};
}}

#endif