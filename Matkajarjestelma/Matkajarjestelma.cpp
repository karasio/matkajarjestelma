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
	shared_ptr<Travelcard> card(new Travelcard);
	Travelcardreader reader;

	do
	{
		cout <<"\n-------------------Matkakortin testausvalikko--------------------";
		cout <<"\n\n";
		cout << "\tAlusta matkakortti";
		cout << "\t\t\t\t1\n";
		cout << "\tLataa matkakortti";
		cout << "\t\t\t\t2\n";
		cout << "\tMatkusta Helsingiss‰";
		//gotoxy(indent, 4);
		cout << "\t\t\t\t3\n";
		cout << "\tMatkusta seudulla";
		//gotoxy(indent, 5);
		cout << "\t\t\t\t4\n";
		cout << "\tTulosta kortin tiedot";
		//gotoxy(indent, 6);
		cout << "\t\t\t\t5\n";
		cout << "\tTulosta leimaajan tiedot";
		//gotoxy(indent, 7);
		cout << "\t\t\t6\n";
		cout << "\tLopeta";
		//gotoxy(indent, 8);
		cout << "\t\t\t\t\t\t7\n";
		//gotoxy(8,10);
		cout << "\n\tValintasi:";
		//gotoxy(indent, 10);
		c=getIntFromStream();
		cout << "\n";
		switch (c)
		{
			case 1:
				cout << "Anna kortin omistajan nimi: ";
				getline(cin, row);
				card->registerCard(row);
				break;
			case 2:
				cout << "Anna lis‰tt‰v‰ saldo: ";
				money = getFloatFromStream();
				cout << "Kortin saldo: " << card->chargeCard(money) << "e";
				break;
			case 3:
				cout << "Matkan hinta: " << HELSINKIPRICE << "e\n";
				//cout << "Main: card @: " << &card << "\n";
				if (reader << card)
				{
					cout << "Hyv‰‰ matkaa!\n";
				}
				else
				{
					cout << "Kortilla ei ole riitt‰v‰sti saldoa.\n";
				}
				cout << "Kortin saldo: " << card->getBalance() << "\n";
				cin.get();
				break;
			case 4:
				cout << "Matkan hinta: " << SEUTUPRICE << "e\n";
				if (reader >> card)
				{
					cout << "Hyv‰‰ matkaa!\n";
				}
				else 
				{
					cout << "Kortilla ei ole riitt‰v‰sti saldoa.\n";
				}
				cout << "Kortin saldo: " << card->getBalance() << "\n";
				cin.get();
				break;
			case 5:
				cout << "KORTIN TIEDOT: \n";
				cout << "Nimi: " << card->getCardOwner() << "\n";
				cout << "Saldo: " << card->getBalance() << "e\n";
				cin.get();
				break;
			case 6:
				reader.print();
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



