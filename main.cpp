//Testprogramm

#include "string.hpp"
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
	
	/*
	
	
	das soll möglich sein!
	
	*/
	
	String coStri1;
	String coStr2 = "Hans";
	
	//hier wird in beiden fallen copy constructor verwendet
	String coStr3(coStr2);
	String coStr4 = coStr2;
	
	//coStr1.operator=(coStr2);
	coStr1 = coStr2;
	
	//if (coStr1.operator==(coStr2))
	if(coStr1 == coStr2)
	{
		
	}
	
	while(i < coStr1.Length() )
	{
		char c = coStr1[i];
		++i;
	}
	
	int iSep = coStr1.FindIndex(':');
	if(iSep>=0)
	{...}
	
	void func1(String coStr) //copy constructor
	{}
	void func2(String& rcoStr)	//referenz
	{
		rcoStr.Cut(10);
	}
	void func3(const String& rccoStr)		//auf einem const objekt kann man nur const funktionen anwenden!!!
	{
		int iLen = rccoStr.Length();
	}
	
	return 0;
}
