#pragma once
#include "string.hpp"
//Contains different Header Tokens
class HTTP_Header_Value
{
public:
	HTTP_Header_Value();
	~HTTP_Header_Value();

//private:
	struct General_Headers_Tokens
	{
		static const String Cache_Control;
		static const String Connection;
		static const String Date;
		static const String Warning;
	};

	struct Tokens
	{
		static const String Turn_Left;
		static const String Turn_Right;
		static const String Acc;
		static const String De_Acc;
		static const String Status; //Moving, Stopped
	};

	struct request_line
	{
		static const String GET;
		static const String URI;
		static const String version;

	};

	Tokens get_token; 
	General_Headers_Tokens get_Ger_Head_Tok;
	request_line get_rqst;

/*
	struct Client_Header_Tokens
	{
		String Accept = "Accept";
		String AcAccept_Charset = "Accept-Charset";
		String Accept_Encoding = "Accept-Encoding";
		String Accept_Language = "Accept-Language";
		String Authorization = "Authorization";
		String From = "From";
		String Host = "Host";
		String If_Match = "If-Match";
		String If_Modified_Since = "If-Modified-Since";
		String If_None_Match = "Accept";
		String If_Range = "If-Range";
		String If_Unmodified_Since = "If-Unmodified-Since";
		String Max_Forwards = "Max-Forwards";
		String Proxy_Authorization = "Proxy-Authorization";
		String Range = "Range";
		String Referer = "Referer";
		String TE = "TE";	
		String User_Agent = "User-Agent";
	};

	struct Server_Response_Tokens
	{
		String Accept_Ranges = "Accept-Ranges";
		String Age = "Age";
		String ETag = "ETag";
		String Location = "Location";
		String Proxy_Authenticate = "Proxy-Authenticate";
		String Retry_After = "Retry-After";
		String Server = "Server";
		String Vary = "Vary                    ";
		String WWW_Authenticate= "WWW-Authenticate";
	};

	struct Entity_Header_Fields
	{
		String Allow = "Allow";
		String Content_Encoding = "Content-Encoding";
		String Content_Language = "Content-Language";
		String Content_Length = "Content-Length";
		String Content_Location = "Content-Location";
		String Content_MD5 = "Content-MD5";
		String Content_Type = "Content-Type";
		String Expires = "Expires";
		String Last_Modified = "Last-Modified";
		String extension_header = "extension-header";
		String Content_Range = "Content-Range";
	};
*/
};

