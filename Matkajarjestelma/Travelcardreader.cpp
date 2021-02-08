#include "stdafx.h"
using namespace std;

Travelcardreader::Travelcardreader()
{
	// generoi reitille tunnus leimaajan luontihetkellä
}

bool Travelcardreader::handleTravel(Travelcard card, Traveltype type)
{
	cout << "TravelcardReader: card @: " << &card << "\n";
	if (card.travel(type)) {
		lastUser = card.getCardOwner();
		time_t seconds;
		time(&seconds);
		localtime_s(&lastTimestamp, &seconds);
		cout << "TravelcardReader::handleTravel - balance = " << card.getBalance() << "\n";
		return true;
	} 
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
