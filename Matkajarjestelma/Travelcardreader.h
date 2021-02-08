#pragma once
#include "stdafx.h"
using namespace std;
class Travelcard; // forward-määrittely, tarpeen jos kaksi luokkaa viittaavat toisiinsa

class Travelcardreader
{
private:
	string lastUser;
	struct tm lastTimestamp;
	string route;
public:
	Travelcardreader();
	bool handleTravel(Travelcard& card, Traveltype type);
	string getLastUser();
	string getRoute();
	void printTime();
};

