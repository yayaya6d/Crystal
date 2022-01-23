#ifndef Logger_H
#define Logger_H

#include <string>
#include <mutex>

namespace Crystal { namespace core {

enum LogLevel {
    Info = 0,
    Debug,
    Warn,
    Error,
};

// for detail of time format, please refer to https://en.cppreference.com/w/cpp/io/manip/put_time

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log (LogLevel logLevel, const std::string& tag, const std::string& message) = 0;
};

class DefaultLogger : public Logger {
public:
    DefaultLogger(const std::string timeFormat) : timeFormat(timeFormat) {};
    ~DefaultLogger() {};
    void log (LogLevel logLevel, const std::string& tag, const std::string& message) override;
private:
    const std::string timeFormat;
    std::mutex m_lock;
};

}}

#endif