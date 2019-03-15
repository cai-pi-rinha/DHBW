#include "HTTP_server.hpp"
#include "comm_processor.hpp"

HTTP_server::HTTP_server()
{
    comm_proc = new http_processor(this);
}

HTTP_server::~HTTP_server()
{
    //dtor
}

HTTP_server::HTTP_server(const HTTP_server& other)
{
    //copy ctor
}
