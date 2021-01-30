
/* 
	http://www.cplusplus.com/articles/S3wTURfi/
	
	put these lines to stdafx.h:
	#include <string> // for IOHelper
	#include <sstream>
	#include <iostream>

	read strings like this:
	string rivi;
	getline(cin, rivi);
*/


#include "stdafx.h"

using namespace std;

// loops until user inputs integer
int getIntFromStream()
{
	string input = "";
	int value = 0;

	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> value)
			break;
		cout << "Ei numeerinen, syötä uusi." << endl;
	}
	return value;
}

// loops until user inputs float
float getFloatFromStream()
{
	string input = "";
	float value = 0;

	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> value)
			break;
		cout << "Ei liukuluku, syötä uusi." << endl;
	}
	return value;
}

