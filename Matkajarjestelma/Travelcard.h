#pragma once
#include "stdafx.h"
// #define HELSINKIPRICE (float)4.0			// C-tyyli


using namespace std;

class Travelcard : public Ticket, public Wallet, public IdentityCard
{
private:
	//shared_ptr<string> cardOwner;		// periytyy Owner-yliluokalta Walletin ja IdentityCardin kautta
	shared_ptr<float> balance;
public:
	Travelcard();
	~Travelcard();
	void registerCard(string& owner);
	bool travel(Traveltype type);		// VOI TESTATA if (tyyppi == HELSINKI)
	float chargeCard(float amount);
	// void printCard();	// pulma: sovelluskerros Matkakortti tulee riippuvaiseksi UI:sta
	string getTicketOwner();
	float getBalance();
	friend ostream& operator<<(ostream &out, const Travelcard &card);
};
