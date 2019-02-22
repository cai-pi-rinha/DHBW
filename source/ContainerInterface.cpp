#include "ContainerInterface.hpp"
//#include "Iterator.hpp"   // to be added when DList and Iterator are combined


ContainerInterface::ContainerInterface(void)
{
    myIteratorImp = NULL;
}

ContainerInterface::~ContainerInterface(void)
{

}

Iterator* ContainerInterface::MakeIterator(void)
{
    /*
    Iterator* newIterator = new Iterator(this); // create a new Iterator with a reference of the current ContainerInterface
    return &newIterator;
    */
    return NULL;
}
