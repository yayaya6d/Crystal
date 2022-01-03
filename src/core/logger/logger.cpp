#include "logger.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <time.h>

#if defined(WIN32) || defined(_WIN32)
    struct tm* localtime_r(time_t *_clock, struct tm *_result) {
        localtime_s(_result, _clock);
        return _result;
    }
#endif

namespace Crystal { namespace core {

class DefaultLogger : Logger {
public:
    DefaultLogger(const std::string timeFormat) : timeFormat(timeFormat) {};
    ~DefaultLogger();

    virtual void log (LogLevel logLevel, const std::string& tag, const std::string& message) override {
        std::lock_guard<std::mutex> lock(m_lock);
        
        switch (logLevel) {
            case Info: 
                std::cout << "Info: ";
                break;
            case Debug: 
                std::cout << "Debug: ";
                break;
            case Error: 
                std::cout << "Error: ";
                break;
        }

        if (!timeFormat.empty()) {
            auto time = std::chrono::system_clock::now().time_since_epoch();
	        time_t seconds = std::chrono::duration_cast<std::chrono::seconds>(time).count();
            struct tm now;
            localtime_r(&seconds, &now);
            std::cout << std::put_time(&now, timeFormat.c_str());
        }

        if (message.empty()) {
            std::cout << " " << tag << std::endl;
        } else {
            std::cout << " " << tag << ":" << message << std::endl;
        }
    }

private:
    const std::string timeFormat;
    std::mutex m_lock;
};

}}