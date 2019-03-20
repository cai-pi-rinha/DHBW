#include "HTTP_Header.hpp"



HTTP_Header::HTTP_Header()
{
	//iterator of the List
	it_entry = Header_entrys.MakeIterator();
}


HTTP_Header::~HTTP_Header()
{
}

String HTTP_Header::Creat_request_Line(String request_method_name, String request_URI, String HTTP_version)
{
	this->request_line += request_method_name;
	this->request_line += " ";
	this->request_line += request_URI;
	this->request_line += " ";
	this->request_line += HTTP_version;
	this->request_line += "\r\n";

	//Always the first entry in the header
	Header_entrys.InsertFirst(&request_line);
	return this->request_line;
}

void HTTP_Header::new_entry(String Token, String field_value, bool last)
{
	//ToDo: check if previos header has CRLF, if not, only then proceed
	
	
	this->entry.header_field(Token, field_value);

	if (last = 1)
	{
		this->entry.add_CRLF();
		Header_entrys.InsertLast(&entry);
	}
	else
	{
		Header_entrys.Insert(&entry);
	}
}

void HTTP_Header::Complete_header_string(void)
{
	Iterator* new_it = Header_entrys.MakeIterator();
	this->Complete_Header += "problem";
	cout << (String)(((HTTP_Header_Entry*)new_it->Current())->header_entry_String()) << endl;

	/*do
	{
		this->Complete_Header += ((HTTP_Header_Entry*)it_entry->Current())->header_entry_String();
	} while (it_entry->Next());
	*/
}

const char* HTTP_Header::Complete_header_to_Str(void)
{
	return this->Complete_Header.GetStr();
}
