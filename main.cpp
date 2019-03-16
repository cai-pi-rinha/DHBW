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
    while(1)
    {
        mein_server.start_server();
        mein_server.get_query();
        mein_server.process();
        cout << "received information: " << mein_server.get_http_header().to_String() << endl;
        mein_server.send_response();
    }


    //HTTP_client mein_client("127.0.0.1","55554", 64);
    //mein_client.start_client();

    return 0;
}
