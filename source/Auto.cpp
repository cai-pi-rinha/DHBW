
#include "Auto.hpp"

clientAuto::clientAuto() {
	cout << "clientAuto started" << endl;
	
	mein_client = new HTTP_client("127.0.0.1", "55554", 64);
	
}
clientAuto::~clientAuto() {

}
void clientAuto::Abfrage() {
	String demo_string;
	char* Puffer;
	
	while (1) {
		/// TODO cin machen
		cout << "Geben sie eine neue Eingabe ein" << endl;
		cin >> Puffer;
		demo_string = Puffer;
		mein_client->start_client();
		cout << "started" << endl;
		mein_client->send(&demo_string);
		cout << "sent" << endl;
		mein_client->receive();
		cout << "received" << endl;
		cout << "received information: " << mein_client->get_http_header().to_String() << endl;
		mein_client->terminate_connection();
	}
}



/////////////////////////////////////////////////////////////////////////////

serverAuto::serverAuto() {
	cout << "serverAuto started" << endl;
	mein_server = new HTTP_server("127.0.0.1", "55554", 64);
	mein_server->start_server();
}

void serverAuto::Abfrage(){
	while (1)
	{
		///ToDo: richtige Tokens eintragen
		String Token1("Token1"), Token2("Token2"), Token3("Token3"), Token4("Token4");
		mein_server->get_query();
		mein_server->process();
		String recString(mein_server->get_http_header().to_String() );
		cout << "received: " << recString.GetStr() << endl;
		if (recString == Token1)
			cout << Token1.GetStr() << "empfangen, führe x aus" << endl;
		else if (recString == Token2) 
			cout << Token2.GetStr() << "empfangen, führe x aus" << endl;
		else if (recString == Token3)
			cout << Token3.GetStr() << "empfangen, führe x aus" << endl;
		else if (recString == Token4)
			cout << Token4.GetStr() << "empfangen, führe x aus" << endl;
		else {
			cout << "ungültiges Token empfangen, kritischer Error" << endl;
		}
		mein_server->send_response_and_terminate_conn();
	}
}


serverAuto::~serverAuto() {
	delete mein_server;
}