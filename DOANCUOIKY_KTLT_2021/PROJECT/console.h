
#include <iostream>
#include <conio.h>
#include<Windows.h>
#include<string>

using namespace std;
enum Status { LEFT, RIGHT };

struct Word {
	string s;
	int x, y;
	Status t;
};
void gotoXY(int x, int y);

void TextColor(int color);

void Flashing(string s);

void Run(string s);

