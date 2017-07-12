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
// Version     : 2.4
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

int FrNmVal = 0; //Total value of First Name converted from letter to number values
int MidNmVal = 0; //Total value of Middle Name converted from letter to number values
int LstNmVal = 0; //Total value of Last Name converted from letter to number values
int tmp = 0;
bool HasMidName;
int MAX_LIMIT = 10;
int dig1, dig2, dig3, MID, LuckyNumber;

string FrNm, MidNm, LstNm;

#define KEY_Y 121 // ASCII value for 'y' key
#define KEY_N 110 // ASCII value for 'n' key
/* END VARIABLES LIST*/

//main prog
int main() {

	cout << "Hi there! This program is here to calculate your lucky number and give you its meaning!! Please follow the instructions to find out what our lucky number is! :)" << endl;

	cout << "Enter FIRST name here >> " << flush;
	cin >> FrNm;
	char *FrNmAr = const_cast<char*>(FrNm.c_str()); // converts a string into char* (pointer to a char, basically a char array)

	for (unsigned int i = 0; i<FrNm.length(); i++) {
		tmp = alphabet.find(FrNmAr[i]); // This function takes a char from char*, tries to find it in the alphabet string, returns its positiion as a integer and writes results to tmp integer
		if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position)
			tmp = CAPalphabet.find(FrNmAr[i]); // This function takes a char from char*, tries to find it in the CAPalphabet string, returns its positiion as a integer and writes results to tmp integer
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position)
				cout << "Invalid character " << FrNmAr[i] << " ,please try again! Press any key to exit . . ." << endl;
				while (true) {
					if (_kbhit()) { // Terminate the program if any key is pressed
						return EXIT_FAILURE;
					}
				}
			}
		}
		FrNmVal += (tmp % 9) + 1; // Use simple mathematical equation to change the tmp int into a right number as in the cheatsheet, for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
	}

										   // What if someone has middle name??
	cout << "Do you have a middle name?? (y)es/(n)o" << endl;
	MID = _getch(); // getch is a function from conio.h that is able to detect what key have you pressed on keyboard, you can use it with keys' ASCII and Hex values
	while (MID != KEY_Y && MID != KEY_N) {
		if (MAX_LIMIT <= 0) {
			cout << "You have pressed wrong button 10 times, application will be closed now. Press any key to exit . . ." << endl;
			while (true) {
				if (_kbhit()) { // Terminate the program if any key is pressed
					return EXIT_FAILURE;
				}
			}
		}
		cout << "Wrong key pressed, press (y) for yes and (n) for no!" << endl;
		MID = _getch();
		MAX_LIMIT--;
	}
	if (MID == KEY_Y) {
		HasMidName = true;
	}
	else if (MID == KEY_N) {
		HasMidName = false;
	}
	if (HasMidName == true) { // Execute only if user choose option to use middle name
		cout << "Enter MIDDLE name here >> " << flush;
		cin >> MidNm;
		char *MidNmAr = const_cast<char*>(MidNm.c_str()); // converts a string into char* (pointer to a char, basically a char array)

		for (unsigned int i = 0; i<MidNm.length(); i++) {
			tmp = alphabet.find(MidNmAr[i]); // This function takes a char from char*, tries to find it in the alphabet string, returns its positiion as a integer and writes results to tmp integer
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position)
				tmp = CAPalphabet.find(MidNmAr[i]); // This function takes a char from char*, tries to find it in the CAPalphabet string, returns its positiion as a integer and writes results to tmp integer
				if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position)
					cout << "Invalid character " << MidNmAr[i] << " ,please try again! Press any key to exit . . ." << endl;
					while (true) {
						if (_kbhit()) { // Terminate the program if any key is pressed
							return EXIT_SUCCESS;
						}
					}
				}
			}
			MidNmVal += (tmp % 9) + 1; // Use simple mathematical equation to change the tmp int into a right number as in the cheatsheet, for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
		}
	}

	cout << "Enter LAST name here >> " << flush;
	cin >> LstNm;
	char *LstNmAr = const_cast<char*>(LstNm.c_str()); // converts a string into char* (pointer to a char, basically a char array)

	for (unsigned int i = 0; i<LstNm.length(); i++) {
		tmp = alphabet.find(LstNmAr[i]); // This function takes a char from char*, tries to find it in the alphabet string, returns its positiion as a integer and writes results to tmp integer
		if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position)
			tmp = CAPalphabet.find(LstNmAr[i]); // This function takes a char from char*, tries to find it in the CAPalphabet string, returns its positiion as a integer and writes results to tmp integer
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position)
				cout << "Invalid character " << LstNmAr[i] << " ,please try again! Press any key to exit . . ." << endl;
				while (true) {
					if (_kbhit()) { // Terminate the program if any key is pressed
						return EXIT_FAILURE;
					}
				}
			}
		}
		LstNmVal += (tmp % 9) + 1; // Use simple mathematical equation to change the tmp int into a right number as in the cheatsheet, for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
	}

	while (FrNmVal > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
		dig1 = (FrNmVal / 10) % 10;
		dig2 = FrNmVal % 10;
		if (FrNmVal > 99) {
			dig3 = (FrNmVal / 100) % 10;
		}
		else {
			FrNmVal = dig1 + dig2;
		}
	}

	if (HasMidName == true) {
		while (MidNmVal > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
			dig1 = (MidNmVal / 10) % 10;
			dig2 = MidNmVal % 10;
			if (MidNmVal > 99) {
				dig3 = (MidNmVal / 100) % 10;
				MidNmVal = dig1 + dig2 + dig3;
			}
			else {
				MidNmVal = dig1 + dig2;
			}
		}
	}

	while (LstNmVal > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
		dig1 = (LstNmVal / 10) % 10;
		dig2 = LstNmVal % 10;
		if (LstNmVal > 99) {
			dig3 = (LstNmVal / 100) % 10;
			LstNmVal = dig1 + dig2 + dig3;
		}
		else {
			LstNmVal = dig1 + dig2;
		}
	}

	if (HasMidName == true) { // We want to add MidNmVal only if user name has chosen to do so.
		LuckyNumber = FrNmVal + LstNmVal + MidNmVal;
	}
	else {
		LuckyNumber = FrNmVal + LstNmVal;
	}

	while (LuckyNumber > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
		int dig1 = (LuckyNumber / 10) % 10;
		int dig2 = LuckyNumber % 10;
		if (LuckyNumber > 99) {
			int dig3 = (LuckyNumber / 100) % 10;
			LuckyNumber = dig1 + dig2 + dig3;
		}
		else {
			LuckyNumber = dig1 + dig2;
		}
	}

	if (HasMidName == true) { // We want to display middle name only if user has it.
		cout << "Okay then " << FrNm << " " << MidNm << " " << LstNm << endl;
	}
	else {
		cout << "Okay then " << FrNm << " " << LstNm << endl;
	}
	cout << "Your lucky number is " << LuckyNumber << "!! This means that you " << lucky[LuckyNumber - 1] << endl;

	cout << "Press any key to exit . . ." << endl;
	while (true) {
		if (_kbhit()) {
			return EXIT_SUCCESS;
		}
	}
}