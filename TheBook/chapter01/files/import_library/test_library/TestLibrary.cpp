#include "TestLibrary.hpp"
#include <iostream>

TestClass::TestClass(){
}

TestClass::~TestClass(){
}

void TestClass::foo(){
    std::cout << __func__ << std::endl;
}












