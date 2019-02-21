#include <iostream>
#include "source/dnode.hpp"
#include "source/dlist.hpp"


using namespace std;

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


    Dlist liste;
    liste.InsertLast(&zahl1);
    liste.InsertLast(&zahl2);
    liste.InsertLast(&zahl3);
    liste.InsertFirst(&zahl4);
    liste.InsertAt(1, &zahl5);
    liste.DeleteAt(2);

    cout << "listen-Werte: " << endl;
    for(int i=0; i < liste.getNumberOfElements(); i++)
    {
        cout << i << ": " << *(int*)liste[i] << endl;
    }

    /* - constructor of Dlist: */
    // start_of_chain and end_of_chain need to be connected with each other:

    // DIESEN TEIL HIER NACHBEARBEITEN UND IN DLIST-CONSTRUCTOR EINFÜGEN

    /*Dnode start_of_chain;
    Dnode end_of_chain;

    Dnode temp_start(NULL, NULL, &end_of_chain);
    Dnode temp_end(NULL, &start_of_chain, NULL);
    start_of_chain = temp_start;
    end_of_chain = temp_end;

    int number_of_elements  = 0;*/
    // ...delete temp_start/end

	/* - END constructor of Dlist */

	/* - start to fill list: */
    /*start_of_chain.insertAfter(&zahl1);
    cout << "start_of_chain: &this - &payload - &previous - &next: " << endl;
    cout << &start_of_chain << " - " << start_of_chain.GetObject() << " - " << start_of_chain.GetPrev() << " - " << start_of_chain.GetNext() << endl << endl;

    cout << "end_of_chain: &this - &payload - &previous - &next: " << endl;
    cout << &end_of_chain << " - " << end_of_chain.GetObject() << " - " << end_of_chain.GetPrev() << " - " << end_of_chain.GetNext() << endl << endl;

    cout << "zahl1: &this - &payload - &previous - &next: " << endl;
    cout << "..." << " - " << &zahl1 << " - " << start_of_chain.GetNext()->GetPrev() << " - " << start_of_chain.GetNext()->GetNext() << endl << endl;
*/


    //cout << *(int*)start_of_chain.GetNext()->GetObject() << endl;
    //cout << *(int*)end_of_chain.GetPrev()->GetObject() << endl;

    /* - END start to fill list */



    /*Dnode miniContainerA(); // invokes ... what?                    ~> value initialization
    Dnode miniContainerB;   // invokes empty standard constructor   ~> default initalization
    Dnode miniContainerZ(NULL, NULL, NULL);
    Dnode miniContainerY;

    Dnode miniContainer2((void*)&zahl2, NULL, NULL);

    cout << miniContainer2.insertBefore(&zahl1);
    miniContainer2.insertAfter(&zahl2);


    cout << "addresses of containers 1 - 2 - 3 : " << endl;
    cout << (int)miniContainer2.GetPrev() << endl;
    cout << (int)&miniContainer2 << endl;
    cout << (int)miniContainer2.GetNext() << endl << endl;
*/
    /*cout << "next of miniContainer1 should be miniContainer2: " << (int)miniContainer2.GetPrev()->GetNext() << endl;
    cout << "prev of miniContainer3 should be miniContainer2: " << (int)miniContainer2.GetNext()->GetPrev() << endl;
    cout << "payload of miniContainer1 should be zahl1:       " << *(int*)miniContainer2.GetPrev()->GetObject() << endl;
    cout << "payload of miniContainer2 should be zahl2:       " << *(int*)miniContainer2.GetObject() << endl;
    cout << "payload of miniContainer3 should be zahl3:       " << *(int*)miniContainer2.GetNext()->GetObject() << endl;
*/
    return 0;
}
