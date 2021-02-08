#include "stdafx.h"

using namespace std;

Travelcard::Travelcard()
{
	std::cout << "NORMAL CONSTUCTOR\n";
	cardOwner = new string("Haltijakohtainen kortti");
	balance = new float(0.0);
}

// t�m� edelleen p�in helvetti�, koska arvot mit� cardOwner & balancesta
// kopioidaan on viitteit�, jotka tuhoutuu sen j�lkeen kun tullaan handleTravelista
// ulos
Travelcard::Travelcard(const Travelcard& toBeCopied)
{
	std::cout << "COPY CONSTUCTOR\n";
	cardOwner = new string(*(toBeCopied.cardOwner));
	balance = new float(*(toBeCopied.balance));
}

Travelcard::~Travelcard()
{
	delete cardOwner;
	delete balance;
}

void Travelcard::registerCard(string &owner)
{
	*cardOwner = owner;
	*balance = 0;
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
		std::cout << "Travelcard::travel - balance = " << *balance << "\n";
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
