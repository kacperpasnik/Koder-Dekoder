#pragma once
#include "stdafx.h"
#include "maszyna.h"
class CKoder :
	public CMaszyna
{

public:
	virtual void Crypt(string text, int dlugosc)=0;
public:
	CKoder(void);
	virtual ~CKoder(void);
};

