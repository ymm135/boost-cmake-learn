#pragma once
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

namespace xm
{
    class ThreadOps
    {
    private:
        boost::mutex mLock;
        
    public:
        ThreadOps(/* args */);
        ~ThreadOps();

        void createThread();
        static void run();
    };
}