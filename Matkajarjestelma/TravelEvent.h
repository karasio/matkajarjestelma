#pragma once
#include "stdafx.h"

using namespace std;

class TravelEvent
{
private:
	string lastUser;
	struct tm lastTimestamp;
public:
	TravelEvent(string &name, struct tm &timestamp);
	~TravelEvent();
	void print(int row);
	string getEventString();
};

