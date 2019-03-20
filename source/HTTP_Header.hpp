#pragma once
#include "HTTP_Header_Entry.hpp"
#include "string.hpp"
#include "DList.hpp"
#include "DNode.hpp"
#include "iterator.hpp"
#include "ContainerInterface.hpp"

//Combinees different Header Entrys into one single header and spits out a Long Headder String which will be then put into a DList
class HTTP_Header :
	public HTTP_Header_Entry
{
public:
	HTTP_Header();
	~HTTP_Header();

	//creat a request line
	String Creat_request_Line(String request_method_name, String request_URI, String HTTP_version);
	
	//creat a new entry
	void new_entry(String Token, String field_value, bool last);
	
	//Combines all the header entrys in a String
	void Complete_header_string(void);

	//Print the whole Header
	const char* Complete_header_to_Str(void);

private:

	// List which will have all the created entrys  
	DList Header_entrys;
	Iterator* it_entry;
	HTTP_Header_Entry entry;

	

	/*Request line vairables*/
	String request_method_name;
	String request_URI;
	String HTTP_version;
	String request_line;

	//Complete header String
	String Complete_Header;
	
	// header.new_entry(Token, Fieldvalue);

};

