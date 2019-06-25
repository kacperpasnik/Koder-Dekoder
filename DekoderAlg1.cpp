#include "stdafx.h"
#include "DekoderAlg1.h"

void CDekoderAlg1::Decrypt(string text, int dlugosc)
{
		int p=0;					//wyjscie poza granice w ascii
	system("cls");
	koniec=text;
	cout<<endl<<"Podaj liczbe przesuniecia liter (byla losowana podczas kodowania): ";
	cin>>losowosc;
	for(int i=0;i<=dlugosc;i++)
	{

		if(text[i]==32)
			continue;
		p=text[i]-losowosc;

		if(text[i]>96 && text[i]<123 && p<97)			//jesli nie miesci sie w malych literach
			{
				text[i]=text[i]+26;
			}

		else if(text[i]>64 && text[i]<91 && p<65)		//jesli nie miesci sie w duzych literach
			{
				text[i]=text[i]+26;
			}
		koniec[i]=text[i]-losowosc;
	}
}

CDekoderAlg1::CDekoderAlg1()
{
	koniec="default";
	losowosc=7;
}


CDekoderAlg1::~CDekoderAlg1(void)
{
}
