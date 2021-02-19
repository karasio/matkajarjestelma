#include "stdafx.h"
using namespace std;

TravelEvent::TravelEvent(string& name, tm& timestamp, Ticket* t)
{
    lastTimestamp = timestamp;
    lastUser = name;
    ticket = t;
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

string TravelEvent::getEventString()
{
    ostringstream oss;
    oss << setfill('0') << setw(2) << lastTimestamp.tm_hour << ":"
        << setfill('0') << setw(2) << lastTimestamp.tm_min << ":"
        << setfill('0') << setw(2) << lastTimestamp.tm_sec << "";
    //string eventString = "Kortin haltija: " + lastUser + 
    //    " -- Matkalippu ostettu: " +
    //    to_string(lastTimestamp.tm_hour) + ":" + 
    //    to_string(lastTimestamp.tm_min) + ":" + 
    //    to_string(lastTimestamp.tm_sec) + "\n";
    return "Kortin haltija: " + lastUser +" -- Matkalippu ostettu: " + oss.str() + " -- Lipputyyppi: " + ticket->ticketType + "\n";
}

