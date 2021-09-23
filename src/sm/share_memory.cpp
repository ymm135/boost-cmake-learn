#pragma once
#include "share_memory.h"

#include <boost/interprocess/allocators/node_allocator.hpp>
#include <boost/interprocess/interprocess_fwd.hpp>
#include <boost/interprocess/segment_manager.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <functional>
#include <utility>
#include <iostream>
#include <string>

namespace xm
{

    ShareMemory::ShareMemory(/* args */)
    {
    }

    ShareMemory::~ShareMemory()
    {
    }

    void ShareMemory::createMaps()
    {
        using namespace boost::interprocess;

        // -exec x/16c 0x65e518   <=   hello.c_str()
        std::string hello = "hello123";
        std::string *pStr = &hello;

        //
        std::pair<std::string, double> product1("tomatoes", 3.25);
        std::pair<std::string, double> *pProduct = &product1;

        //Remove shared memory on construction and destruction
        struct shm_remove
        {
            shm_remove() { shared_memory_object::remove("MySharedMemory"); }
            ~shm_remove() { shared_memory_object::remove("MySharedMemory"); }
        } remover;

        //Shared memory front-end that is able to construct objects
        //associated with a c-string. Erase previous shared memory with the name
        //to be used and create the memory segment at the specified address and initialize resources
        managed_shared_memory segment(create_only,
                                      "MySharedMemory", //segment name
                                      65536);           //segment size in bytes

        //Note that map<Key, MappedType>'s value_type is std::pair<const Key, MappedType>,
        //so the allocator must allocate that pair.
        typedef int KeyType;
        typedef std::string MappedType;
        typedef std::pair<const int, std::string> ValueType;

        //Alias an STL compatible allocator of for the map.
        //This allocator will allow to place containers
        //in managed shared memory segments
        typedef allocator<ValueType, managed_shared_memory::segment_manager> ShmemAllocator;

        //Alias a map of ints that uses the previous STL-like allocator.
        //Note that the third parameter argument is the ordering function
        //of the map, just like with std::map, used to compare the keys.
        typedef map<KeyType, MappedType, std::less<KeyType>, ShmemAllocator> MyMap;

        //Initialize the shared memory STL-compatible allocator
        ShmemAllocator alloc_inst(segment.get_segment_manager());

        //Construct a shared memory map.
        //Note that the first parameter is the comparison function,
        //and the second one the allocator.
        //This the same signature as std::map's constructor taking an allocator
        MyMap *mymap =
            segment.construct<MyMap>("MyMap") //object name
            (std::less<int>(),                //first  ctor parameter
             alloc_inst);                     //second ctor parameter

        std::cout << "addr:" << segment.get_address() << std::endl;

        //Insert data in the map
        for (int i = 0; i < 100; ++i)
        {
            std::ostringstream oss;
            oss << "smm + " << i;

            mymap->insert(std::pair<const int, std::string>(i, oss.str()));
        }
    }

    //This test creates a in memory data-base using Interprocess machinery and
    //serializes it through a message queue. Then rebuilds the data-base in
    //another buffer and checks it against the original data-base
    bool ShareMemory::serializeDBByMQ()
    {
        return true;
    }

} // namespace xm
