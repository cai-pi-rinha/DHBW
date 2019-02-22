#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "DNode.hpp"
#include "ContainerInterface.hpp"

using namespace std;

typedef void (*DestroyFunc)(void*); /* used in DeleteAt() */

class DList : public ContainerInterface
{
private:
	DNode start_of_chain; /* start and end of chain as constant ?? */
	DNode end_of_chain;
	int number_of_elements;
	DestroyFunc destroyFunc_ptr;

	DNode* get_DNode_element(int index);

public:
    DList(DestroyFunc pfn=NULL);

    int Insert(void* obj);
    void Empty(void);
    int Count(void);
    void* GetAt(int index);

	int InsertFirst(void* obj);
	int InsertLast(void* obj);
	int InsertAt(int index, void* obj);
	int DeleteAt(int index);    // entfernt listenelement UND payload
	void* RemoveAt(int index);  // entfernt listenelement; payload bleibt irgendwo erhalten
	DNode* GetFirst(void);
	DNode* GetLast(void);
	DestroyFunc getDestroyFuncPtr(void);
	void RefreshNumberOfElements(void);

	void* operator [](int index);
};

#endif
