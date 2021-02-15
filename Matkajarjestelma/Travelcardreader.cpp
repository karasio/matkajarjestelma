#include "stdafx.h"

using namespace std;

Travelcardreader::Travelcardreader()
{
	cout << "Minkä linjan matkoja leimataan?\t";
	getline(cin, routeName);
	eventAmount = 0;
	MAX = 5;
	events.resize(MAX);
	for (int i = 0; i < MAX; i++)
	{
		events[i] = NULL;
	}
	
}

Travelcardreader::~Travelcardreader()
{
	for (int i = 0; i < MAX; i++)
	{
		delete events[i];
	}
}

bool Travelcardreader::handleTravel(Travelcard& card, Traveltype type)
{
	if (card.travel(type))
	{
		TravelEvent* newEvent;
		struct tm timestamp;
		time_t seconds;
		time(&seconds);
		localtime_s(&timestamp, &seconds);
		newEvent = new TravelEvent(card.getCardOwner(), timestamp);
		delete events[eventAmount % MAX];
		events[eventAmount % MAX] = newEvent;
		eventAmount++;
		p.changeTextColorAfterTravel(true);
		return true;
	}
	p.changeTextColorAfterTravel(false);
	return false;
}

string Travelcardreader::getRouteName()
{
	return routeName;
}

bool Travelcardreader::operator<<(Travelcard& card)
{
	return handleTravel(card, HELSINKI);
}

bool Travelcardreader::operator>>(Travelcard& card)
{
	return handleTravel(card, SEUTU);
}

void Travelcardreader::setMAX(int value)
{
	MAX = value;
	events.resize(MAX);
	for (int i = 0; i < MAX; i++)
	{
		events[i] = NULL;
	}
}

ostream& operator<<(ostream& out, const Travelcardreader& reader)
{
	bool isAllNull = true;
	out << "Leimaaja operoi linjalla: " << reader.routeName  << '\n';
	string travelEventString;

	for (int i = 0; i < reader.MAX; i++)
	{
		if (reader.events[i] != NULL) {
			out << reader.events[i]->getEventString();
			isAllNull = false;
		}

		if (i == (reader.MAX - 1) && isAllNull)
		{
			out << "Ei leimaustietoja\n";
		}
	}
	return out;
}

void Travelcardreader::print()
{
	bool isAllNull = true;
	cout << "Linja " << routeName << "\n";
	for (int i = 0; i < MAX; i++)
	{
		if (events[i] != NULL)
		{
			events[i]->print(i);
			isAllNull = false;
		}
		if (i == (MAX-1) && isAllNull)
		{
			cout << "Ei leimaustietoja\n";
		}
	}
}
