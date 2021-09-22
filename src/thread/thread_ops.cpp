#pragma once
#include "thread_ops.h"
#include <iostream>

namespace xm
{
    ThreadOps::ThreadOps(/* args */)
    {
        std::cout << "ThreadOps Create" << std::endl;
    }
    
    ThreadOps::~ThreadOps()
    {
        std::cout << "ThreadOps Destory" << std::endl;
    }

    void ThreadOps::createThread()
    {
        std::cout << "ThreadOps createThread start" << std::endl;

        boost::thread thread1(&ThreadOps::run);
        thread1.join();

        std::cout << "ThreadOps createThread end" << std::endl;

    }

    void ThreadOps::run()
    {
        std::cout << "ThreadOps run" << std::endl;
    }
}