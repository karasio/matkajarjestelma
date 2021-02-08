#include "stdafx.h"
using namespace std;

Travelcardreader::Travelcardreader()
{
	// generoi reitille tunnus leimaajan luontihetkell‰
}

bool Travelcardreader::handleTravel(Travelcard& card, Traveltype type)
{
	// kutsu matkakortin travel()
	// jos saldo riitt‰‰ (card.travel() == true)
		// kopioi matkakortin omistaja leimaajalle
		// generoi aikaleima ja talleta se leimaajalle
		// palauta true
	// muuten
		// palauta false

	if (card.travel(type)) {
		lastUser = card.getCardOwner();
		time_t seconds;
		time(&seconds);
		localtime_s(&lastTimestamp, &seconds);
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
	std::cout << lastTimestamp.tm_hour << ":" << lastTimestamp.tm_min << ":" << lastTimestamp.tm_sec;
}
