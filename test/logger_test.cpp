#include <gtest/gtest.h>
#include "test_helper.hpp"
#include "logger.hpp"

class LoggerTest : public ::testing::Test {
public:
    LoggerTest() {}
    ~LoggerTest() {}
};
TEST(LoggerTest, log_logWithEmptyTimeFormat_logExpectedString) {
    Crystal::base::Logger *defaultLogger = new Crystal::base::DefaultLogger("");
    
    auto func = [&]() {
        defaultLogger->log(Crystal::base::Info, "test_tag", "test_logger");
    };

    std::string actualOutput = generateTestOutputString(func);

    EXPECT_EQ(actualOutput, "Info:  test_tag:test_logger\n");
}

TEST(LoggerTest, log_logWithTimeFormat_logExpectedStringLength) {
    Crystal::base::Logger *defaultLogger = new Crystal::base::DefaultLogger("%c");
    
    auto func = [&]() {
        defaultLogger->log(Crystal::base::Info, "test_tag", "test_logger");
    };

    std::string actualOutput = generateTestOutputString(func);

    // since i could not know current time...
    // the output should similar with "Info: 01/10/22 00:11:33 test_tag:test_logger\n"
    // i just check its length here.
    
    // because windows and linux has different time format, so i add different expected result here.
#if defined(WIN32) || defined(_WIN32)
    EXPECT_EQ(actualOutput.length(), 45);
#else
    EXPECT_EQ(actualOutput.length(), 52);
#endif
    
}
