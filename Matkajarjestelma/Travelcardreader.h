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
	bool handleTravel(shared_ptr<Travelcard> card, Traveltype type);
	void print();
	bool operator<<(shared_ptr<Travelcard> card);
	bool operator>>(shared_ptr<Travelcard> card);
};

