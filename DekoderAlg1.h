#pragma once
#include "dekoder.h"
#include "stdafx.h"
class CDekoderAlg1 :
	public CDekoder
{
	public:
	void Decrypt(string text, int dlugosc);

	short losowosc;
	string koniec;

	
	CDekoderAlg1();
	~CDekoderAlg1(void);
};

