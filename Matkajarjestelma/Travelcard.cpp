#include "stdafx.h"

using namespace std;

Travelcard::Travelcard()
{
	//std::cout << "NORMAL CONSTUCTOR\n";
	cardOwner.reset(new string("Haltijakohtainen kortti"));
	balance.reset(new float(0.0));
}


Travelcard::~Travelcard()
{
	cout << "Travelcard - Destructor";
	//delete cardOwner;
	//delete balance;
}

void Travelcard::registerCard(string &owner)
{
	cardOwner.reset(new string(owner));
	balance.reset(new float(0.0));
	//*cardOwner = owner;
	//*balance = 0;
}

bool Travelcard::travel(Traveltype type)
{
	bool success = false;
	float price = HELSINKIPRICE;
	if (type) {
		price = SEUTUPRICE;
	}

	if (*balance >= price) {
		*balance -= price;
		success = true;
	}
	return success;
}

float Travelcard::chargeCard(float amount)
{
	*balance += amount;
	return *balance;
}

string& Travelcard::getCardOwner()
{
	return *cardOwner;
}

float Travelcard::getBalance()
{
	return *balance;
}

ostream& operator<<(ostream &out, const Travelcard &card)
{
	out << "Kortin tiedot: \nNimi: " << *card.cardOwner
		<< "\nSaldo: " << *card.balance << "e\n";
	return out;
}
