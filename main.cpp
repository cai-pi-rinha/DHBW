#include <iostream>
#include "source/string.hpp"
#include "source/TCP.hpp"
#include "source/TCP_server.hpp"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    TCP_server mein_server("55554", 64);
    mein_server.start_server();
    return 0;
}
