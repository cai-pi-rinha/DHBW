#include "TCP_client.hpp"

TCP_client::TCP_client(int buffer_size)
    : TCP(buffer_size)
{
    //ctor
}

TCP_client::TCP_client(const char* source_ip, const char* source_port, const char* dest_ip, const char* dest_port, int buffer_size)
    : TCP(source_ip, source_port, dest_ip, dest_port, buffer_size)
{

}

TCP_client::~TCP_client()
{
    //dtor
}

TCP_client::TCP_client(const TCP_client& other)
{
    //copy ctor
}

int TCP_client::dummy_client(void)
{
    init_socket();

    // connect()

    //send_tcp();
    //terminate_connection();


    return 0;
}
