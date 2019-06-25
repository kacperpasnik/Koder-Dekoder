#include "stdafx.h"
#include "KoderAlg2.h"

void CKoderAlg2::Crypt(string text, int dlugosc)
{
	clock_t start,start2,stop2, stop;
	double czas,czas2;
		start=clock();
		string litery[123][123];
		
	int alfabet=0,pp=0;
	for(int i=0;i<123;i++)
	{
		for(int j=0;j<123;j++)
		{
			litery[i][j]='*';
		}
	}
		for(int i=65;i<91;i++)
	{
		
		alfabet=64;
		pp=i-alfabet;
		alfabet+=pp;
		if(alfabet==91)
			alfabet=65;

		for(int j=65;j<91;j++)
		{
			if(alfabet==91)
				alfabet=65;
			litery[i][j]=alfabet;
			alfabet ++;
			
		}

	}
	for(int i=97;i<123;i++)
	{
		
		alfabet=96;
		pp=i-alfabet;
		alfabet+=pp;
		if(alfabet==123)
			alfabet=97;

		for(int j=97;j<123;j++)
		{
			if(alfabet==123)
				alfabet=97;
			litery[i][j]=alfabet;
			alfabet ++;
			
		}

	}
	
	klucz.clear();
	koniec.clear();
	stop=clock();
	do
	{
		
		cout<<endl<<"Podaj slowo klucz"<<endl;
		cin>>klucz;
		if(klucz.size()==dlugosc+1)
			cout<<"Za dlugie slowo klucz!"<<endl;
	}while(klucz.size()==dlugosc+1);
	start2=clock();
	
	int literka1=0, literka2=0, zerowanie=0;  //tu mieszalem
	for(int i=0;i<dlugosc;i++)
	{
		if (text[i]==32)
		{
			koniec.append(" ");
			continue;
		}

		if(text[i]>96 && klucz[zerowanie]<96)
			klucz[zerowanie]+=32;
		else if(text[i]<91 && klucz[zerowanie]>91)
			klucz[zerowanie]-=32;


		literka1=text[i];
		literka2=klucz[zerowanie];
		koniec.append(litery[literka1][literka2]);
		zerowanie++;
		if(zerowanie==klucz.size() )
			zerowanie=0;
		
	}
	stop2=clock();
	czas=(double)(stop-start)/CLOCKS_PER_SEC;
	czas2=(double)(stop2-start2)/CLOCKS_PER_SEC;
	cout<<"Czas trwania algorytmu: "<<czas<<" i "<<czas2<<endl; 
	
	Sleep(1000);

}

CKoderAlg2::CKoderAlg2()
{
	klucz="default";
	koniec="default";
}


CKoderAlg2::~CKoderAlg2(void)
{
}
