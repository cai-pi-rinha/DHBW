#include "dlist.hpp"
#include "dnode.hpp"

// constructor
Dlist::Dlist(void)
{
	start_of_chain = NULL;
	end_of_chain = NULL;
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
	/* 1) go to start of list -> pointer of start_of_chain
	 * 2) create dnode-object and configure:
	 *      prev-pointer    = NULL, as it is going to be the first element in the list;
	 *      next-pointer    = start_of_chain;
	 *      payload         = obj
	 * 3) change start_of_chain to address of dnode-object
	 */
    new Dnode obj_to_insert(obj, NULL, start_of_chain);
    start_of_chain = &obj_to_insert;
}

int Dlist::insertlast(void* obj)
{
	// ...
	//end_of_chain->
}

void* Dlist::operator [](int index)
{
	// iterate through the list until entry number "index"
}

