#include "stdafx.h"

using namespace std;

Travelcard::Travelcard()
{
	cardOwner = new string("Haltijakohtainen kortti");
	balance = new float(0.0);
}

Travelcard::Travelcard(const Travelcard& toBeCopied)
{
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
