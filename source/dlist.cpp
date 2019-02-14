#include "dlist.hpp"
#include "dnode.hpp"

// constructor
Dlist::Dlist(void)
{
	start_of_chain.prev     = NULL;
	start_of_chain.next     = NULL; /* will point on first element of list */
	start_of_chain.payload  = NULL;
	end_of_chain.prev       = NULL; /* will point on last element of list */
	end_of_chain.next       = NULL;
	end_of_chain.payload    = NULL;
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

int Dlist::insertfirst(void* obj)   /** insert a new object as first element of the list */
{
    start_of_chain.insert_after(obj);
}

int Dlist::insertlast(void* obj)    /** insert a new object as last element of the list */
{
	end_of_chain.insert_before(obj);
}

int Dlist::insertAt(int index, void* obj)
{
    /* 1) go to element number (index - 1)
     * 2) use element.insert_after
     */
}

void* Dlist::removeAt(int index)
{

}

int Dlist::deleteAt(int index)
{

}

void* Dlist::operator [](int index)
{
	// iterate through the list until entry number "index"
}

