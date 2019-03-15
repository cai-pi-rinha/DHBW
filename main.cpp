#include <iostream>
#include "source/string.hpp"
#include "source/TCP.hpp"
#include "source/TCP_server.hpp"
#include "source/TCP_client.hpp"
#include "HTTP_server.hpp"

using namespace std;

int main()
{

    HTTP_server mein_server("127.0.0.1","55554", 64);
    mein_server.start_server();


    return 0;
}
