#include <gtest/gtest.h>
#include "logger.hpp"

std::string generateTestOutputString(std::function<void()> func) {
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    func();
    std::cout.rdbuf(p_cout_streambuf);
    return oss.str();
}

TEST(loggerTestCases, log_logWithEmptyTimeFormat_logExpectedString) {
    Crystal::core::Logger *defaultLogger = new Crystal::core::DefaultLogger("");
    
    auto func = [&]() {
        defaultLogger->log(Crystal::core::Info, "test_tag", "test_logger");
    };

    std::string actualOutput = generateTestOutputString(func);

    EXPECT_EQ(actualOutput, "Info:  test_tag:test_logger\n");
}

TEST(loggerTestCases, log_logWithTimeFormat_logExpectedStringLength) {
    Crystal::core::Logger *defaultLogger = new Crystal::core::DefaultLogger("%c");
    
    auto func = [&]() {
        defaultLogger->log(Crystal::core::Info, "test_tag", "test_logger");
    };

    std::string actualOutput = generateTestOutputString(func);

    // since i could not know current time...
    // the output should similar with "Info: 01/10/22 00:11:33 test_tag:test_logger\n"
    // i just check its length here.
    EXPECT_EQ(actualOutput.length(), 45);
}