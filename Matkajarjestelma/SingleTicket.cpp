#include "SingleTicket.h"

SingleTicket::SingleTicket()
{
	ticketType = "Kertalippu";
	travelOk = false;
}

SingleTicket::~SingleTicket()
{
}

bool SingleTicket::travel(Traveltype type)
{
	if (travelOk)
	{
		travelOk = false;
		return true;
	}
	return false;
}

string SingleTicket::getTicketOwner()
{
	return "-";
}
