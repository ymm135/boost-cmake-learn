#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>
#include "consumer.h"

using namespace boost::interprocess;

namespace xm
{
    Consumer::Consumer(/* args */)
    {
    }

    Consumer::~Consumer()
    {
    }

    void Consumer::start()
    {
        try
        {
            //Open a message queue.
            message_queue mq(open_only //only create
                             ,
                             "message_queue" //name
            );

            unsigned int priority;
            message_queue::size_type recvd_size;

            //Receive 100 numbers
            for (int i = 0; i < 100; ++i)
            {
                int number;
                mq.receive(&number, sizeof(number), recvd_size, priority);
                printf("I:%d Rec:%d\n", i, number);

                if (number != i || recvd_size != sizeof(number))
                    std::cout << "quit" << std::endl;
            }
        }
        catch (interprocess_exception &ex)
        {
            message_queue::remove("message_queue");
            std::cout << ex.what() << std::endl;
        }
        
        message_queue::remove("message_queue");
    }

} // namespace xm