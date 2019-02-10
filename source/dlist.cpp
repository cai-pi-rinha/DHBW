#include "dlist.hpp"
 
// constructor
Dlist::Dlist(void)
{
	
}
 
// Date member function
virtual int remove(int)
{}

virtual int insert(void* obj)
{
	insertlast(obj);
}

virtual int create(void)
{}

int Dlist::insertfirst(void* obj)
{
	// insert Dnode in front of Dlist
}

int Dlist::insertlast(void* obj)
{
	// ...
}

void* Dlist::operator [](int index)
{
	// iterate through the list until entry number "index"
}