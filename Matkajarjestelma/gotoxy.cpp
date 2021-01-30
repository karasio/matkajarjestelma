#include "stdafx.h"

// tämä löytyi Borlandin ympäristöstä conio.h-tiedostosta...
void gotoxy(int x,int y)
{ 
  HANDLE hConsole;
  COORD cursorLoc;
  std::cout.flush();
  cursorLoc.X = x;
  cursorLoc.Y = y;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsole, cursorLoc);
}

