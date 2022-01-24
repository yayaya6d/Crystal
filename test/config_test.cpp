#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>
#include "config.hpp"
#include "test_helper.hpp"

class ConfigTest : public ::testing::Test {
public:
    ConfigTest() {
        content = 
            "strConfig=\"strConfig\"\n" 
            "111\n"
            "intConfig=100\n"
            "=000\n";

        logger = std::make_unique<Crystal::base::DefaultLogger>("");
    }
    ~ConfigTest() {}

    void SetUp() override {
        // create test file
        std::ofstream testFile("config.txt");
        testFile << content;
        testFile.close();

        Crystal::base::Config& c = Crystal::base::Config::GetConfig(logger.get());
    }

    void TearDown() override {
        std::remove("config.txt");
    }

    std::string content;
    std::unique_ptr<Crystal::base::Logger> logger;
};

TEST_F(ConfigTest, GetConfig_GetConfigSeveralTimes_DoNotLoadAgain) {
    std::string output = generateTestOutputString([&]() {
        Crystal::base::Config::GetConfig(logger.get());
    });

    EXPECT_EQ(output, "");
}

TEST_F(ConfigTest, GetStringConfigWithDefault_getStringConfig_getExpectedValue) {
    std::string s1 = Crystal::base::Config::GetConfig().GetStringConfigWithDefault("", "123");
    std::string s2 = Crystal::base::Config::GetConfig().GetStringConfigWithDefault("strConfig", "");

    EXPECT_EQ(s1, "123");
    EXPECT_EQ(s2, "strConfig");
}

TEST_F(ConfigTest, GetIntConfigWithDefault_getIntConfig_getExpectedValue) {
    int i1 = Crystal::base::Config::GetConfig().GetIntConfigWithDefault("", 123);
    int i2 = Crystal::base::Config::GetConfig().GetIntConfigWithDefault("intConfig", 0);

    EXPECT_EQ(i1, 123);
    EXPECT_EQ(i2, 100);
}