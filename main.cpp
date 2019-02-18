#include <iostream>
#include "source/dnode.hpp"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int zahl1 = 11;
    int zahl2 = 22;
    int zahl3 = 33;
    Dnode miniContainer1();
    Dnode miniContainer2;
    //Dnode miniContainer1, miniContainer2;
    //Dnode miniContainer3((void*)&zahl1, &miniContainer1, &miniContainer2);

    //miniContainer1.insertAfter(&miniContainer3);
    //miniContainer2.insertBefore(&miniContainer3);


    cout << "addresses of container 1 - 2 - 3 : " << endl;
/*    cout << (int)&miniContainer1 << endl;
    cout << (int)&miniContainer2 << endl;
    cout << (int)&miniContainer3 << endl << endl;
*/
    /*cout << "next of miniContainer1 should be miniContainer3: " << (int)miniContainer1.GetNext() << endl;
    cout << "prev of miniContainer2 should be miniContainer3: " << (int)miniContainer1.GetPrev() << endl;
    cout << "payload of miniContainer3 should be zahl1:       " << *(int*)miniContainer3.GetObject() << endl;
*/
    return 0;
}
