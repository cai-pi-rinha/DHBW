#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "DNode.hpp"
#include "ContainerInterface.hpp"
#include"dlist_iteratorImp.hpp"

using namespace std;

typedef void (*DestroyFunc)(void*); /* used in DeleteAt() */

class DList : public ContainerInterface
{
private:
	DNode* start_of_chain;	/*note that start and end of chain are both empty! both don't contain payload */
	DNode* end_of_chain;
	int number_of_elements;
	DestroyFunc destroyFunc_ptr;
	DNode* get_DNode_element(int index);

protected:
    

public:
    DList(DestroyFunc pfn=NULL);
	~DList(); 
	IteratorImp* CreateIteratorImp() const;
    int Insert(void* obj);
    void Empty();
    int Count() const;
    void* GetAt(int index);

	int InsertFirst(void* obj);
	int InsertLast(void* obj);
	int InsertAt(int index, void* obj);
	int DeleteAt(int index);    // entfernt listenelement UND payload
	void* RemoveAt(int index);  // entfernt listenelement; payload bleibt irgendwo erhalten
	DNode* GetFirst() const;
	DNode* GetLast() const;
	DestroyFunc getDestroyFuncPtr() const;
	void RefreshNumberOfElements();

	void* operator [](int index);
};

#endif
