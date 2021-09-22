#include <iostream>
#include "ipc/target_func.h"
#include "thread/thread_ops.h"

typedef void (* pFunc)(char* msg);

int main()
{
    std::cout << "Hello, Boost!" << std::endl;

    // 测试函数指针(静态函数)
    pFunc func = &xm::TargetFunc::start;
    func("Hi, I am from main!");

    //线程测试
    xm::ThreadOps threadOps;
    threadOps.createThread();

    return 0;
}