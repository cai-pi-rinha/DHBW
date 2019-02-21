#ifndef DNODE_ITERATOR_H
#define DNODE_ITERATOR_H
#include "dnode.hpp"
#include "iterator.hpp"

class Dlist_IteratorImp : public IteratorImp
{
private:
	Dnode* m_current = NULL;		//wo und wann und wie wird das gesetzt????
	
	Dlist_IteratorImp(const Container_Interface& owner);
	~Dlist_IteratorImp();
public:
	void set(Dnode* dnode);
	virtual void* First();			//virtual ist nicht benoetigt zu schreiben, aebr zur uebersicht besser
	virtual void* Last();
	virtual void* Prev();
	virtual void* Next();
	virtual void* Current();
	virtual void* Clone();
};

#endif
