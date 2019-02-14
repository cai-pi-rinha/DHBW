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
	number_of_elements = 0;
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
    number_of_elements++;
    start_of_chain.insert_after(obj);
}

int Dlist::insertlast(void* obj)    /** insert a new object as last element of the list */
{
    number_of_elements++;
	end_of_chain.insert_before(obj);
}

int Dlist::insertAt(int index, void* obj)   /** insert a new object at position number <index> */
{
    /* 1) go to element number (index)
     * 2) use element.insert_before
     */
    Dnode* temp = get_Dnode_element(index);
    if(temp)    /* temp is no null-pointer, hence insert the object */
        temp.insert_before(obj);
    else        /* temp is a null-pointer; quit with error -1 */
        return -1;
    return 0;
}

void* Dlist::removeAt(int index)    /** remove the link between the list element and the payload; return pointer to payload */
{
    Dnode* temp = get_Dnode_element(index);
    if(!temp)    /* temp is a null-pointer, hence quit and return a null-pointer */
        return NULL;
    return temp.remove(); /* return a pointer to the removed payload */
}

int Dlist::deleteAt(int index)  /** call destructor of list element */
{
    Dnode* temp = get_Dnode_element(index);
    delete temp;    /* delete statement can be called with a null-pointer */
    if(!temp)
        number_of_elements--;
    return 0;
}

void* Dlist::operator [](int index)
{
    Dnode* temp = get_Dnode_element(index);
    return temp ? temp.payload : NULL;  /* return NULL if there is no element at position "index" */
}

Dnode* Dlist::get_Dnode_element(int index)
{
    /* iterate through the list until entry number "index" */
	Dnode* current_element = start_of_chain.next;
    while(index && current_element)
    {
        current_element = current_element.next;
        index--;
    }
    return current_element;
}
