//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

//============================================================================
// Name        : LuckyNumbers.cpp
// Author      : Adam Myczkowski
// Version     : 2.5
// Description : Lucky number calculator
//============================================================================

//==========CHEATSHEET================
//	1	2	3	4	5	6	7	8	9
//	a	b	c	d	e	f	g	h	i
//	j	k	l	m	n	o	p	q	r
//	s	t	u	v	w	x	y	z
//====================================

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <fstream>
using namespace std;

/* VARIABLES USED */
string lucky[] = {
	"are a natural leader",
	"are a natural peacemaker",
	"are creative and optimistic",
	"are a hard worker",
	"value freedom",
	"are a carer and provider",
	"are a thinker",
	"have diplomatic skills",
	"are selfless and generous"
};

string alphabet = "abcdefghijklmnopqrstuvwxyz"; //Letters of alphabet used throughout the program
string CAPalphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //Capital letters of alphabet used throughout the program

int tmp = 0;
int NmVal, FrNmVal, MidNmVal, LstNmVal, dig1, dig2, dig3, keyInput, LuckyNumber, LIMIT;

string FrNm, MidNm, LstNm;

#define KEY_Y 121 // ASCII value for 'y' key
#define KEY_N 110 // ASCII value for 'n' key
/* END VARIABLES LIST*/

int convert(string Nm) {
	char *NmAr = const_cast<char*>(Nm.c_str()); // converts a string into char* (pointer to a char, basically a char array)

	for (unsigned int i = 0; i<Nm.length(); i++) {
		tmp = alphabet.find(NmAr[i]); // This function takes a char from char*, tries to find it in the alphabet string, returns its positiion as a integer and writes results to tmp integer
		if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position)
			tmp = CAPalphabet.find(NmAr[i]); // This function takes a char from char*, tries to find it in the CAPalphabet string, returns its positiion as a integer and writes results to tmp integer
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position)
				cout << "Invalid character " << NmAr[i] << " ,please try again! Press any key to exit . . ." << endl;
				while (true) {
					if (_kbhit()) { // Terminate the program if any key is pressed
						return EXIT_FAILURE;
					}
				}
			}
		}
		NmVal += (tmp % 9) + 1; // Use simple mathematical equation to change the tmp int into a right number as in the cheatsheet, for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
	}
	int cNmVal = NmVal;
	NmVal = 0;
	return cNmVal;
}

int splitNumber(int Number) {
	while (Number > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
		dig1 = (Number / 10) % 10;
		dig2 = Number % 10;
		if (Number > 99) {
			dig3 = (Number / 100) % 10;
			Number = dig1 + dig2 + dig3;
		}
		else {
			Number = dig1 + dig2;
		}
	}
	return Number;
}

//main prog
int main() {

	cout << "Hi there! This program is here to calculate your lucky number and give you its meaning!! Please follow the instructions to find out what our lucky number is! :)" << endl;

	cout << "Enter FIRST name here >> " << flush;
	cin >> FrNm;
	FrNmVal = convert(FrNm);
	FrNmVal = splitNumber(FrNmVal);

	// What if someone has middle name??
	cout << "Do you have a middle name?? (y)es/(n)o" << endl;
	keyInput = _getch(); // getch is a function from conio.h that is able to detect what key have you pressed on keyboard, you can use it with keys' ASCII and Hex values
	while (keyInput != KEY_Y && keyInput != KEY_N) {
		if (LIMIT <= 10) {
			cout << "You have pressed wrong button 10 times, application will be closed now. Press any key to exit . . ." << endl;
			while (true) {
				if (_kbhit()) { // Terminate the program if any key is pressed
					return EXIT_FAILURE;
				}
			}
		}
		cout << "Wrong key pressed, press (y) for yes and (n) for no!" << endl;
		keyInput = _getch();
		LIMIT++;
	}
	if (keyInput == KEY_Y) {
		cout << "Enter MIDDLE name here >> " << flush;
		cin >> MidNm;
		MidNmVal = convert(MidNm);
		MidNmVal = splitNumber(MidNmVal);
	}

	cout << "Enter LAST name here >> " << flush;
	cin >> LstNm;
	LstNmVal = convert(LstNm);
	LstNmVal = splitNumber(LstNmVal);

	if (keyInput == KEY_Y) { // We want to display middle name only if user has it.
		cout << "Okay then " << FrNm << " " << MidNm << " " << LstNm << endl;
		LuckyNumber = FrNmVal + MidNmVal + LstNmVal;
	}
	else {
		cout << "Okay then " << FrNm << " " << LstNm << endl;
		LuckyNumber = FrNmVal + LstNmVal;
	}

	LuckyNumber = splitNumber(LuckyNumber);

	cout << "Your lucky number is " << LuckyNumber << "!! This means that you " << lucky[LuckyNumber - 1] << endl;

	cout << "Press any key to exit . . ." << endl;
	while (true) {
		if (_kbhit()) {
			return EXIT_SUCCESS;
		}
	}
}
