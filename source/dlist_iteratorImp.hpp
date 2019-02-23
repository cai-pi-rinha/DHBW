#ifndef DNODE_ITERATOR_H
#define DNODE_ITERATOR_H
#include "dnode.hpp"
#include "iterator.hpp"

class DNode;
class Dlist_IteratorImp : public IteratorImp
{
private:
	DNode* m_current = NULL;		
	~Dlist_IteratorImp();
public:
	Dlist_IteratorImp(const DList& owner);	//müsste eig DList sein, aber dann kann ich konstruktor von basisklasse nich aufrufen
	Dlist_IteratorImp(const Dlist_IteratorImp& DlistIt);
	void set(DNode* dnode);
	virtual void* First();			//virtual ist nicht benoetigt zu schreiben, aber zur uebersicht besser
	virtual void* Last();
	virtual void* Prev();
	virtual void* Next();
	virtual void* Current();
	virtual Dlist_IteratorImp* Clone();
};

#endif
