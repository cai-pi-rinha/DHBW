#include <iostream>
#include "source/ContainerInterface.hpp"
#include "source/DList.hpp"
#include "source/DNode.hpp"


using namespace std;

void DestroyIntPointer(void* pv)
{ delete (int*)pv; }

int main()
{
    cout << "Hello world!" << endl;
    int zahl1 = 11;
    int zahl2 = 22;
    int zahl3 = 33;

    DList myList;
    myList.Insert(&zahl1);
    myList.Insert(&zahl2);
    myList.Insert(&zahl3);
    cout << "werte: ";
    int i=-1;
    int output = 0;
    while(myList.GetAt(++i))
    {
        cout << *(int*)myList.GetAt(i) << " - ";
    }
    cout << endl;

    myList.Empty();
    cout << "werte: ";
    i=-1;
    output = 0;
    while(myList.GetAt(++i))
    {
        cout << *(int*)myList.GetAt(i) << " - ";
    }
    cout << endl;


    return 0;
}
