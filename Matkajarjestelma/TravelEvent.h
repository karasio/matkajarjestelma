#pragma once
#include "stdafx.h"

using namespace std;

class TravelEvent
{
private:
	string lastUser;
	struct tm lastTimestamp;
	Ticket *ticket;
public:
	TravelEvent();
	TravelEvent(string &name, struct tm &timestamp, Ticket *t);
	~TravelEvent();
	void print();
	string getEventString();
};

