#ifndef DNODE_H
#define DNODE_H

#ifndef NULL
    #define NULL 0
#endif // NULL

class Dnode
{
private:
    Dnode* next;
    Dnode* prev;
    void* payload;

public:
    Dnode(void);
    Dnode(void* payload, Dnode* prev, Dnode* next);
    ~Dnode(void);

	Dnode* GetNext(void);
	Dnode* GetPrev(void);
	void* GetObject(void);

	void* Remove(void);
	int insertBefore(void* obj);
	int insertAfter(void* obj);
};

#endif
