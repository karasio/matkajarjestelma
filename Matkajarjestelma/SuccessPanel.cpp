#include "stdafx.h"

SuccessPanel::SuccessPanel()
{
	GREEN = new int(10);
	RED = new int(12);
	WHITE = new int(7);
}

SuccessPanel::~SuccessPanel()
{
	delete GREEN;
	delete RED;
	delete WHITE;
}

void SuccessPanel::changeTextColorAfterTravel(bool success)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	if (success)
	{
		SetConsoleTextAttribute(hConsole, *GREEN);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, *RED);
	}
}

void SuccessPanel::changeToDefaultColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, *WHITE);
}
