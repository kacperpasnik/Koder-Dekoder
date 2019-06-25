#include "stdafx.h"
#include "DekoderAlg2.h"

void CDekoderAlg2::Decrypt(string text, int dlugosc)
{
	clock_t start,start2,stop2, stop;
	double czas,czas2;
		start=clock();
			string litery[123][123];
	int alfabet=67,alfabet2=99,podalfabet=0;
	for(int i=0;i<123;i++)
	{
		for(int j=0;j<123;j++)
		{
			litery[i][j]='*';
		}
	}
		for(int i=65;i<91;i++)
	{
		
		
		

		if(alfabet==91)
			alfabet=65;

		for(int j=67;j!=66;j++)
		{
			
			if(alfabet==91)
			{
				alfabet=65;
			}

			litery[i][j]=alfabet;
			
			if(j==65)
			{
				podalfabet=alfabet+1;
					if(podalfabet==91)
						podalfabet=65;
				litery[i][j+1]=podalfabet;
			}
			if(j==90)
				j=64;
			alfabet ++;
			
			
			
		}

	}

		

		for(int i=97;i<123;i++)
	{
		
		
		

		if(alfabet2==91)
			alfabet2=65;

		for(int j=99;j!=98;j++)
		{
			
			if(alfabet2==123)
			{
				alfabet2=97;
			}

			litery[i][j]=alfabet2;
			
			if(j==97)
			{
				podalfabet=alfabet2+1;
					if(podalfabet==123)
						podalfabet=97;
				litery[i][j+1]=podalfabet;
			}
			if(j==122)
				j=96;
			alfabet2 ++;
			
			
			
		}

	}
	
	
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
	int literka1, literka2, zerowanie=0;
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


		literka1=klucz[zerowanie];
		literka2=text[i];
		koniec.append(litery[literka1][literka2]);
		zerowanie++;
		if(zerowanie==klucz.size() )
			zerowanie=0;
		
	}
	stop2=clock();
	czas=(double)(stop-start)/CLOCKS_PER_SEC;
	czas2=(double)(stop2-start2)/CLOCKS_PER_SEC;
	cout<<"Czas trwania algorytmu: "<<czas<<" i "<<czas2<<endl;
}

CDekoderAlg2::CDekoderAlg2()
{
	koniec="default";
	klucz="default";
}


CDekoderAlg2::~CDekoderAlg2(void)
{
}
