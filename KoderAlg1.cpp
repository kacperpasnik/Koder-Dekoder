#include "stdafx.h"
#include "KoderAlg1.h"

void CKoderAlg1::Crypt(string text, int dlugosc)

{
		int p=0;				//wyjscie poza granice w ascii
		//text=*text2;
	system("cls");
	koniec=text;
	srand (time(NULL));
	losowosc= rand() % 25 + 1;
	cout<<endl<<losowosc<<" <-- zapamietaj te liczbe, aby odkodowac tym algorytmem!"<<endl;
	for(int i=0;i<=dlugosc;i++)
	{
		if(text[i]==32)
			continue;
		p=text[i]+losowosc;

		if(text[i]>96 && text[i]<123 && p>122)		//jesli nie miesci sie w malych literach
			{
				text[i]=text[i]-26;
			}

		else if(text[i]>64 && text[i]<91 && p>90)		//jesli nie miesci sie w duzych literach
			{
				text[i]=text[i]-26;
			}
		koniec[i]=text[i]+losowosc;
		
	}

	
}

CKoderAlg1::CKoderAlg1()
{
	losowosc=0;
	koniec="default";
}


CKoderAlg1::~CKoderAlg1(void)
{
}
