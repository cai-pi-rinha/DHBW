#include "DList.hpp"
#include "dlist_iteratorImp.hpp"   

// constructor
DList::DList(DestroyFunc pfn)
{
    destroyFunc_ptr = pfn;			/* pointer to function which is capable of deleting the list's payload properly */
	DNode* newStart = new DNode(NULL, NULL, NULL, this); 
	start_of_chain = newStart;
	start_of_chain->insertAfter(NULL);						//create endOfchain
	end_of_chain = start_of_chain->GetNext();
    number_of_elements  = 0;
}

DList::~DList()
{
	if (destroyFunc_ptr)
	{
		Empty();		//delete entire list
	}
}
IteratorImp* DList::CreateIteratorImp() const
{
    Dlist_IteratorImp* DlistIt = new Dlist_IteratorImp(*this);  // create a new DListIteratorImp and return the pointer as IteratorImp
    return DlistIt;
}

int DList::Insert(void* obj)    /** Insert new element at end of list */
{
    return InsertLast(obj);
}

void DList::Empty(void) /** kills entire list */
{
    while(start_of_chain->GetNext()->GetNext())		//we need 2 getNext because we don't want to delete end_of_chain
        DeleteAt(0);
	//refresh is already done at delete
}

void* DList::GetAt(int index)
{
	DNode* DNode_element = NULL;
    if(index >= 0 && index < number_of_elements )
		DNode_element = this->get_DNode_element(index);
    return DNode_element ? DNode_element->GetObject() : NULL;
}

int DList::Count(void) const
{ return number_of_elements; }

int DList::InsertFirst(void* obj)   /** insert a new object as first element of the list */
{
	int iReturn = start_of_chain->insertAfter(obj);
	RefreshNumberOfElements();
	return iReturn;
}

int DList::InsertLast(void* obj)    /** insert a new object as last element of the list */
{
	int iReturn = end_of_chain->insertBefore(obj);
	RefreshNumberOfElements();
	return iReturn;
}

int DList::InsertAt(int index, void* obj)   /** insert a new object at position number <index> */
{
    /* 1) go to element number (index)
     * 2) use element.insertBefore
     */
	int iReturn = 0;
	if (index >= 0 && index <= number_of_elements)
	{
		DNode* temp = get_DNode_element(index);
		if (temp)    /* temp is no null-pointer, hence insert the object */
		{
			temp->insertBefore(obj);
			RefreshNumberOfElements();
		}
		else        /* temp is a null-pointer; quit with error -1 */
			iReturn = -1;
	}
	else
		iReturn = -1;
	return iReturn;			//if iReturn = -1, something went wrong
}

void* DList::RemoveAt(int index)    /** delete list element; payload stays alive ~somewhere~ */
{
    DNode* temp = get_DNode_element(index);
    void* payload = NULL;
	if (temp && index >= 0 && index < number_of_elements)   /* skip if temp is a null pointer or index out of bounds */
    {
        payload = temp->GetObject();   /* save the address of the removed payload */
		temp->Remove();					//reorder DNode pointers
        delete temp;		 //number of elements is refreshed at ~DNode()
    }
    return payload; /* return a pointer to the removed payload */
}

int DList::DeleteAt(int index)  /** delete list element AND payload  */
{
    DNode* temp = get_DNode_element(index);
    if(temp && index >= 0 && index < number_of_elements)
    {
		void* payload = NULL;
        payload = temp->GetObject();           /* save the address of the removed payload */
        if(destroyFunc_ptr)
            (*destroyFunc_ptr)(payload);    /* delete payload */
		temp->Remove();					//reorder DNode pointers
		delete temp;					//number of elements is refreshed at ~DNode()
	}
    return temp ? 0 : -1;
}

void* DList::operator [](int index)
{
	DNode* temp = NULL;
	if (index >= 0 && index < number_of_elements)
		temp = this->get_DNode_element(index);
	return temp ? temp->GetObject() : NULL; /* return NULL if there is no element at position "index" */
}

DNode* DList::get_DNode_element(int index)
{
	/* iterate through the list until entry number "index" */
	DNode* current_element = start_of_chain->GetNext();
	while (index && current_element)
	{
		current_element = current_element->GetNext();
		index--;
	}
	return current_element;
}

DNode* DList::GetFirst(void) const
{ return start_of_chain->GetNext(); }

DNode* DList::GetLast(void) const
{ return end_of_chain->GetPrev(); }

DestroyFunc DList::getDestroyFuncPtr(void) const
{ return destroyFunc_ptr; }

void DList::RefreshNumberOfElements(void) 
{
	int counter = 0;
    DNode* current = start_of_chain->GetNext();
    while(current->GetNext() )		//check if we are already at end of chain
    {
        current = current->GetNext();
        counter++;
    }
    number_of_elements = counter;
}
