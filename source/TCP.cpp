#include "TCP.hpp"

TCP::TCP()
{
    ZeroMemory(&source, sizeof(source));
    source.ai_family = AF_INET;
    source.ai_socktype = SOCK_STREAM;
    source.ai_protocol = IPPROTO_TCP;
    source.ai_flags = AI_PASSIVE;

    ZeroMemory(&dest, sizeof(dest));
    dest.ai_family = AF_INET;
    dest.ai_socktype = SOCK_STREAM;
    dest.ai_protocol = IPPROTO_TCP;
    dest.ai_flags = AI_PASSIVE;
}

TCP::TCP(String* source_ip, uint16_t source_port, String* dest_ip, uint16_t dest_port)
{

}

TCP::~TCP()
{
    //dtor
}

TCP::TCP(const TCP& other)
{
    //copy ctor
}
