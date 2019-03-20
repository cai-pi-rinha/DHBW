#include "HTTP_Header_Value.hpp"

//General_Headers_Tokens initlisation 
const String HTTP_Header_Value::General_Headers_Tokens::Cache_Control = "Cache-Control";
const String HTTP_Header_Value::General_Headers_Tokens::Connection = "Connection";
const String HTTP_Header_Value::General_Headers_Tokens::Date = "Date";
const String HTTP_Header_Value::General_Headers_Tokens::Warning = "Warning";

//Tokens for the Vehical
const String HTTP_Header_Value::Tokens::Turn_Left = "Left";
const String HTTP_Header_Value::Tokens::Turn_Right = "Right";
const String HTTP_Header_Value::Tokens::Acc = "Accelration";
const String HTTP_Header_Value::Tokens::De_Acc = "Deaccelration";
const String HTTP_Header_Value::Tokens::Status = "Status";

//Client requests 
const String HTTP_Header_Value::request_line::GET = "GET";
const String HTTP_Header_Value::request_line::URI = "https://www.google.de/";
const String HTTP_Header_Value::request_line::version = "HTTP/1.1";
//Status Code for requestline

//

HTTP_Header_Value::HTTP_Header_Value()
{
}


HTTP_Header_Value::~HTTP_Header_Value()
{
}
