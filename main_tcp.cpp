#include <iostream>
#include "source/string.hpp"
#include "source/TCP.hpp"
#include "source/TCP_server.hpp"
#include "source/TCP_client.hpp"
#include "HTTP_server.hpp"
#include "HTTP_client.hpp"

#define SERVER_1_CLIENT_0 0

using namespace std;

int main()
{

#if SERVER_1_CLIENT_0 == 1
    cout << "server started" << endl;
    HTTP_server mein_server("127.0.0.1","55554", 64);
    while(1)
    {
        mein_server.start_server();
        mein_server.get_query();
        mein_server.process();
        cout << "received information: " << mein_server.get_http_header().to_String() << endl;
        mein_server.send_response_and_terminate_conn();
    }

#elif SERVER_1_CLIENT_0 == 0
    cout << "client started" << endl;
    String demo_string = "hello world";
    HTTP_client mein_client("127.0.0.1","55554", 64);
    mein_client.start_client();
    cout << "started" << endl;
    mein_client.send(&demo_string);
    cout << "sent" << endl;
    mein_client.receive();
    cout << "received" << endl;
    cout << "received information: " << mein_client.get_http_header().to_String() << endl;
    mein_client.terminate_connection();

#endif // SERVER_CLIENT

    return 0;
}
