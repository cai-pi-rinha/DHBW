//Testprogramm

#include "source/string.hpp"
#include <stdio.h>

//kompilieren und direkt exe erzeugen mit namen der exe angebbar: >cl /Fe:test.exe string.cpp main.cpp
int main()
{
	
	 const char* bla = "hans"; //adresse von hans wird in bla gespeichert damit er nur einmal angelegt werden muss
	 const char* apcszNamen[] = 	//array von pointern
	 {
			 "Hans", "Hannes", "Hein", "Heiner", "Hein", "Hein", NULL
	 };

	 int i = 0;
	 for (i = 0; apcszNamen[i] != NULL; ++i)
	 {
		 const char* pcszStr = apcszNamen[i];
		 const char* pcszStrNext = apcszNamen[i + 1];

		 printf("Strlen(\"%s\"): %d\n", pcszStr, Strlen(pcszStr));

		 printf(
				 "Stricmp(\"%s\", \"%s\"): %d\n",
				 pcszStr,
				 pcszStrNext,
				 Strcmp(pcszStr, pcszStrNext));
		 char szBuffer[80];
		 szBuffer[0] = '\0';
		 printf(
				 "Strcpy(\"%s\") = \"%s\"\n",
				 pcszStr,
				 Strcpy(szBuffer, pcszStr));
		 char* pszDup = Strdup(pcszStr);
		 printf("Strdup(\"%s\"): \"%s\"\n", pcszStr, pszDup);
		 delete[] pszDup;		//array delete operator (delete[] p) löscht komplettes array 
								//und nicht nur den ersten pointer wie es bei delete ohne [] der fall wäre
	 }
		
	
	 char* character = "hallo";
	 printf("charakter ist : %c \n", character[1]);
	 String coStr1;
	 String coStr2 = "Hans";
	
	 const char* pcszStr123 = coStr2; //zuweisung von string zu const char. das geht mit dem überladenen const char*()
	 printf("Konstruktor: coStr2 = \"%s\" \n", coStr2.GetStr() );
	
	 //hier wird in beiden fallen copy constructor verwendet
	 String coStr5(coStr2);
	 printf("Konstruktor mit Parameter: coStr5 = \"%s\" \n", coStr5.GetStr() );

	 String coStr4 = coStr2;
	
	 printf("Copy Konstruktor: coStr4 = \"%s\" \n", coStr4.GetStr() );

	 coStr1.operator=(coStr2);
	 printf("= Zuweisung coStr1 = coStr2 \n davor coStr1 = \"%s\" \n ", coStr1.GetStr() );
	 coStr1 = coStr2;
	 printf("danach coStr1 = \"%s\" \n", coStr1.GetStr() );

	 if (coStr1.operator==(coStr2))
	 coStr2 = "Gustav";
	 printf("Costr2= \"%s\" \n", coStr2.GetStr() );
	 if(coStr1 == coStr2)
	 {
		 printf("vergleich == von Costr1 \"%s\" und Costr2 \"%s\" = gleich\n", coStr1.GetStr(), coStr2.GetStr());
	 }
	 else{
		 printf("vergleich == von Costr1 \"%s\" und Costr2 \"%s\" = ungleich\n", coStr1.GetStr(), coStr2.GetStr());

	 }
		 if(coStr1 != coStr2)
	 {
		 printf("vergleich != von Costr1 \"%s\" und Costr2 \"%s\" = ungleich\n", coStr1.GetStr(), coStr2.GetStr());
	 }
	 else{
		 printf("vergleich != von Costr1 \"%s\" und Costr2 \"%s\" = gleich\n", coStr1.GetStr(), coStr2.GetStr());

	 }
	
	 i = 0;
	 while(i < coStr1.Length() )
	 {
		 char c = coStr1[i];
		 printf("While Schleife: \"%c\" \n", c);
		 ++i;
	 }
	
	 i = 0;
	 char cRep = 'p';
	
	
	 if(coStr1.Replace(i, cRep))
	 {
		 printf("character on index [%i] has been replaced with %c ==> resulting string: \"%s\" \n", i, cRep, coStr1.GetStr() );
	 }
	
	 coStr1 = "Hans";
	 coStr2 = "Ans";
	 if(coStr1 >= coStr2)
	 {
		 printf("vergleich >= von Costr1 \"%s\" und Costr2 \"%s\" = groessergleich\n", coStr1.GetStr(), coStr2.GetStr());
	 }
	 if(coStr1 <= coStr2)
	 {
		 printf("vergleich <= von Costr1 \"%s\" und Costr2 \"%s\" = kleinergleich\n", coStr1.GetStr(), coStr2.GetStr());
	 }
	
	 if(coStr1 > coStr2)
	 {
		 printf("vergleich > von Costr1 \"%s\" und Costr2 \"%s\" = groesser\n", coStr1.GetStr(), coStr2.GetStr());
	 }
	 if(coStr1 < coStr2)
	 {
		 printf("vergleich < von Costr1 \"%s\" und Costr2 \"%s\" = kleiner\n", coStr1.GetStr(), coStr2.GetStr());
	 }
	
	String coStr3("Gustav");
	
	printf("coStr3 = %s\n", coStr3.GetStr());
	coStr3 = "HansWurscht";
	printf("coStr3 = %s\n", coStr3.GetStr());
	int cutStart = 3;
	int cutEnde = 5;
	String coStr15;
	printf("Cut Funktion angewendet auf coStr3: davor \"%s\", cut an Stelle %d bis %d\n", 
			coStr3.GetStr(), cutStart, cutEnde);
	coStr15 = coStr3.Cut(cutStart, cutEnde);
	printf("ausgeschnittenes: \"%s\" Laenge: %d\n", coStr15.GetStr(), coStr15.Length());
	printf("danach: \"%s\" \n", coStr3.GetStr());
	printf("+= operator %s\n", (coStr3+=coStr15).GetStr());
	
	coStr3="HansWurscht";
	printf("Partcopy von 2 bis 5: string: %s laenge %d \n", coStr3.PartCopy(2,5).GetStr(),coStr3.PartCopy(2,5).Length());
	
	
	String coStr12 = "   Alle Kinder sind Chineeeeesennn   ";
	String coStr13 = coStr12;
	char* criteria = "Ane ";
	coStr12.Normalise(criteria);
	printf("\n\nnormalise Funktion Test: zu entfernende zeichen: \"%s\" \ndavor: \"%s\"\ndanach: \"%s\"\n", criteria, coStr13.GetStr(), coStr12.GetStr());
	
	char cSearch = ' ';
	int iSep = coStr12.FindChar(cSearch,4);
	printf("\n\nindex search: \"%c\", string: %s, index: %d \n", cSearch, coStr12.GetStr(), iSep); 
	
	
	String coStr50 = "Gustav Gans Die Ente";
	char* pszSearch = "nt";
	printf("suche in string \"%s\" nach \"%s\": Index %d\n\n}", coStr50.GetStr(), pszSearch, coStr50.FindString(pszSearch,0));
	
	/*
	
	void func1(String coStr) //copy constructor
	{}
	void func2(String& rcoStr)	//referenz
	{
		rcoStr.Cut(10);
	}
	void func3(const String& rccoStr)		//auf einem const objekt kann man nur const funktionen anwenden!!!
	{
		int iLen = rccoStr.Length();
	}	*/
	return 0;
}
