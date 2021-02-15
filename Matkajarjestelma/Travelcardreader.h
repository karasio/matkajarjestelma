#pragma once
#include "stdafx.h"

using namespace std;

class Travelcard; // forward-m‰‰rittely, tarpeen jos kaksi luokkaa viittaavat toisiinsa
class TravelEvent;

class Travelcardreader
{
private:
	vector<TravelEvent *> events;
	string routeName;
	int eventAmount;
public:
	int MAX;
	Travelcardreader();
	~Travelcardreader();
	bool handleTravel(Travelcard &card, Traveltype type);
	string getRouteName();
	void print();
	bool operator<<(Travelcard& card);
	bool operator>>(Travelcard& card);
	friend ostream& operator<<(ostream& out, const Travelcardreader& reader);
	void setMAX(int value);
};

