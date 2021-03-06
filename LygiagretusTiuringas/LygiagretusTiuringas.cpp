// LygiagretusTiuringas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//All Turing functions in this class
class  TuringClass {
private:
	int headPosition = 0, amountOfInstructions = 0;
	string currentState = "0";
	string ThisState[100], NewState[100];
	char Symbol[100], NewSymbol[100], Direction[100];

public:
	string tape;

	bool Turing() {
		//while (!_kbhit()) {
		if (((unsigned int)headPosition >= tape.length()) || (headPosition < 0)) return false;
		if (!moveHead()) {
			//cout << "Halt - state: " << currentState << " - symbol: " << tape[headPosition] << endl;
			return false;
		}
		//cout << tape << endl;
		return true;
	}

	void readFile(string &filename) {
		ifstream file(filename);
		file >> headPosition;
		while (tape.empty()) {
			getline(file, tape);
		}
		int i = 0;
		while (!file.eof()) {
			file >> ThisState[i] >> Symbol[i] >> NewSymbol[i] >> Direction[i] >> NewState[i];
			i++;
		}
		amountOfInstructions = i - 1;
		file.close();
	}

	bool moveHead() {
		for (int i = 0; i < amountOfInstructions; i++) {
			if (currentState == ThisState[i]) {
				if (tape[headPosition] == Symbol[i]) {
					tape[headPosition] = NewSymbol[i];
					if (Direction[i] == 'R') headPosition++;
					else headPosition--;

					currentState = NewState[i];
					return true;
				}
			}
		}
		return false;
	}
};

void newTuring();

int main()
{
	char command;
	while (true) {
		newTuring();
		cout << "Testi? - (Y//N) "; cin >> command;
		if (command == 'N') break;
	}
	return 0;
}
//takes 4 file names and starts turing on them
//1 - turing step on each file at a time
void newTuring() {
	string filename;
	TuringClass file0, file1, file2, file3;
	bool chk0 = true, chk1 = true, chk2 = true, chk3 = true;
	cout << "Iveskite 4 failus kuriuos naudosite: " << endl;
	cin >> filename; file0.readFile(filename);
	cin >> filename; file1.readFile(filename);
	cin >> filename; file2.readFile(filename);
	cin >> filename; file3.readFile(filename);
	while (!_kbhit()) {
		if(chk0){
			if (!file0.Turing()) chk0 = false;
		}
		cout << file0.tape << endl;
		if (chk1) {
			if (!file1.Turing()) chk1 = false;
		}
		cout << file1.tape << endl;
		if (chk2) {
			if (!file2.Turing()) chk2 = false;
		}
		cout << file2.tape << endl;
		if (chk3) {
			if (!file3.Turing()) chk3 = false;
		}
		cout << file3.tape << endl;
		system("CLS");
	}
	cout << file0.tape << endl << file1.tape << endl << file2.tape << endl << file3.tape << endl;
}
//1.txt 2.txt 3.txt 4.txt