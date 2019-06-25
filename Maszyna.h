#pragma once

#include "stdafx.h"

class CMaszyna
{
private:
	//void* obiekty;

	
	void Wypisz();
	string klucz, koniec;
	short losowosc, algorytm;
	bool wybor;
	
protected:

	string text;
	int dlugosc;
	void Crypt() ;
	void Decrypt();

public:

	
	void Kodowanie_dekodowanie();
	CMaszyna();
	~CMaszyna();
};

