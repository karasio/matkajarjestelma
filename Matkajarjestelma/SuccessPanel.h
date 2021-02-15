#pragma once
#include "stdafx.h"
class SuccessPanel
{
private:
	int *GREEN;
	int *RED;
	int* WHITE;
public:
	SuccessPanel();
	~SuccessPanel();
	void changeTextColorAfterTravel(bool success);
	void changeToDefaultColor();
};

