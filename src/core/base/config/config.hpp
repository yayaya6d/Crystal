#ifndef Config_H
#define Config_H

#include <any>
#include <unordered_map>
#include "config_parser.hpp"
#include "logger.hpp"

namespace Crystal { namespace base {

#define CONFIG_FILE "config.txt"

class Config {
public:
    static Config& GetConfig(Logger* logger = nullptr) {
        static Config instance(logger);
        return instance;
    };

    Config(const Config&) = delete;
    void operator=(const Config&) = delete;
    ~Config() {};

    std::string GetStringConfigWithDefault(std::string key, std::string defaultString);
    int GetIntConfigWithDefault(std::string key, int defaultInt);

private:
    Config(Logger* logger);
    ConfigParser configParser;
    std::unordered_map<std::string, std::any> configs;
};

}}

#endif