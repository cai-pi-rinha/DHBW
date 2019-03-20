#include "HTTP_Header_Entry.hpp"



HTTP_Header_Entry::HTTP_Header_Entry()
{

}


HTTP_Header_Entry::~HTTP_Header_Entry()
{
}

String HTTP_Header_Entry::header_field(String field_name, String field_value)
{

	this->token = field_name;
	this->field_value = field_value;

	this->header_entry_as_String += this->token;
	this->header_entry_as_String += ": ";
	this->header_entry_as_String += this->field_value;
	this->header_entry_as_String += "\n";

	return this->header_entry_as_String;
}

void HTTP_Header_Entry::add_CRLF()
{
	this->header_entry_as_String += "\r\n\r\n";
}

String HTTP_Header_Entry::header_entry_String(void)
{
	return this->header_entry_as_String;
}




const char* HTTP_Header_Entry::header_field_to_Str()
{
	return header_entry_as_String.GetStr();
}
