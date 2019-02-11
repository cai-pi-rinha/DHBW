#include "dlist.hpp"
#include "dnode.hpp"

// constructor
Dlist::Dlist(void)
{
	start_of_chain = null;
	end_of_chain = null;
}

// Date member function
virtual int Dlist::remove(int)
{}

virtual int Dlist::insert(void* obj)
{
	insertlast(obj);
}

virtual int Dlist::create(void)
{}

int Dlist::insertfirst(void* obj)
{
	// insert Dnode in front of Dlist
}

int Dlist::insertlast(void* obj)
{
	// ...
	end_of_chain->
}

void* Dlist::operator [](int index)
{
	// iterate through the list until entry number "index"
}

