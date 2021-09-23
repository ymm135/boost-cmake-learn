#pragma once

namespace xm
{
    class ShareMemory
    {
    private:
        /* data */
    public:
        ShareMemory(/* args */);
        ~ShareMemory();

        void createMaps();
        bool serializeDBByMQ();
    };
}