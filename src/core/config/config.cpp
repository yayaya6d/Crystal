#include <string>
#include "config.hpp"

namespace Crystal { namespace core {
    std::string Config::GetStringConfigWithDefault(std::string key, std::string defaultString) {
        if (configs.find(key) != configs.end() && configs[key].type() == typeid(std::string)) {
            return std::any_cast<std::string>(configs[key]);
        }
        return defaultString;
    }

    int Config::GetIntConfigWithDefault(std::string key, int defaultInt) {
        if (configs.find(key) != configs.end() && configs[key].type() == typeid(int)) {
            return std::any_cast<int>(configs[key]);
        }
        return defaultInt;
    }

    Config::Config(Logger* logger) {
        configs = configParser.LoadConfig(CONFIG_FILE, logger);
    };
}}