#include <process.h>
#include <iostream>
#include "KeyEvent.h"
using namespace std;
class Game {
private:
	int x;
	int y;
	int direction;
	void gotoXY(int x, int y) {
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public:
	Game() {
		x = 5;
		y = 5;
		direction = 0;
	}
	void setDirection(int i) {
		direction = i;
	}
	void move() {
		if (direction == 37) {
			x--;
		}
		else if (direction == 38) {
			y--;
		}
		else if (direction == 39) {
			x++;
		}
		else if (direction == 40) {
			y++;
		}
		system("cls");
		this->gotoXY(x, y);
		cout << x << "  " << y;
		cout << "��";
	}
};
Game* game = new Game();
unsigned int __stdcall mythread(void*)
{

	int i = 0;
	while (1) {
		game->move();
		Sleep(500);
	}
	return 0;
}
unsigned int __stdcall keyEvent(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getKey();
		switch (i) {
		case 37: game->setDirection(i); break;
		case 38: game->setDirection(i); break;
		case 39: game->setDirection(i); break;
		case 40: game->setDirection(i); break;
		}
	}
	return 0;
}
int main() {
	HANDLE handleA, handleB;
	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}