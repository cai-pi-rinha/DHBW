// Headerfile "string.hpp"

#ifndef STRING_HPP
#define STRING_HPP
#include <stdarg.h> 
#include <stdlib.h>
#include <stdio.h>


class String
{
private:

	char*			m_pszStr;
	int 			m_ilength;
	void		   	setLength();

public:

	String();
	String(char* pcszStr);
	String(const char* pcszStr);

	String(const String& rccoObj);

	~String();


	int       	   Length() const;		
		/*
		gibt länge des strings zurück
		*/
	int            FindChar(char cSearch, int iStartIndex=0) const;		
		/*
		sucht nach char, gibt index zurück, an dem char ist. wenn nicht gefunden rückgabe -1
		*/
	int            FindString(const char* pszSearchString, int iStartIndex=0) const;
		/*
		sucht nach string, gibt index zurück, an dem string startet. wenn nicht gefunden rückgabe -1
		*/
	const char*    GetStr() const;						//gibt string aus
		/*
		Ausgabe des Strings
		*/
	operator const char*() const;			
	operator char*();
	operator int() const;								//wandelt string in zahl um 
		/*
		wandelt String in Zahl um. BSP: "1234" wird zu Zahl 1234
		*/
	String& 	   Normalise(const char* pszParameters);
		/*
		String von kriterien die nicht am anfang oder ende stehen sollen wird eingegeben -> zeichen am ende und anfang werden gelöscht
		*/
	String&		   Cut(int iStartIndex, int iStopIndex);
		/*
		legt dynamisch string an und liefert ausgeschnittenen teil zurück, übriggebliebener teil wird in ursprungsstring gespeichert
		bei nichteinhaltung der grenzen wird string mit "NULL" zurückgeliefert
		*/
	String&		   PartCopy(int iStartIndex, int iStopIndex) const;
		/*
		partialcopy, kopiert von start bis stop den string und gibt string obj zurück
		*/
	char           operator[](int i) const;
		/*
		Zugriffsoperator, liefert Zeichen an angegebenem Index zurück
		*/
	bool           Replace(int i, char cNew);
		/*
		ersetzt den char an stelle i durch cNew, wenn es geklappt hat wird true zurückgegeben, sonst false
		*/

	String& 	   operator=(const char* pszBuf);
	String&        operator=(const String& rccoObj);
	/*
	Zuweisung
	*/
	bool           operator==(const String& rccoObj); 
	/*
	Vergleichsoperatoren, selbsterklärend...
	*/
	bool           operator!=(const String& rccoObj);
		/*ungleich -> true*/
	bool           operator>=(const String& rccoObj);
		/*true wenn größergleich*/
	bool           operator<=(const String& rccoObj);
	bool           operator>(const String& rccoObj);
	bool           operator<(const String& rccoObj);
	String& 	   operator+=(const String& rccoObj);
	String& 	   operator+=(char* rccoObj);
	
		/*
		String an jetzigen String anhängen. Bsp: Gustav += Gans --> GustavGans
		*/
	};

// Berechnet die Laenge des uebergebenen Strings in Zeichen
// (ohne das abschliessende 0-Byte)
extern int Strlen(const char* pcszStr);

// Vergleicht die beiden uebergebenen Strings zeichenweise miteinander
// und liefert den ASCII-Unterschied des ersten nicht mehr uebereinstimmenden
// Zeichens zurueck.
// Sind beide Strings identisch, dann liefert die Funktion den Wert 0.
//
// "Hans", "Heiner" => Differenz: 'a' - 'e'
// "Hein", "Heiner" => Differenz: '\0' - 'e'
// "", "Hans"		=> Differenz: '\0' - 'H'
// NULL, "Hans"		=> Differenz: '\0' - 'H'
extern int Strcmp(const char* pcszStr1, const char* pcszStr2);

// Kopiert den String aus pcszSrc zeichenweise in den bereitgestellten
// Puffer, der ueber pszBuf addressiert wird.
extern char* Strcpy(char* pszBuf, const char* pcszSrc);

// Erzeugt eine Kopie des uebergebenen Strings auf dem dynamischen Heap.
//
// Zu beachten:
// 	Allokiert wird mit array-new:			char* psz = new char[count];
//  Die Freigabe erfolgt mit array-delete:	delete[] psz;
//
extern char* Strdup(const char* pcszStr);

#endif	// STRING_HPP

