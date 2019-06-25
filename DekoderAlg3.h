#pragma once
#include "dekoder.h"
class CDekoderAlg3 :
	public CDekoder
{
public:
	void Decrypt(string text, int dlugosc);
	string koniec;
	
	CDekoderAlg3();
	~CDekoderAlg3(void);
};

