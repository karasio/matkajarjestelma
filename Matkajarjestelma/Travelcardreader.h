#pragma once
#include "stdafx.h"

using namespace std;

class Travelcard; // forward-m‰‰rittely, tarpeen jos kaksi luokkaa viittaavat toisiinsa
class TravelEvent;
class SuccessPanel;

class Travelcardreader
{
private:
	vector<TravelEvent *> events;
	string routeName;
	int eventAmount;
	SuccessPanel panel;
public:
	int MAX;
	Travelcardreader();
	~Travelcardreader();
	bool handleTravel(Ticket &card, Traveltype type);
	string getRouteName();
	void print();
	bool operator<<(Travelcard& card);
	bool operator>>(Travelcard& card);
	friend ostream& operator<<(ostream& out, const Travelcardreader& reader);
	void setMAX(int value);
	void addEvent(Ticket& ticket);
};

