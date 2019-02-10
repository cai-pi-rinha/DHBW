#ifndef CONTAINER_H
#define CONTAINER_H
 
class Container
{
private:
    int m_length;
 
public:
    Container(void);
	virtual int remove(int) 		= 0;
	virtual int insert(void* obj) 	= 0;
	virtual int create(void) 		= 0;
	/*	'= 0';
	 *	This is a pure virtual function. Used when there 
	 *	is no sensible default implementation for that method.  
	 *	This means, that subclasses have to implement this 
	 *	function, otherwise they are abstract, meaning you 
	 *	cannot create objects of that class.
	 */
    int getlength(void);
};
 
#endif