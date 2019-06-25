#pragma once
#include "dekoder.h"
class CDekoderAlg2 :
	public CDekoder
{
public:
	void Decrypt(string text, int dlugosc);
	string koniec, klucz;
	
	CDekoderAlg2();
	~CDekoderAlg2(void);
};

