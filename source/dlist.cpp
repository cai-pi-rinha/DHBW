#include "dlist.hpp"
#include "dnode.hpp"

// constructor
Dlist::Dlist(DestroyFunc pfn)
{
    destroyFunc_ptr = pfn;  /* pointer to function which is capable of deleting the list's payload properly */

    start_of_chain = Dnode(NULL, NULL, &end_of_chain);
    end_of_chain = Dnode(NULL, &start_of_chain, NULL);

    number_of_elements  = 0;
}

int Dlist::InsertFirst(void* obj)   /** insert a new object as first element of the list */
{
    number_of_elements++;
    return start_of_chain.insertAfter(obj);
}

int Dlist::InsertLast(void* obj)    /** insert a new object as last element of the list */
{
    number_of_elements++;
	return end_of_chain.insertBefore(obj);
}

int Dlist::InsertAt(int index, void* obj)   /** insert a new object at position number <index> */
{
    /* 1) go to element number (index)
     * 2) use element.insertBefore
     */
    Dnode* temp = get_Dnode_element(index);
    if(temp)    /* temp is no null-pointer, hence insert the object */
    {
        temp->insertBefore(obj);
        number_of_elements++;
    }
    else        /* temp is a null-pointer; quit with error -1 */
        return -1;
    return 0;
}

void* Dlist::RemoveAt(int index)    /** remove the link between the list element and the payload; delete the list element; return pointer to payload */
{
    Dnode* temp = get_Dnode_element(index);
    void* payload = NULL;
    if(temp)    /* skip if temp is a null pointer */
    {
        payload = temp->Remove();   /* save the address of the removed payload */
        delete temp;                /* delete the list element */
        number_of_elements--;
    }
    return payload; /* return a pointer to the removed payload */
}

int Dlist::DeleteAt(int index)  /** call destructor of payload and delete list element  */
{
    Dnode* temp = get_Dnode_element(index);
    void* payload = NULL;
    if(temp)
    {
        payload = temp->Remove();           /* save the address of the removed payload */
        if(destroyFunc_ptr)
            (*destroyFunc_ptr)(payload);    /* delete payload */
        delete temp;
        number_of_elements--;
    }
    return temp ? 0 : -1;
}

void* Dlist::operator [](int index)
{
    Dnode* temp = get_Dnode_element(index);
    return temp ? temp->GetObject() : NULL;  /* return NULL if there is no element at position "index" */
}

Dnode* Dlist::get_Dnode_element(int index)
{
    /* iterate through the list until entry number "index" */
	Dnode* current_element = start_of_chain.GetNext();
    while(index && current_element)
    {
        current_element = current_element->GetNext();
        index--;
    }
    return current_element;
}

int Dlist::getNumberOfElements(void)
{ return number_of_elements; }

Dnode* Dlist::GetFirst(void)
{ return start_of_chain.GetNext(); }

Dnode* Dlist::GetLast(void)
{ return end_of_chain.GetPrev(); }
