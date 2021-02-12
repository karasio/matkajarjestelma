#include "stdafx.h"
using namespace std;

Travelcardreader::Travelcardreader()
{
	// generoi reitille tunnus leimaajan luontihetkellä
}

bool Travelcardreader::handleTravel(shared_ptr<Travelcard> card, Traveltype type)
{
	//cout << "TravelcardReader :: 1 : card @ " << &card << "\n";
	if (card->travel(type)) {
		lastUser = card->getCardOwner();
		time_t seconds;
		time(&seconds);
		localtime_s(&lastTimestamp, &seconds);
		//cout << "TravelcardReader::handleTravel - balance = " << card.getBalance() << "\n";
		//cout << "TravelcardReader :: 2: card @ " << &card << "\n";
		return true;
	}
	//cout << "TravelcardReader :: 2: card @ " << &card << "\n";
	return false;
}

string Travelcardreader::getLastUser()
{
	return lastUser;
}

string Travelcardreader::getRoute()
{
	return route;
}

void Travelcardreader::printTime()
{
	cout << "VIIMEISIN LEIMAUS: \n";
	cout << "Viimeisin leimaaja: " << lastUser << "\n";
	cout << "Viimeisin matka: ";
	cout << lastTimestamp.tm_hour << ":" << lastTimestamp.tm_min << ":" << lastTimestamp.tm_sec;
}
