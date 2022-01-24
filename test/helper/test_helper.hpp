#ifndef TestHelper__H
#define TestHelper__H

#include<string>
#include<functional>
#include<iostream>
#include<sstream>

std::string generateTestOutputString(std::function<void()> func);

#endif