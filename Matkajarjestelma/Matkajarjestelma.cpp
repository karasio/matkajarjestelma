// Matkajarjestelma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matkajarjestelma.h"

class Travelcard;			// forward-m‰‰rittely
using namespace std;

int main(int argc, char* argv[])
{
	int indent = 36;
	int c;
	string row;
	float money;
	Travelcard card;
	Travelcardreader reader;

	do
	{
		system("cls");
		cout <<"-------------------Matkakortin testausvalikko--------------------";
		cout <<"\n\n";
		cout << "\tAlusta matkakortti";
		gotoxy(indent,2);
		cout << "1\n";
		cout << "\tLataa matkakortti";
		gotoxy(indent, 3);
		cout << "2\n";
		cout << "\tMatkusta Helsingiss‰";
		gotoxy(indent, 4);
		cout << "3\n";
		cout << "\tMatkusta seudulla";
		gotoxy(indent, 5);
		cout << "4\n";
		cout << "\tTulosta kortin tiedot";
		gotoxy(indent, 6);
		cout << "5\n";
		cout << "\tTulosta leimaajan tiedot";
		gotoxy(indent, 7);
		cout << "6\n";
		cout << "\tLopeta";
		gotoxy(indent, 8);
		cout << "7\n";
		gotoxy(8,10);
		cout << "Valintasi:";
		gotoxy(indent, 10);
		c=getIntFromStream();
		cout << "\n";
		switch (c)
		{
			case 1:
				cout << "Anna kortin omistajan nimi: ";
				getline(cin, row);
				card.registerCard(row);
				break;
			case 2:
				cout << "Anna lis‰tt‰v‰ saldo: ";
				money = getFloatFromStream();
				cout << "Kortin saldo: " << card.chargeCard(money) << "e";
				break;
			case 3:
				cout << "Matkan hinta: " << HELSINKIPRICE << "e\n";
				if (reader.handleTravel(card, HELSINKI))
				{
					cout << "Hyv‰‰ matkaa!\n";
					cout << "Kortin saldo: " << card.getBalance() << "e\n";
				}
				else {
					cout << "Kortilla ei ole riitt‰v‰sti saldoa.\n";
					cout << "Kortin saldo: " << card.getBalance() << "e\n";
				}
				cin.get();
				break;
			case 4:
				cout << "Matkan hinta: " << SEUTUPRICE << "e\n";
				if (reader.handleTravel(card, SEUTU))
				{
					cout << "Hyv‰‰ matkaa!\n";
					cout << "Kortin saldo: " << card.getBalance() << "e\n";
				}
				else {
					cout << "Kortilla ei ole riitt‰v‰sti saldoa.\n";
					cout << "Kortin saldo: " << card.getBalance() << "e\n";
				}
				cin.get();
				break;
			case 5:
				cout << "KORTIN TIEDOT: \n";
				cout << "Nimi: " << card.getCardOwner() << "\n";
				cout << "Saldo: " << card.getBalance() << "e\n";
				cin.get();
				break;
			case 6:
				reader.printTime();
				cin.get();
				break;
			case 7:
				cout << "Kiitos n‰kemiin!";
				break;
		}
	}
	while (c!=7);
	return 0;
}



