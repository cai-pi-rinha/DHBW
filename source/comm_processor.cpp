#include "comm_processor.hpp"
#include "TCP.hpp"

comm_processor::comm_processor(TCP* owner)
    : owner(owner)
{
    //ctor
}

comm_processor::~comm_processor()
{
    //dtor
}

comm_processor::comm_processor(const comm_processor& other)
{
    //copy ctor
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

http_processor::http_processor(TCP* owner)
    :comm_processor(owner)
{
    //ctor
}

http_processor::~http_processor()
{
    //dtor
}

http_processor::http_processor(const http_processor& other) /* copy constructor with inheritance */
    :comm_processor(other)
{
    //copy ctor
}

int http_processor::read_and_process_data()
{
    return 0;
}

int http_processor::send_data()
{
    return 0;
}
