#include <iostream>
#include "source/dnode.hpp"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int zahl1 = 11;
    int zahl2 = 22;
    int zahl3 = 33;
    Dnode miniContainerA(); // invokes ... what?                    ~> value initialization
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

    /*cout << "next of miniContainer1 should be miniContainer2: " << (int)miniContainer2.GetPrev()->GetNext() << endl;
    cout << "prev of miniContainer3 should be miniContainer2: " << (int)miniContainer2.GetNext()->GetPrev() << endl;
    cout << "payload of miniContainer1 should be zahl1:       " << *(int*)miniContainer2.GetPrev()->GetObject() << endl;
    cout << "payload of miniContainer2 should be zahl2:       " << *(int*)miniContainer2.GetObject() << endl;
    cout << "payload of miniContainer3 should be zahl3:       " << *(int*)miniContainer2.GetNext()->GetObject() << endl;
*/
    return 0;
}
