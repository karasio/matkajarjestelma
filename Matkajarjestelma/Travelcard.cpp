#include "stdafx.h"

using namespace std;

Travelcard::Travelcard()
{
	cardOwner = "Haltijakohtainen kortti";
	balance = 0;
}

void Travelcard::registerCard(string& owner)
{
	cardOwner = owner;
	balance = 0;
}

bool Travelcard::travel(Matkatyyppi type)
{
	bool success = false;
	float price = HELSINKIPRICE;
	if (type) {
		price = SEUTUPRICE;
	}

	if (balance >= price) {
		balance -= price;
		success = true;
	}
	return success;
}

float Travelcard::chargeCard(float amount)
{
	balance += amount;
	return amount;
}

string& Travelcard::getCardOwner()
{
	return cardOwner;
}

float Travelcard::getBalance()
{
	return balance;
}
