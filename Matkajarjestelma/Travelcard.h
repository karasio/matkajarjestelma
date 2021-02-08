#pragma once
#include "stdafx.h"
// #define HELSINKIPRICE (float)4.0			// C-tyyli
const float HELSINKIPRICE = (float) 3.0;			// CPP-tyyli
const float SEUTUPRICE = (float) 4.20;
enum Traveltype { HELSINKI, SEUTU };			// lueteltu tietotyyppi

using namespace std;

class Travelcard
{
private:
	string *cardOwner;
	float *balance;
public:
	Travelcard();
	// teht10: kirjoita kopiointikonstruktori
	~Travelcard();
	void registerCard(string& owner);
	bool travel(Traveltype tyyppi);		// VOI TESTATA if (tyyppi == HELSINKI)
	float chargeCard(float amount);
	// void printCard();	// pulma: sovelluskerros Matkakortti tulee riippuvaiseksi UI:sta
	string& getCardOwner();
	float getBalance();
};
