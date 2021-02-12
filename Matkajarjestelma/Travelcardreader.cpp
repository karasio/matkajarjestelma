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

bool Travelcardreader::handleTravel(shared_ptr<Travelcard> card, Traveltype type)
{
	if (card->travel(type))
	{
		TravelEvent* newEvent;
		struct tm timestamp;
		time_t seconds;
		time(&seconds);
		localtime_s(&timestamp, &seconds);
		newEvent = new TravelEvent(card->getCardOwner(), timestamp);
		delete events[eventAmount % MAX];
		events[eventAmount % MAX] = newEvent;
		eventAmount++;
		return true;
	}
	return false;
}

bool Travelcardreader::operator<<(shared_ptr<Travelcard> card)
{
	return handleTravel(card, HELSINKI);
}

bool Travelcardreader::operator>>(shared_ptr<Travelcard> card)
{
	return handleTravel(card, SEUTU);
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
