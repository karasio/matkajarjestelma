// Matkajarjestelma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matkajarjestelma.h"

class Travelcard;			// forward-m‰‰rittely
using namespace std;

int main(int argc, char* argv[])
{
	int c;
	string row;
	float money;
	Travelcard card;

	do
	{
		system("cls");
		cout <<"-------------------Matkakortin testausvalikko--------------------";
		cout <<"\n\n";
		cout << "\tAlusta matkakortti";
		gotoxy(32,2);
		cout << "1\n";
		cout << "\tLataa matkakortti";
		gotoxy(32, 3);
		cout << "2\n";
		cout << "\tMatkusta Helsingiss‰";
		gotoxy(32, 4);
		cout << "3\n";
		cout << "\tMatkusta seudulla";
		gotoxy(32, 5);
		cout << "4\n";
		cout << "\tTulosta kortin tiedot";
		gotoxy(32, 6);
		cout << "5\n";
		cout << "\tLopeta";
		gotoxy(32, 7);
		cout << "6\n";
		gotoxy(8,9);
		cout << "Valintasi:";
		gotoxy(32, 9);
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
				card.chargeCard(money);
				break;
			case 3:
				cout << "Matkan hinta: " << HELSINKIPRICE << "e\n";
				if (card.travel(HELSINKI))
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
				if (card.travel(SEUTU))
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
				cout << "Kortin tiedot: \n";
				cout << "Nimi: " << card.getCardOwner() << "\n";
				cout << "Saldo: " << card.getBalance() << "e\n";

				cin.get();
				break;
			case 6:
				cout << "Kiitos n‰kemiin!";
				break;
		}
	}
	while (c!=6);
	return 0;
}



