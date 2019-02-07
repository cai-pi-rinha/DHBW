//Implementierung "string.cpp"

#include "string.hpp"
//zum Kompilieren: developer eingabeaufforderung in windows öffnen, dann zum ordner wo .cpp drin liegt
//dann in developer konsole  cl /Zi /c string.cpp

//NUllpointer soll behandelt werden wie leerer String

int Strlen(const char* pcsz)		
{

	int iRet = 0;
	if(pcsz != NULL)
	{
		while(pcsz[iRet] != '\0')
		{
			++iRet;
		}
	}
	return iRet;
}

int Strcmp(const char* pcsz1, const char* pcsz2)
{
	int iRet = 0;
	if(pcsz1 != NULL && pcsz2 != NULL)
	{
		const char* temp = NULL;
		//was passiert wenn die zwei strings ungleich lang?
		if(Strlen(pcsz1) > Strlen(pcsz2))
		{
			temp = pcsz1;
		}
		else
		{
			temp = pcsz2;
		}
		for(int iCtr = 0; temp[iCtr] != '\0'; ++iCtr)
		{
			if(pcsz1[iCtr] != pcsz2[iCtr])
			{
				iRet = pcsz1[iCtr] - pcsz2[iCtr];
				break;
			}
		}	
	}
	else if(pcsz1 != NULL)
	{
		iRet = pcsz1[0] - 0;
	}
	else if(pcsz2 != NULL)
	{
		iRet = 0 - pcsz2[0];
	}
	// if both NULL, iRet => 0 
	return iRet;
}

char* Strcpy(char* pszBuf, const char* psczStr)
{
	int iCtr = 0;
	char* pszRet = pszBuf;
	if(psczStr != NULL)
	{
		do
		{
			pszRet[iCtr] = psczStr[iCtr];
			++iCtr;
		}while(psczStr[iCtr] != '\0');
		pszRet[iCtr] = '\0';		//an letzter Stelle muss noch ein Abschlusszeichen stehen
	}
	return pszRet;
}

char* Strdup(const char* pcsz)
{
	char* pszRet = NULL;
	if(pcsz)
	{
		pszRet = Strcpy(new char[Strlen(pcsz)], pcsz);
	}
	return pszRet;
}	

