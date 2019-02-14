#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator
{
private:
	Container* imp;
	Dnode* current;
	Dnode* next;
	Dnode* prev;
	Dnode* first;
	Dnode* last;

public:
    Iterator(void);
	Iterator(Container container);
	// - Q: Ist es denn möglich, die Werte für current, next, ... in den vererbten Klassen zu befüllen und in der Parent-Klasse auszugeben?
	//	-> A: Prinzipiell sollte das funktionieren; was aber, wenn ich nach Ausgabe von next das Attribut aktualisieren will (also "next = next++")
	virtual Dnode* first(void)		{return first;}
	virtual Dnode* last(void) 		{return last;}
	virtual Dnode* next(void) 		{return next;}
	virtual Dnode* prev(void) 		{return prev;}
	virtual Dnode* current(void)	= 0;
	/*	'= 0';
	 *	This is a pure virtual function. Used when there
	 *	is no sensible default implementation for that method.
	 *	This means, that subclasses have to implement this
	 *	function, otherwise they are abstract, meaning you
	 *	cannot create objects of that class.
	 */
};

class Iterator_Impl : public Iterator : public Container
{
private:

public:
    Iterator_Impl(void);
	Iterator_Impl(Container container);
	// - Q: Ist es denn möglich, die Werte für current, next, ... in den vererbten Klassen zu befüllen und in der Parent-Klasse auszugeben?
	//	-> A: Prinzipiell sollte das funktionieren; was aber, wenn ich nach Ausgabe von next das Attribut aktualisieren will (also "next = next++")
	virtual Dnode* first(void)		= 0;
	virtual Dnode* last(void)		= 0;
	virtual Dnode* next(void)		= 0;
	virtual Dnode* prev(void)		= 0;
	virtual Dnode* current(void)	= 0;
	/*	'= 0';
	 *	This is a pure virtual function. Used when there
	 *	is no sensible default implementation for that method.
	 *	This means, that subclasses have to implement this
	 *	function, otherwise they are abstract, meaning you
	 *	cannot create objects of that class.
	 */
};


#endif
