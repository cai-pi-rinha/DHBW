//Testprogramm

#include "string.hpp"
#include <stdio.h>
#include <iostream>
#include "iterator.hpp"
#include "dnode.hpp"
#include "dlist.hpp"
//kompilieren und direkt exe erzeugen mit namen der exe angebbar: >cl /Fe:test.exe string.cpp main.cpp
using namespace std;

int main()
{
	String String1 = "Gustav Gans";
	String String2 = "Arnold Schwarzenegger";
	String String3 = "Stinkstiefel";
	cout << "erstes cout ohne Liste: " << String1.GetStr() << endl;
	
	DList* Liste = new DList(NULL);
	Liste->Insert(String1);
	Liste->Insert(String2);
	Liste->Insert(String3);
	Iterator* it = Liste->MakeIterator();
	//String* Bla = (String*)it->First();		
		//so funktioniert dann typconversion!
	cout << "Ausgabe direkt: "<< String1.GetStr()<< " Ausgabe ueber iterator" << ((String*)it->First())->GetStr()<< endl;
	//static_cast<Iterator*>
}
