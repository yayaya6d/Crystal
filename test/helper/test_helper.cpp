#include "test_helper.hpp"

std::string generateTestOutputString(std::function<void()> func) {
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    func();
    std::cout.rdbuf(p_cout_streambuf);
    return oss.str();
}