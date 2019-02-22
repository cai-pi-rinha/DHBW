#include <iostream>
#include "source/DList.hpp"
#include "source/DNode.hpp"


using namespace std;

void print_list(DList &liste);
void DestroyIntPointer(void* pv)
{ delete (int*)pv; }

int main()
{
    cout << "Hello world!" << endl;
    int zahl1 = 11;
    int zahl2 = 22;
    int zahl3 = 33;
    int zahl4 = 44;
    int zahl5 = 55;
    int zahl6 = 66;
    int zahl7 = 77;


    DList liste(&DestroyIntPointer);
    liste.InsertLast(&zahl1);
    liste.InsertLast(&zahl2);
    liste.InsertLast(&zahl3);
    liste.InsertFirst(&zahl4);
    liste.InsertAt(1, &zahl5);
    liste.InsertLast(&zahl6);
    cout << "removed following object: " << *(int*)liste.RemoveAt(2) << endl;
    liste.DeleteAt(2);
    liste.DeleteAt(3);
    liste.DeleteAt(0);
    liste.InsertAt(2, &zahl3);
    liste.InsertAt(2, &zahl7);
    liste.InsertLast(&zahl7);
    liste.InsertLast(&zahl7);
    liste.InsertLast(&zahl7);
    liste.InsertLast(&zahl7);
    liste.GetFirst()->Remove(); // löscht den payload eines listenelements; das Listenelement selbst bleibt aber noch erhalten; außerdem wird "number_of_elements" nicht verändert
    delete liste.GetFirst();

    print_list(liste);

    return 0;
}

void print_list(DList &liste)
{
    cout << "alle " << liste.getNumberOfElements() << " listen-Werte: " << endl;
    for(int i=0; i < liste.getNumberOfElements(); i++)
    {
        if(liste[i])
            cout << i << ": " << *(int*)liste[i] << endl;
    }
    cout << endl;
}
