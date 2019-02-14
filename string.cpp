// Implementierung: string.cpp

#include "string.hpp"

// ***************************************************************************
// Members of class String
// ***************************************************************************
String::String()
{
	m_pszStr = NULL;
}

String::String(const String& rccoObj)
{
	m_pszStr = Strdup(rccoObj.GetStr() ); 
		//	m_pszStr = Strdup(rccoObj.m_pszStr() ); würde auch gehen da C++ davon ausgeht,
		//	dass die KLasse ein freund von sich selber ist( darf auf private zugreifen) 
	setLength();
}

String::String(const char* pcszStr)
{
	m_pszStr = Strdup(pcszStr);
	setLength();
}

String::~String()
{
	//if (m_pszStr != NULL) 		//free funktion stürzt ab wenn pointer null wäre! (hier aber unnötig da delete darauf prüft)
		delete[] m_pszStr;
}


void String::setLength()
{
	m_ilength = Strlen(m_pszStr);
}

int String::Length() const
{
	return m_ilength;
}

const char* String::GetStr() const
{
	return m_pszStr;
}

int String::FindChar(char cSearch, int iStartIndex) const
{
	int iRet = -1;
	if(iStartIndex < m_ilength && iStartIndex >= 0)
	{
		iRet = 0;
		char* temp = m_pszStr + iStartIndex;
		bool found = false;
		while(*temp != '\0' && !found)		// \0 marks the end of the string_type
		{
			if(cSearch == *temp)	//when we found it, we mustn't increase the index iRet
			{
				found = true;
			}
			else{
				iRet++;
			}
			temp++;
		}
		iRet += iStartIndex; 		//dont forget to add the startindex(offset)
		if(!found)
			iRet = -1;
	}
	return iRet;		
}


int String::FindString(const char* pszSearchString, int iStartIndex) const
{
	int iRet = -1;
	if(iStartIndex < m_ilength && iStartIndex >= 0)
	{
		iRet = 0;
		char* temp = m_pszStr + iStartIndex;
		bool found = false;
		while(*temp != '\0' && !found)		// \0 marks the end of the string_type
		{
			const char* searchString = pszSearchString;				//remember
			char* stringStart = temp;
			while(*searchString != '\0' && *searchString == *stringStart)		//compare each char of both strings
			{
				printf("%c", *searchString);
				searchString++;
				stringStart++;
			}
			if(*searchString == '\0')		
				found = true;					//if we've made it to here, that means we found our string
			else
				iRet++;
			temp++;
		}
		iRet += iStartIndex; 		//dont forget to add the startindex(offset)
		if(!found)
			iRet = -1;
	}
	return iRet;	
}




String:: operator const char*() const	//Bsp: String string1; const char* pszStr = string1 
{										//man kann also einen String einem const character pointer zuweisen! 
	return m_pszStr;
}

String:: operator char*() 
{									 
	return m_pszStr;
}

String:: operator int() const	
{										
	int iRet = 0;
	if(m_pszStr != NULL)
		iRet = atoi(m_pszStr); //wandelt string "1234" in eine zahl 1234, buchstaben werden zu null
	return iRet;
}

String& String::Normalise(const char* pszParameters)
{	
	bool found = false;
	for(int i = 0; i < Strlen(pszParameters); i++)
	{
		while(m_pszStr[0] == pszParameters[i]){
			found = true;
			*this = PartCopy(1, m_ilength - 1);		//lose the first character, stopindex is length-1
		}
		while(m_pszStr[m_ilength-1] == pszParameters[i]){	//last character is length-1
			found = true;
			*this = PartCopy(0, m_ilength - 2);		//lose the last character
		}
		if(found)
		{
			i = -1;									//if we found a parameter we have to go over the whole string again
													//-1 because it will be counted immediately afterwards
			found = false;
		}
	}
	return *this;
}

String& String::operator+=(const String& rccoStr)
{
		int iNewLen = m_ilength + rccoStr.m_ilength +1;		//dont forget \0
		int iNext = 0;
		char* pszNew = new char[iNewLen];
		if(m_pszStr)
		{
			Strcpy(pszNew, m_pszStr);
			iNext = m_ilength;
		}
		if (rccoStr.m_pszStr)
			Strcpy(&pszNew[iNext], rccoStr.m_pszStr); //oder anstatt &pszNew[iNext] kann man pszNew+iNext nehmen!
		delete[] m_pszStr;
		m_pszStr = pszNew;
		setLength();
		return *this;
}


String&	String::Cut(int iStartIndex, int iStopIndex)
{
	String* returnString = new String("NULL");
	//check for some stuff
	if (m_pszStr && iStartIndex >= 0  && iStartIndex < iStopIndex && iStopIndex < m_ilength ){
		char* pszCutString = new char[iStopIndex - iStartIndex +1]; 					//don't forget the /0
		char* pszNewString = new char[m_ilength - (iStopIndex - iStartIndex) +1]; 		
		char* pszCutBegin = pszCutString; 					//remember the beginning of the pszCutString
		char* pszNewBegin = pszNewString; 					//remember the beginning of the pszNewString
		char* pszThis = m_pszStr;							//remember the beginning of the m_pszStr
		for(int i = 0; i <= m_ilength; i++) 				//if you cut longer than the actual length of the string we would
		{													//go into the false memory locations
			if(i >= iStartIndex && i <= iStopIndex)
			{
				*pszCutString++ = *pszThis++;
			}else{
				*pszNewString++ = *pszThis++;
			}
		}
		*pszCutString = '\0';
		*pszNewString = '\0';
		delete[] m_pszStr;
		m_pszStr = pszNewBegin;
		setLength();
		*returnString = pszCutBegin;
	}
	return *returnString;		//return the actual string, not the pointer, because reference is given back
}

String&	String::PartCopy(int iStartIndex, int iStopIndex) const
{
	String* returnString = new String("NULL");
	//check for some stuff
	if (m_pszStr && iStartIndex >= 0  && iStartIndex < iStopIndex && iStopIndex < m_ilength ){
		char* pszNewString = new char[iStopIndex - iStartIndex +1]; 		
		char* pszCopyBegin = pszNewString; 					//remember the beginning of the pszCopyString
		char* pszThis = m_pszStr+iStartIndex;				//start copying at the startpoint
		for(int i = iStartIndex; i <= iStopIndex; i++) 				//if you cut longer than the actual length of the string we would
		{													//go into the false memory locations
			*pszNewString++ = *pszThis++;
		}
		*pszNewString = '\0';
		*returnString = pszCopyBegin;
	}
	return *returnString;
}


bool String::Replace(int i, char cNew)
{
	bool bReplaced = false;
	if(i <= Strlen(m_pszStr)-1 && m_pszStr && i >= 0)		// -1 bcs when we want to change the last character its at length-1 
	{									//(index starts counting at 0, length not)
		m_pszStr[i] = cNew;
		bReplaced = true;
	}
	return bReplaced;
}

String& String::operator=(const char* pszBuf)
{
	if (m_pszStr != NULL && pszBuf != NULL)
	{
		delete[] m_pszStr;
		m_pszStr = Strdup(pszBuf);
		setLength();
	}
	return *this;
}

String& String::operator=(const String& rccoObj)
{
	if (&rccoObj != this)		//wenn man string1 = string1 machen würde, würde es abstürzen weil es ja davor deletet wird und dann nochmal aufgerufen
	{
		delete[] m_pszStr;
		m_pszStr = Strdup(rccoObj.GetStr());
		setLength();
	}
	return *this;
}

bool String::operator==(const String& rccoObj)
{
	bool identical = false;
	if(Strcmp(this->m_pszStr, rccoObj.GetStr()) )	//strcmp returns 0 if they are identical
	{
		identical = false;
	}
	else{
		identical = true;
	}
	return identical;
}

bool String::operator!=(const String& rccoObj)
{
	bool different = false;
	if(Strcmp(this->m_pszStr, rccoObj.GetStr()) )	//strcmp returns 0 if they are identical
	{
		different = true;
	}
	return different;
}

bool String::operator>=(const String& rccoObj)
{
	bool bLessorequal = false;
	if(Strcmp(this->m_pszStr, rccoObj.GetStr()) >= 0 )	//strcmp returns 0 if they are identical
	{
		bLessorequal = true;
	}
	return bLessorequal;
}

bool String::operator<=(const String& rccoObj)
{
	bool bBiggerequal = false;
	if(Strcmp(this->m_pszStr, rccoObj.GetStr()) <= 0 )	//strcmp returns 0 if they are identical
	{
		bBiggerequal = true;
	}
	return bBiggerequal;
}


bool String::operator<(const String& rccoObj)
{
	bool bBigger = false;
	if(Strcmp(this->m_pszStr, rccoObj.GetStr()) < 0 )	//strcmp returns 0 if they are identical
	{
		bBigger = true;
	}
	return bBigger;
}


bool String::operator>(const String& rccoObj)
{
	bool bLess = false;
	if(Strcmp(this->m_pszStr, rccoObj.GetStr()) > 0 )	//strcmp returns 0 if they are identical
	{
		bLess = true;
	}
	return bLess;
}

char String::operator[](int i) const
{
	char cReturn = NULL;
	if(m_pszStr && i >= 0 && i <= Strlen(m_pszStr)-1 )
		cReturn = m_pszStr[i];
	return cReturn;
}


// ***************************************************************************
// C-String utility functions
// ***************************************************************************

int Strlen(const char* pcszStr)
{
	int iRet = 0;
	if (pcszStr)
	{
		while (*pcszStr++)
			++iRet;
	}
	return iRet;
}

int Strcmp(const char* pcszStr1, const char* pcszStr2)
{
	int iRet = 0;

	if (pcszStr1 && pcszStr2)
	{
		bool bEnd = false;
		while (!bEnd && iRet == 0)
		{
			iRet = *pcszStr1 - *pcszStr2;

			if (*pcszStr1 == '\0' || *pcszStr2 == '\0')
				bEnd = true;
			else
			{
				++pcszStr1;
				++pcszStr2;
			}
		}
	}
	else if (pcszStr1)
		iRet = *pcszStr1;
	else if (pcszStr2)
		iRet = 0 - *pcszStr2;

	return iRet;
}

char* Strcpy(char* pszBuf, const char* pcszSrc)
{
	char* pszRet = pszBuf;

	if (pcszSrc)
	{
		while (*pcszSrc != '\0')
			*pszBuf++ = *pcszSrc++;
	}

	*pszBuf = '\0';

	return pszRet;
}

char* Strdup(const char* pcszStr)
{
	char* pszRet = NULL;

	if (pcszStr)
		pszRet = Strcpy(new char[Strlen(pcszStr) + 1], pcszStr);	//allocate one more than length, dont forget \0

	return pszRet;
}

