#include "stdafx.h"
#include "KoderAlg3.h"

void CKoderAlg3::Crypt(string text, int dlugosc)
{
	clock_t start, stop;
	double czas;
	start=clock();
	koniec.clear();
	int p=0; // text na int
	string p2="00000000",p3="0";  //tymczasowy string z kodem
	
	
	for(int i=0;i<dlugosc;i++)
	{
		p=text[i];
		for(int j=0;j<7;j++)
		{
			if(p%2==0)
			p2[j]='0';
			else if(p%2==1)
			p2[j]='1';
			p=p/2;
		}
		for(int j=7;j>=0;j--)
		{
			p3=p2[j];
			koniec.append(p3);
		}
	}
	stop=clock();
	czas=(double)(stop-start)/CLOCKS_PER_SEC;
	cout<<"Czas trwania algorytmu: "<<czas<<endl;
	Sleep(1000);
}

CKoderAlg3::CKoderAlg3()
{
	koniec="default";
}


CKoderAlg3::~CKoderAlg3(void)
{
}
