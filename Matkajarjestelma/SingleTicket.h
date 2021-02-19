#pragma once
#include "stdafx.h"
class SingleTicket : public Ticket
{
public:
	SingleTicket();
	~SingleTicket();
	bool travel(Traveltype type);
	string getTicketOwner();
};

