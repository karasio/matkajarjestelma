#include "stdafx.h"
using namespace std;

TravelEvent::TravelEvent(string &name, struct tm &timestamp)
{
    lastTimestamp = timestamp;
    lastUser = name;
}

TravelEvent::~TravelEvent()
{
}

void TravelEvent::print(int row)
{
    cout << "Kortin haltija: " << lastUser << " -- Matkalippu ostettu: ";
    cout 
        << setfill('0') << setw(2) << lastTimestamp.tm_hour << ":" 
        << setfill('0') << setw(2) << lastTimestamp.tm_min << ":" 
        << setfill('0') << setw(2) << lastTimestamp.tm_sec << "\n";
}
