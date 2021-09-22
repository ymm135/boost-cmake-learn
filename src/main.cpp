#include <iostream>
#include "ipc/target_func.h"

typedef void (* pFunc)(char* msg);

int main()
{
    std::cout << "Hello, Boost!" << std::endl;

    // 测试函数指针(静态函数)
    pFunc func = &xm::TargetFunc::start;
    func("Hi, I am from main!");

    //

    return 0;
}