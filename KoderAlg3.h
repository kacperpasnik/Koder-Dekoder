#pragma once
#include "koder.h"
#include "stdafx.h"
class CKoderAlg3 :
	public CKoder
{
public:
	string koniec;
	void Crypt(string text, int dlugosc);

	
	CKoderAlg3();
	~CKoderAlg3(void);
};

