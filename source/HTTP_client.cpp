#include "HTTP_client.hpp"
#include "comm_processor.hpp"

HTTP_client::HTTP_client()
{
    comm_proc = new http_processor(this);
}

HTTP_client::~HTTP_client()
{
    //dtor
}

HTTP_client::HTTP_client(const HTTP_client& other)
{
    //copy ctor
}
