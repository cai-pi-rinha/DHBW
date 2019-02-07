#ifndef STRING_HPP
#define STRING_HPP


#include <stdlib.h> //damit NULL erkannt wird

class String		//es muss speicher auf dem heap allokiert werden weil man l�nge nicht kennt
{
	private:
		char* 			m_pszStr;
		mutable int		m_iLen;			//mutable kann man auch in const funktionen �ndern
										//L�nge wird nur einmal berechnet sodass man das nicht mehrmals machen muss			
										//sobald �nderung an string stattfindet muss diese neu berechnet werden
	public:
	
	String();
	String(const char* pcszStr);
	String(const String& rccoObj);
	
	~String();
	String&		operator=(const String& rccoObj);
	
	/*
	files von onedrive holen
	*/
	
	
		
	//liefert die Laenge der uebergegebenen Strings (Ohne abschlie�ende '\0')
	extern int Strlen(const char* pcszStr);		//extern hei�t nur dass irgendwo diese Fkt liegt -> nur deklaration

	//Vergleicht die beiden uebergegebenen Strings zeichenweise und liefert den ASCII-Unterschied des ersten nicht uebereinstimmenden
	//Zeichens zurueck. Sind beide Strings gleich, wird 0 zurueck geliefert.
	//Ist der erste String "alphabetisch groesser" als der zweite, dann ist der Rueckgabewert positiv, ansonsten wenn kleiner negativ.
	extern int Strcmp(const char* pcsz1, const char* pcsz2);

	//kopiert den Inhalt von pcszStr in den uergebenen Puffer pszBuf
	extern char* Strcpy(char* pcszBuf, const char* pcszStr); //variablen benennung nach ungarischer notation

	//Dupliziert pcszSrc auf dem Heap
	extern char* Strdup(const char* pcszSrc);  	//pcsz= pointer const to string zero terminated

	int	Length() const; 		//const funktion kann nichts an werten des strings �ndern
}

#endif //STRING_HPP