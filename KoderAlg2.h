#pragma once
#include "koder.h"
#include "stdafx.h"
class CKoderAlg2 :
	public CKoder
{

	
public:
	 void Crypt(string text, int dlugosc);
	 string klucz, koniec;

	
	CKoderAlg2();
	~CKoderAlg2(void);
};

