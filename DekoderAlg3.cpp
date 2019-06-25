#include "stdafx.h"
#include "DekoderAlg3.h"

void CDekoderAlg3::Decrypt(string text, int dlugosc)
{
	clock_t start, stop;
	double czas;
	start=clock();
	if(dlugosc%8!=0)
	{
	cout<<endl<<"Algorytm liczy jedynie kod 8 bitowy. Program zostanie zamkniety";
	Sleep(3000);
	exit(0);
	}
	int zastepca=dlugosc/8;
	koniec=text;
	koniec.resize(zastepca);
	int p=0; //zmienna mnozona przez potegi 
	int suma=0; // liczba w ascii ktora odpowiada danej literce
	double ii=0;
	for(int i=1;i<=dlugosc/8;i++)
	{
		suma=0;
		ii=0;
		for(int j=(i*8)-1;j>i*8-8;j--)
		{
			if(text[j]=='0')
				p=0;
			else if(text[j]=='1')
				p=1;
			suma=suma+(pow(2,ii)*p);
			ii++;
			
		}
		koniec[i-1]=suma;
	}
	stop=clock();
	czas=(double)(stop-start)/CLOCKS_PER_SEC;
	cout<<"Czas trwania algorytmu: "<<czas<<endl;
	Sleep(1000);
}

CDekoderAlg3::CDekoderAlg3()
{
	koniec="default";	
}


CDekoderAlg3::~CDekoderAlg3(void)
{
}
