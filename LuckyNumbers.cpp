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
string lucky1 = "are a natural leader";
string lucky2 = "are a natural peacemaker";
string lucky3 = "are creative and optimistic";
string lucky4 = "are a hard worker";
string lucky5 = "value freedom";
string lucky6 = "are a carer and provider";
string lucky7 = "are a thinker";
string lucky8 = "have diplomatic skills";
string lucky9 = "are selfless and generous";

string alphabet = "abcdefghijklmnopqrstuvwxyz"; //Letters of alphabet used throughout the program
string CAPalphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //Capital letters of alphabet used throughout the program

int FrNmVal = 0; //Total value of First Name converted from letter to number values
int MidNmVal = 0; //Total value of Middle Name converted from letter to number values
int LstNmVal = 0; //Total value of Last Name converted from letter to number values
int tmp = 0;
bool HasMidName;
int MAX_LIMIT = 10;
int MID, LuckyNumber;

string FrNm, MidNm, LstNm, FrNmValS, MidNmValS, LstNmValS, LuckyNumberS;
char *FrNmValAr, *MidNmValAr, *LstNmValAr, *LuckyNumberAr;

ofstream LOG;

#define KEY_Y 121 // ASCII value for 'y' key
#define KEY_N 110 // ASCII value for 'n' key
/* END VARIABLES LIST*/

//main prog
int main() {

	LOG.open("LOG.txt", ios::app);

	cout << "Hi there! This program is here to calculate your lucky number and give you its meaning!! Please follow the instructions to find out what our lucky number is! :)" << endl;

	cout << "Enter FIRST name here >> " << flush;
	cin >> FrNm;
	LOG << "First name: " << FrNm << endl;
	char *FrNmAr = const_cast<char*>(FrNm.c_str()); // converts a string into char* (pointer to a char, basically a char array) 

	for (unsigned int i = 0; i<FrNm.length(); i++) {
		tmp = alphabet.find(FrNmAr[i]); // This function takes a char from char*, tries to find it in the alphabet string, returns its positiion as a integer and writes results to tmp integer  
		if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
			tmp = CAPalphabet.find(FrNmAr[i]); // This function takes a char from char*, tries to find it in the CAPalphabet string, returns its positiion as a integer and writes results to tmp integer
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
				cout << "Invalid character " << FrNmAr[i] << " ,please try again! Press any key to exit . . ." << endl;
				while (true) {
					if (_kbhit()) { // Terminate the program if any key is pressed
						LOG << "Session Failed" << endl;
						LOG.close();
						return EXIT_FAILURE;
					}
				}
			}
		}
		FrNmVal += (tmp % 9) + 1; // Use simple mathematical equation to change the tmp int into a right number as in the cheatsheet, for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
		LOG << i + 1 << ". " << FrNmVal << endl;
	}
	LOG << "Total is " << FrNmVal << endl; //My name (Adam) should be 1 + 4 + 1 + 4 = 10, lets see...
	
	// What if someone has middle name??
	cout << "Do you have a middle name?? (y)es/(n)o" << endl;
	MID = _getch(); // getch is a function from conio.h that is able to detect what key have you pressed on keyboard, you can use it with keys' ASCII and Hex values
	while (MID != KEY_Y && MID != KEY_N) {
		if (MAX_LIMIT <= 0) {
			cout << "You have pressed wrong button 10 times, application will be closed now. Press any key to exit . . ." << endl;
			while (true) {
				if (_kbhit()) { // Terminate the program if any key is pressed
					LOG << "Session Failed" << endl; 
					LOG.close();
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
		LOG << "Last Name: " << MidNm << endl;
		char *MidNmAr = const_cast<char*>(MidNm.c_str()); // converts a string into char* (pointer to a char, basically a char array)

		for (unsigned int i = 0; i<MidNm.length(); i++) {
			tmp = alphabet.find(MidNmAr[i]); // This function takes a char from char*, tries to find it in the alphabet string, returns its positiion as a integer and writes results to tmp integer 
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
				tmp = CAPalphabet.find(MidNmAr[i]); // This function takes a char from char*, tries to find it in the CAPalphabet string, returns its positiion as a integer and writes results to tmp integer 
				if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
					cout << "Invalid character " << MidNmAr[i] << " ,please try again! Press any key to exit . . ." << endl;
					while (true) {
						if (_kbhit()) { // Terminate the program if any key is pressed
							LOG << "Session Failed" << endl;
							LOG.close();
							return EXIT_SUCCESS;
						}
					}
				}
			}
			MidNmVal += (tmp % 9) + 1; // Use simple mathematical equation to change the tmp int into a right number as in the cheatsheet, for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
			LOG << i + 1 << ". " << MidNmVal << endl;
		}
		LOG << "Total is " << MidNmVal << endl; //My middle name (Filip) should be 6 + 9 + 3 + 9 + 7 = 34, lets see...
	}
	
	cout << "Enter LAST name here >> " << flush;
	cin >> LstNm;
	LOG << "Last Name: " << LstNm << endl;
	char *LstNmAr = const_cast<char*>(LstNm.c_str()); // converts a string into char* (pointer to a char, basically a char array)

	for (unsigned int i = 0; i<LstNm.length(); i++) {
		tmp = alphabet.find(LstNmAr[i]); // This function takes a char from char*, tries to find it in the alphabet string, returns its positiion as a integer and writes results to tmp integer 
		if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
			tmp = CAPalphabet.find(LstNmAr[i]); // This function takes a char from char*, tries to find it in the CAPalphabet string, returns its positiion as a integer and writes results to tmp integer 
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
				cout << "Invalid character " << LstNmAr[i] << " ,please try again! Press any key to exit . . ." << endl;
				while (true) {
					if (_kbhit()) { // Terminate the program if any key is pressed
						LOG << "Session Failed" << endl;
						LOG.close();
						return EXIT_FAILURE;
					}
				}
			}
		}
		LstNmVal += (tmp % 9) + 1; // Use simple mathematical equation to change the tmp int into a right number as in the cheatsheet, for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
		LOG << i + 1 << ". " << LstNmVal << endl;
	}
	LOG << "Total is " << LstNmVal << endl; //My surname (Myczkowski) should be 4 + 7 + 3 + 8 + 2 + 6 + 5 + 1 + 2 + 9 = 47, lets see...

	while (FrNmVal > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
		FrNmValS = to_string(FrNmVal);
		FrNmValAr = const_cast<char*>(FrNmValS.c_str());
		if (FrNmVal > 99) {
			FrNmVal = (FrNmValAr[0] - '0') + (FrNmValAr[1] - '0') + (FrNmValAr[2] + '0');
			LOG << "Dig1 is: " << FrNmValAr[2] << " , " << flush;
			LOG << "Dig2 is: " << FrNmValAr[0] << " , " << flush;
			LOG << "Dig3 is: " << FrNmValAr[1] << " , " << flush;
			// dig3 is actually the farest number to to left when 3-digit number is called,
			// changing int names would introduce too much mess to the program hence
			// just putting dig3 as dig1 and moving dig1 and dig2 by 1 to the right
		}
		else {
			FrNmVal = (FrNmValAr[0] - '0') + (FrNmValAr[1] - '0');
			LOG << "Dig1 is: " << FrNmValAr[0] << " , " << flush;
			LOG << "Dig2 is: " << FrNmValAr[1] << " , " << flush;
		}
	}
	LOG << "First name digit: " << FrNmVal << endl;
	
	if (HasMidName == true) {
		while (MidNmVal > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
			MidNmValS = to_string(MidNmVal);
			MidNmValAr = const_cast<char*>(MidNmValS.c_str());
			if (MidNmVal > 99) {
				MidNmVal = (MidNmValAr[0] - '0') + (MidNmValAr[1] - '0') + (MidNmValAr[2] + '0');
				LOG << "Dig1 is: " << MidNmValAr[2] << " , " << flush;
				LOG << "Dig2 is: " << MidNmValAr[0] << " , " << flush;
				LOG << "Dig3 is: " << MidNmValAr[1] << " , " << flush;
				// dig3 is actually the farest number to to left when 3-digit number is called,
				// changing int names would introduce too much mess to the program hence
				// just putting dig3 as dig1 and moving dig1 and dig2 by 1 to the right
			}
			else {
				MidNmVal = (MidNmValAr[0] - '0') + (MidNmValAr[1] - '0');
				LOG << "Dig1 is: " << MidNmValAr[0] << " , " << flush;
				LOG << "Dig2 is: " << MidNmValAr[1] << " , " << flush;
			}
		}
		LOG << "Middle name digit: " << MidNmVal << endl;
	}

	while (LstNmVal > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
		LstNmValS = to_string(LstNmVal);
		LstNmValAr = const_cast<char*>(LstNmValS.c_str());
		if (LstNmVal > 99) {
			FrNmVal = (LstNmValAr[0] - '0') + (LstNmValAr[1] - '0') + (LstNmValAr[2] + '0');
			LOG << "Dig1 is: " << LstNmValAr[2] << " , " << flush;
			LOG << "Dig2 is: " << LstNmValAr[0] << " , " << flush;
			LOG << "Dig3 is: " << LstNmValAr[1] << " , " << flush;
			// dig3 is actually the farest number to to left when 3-digit number is called,
			// changing int names would introduce too much mess to the program hence
			// just putting dig3 as dig1 and moving dig1 and dig2 by 1 to the right
		}
		else {
			LstNmVal = (LstNmValAr[0] - '0') + (LstNmValAr[1] - '0');
			LOG << "Dig1 is: " << LstNmValAr[0] << " , " << flush;
			LOG << "Dig2 is: " << LstNmValAr[1] << " , " << flush;
	}
	LOG << "Last name digit: " << LstNmVal << endl;

	if (HasMidName == true) { // We want to add MidNmVal only if user name has chosen to do so.
		LuckyNumber = FrNmVal + LstNmVal + MidNmVal;
	}
	else {
		LuckyNumber = FrNmVal + LstNmVal;
	}

	while (LuckyNumber > 9) { // if number is lower than 9 it's a single digit and doesn't need to be split
				LuckyNumberS = to_string(LuckyNumber);
		LuckyNumberAr = const_cast<char*>(LuckyNumberS.c_str());
		if (LuckyNumber > 99) {
			LuckyNumber = (LuckyNumberAr[0] - '0') + (LuckyNumberAr[1] - '0') + (LuckyNumberAr[2] + '0');
			LOG << "Dig1 is: " << LuckyNumberAr[2] << " , " << flush;
			LOG << "Dig2 is: " << LuckyNumberAr[0] << " , " << flush;
			LOG << "Dig3 is: " << LuckyNumberAr[1] << " , " << flush;
			// dig3 is actually the farest number to to left when 3-digit number is called,
			// changing int names would introduce too much mess to the program hence
			// just putting dig3 as dig1 and moving dig1 and dig2 by 1 to the right
		}
		else {
			LuckyNumber = (LuckyNumberAr[0] - '0') + (LuckyNumberAr[1] - '0');
			LOG << "Dig1 is: " << LuckyNumberAr[0] << " , " << flush;
			LOG << "Dig2 is: " << LuckyNumberAr[1] << " , " << flush;
		}
	}
	
	LOG << "Your lucky number is: " << LuckyNumber << endl;
	if (HasMidName == true) { // We want to display middle name only if user has it.
		cout << "Okay then " << FrNm << " " << MidNm << " " << LstNm << endl;
	}
	else {
		cout << "Okay then " << FrNm << " " << LstNm << endl;
	}
	cout << "Your lucky number is " << LuckyNumber << "!! This means that you " << flush;
	if (LuckyNumber == 1) {
		cout << lucky1 << endl;
	}
	else if (LuckyNumber == 2) {
		cout << lucky2 << endl;
	}
	else if (LuckyNumber == 3) {
		cout << lucky3 << endl;
	}
	else if (LuckyNumber == 4) {
		cout << lucky4 << endl;
	}
	else if (LuckyNumber == 5) {
		cout << lucky5 << endl;
	}
	else if (LuckyNumber == 6) {
		cout << lucky6 << endl;
	}
	else if (LuckyNumber == 7) {
		cout << lucky7 << endl;
	}
	else if (LuckyNumber == 8) {
		cout << lucky8 << endl;
	}
	else if (LuckyNumber == 9) {
		cout << lucky9 << endl;
	}

	cout << "Press any key to exit . . ." << endl;
	while (true) {
		if (_kbhit()) {
			LOG << "Session succeeded" << endl;
			LOG.close();
			return EXIT_SUCCESS;
		}
	}
}
