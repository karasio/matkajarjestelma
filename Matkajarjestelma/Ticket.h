#pragma once
#include "stdafx.h"
using namespace std;

const float HELSINKIPRICE = (float)3.0;			// CPP-tyyli
const float SEUTUPRICE = (float)4.20;
enum Traveltype { HELSINKI, SEUTU };			// lueteltu tietotyyppi

class Ticket
{
private:
	
public:
	bool travelOk;
	string ticketType;
	virtual bool travel(Traveltype type) = 0;
	virtual string getTicketOwner() = 0;
};

