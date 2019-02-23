#ifndef ITERATOR_H
#define ITERATOR_H


class ContainerInterface;
class IteratorImp
{
private:


protected:
	const ContainerInterface* m_owner = 0;	//is used in copy constructor of Dlist_iteratorImp
	IteratorImp(const ContainerInterface& owner);
	IteratorImp();			//muss weg! ich weiß nur nich was man mit owner macht und wie man den in dlistiterator übergibt
	IteratorImp(const IteratorImp& implementation);

public:
	virtual IteratorImp* Clone() = 0;
	virtual ~IteratorImp() = 0;
	virtual void* First() = 0;
	virtual void* Last() = 0;
	virtual void* Prev() = 0;
	virtual void* Next() = 0;
	virtual void* Current() = 0;

	//virtual Dnode* current(void)	= 0;
	/*	This is a pure virtual function. Used when there
	*	is no sensible default implementation for that method.
	*	This means, that subclasses have to implement this
	*	function, otherwise they are abstract, meaning you
	*	cannot create objects of that class.
	*/
};

class Iterator 
{
private:
	IteratorImp* m_imp;		//=Null bringt tatsächlich nichts, wird im konstrutkor initialisiert
	
public:
	Iterator();
	Iterator(const ContainerInterface& container);
	Iterator(const Iterator& iterator);
	~Iterator();
	Iterator& operator=(const Iterator& iterObj);
	void* First();
	void* Last();
	void* Prev();
	void* Next();
	void* Current();
};



#endif
