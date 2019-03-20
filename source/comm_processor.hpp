#ifndef COMMPROCESSOR_H
#define COMMPROCESSOR_H
#include <winsock2.h>
#include "HTTP_Header.hpp"

class TCP;
class String;
//class HTTP_Header{public: int from_String(String* x){return 0;} char* to_String(void){return 0;}};  // TODO: to be replaced by correct classes
class HTTP_Body{public: int from_String(String* x){return 0;} char* to_String(void){return 0;}};


typedef HTTP_Header t_HTTP_header;
typedef HTTP_Body   t_HTTP_body;

class comm_processor
{
    private:
        TCP* owner;
    protected:
        TCP* get_owner(void){return owner;}
    public:
        comm_processor(TCP* owner);
        virtual ~comm_processor();
        comm_processor(const comm_processor& other);

        virtual int read(SOCKET* socket) = 0;
        virtual int process() = 0;
        virtual int write(SOCKET* DestinationSocket, String* data = NULL) = 0;
};

class http_processor : public comm_processor
{
    private:
        t_HTTP_header*    received_header;
        t_HTTP_body*      received_body;
        t_HTTP_header*    sent_header;
        t_HTTP_body*      sent_body;

        String read_string(SOCKET* socket);
        int write_string(SOCKET* DestinationSocket, String* data);
    public:
        http_processor(TCP* owner);
        virtual ~http_processor();
        http_processor(const http_processor& other);

        int read(SOCKET* socket);
        int process(void);
        int write(SOCKET* DestinationSocket, String* data = NULL);

        void set_http_header(t_HTTP_header sent_header);
        t_HTTP_header get_http_header(void);
};

#endif // COMMPROCESSOR_H
