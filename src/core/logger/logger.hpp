#include <string>
#include <mutex>

namespace Crystal { namespace core {

enum LogLevel {
    Info = 0,
    Debug,
    Error,
};

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log (LogLevel logLevel, const std::string& tag, const std::string& message) = 0;
};

}}