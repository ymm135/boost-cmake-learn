#pragma once
#include "proto/addressbook.pb.h"

namespace xm
{
    class ProtoBufDemo
    {
    private:
        /* data */
    public:
        ProtoBufDemo(/* args */);
        ~ProtoBufDemo();

        void start();

    private:
        void PromptForAddress(tutorial::Person *person);
    };

} // namespace xm
