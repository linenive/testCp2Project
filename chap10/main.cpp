#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "Frame.h"
#include "ExArray.h"

class Word {
private:
	string word;
public:
	Word(string word) {
		this->word = word;
	}
	string getWord() {
		return this->word;
	}
};

void dump(list<string> &l) {
	list <string> ::iterator iter = l.begin();
	while (iter != l.end()) {
		cout << *iter << endl;
		iter++;
	}
}
void main() {
	/*
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
	cout << "бс";
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
	*/
	/*
	try {
	Frame *f1 = new Frame;
	Frame *f2 = new Frame[10];

	delete f1;
	delete f2;
	}
	catch (string msg) {
	cout << "Error msg :" << msg << endl;
	}
	*/
	/*
	ExArray<int> arr1(3);
	ExArray<char> arr2(4);
	ExArray<double> arr3(5);

	arr1.addData(2);
	arr2.addData('A');
	arr3.addData(32.12);

	arr1.printData();
	arr2.printData();
	arr3.printData();
	*/
	/*
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.insert(v.begin(), 40);
	v.insert(v.end(), 50);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << "access index at 1 : " << v.at(1) << endl;

	v.erase(v.begin());
	v.erase(v.end() - 1);

	vector<int>::iterator iter = v.begin();

	cout << "access index at 1 with iterator : " << iter[1] << endl;

	while (iter != v.end()) {
		cout << *iter << endl;
		iter++;
	}
	*/
	/*
	list<string> names;
	names.insert(names.begin(), "Konkuk");
	names.insert(names.end(), "University");
	names.insert(names.end(), "SCLAB");
	names.insert(names.end(), "CSY");
	dump(names);
	cout << "===" << endl;
	names.reverse();
	dump(names);
	*/

/*
map<string, int>m;
m["seoul"] = 100;
m["daegu"] = 120;
m["busan"] = 200;

cout << "Train to Seoul = " << m["seoul"] << "$" << endl;
cout << "Train to Daegu = " << m["daegu"] << "$" << endl;
cout << "Train to Busan = " << m["busan"] << "$" << endl;
*/
map<char, list<Word>>m;

list<Word> aList;
list<Word> bList;

aList.push_back(Word("apple"));
aList.push_back(Word("avoid"));
aList.push_back(Word("appear"));

bList.push_back(Word("bread"));
bList.push_back(Word("bring"));
bList.push_back(Word("bow"));

m['a'] = aList;
m['b'] = bList;

map<char, list<Word>>::const_iterator iter = m.begin();

while (iter != m.end()) {
	cout << iter->first << ":" << endl;

	list<Word> temp = iter->second;
	list<Word>::const_iterator iter_list = temp.begin();

	while (iter_list != temp.end()) {
		Word word = *iter_list;
		cout << word.getWord() << ", ";
		iter_list++;
	}
	cout << "\n===" << endl;
	iter++;
}
}