#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>
#include <boost/thread/thread.hpp>

#include "producer.h"

using namespace boost::interprocess;

namespace xm
{
    Producer::Producer(/* args */)
    {
    }

    Producer::~Producer()
    {
    }

    void Producer::start()
    {
        try
        {
            //Erase previous message queue
            message_queue::remove("message_queue");

            //Create a message_queue.
            message_queue mq(create_only //only create
                             ,
                             "message_queue" //name
                             ,
                             100 //max message number
                             ,
                             sizeof(int) //max message size
            );

            //Send 100 numbers
            for (int i = 0; i < 100; ++i)
            {
                mq.send(&i, sizeof(i), 0);
                std::cout << "send msg:" << i << std::endl;

                boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(3)); 
            }
        }
        catch (interprocess_exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }

    void Producer::stop()
    {
    }
} // namespace xm