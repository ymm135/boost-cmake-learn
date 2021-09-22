#include <iostream>
#include <string>
#include "ipc/target_func.h"
#include "thread/thread_ops.h"
#include "mq/consumer.h"
#include "mq/producer.h"

typedef void (*pFunc)(char *msg);

int main(int argc, char **argv)
{
    std::cout << "Hello, Boost!" << std::endl;

    std::string ops = "null";
    if (argc > 0)
    {
        ops = argv[1];
    }

    std::cout << "ops = " << ops << std::endl;

    if (ops.compare("null") == 0)
    {
        // 测试函数指针(静态函数)
        pFunc func = &xm::TargetFunc::start;
        func("Hi, I am from main!");

        //线程测试
        xm::ThreadOps threadOps;
        threadOps.createThread();
    }

    //消息队列测试
    if (ops.compare("mqc") == 0)
    {
        xm::Consumer consumer;
        consumer.start();
    }

    //消息队列测试生产者
    if (ops.compare("mqp") == 0)
    {
        xm::Producer producer;
        producer.start();
    }

    return 0;
}