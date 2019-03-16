#include "ContainerInterface.hpp"
//#include "Iterator.hpp"   // to be added when DList and Iterator are combined


ContainerInterface::ContainerInterface()
{
  
}

ContainerInterface::~ContainerInterface()
{

}

Iterator* ContainerInterface::MakeIterator() const
{
    Iterator* newiterator = new Iterator(*this); // create a new iterator with a reference of the current containerinterface
    return newiterator;
 }
