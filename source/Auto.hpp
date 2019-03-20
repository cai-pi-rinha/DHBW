// Headerfile "string.hpp"

#ifndef AUTO_HPP
#define AUTO_HPP
#include"HTTP_server.hpp"

#include"HTTP_client.hpp"

class HTTP_server;
class HTTP_client;

class clientAuto
{
private:
	HTTP_client* mein_client;
	

public:
	clientAuto();
	~clientAuto();
	void Abfrage();
};

///////////////////////////////////////////////////////////////////////////////////

class serverAuto
{
private:
	HTTP_server* mein_server;


public:
	serverAuto();
	~serverAuto();
	void Abfrage();

};


#endif