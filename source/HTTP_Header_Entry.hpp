#pragma once
//Combines Header Values/Token with header with the actuall value of the Entry 
#include "HTTP_Header_Value.hpp"

class HTTP_Header_Entry :
	public HTTP_Header_Value
{
public:
	HTTP_Header_Entry();
	~HTTP_Header_Entry();

	//for creating a Header field String
	String header_field(String field_name, String field_value);
	
	//add CRLF after a token
	void add_CRLF(void);

	//for returning the complete String
	String header_entry_String(void);

	//Geting the String of the created header, TODO check if header is empty
	const char* header_field_to_Str();

private:
	
	String token;
	String field_value;

	//Combines the toke and Field value in this String
	String header_entry_as_String;
};

