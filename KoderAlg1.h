#pragma once
#include "koder.h"
#include "stdafx.h"
class CKoderAlg1 :
	public CKoder
{
public:
	short losowosc;
	string koniec;
	 void Crypt(string text, int dlugosc);
	
	CKoderAlg1();
	~CKoderAlg1(void);
};

