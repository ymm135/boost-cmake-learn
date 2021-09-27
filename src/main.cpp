#include <iostream>
#include <string>
#include "ipc/target_func.h"
#include "thread/thread_ops.h"
#include "mq/consumer.h"
#include "mq/producer.h"
#include "sm/share_memory.h"
#include "protobuf/addressbook.h"
#include "base/base.h"

typedef void (*pFunc)(char *msg);

int main(int argc, char **argv)
{
    std::cout << "Hello, Boost!" << std::endl;

    std::string ops = "null";
    if (argc > 1)
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
    if (ops.compare("base") == 0)
    {
        xm::BaseOps base;
        base.run();
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

    // share memory maps
    if (ops.compare("smm") == 0)
    {
        xm::ShareMemory sm;
        sm.createMaps();
    }

    // proto
    if (ops.compare("proto") == 0)
    {
        xm::ProtoBufDemo proto;
        proto.start();
    }

    return 0;
}