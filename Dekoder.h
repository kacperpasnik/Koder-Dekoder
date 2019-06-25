#pragma once
#include "stdafx.h"
#include "maszyna.h"
class CDekoder :
	public CMaszyna
{

private:
	virtual void Decrypt(string text, int dlugosc)=0;
public:
	CDekoder(void);
	 virtual ~CDekoder(void);
};

