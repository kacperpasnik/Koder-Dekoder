
#include "stdafx.h"


void CMaszyna::Kodowanie_dekodowanie()
{

	system("cls");
	short y;
	
	cout<<"Chcesz kodowac (k) czy dekodowac (d)? ";
	y=_getch();
	if(y==107)
		wybor=0;
	else if(y==100)
		wybor=1;
	else
		CMaszyna::Kodowanie_dekodowanie();
	system("cls");

		switch (wybor)
	{
			case 0:
				{
					CMaszyna::Crypt();
				}
			break;
			case 1:
				{
					CMaszyna::Decrypt();
				}
			break;
			
	}
	
}

void CMaszyna::Crypt()
{
	text.clear();
	
	cout<<"\t\t\t   -----Wpisz tekst-----"<<endl;
	getline(cin,text); 
		dlugosc= text.size();
	for(int i=0; i<dlugosc; i++)
		{
			if(text[i]==32 || text[i]==48||text[i]==49 )
				continue;

			else if(text[i]<65 || text[i]>122 || text[i]==(91,92,93,94,95,96) )
			{

			
				system("cls");
				cout<<endl<<"\t  Program pozwala uzyc jedynie znakow alfabetu lacinskiego!"<<endl;
				Sleep(3000);
				system("cls");
				CMaszyna::Crypt();
			}
		else
			continue;
		}
			
	do
		{
			cout<<endl<<"Wybierz algorytm, jakiego chcesz uzyc. 1 dla szyfru Cezara, 2 dla szyfru \nVigenere'a lub 3 dla kodowania binarnego. Wybierz 0, aby wyjsc z programu. ";
			algorytm=_getch();
			if(algorytm==49)
				{
					
					CKoderAlg1* uzyj=new CKoderAlg1;
					
					uzyj->Crypt(text, dlugosc);
					koniec=uzyj->koniec;
					losowosc=uzyj->losowosc;
					CMaszyna::Wypisz();
					delete uzyj;
				}
			else if(algorytm==50)
				{
					/*obiekty=malloc(sizeof(CKoderAlg2));
					CKoderAlg2* uzyj=new(obiekty) CKoderAlg2;
					uzyj->Crypt(text, dlugosc);
					koniec=uzyj->koniec;
					klucz=uzyj->klucz;
					uzyj->~CKoderAlg2();
					CMaszyna::Wypisz();*/

					CKoderAlg2* uzyj=new CKoderAlg2;
					
					uzyj->Crypt(text, dlugosc);
					koniec=uzyj->koniec;
					klucz=uzyj->klucz;
					CMaszyna::Wypisz();
					delete uzyj;
				}
			else if (algorytm==51)
			{
					CKoderAlg3* uzyj=new CKoderAlg3;
					
					uzyj->Crypt(text, dlugosc);
					koniec=uzyj->koniec;
					CMaszyna::Wypisz();
					delete uzyj;
			}
			else if (algorytm==48)
					exit(0);
			else
					cout<<endl<<"Blad. Jeszcze raz."<<endl;
		}while(algorytm!=49 && algorytm!=50 && algorytm!=51);

	
}
void CMaszyna::Decrypt()
{
	text.clear();
	cout<<"\t\t\t   -----Wpisz tekst-----"<<endl;
	getline(cin,text);
		dlugosc= text.size();
	for(int i=0; i<dlugosc; i++)
		{
			if(text[i]==32 || text[i]==48||text[i]==49 )
					continue;

			else if(text[i]<65 || text[i]>122 || text[i]==(91,92,93,94,95,96) )
				{

			
					system("cls");
					cout<<endl<<"\t  Program pozwala uzyc jedynie znakow alfabetu lacinskiego!"<<endl;
					Sleep(3000);
					system("cls");
					CMaszyna::Decrypt();
				}
			else
					continue;

		}		
	do
		{
			cout<<endl<<"Wybierz algorytm, jakiego chcesz uzyc. 1 dla szyfru Cezara, 2 dla szyfru \nVigenere'a lub 3 dla kodowania binarnego. Wybierz 0, aby wyjsc z programu. ";
			algorytm=_getch();
			if(algorytm==49)
				{
					CDekoderAlg1* uzyj=new CDekoderAlg1;
					uzyj->Decrypt(text, dlugosc);
					koniec=uzyj->koniec;
					losowosc=uzyj->losowosc;
					CMaszyna::Wypisz();
					delete uzyj;
				}
			else if(algorytm==50)
				{
					CDekoderAlg2* uzyj=new CDekoderAlg2;
					uzyj->Decrypt(text,dlugosc);
					koniec=uzyj->koniec;
					klucz=uzyj->klucz;
					CMaszyna::Wypisz();
					delete uzyj;
				}
			else if (algorytm==51)
				{
					CDekoderAlg3* uzyj=new CDekoderAlg3;
					uzyj->Decrypt(text,dlugosc);
					koniec=uzyj->koniec;
					CMaszyna::Wypisz();
					delete uzyj;
				}
			else if (algorytm==48)
					exit(0);
			else
					cout<<endl<<"Blad. Jeszcze raz."<<endl;
		}while(algorytm!=49 && algorytm!=50 && algorytm!=51);

	
}

void CMaszyna::Wypisz()
{

		fstream plik;
		time_t now= time(0);
		string dt= ctime(&now);
		plik.open("szyfr.txt",  ios::out|ios::app);
		if (plik.good() == true)
		{
			if(wybor==0)
			{
			plik << "--------------------------------------------------------------"<<endl;
			plik << "Tekst jawny: " << text << endl;
			plik<<endl<< "Tekst zaszyfrowany to: " << koniec << endl << endl;
			}
			else if (wybor==1)
			{
			plik << "--------------------------------------------------------------" << endl;
			plik << "Tekst zakodowany: " << text << endl;
			plik << endl << "Tekst odkodowany to: " << koniec << endl << endl;
			}
			if (algorytm == 49)
				plik << "Liczba do odkodowania: " << losowosc << endl;
			else if (algorytm == 50)
				plik << "Slowo klucz:" << klucz << endl;
			else if (algorytm==51)
				plik<<"(jedna litera= 8 bitow tj. 8 cyfr kodu)"<<endl;
			plik<<endl<< dt<<endl;
			plik << endl << "-------------------------------------------------------------------" << endl;
			plik.close();
			system("call szyfr.txt");
		}
		
}

CMaszyna::CMaszyna()
{
	text="default";
	klucz="default";
	koniec="default";
	wybor=0;
	losowosc=0;
	dlugosc=7;
	algorytm=49;
}


CMaszyna::~CMaszyna()
{
	
}
