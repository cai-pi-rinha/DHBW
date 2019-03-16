//Testprogramm

#include "source/string.hpp"
#include <stdio.h>
#include <iostream>
#include "source/iterator.hpp"
#include "source/dnode.hpp"
#include "source/dlist.hpp"
//kompilieren und direkt exe erzeugen mit namen der exe angebbar: >cl /Fe:test.exe string.cpp main.cpp
using namespace std;

void DestroyStringPointer(void* obj)
{
	if (obj != NULL)
		delete (String*)obj;
}

int main()
{
	String String1 = "Gustav Gans";
	String String2 = "Arnold Schwarzenegger";
	String String3 = "Stinkstiefel";
	cout << "erstes cout ohne Liste: " << String1.GetStr() << endl;
	
			//DList* Liste = new DList(NULL);				//dynamisch anlegen
	DList Liste1(NULL);
	Liste1.Insert(&String1);
	Liste1.Insert(&String2);
	Liste1.Insert(&String3);
	Iterator* it = Liste1.MakeIterator();
			//String* Bla = (String*)it->First();			//so funktioniert dann typconversion!

	//Test Iterator 
	cout << "\n\n\nTest der Next Funktion: " << endl;
	do{ 
		cout << "Ausgabe ueber iterator: " << ((String*)it->Current())->GetStr()<< endl;
	} while (it->Next());

	cout << "\n\n\n Test der Prev Funktion: " << endl;
	do {
		cout << "Ausgabe ueber iterator: " << ((String*)it->Current())->GetStr() << endl;
	} while (it->Prev());

	cout << "\n\n\nTest der Last Funktion: " << ((String*)it->Last())->GetStr() <<  endl;
	cout << "\n\n\nTest der First Funktion: " << ((String*)it->First())->GetStr() << endl;
	cout << "------------ Iterator Test over ------------ " << endl;


	//Test Empty und Count von Container
	cout << "\n\n\nTest der Count und Empty Funktion: " << endl << "Laenge vor empty: " << Liste1.Count() << " ";
	Liste1.Empty();
	cout << "Laenge nach empty: "<< Liste1.Count() << endl;
	delete it;


	//Test von GetAt
	Liste1.Insert(&String1);
	Liste1.Insert(&String2);
	Liste1.Insert(&String3);
	Iterator* it1 = Liste1.MakeIterator();
	cout << "\n\n\nTest der GetAt Funktion: " << endl;
	for (int i = -1; i < 4; i++)
	{ 
		const char* puffer = ((String*)Liste1.GetAt(i))->GetStr();
		if (puffer)
			cout << "GetAt(" << i << ") : " << ((String*)Liste1.GetAt(i))->GetStr() << endl;
		else
			cout << "Zugriff ausserhalb der Dlist! Ueberhitzung der Systeme! Index: " << i << endl;
	}
	

	//Test InsertFirst/Last
	String String4("Neuer Erster String");
	String String5("Neuer Letzer String");
	Liste1.InsertFirst(&String4);
	Liste1.InsertLast(&String5);
	delete it1;
	Iterator* it2 = Liste1.MakeIterator();
	int i = 0;
	cout << "\n\n\nTest InsertFirst/Last: " << endl;
	do {
		cout << "String an Stelle" << i <<": " << ((String*)it->Current())->GetStr() << endl;
			i++;
	} while (it2->Next());



	//Test DeleteAt
	cout << "\n\n\nTest DeletAt: " << endl;
	int iToDelete = 4;
	if(Liste1.GetAt(iToDelete))
		cout << "Loesche String: "<< ((String*)Liste1.GetAt(iToDelete))->GetStr() <<endl << "Ausgabe von Container danach:"<<endl;
	Liste1.DeleteAt(iToDelete);
	for (int i = 0; i < 5; i++)
	{
		const char* puffer = ((String*)Liste1.GetAt(i))->GetStr();
		if (puffer)
			cout << "String an Stelle" << i << ": " << ((String*)Liste1.GetAt(i))->GetStr() << endl;
	}



	//Test RemoveAt
	cout << "\n\n\nTest RemoveAt: " << endl;
	iToDelete = 0;
	if (Liste1.GetAt(iToDelete))
		cout << "Loesche String: "<< ((String*)Liste1.GetAt(iToDelete))->GetStr() <<endl << "Ausgabe von Container danach:"<<endl;
	Liste1.DeleteAt(iToDelete);
	for (int i = 0; i < 5; i++)
	{
		const char* puffer = ((String*)Liste1.GetAt(i))->GetStr();
		if (puffer)
			cout << "String an Stelle" << i << ": " << ((String*)Liste1.GetAt(i))->GetStr() << endl;
	}

	//oprator []
	i = 2;
	if (Liste1[i])
		cout << "\n\n\nTest operator[]: Liste[" << i << "] = \"" << ((String*)Liste1[i])->GetStr() << "\"" << endl;
	else
		cout << "\n\n\nTest operator[]: Falscher Zugrifft an Stelle Liste[" << i << "]" << endl;

	//Test InsertAt
	String String6 = "InsertAt String";
	i = 2;
	cout << "\n\n\nTest InsertAt: Insert an Stelle "<< i << endl;
	Liste1.InsertAt(i, &String6);
	Iterator* it3 = Liste1.MakeIterator();
	do	{
		cout << "Stringausgabe: " << ((String*)it3->Current())->GetStr() << endl;
	} while (it3->Next());



	//Test Destruktor mit löschung der payload
	DList* Liste2 = new DList(&DestroyStringPointer);
	String* stringPtr1 = new String("Nummer 1/2");
	String* stringPtr2 = new String("Nummer 2/2");
	Liste2->Insert(stringPtr1);
	Liste2->Insert(stringPtr2);
	cout << "\n\n\nTest Destruktor: Ausgabe aller Strings:" << endl;

	for (int i = 0; i < 5; i++)
	{
		const char* puffer = ((String*)Liste2->GetAt(i))->GetStr();
		if (puffer)
			cout << "String an Stelle" << i << ": " << ((String*)Liste2->GetAt(i))->GetStr() << endl;
	}
	String* Test = stringPtr1;
	cout << "Ausgabe des Strings nach delete: ";
	if (Test)
		cout << stringPtr1->GetStr() << endl;
	else
		cout << "String wurde geloescht" << endl;
	delete Liste2;		//stürzt ab wenn ich das vor das cout mache, also wird es wohl stimmen!


	//das geht noch nicht! stürzt ab weil iterator wo steht wo er nicht sollte
	/*Iterator* it1 = Liste1.MakeIterator();
	Liste1.Empty();
	Liste1.Insert(&String1);
	if (it1->Current())
	{
		do {
			cout << "Ausgabe ueber iterator: " << ((String*)it1->Current())->GetStr() << endl;
		} while (it->Next());
	}
	Liste1.Insert(&String1);
	cout << ((String*)it1->Next())->GetStr() << endl;*/

}
