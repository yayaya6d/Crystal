#include <string>
#include "config.hpp"

namespace Crystal { namespace core {
    std::string Config::GetStringConfigWithDefault(std::string key, std::string default) {
        if (configs.find(key) != configs.end() && configs[key].type() == typeid(std::string)) {
            return std::any_cast<std::string>(configs[key]);
        }
        return default;
    }

    int Config::GetIntConfigWithDefault(std::string key, int default) {
        if (configs.find(key) != configs.end() && configs[key].type() == typeid(int)) {
            return std::any_cast<int>(configs[key]);
        }
        return default;
    }

    Config::Config(Logger* logger) {
        configs = configParser.LoadConfig(CONFIG_FILE, logger);
    };
}}