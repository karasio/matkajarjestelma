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
	int value;
	//shared_ptr<Travelcard> card(new Travelcard);
	Travelcard card;
	Travelcardreader reader;
	SuccessPanel panel;
	do
	{
		cout <<"\n-------------------Matkakortin testausvalikko--------------------";
		cout <<"\n\n";
		cout << "\tAlusta matkakortti\t\t\t\t1\n";
		cout << "\tLataa matkakortti\t\t\t\t2\n";
		cout << "\tMatkusta Helsingiss‰\t\t\t\t3\n";
		cout << "\tMatkusta seudulla\t\t\t\t4\n";
		cout << "\tTulosta kortin tiedot\t\t\t\t5\n";
		cout << "\tTulosta leimaajan tiedot\t\t\t6\n";
		cout << "\tMuuta tallennettavien matkojen m‰‰r‰‰\t\t7\n";
		cout << "\tLopeta\t\t\t\t\t\t8\n";
		cout << "\n\tValintasi:";

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
				//cout << "Main: card @: " << &card << "\n";
				if (reader << card)
				{
					cout << "Hyv‰‰ matkaa!\n";
				}
				else
				{
					cout << "Kortilla ei ole riitt‰v‰sti saldoa.\n";
				}
				panel.changeToDefaultColor();
				cout << "Kortin saldo: " << card.getBalance() << "\n";
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
				panel.changeToDefaultColor();
				cout << "Kortin saldo: " << card.getBalance() << "\n";
				cin.get();
				break;
			case 5:
				cout << card;
				cin.get();
				break;
			case 6:
				//reader.print();
				cout << reader;
				cin.get();
				break;
			case 7:
				cout << "Kuinka monta matkaa tallennetaan lukijalle?\t";
				value = getIntFromStream();
				while (value < 0)
				{
					cout << "Anna positiivinen kokonaisluku.\n";
					cout << "Kuinka monta matkaa tallennetaan lukijalle?\t";
					value = getIntFromStream();
				}
				reader.setMAX(value);
				cin.get();
				break;
			case 8:
				cout << "Kiitos n‰kemiin!";
				break;
		}
	}
	while (c!=8);
	return 0;
}



