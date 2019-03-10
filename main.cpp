#include <iostream>
#include "source/string.hpp"
#include "source/TCP.hpp"
#include "source/TCP_server.hpp"
#include "source/TCP_client.hpp"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    TCP_server mein_server("55554", 64);
    mein_server.start_server();

    //TCP_client mein_client("8.8.8.8", "80", 64);
    //mein_client.dummy_client();
    return 0;
}
