#include "stdafx.h"
#include "Console.h"



void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Flashing(string s)
{
	while (1) {
		system("cls");
		gotoXY(1, 0);
		TextColor(rand() % 15 + 1);
		cout << s.c_str();
		if (_kbhit())
			break;
		Sleep(500);
	}
	TextColor(15);
}

void Run(string s)
{
	Word a;
	a.x = 1;
	a.y = 1;
	a.t = RIGHT;
	while (1) {
		system("cls");
		gotoXY(a.x, a.y);
		TextColor(rand() % 15 + 1);
		cout << s.c_str();

		if (_kbhit())
			break;

		if (a.x >= 30)
			a.t = LEFT;
		else if (a.x <= 0)
			a.t = RIGHT;

		if (a.t == LEFT)
			a.x--;
		else if (a.t == RIGHT)
			a.x++;
		Sleep(30);
	}
}
