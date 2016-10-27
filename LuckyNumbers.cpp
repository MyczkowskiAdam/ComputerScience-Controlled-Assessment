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
// Version     : 2.2
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
string lucky1 = "Natural leader";
string lucky2 = "Natural peacemaker";
string lucky3 = "Creative and optimistic";
string lucky4 = "Hard worker";
string lucky5 = "Value freedom";
string lucky6 = "Carer and provider";
string lucky7 = "Thinker";
string lucky8 = "Have diplomatic skills";
string lucky9 = "Selfless and generous";

string alphabet =  "abcdefghijklmnopqrstuvwxyz"; //Letters of alphabet used throughout the program
string CAPalphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //Capital letters of alphabet used throughout the program

int FrNmVal = 0; //Total value of First Name converted from letter to number values
int MidNmVal = 0; //Total value of Middle Name converted from letter to number values
int LstNmVal = 0; //Total value of Last Name converted from letter to number values
int tmp = 0;
bool HasMidName;
int MAX_LIMIT = 10;
int c_FrNmVal, c_LstNmVal, c_MidNmVal, dig1, dig2, dig3, MID, LuckyNumber;

string FrNm;
string MidNm;
string LstNm;

ofstream LOG;

#define KEY_Y 121
#define KEY_N 110
/* END VARIABLES LIST*/

//main prog
int main() {

	LOG.open("LOG.txt", ios::app);

	cout << "Hi there! This program is here to calculate your lucky number and give you its meaning!! Please follow the instructions to find out what our lucky number is! :)" << endl;

	cout << "Enter FIRST name here >> " << flush;
	cin >> FrNm;
	LOG << "First name: " << FrNm << endl;
	char *FrNmAr = const_cast<char*>(FrNm.c_str()); // converts a string into array of chars

	for (unsigned int i=0; i<FrNm.length(); i++) { // check each char in array if its equal to chars from alphabet array and add value associated to that char to FrNmVal integer
		tmp = alphabet.find(FrNmAr[i]); //function that returns the position of a character it loops through from a alphabet character 
		if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
			tmp = CAPalphabet.find(FrNmAr[i]); //function that returns the position of a character it loops through from a alphabet character
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
				cout << "Invalid character " << FrNmAr[i] << " ,please try again! Press any key to exit" << endl;
				while (true) {
					if (_kbhit()) {
						LOG << "Session Failed" << endl;
						LOG.close();
						return EXIT_FAILURE;
					}
				}
			}
		}
		FrNmVal += (tmp % 9) + 1; // for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
		//Staging - check if the value is being add up correctly
		LOG << i + 1 << ". " << FrNmVal << endl;
	}
	LOG << "Total is " << FrNmVal << endl; //My name (adam) should be 1 + 4 + 1 + 4 = 10, lets see...
	
	//what if someone has middle name??
	cout << "Do you have a middle name?? (y)es/(n)o" << endl;
	MID = _getch();
	while (MID != KEY_Y && MID != KEY_N) {
		if ( MAX_LIMIT <= 0) {
			cout << "You have pressed wrong button 10 times, application will be closed now. Press any key to exit" << endl;
			while (true) {
				if (_kbhit()) {
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
	if (MID == KEY_N) {
		HasMidName = false;
	}
	if (HasMidName == true ) {
		cout << "Enter MIDDLE name here >> " << flush;
		cin >> MidNm;
		LOG << "Last Name: " << MidNm << endl;
		char *MidNmAr = const_cast<char*>(MidNm.c_str()); // converts a string into array of chars

		for (unsigned int i = 0; i<MidNm.length(); i++) { // check each char in array if its equal to chars from alphabet array and add value associated to that char to FrNmVal integer
			tmp = alphabet.find(MidNmAr[i]); //function that returns the position of a character it loops through from a alphabet character
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
				tmp = CAPalphabet.find(MidNmAr[i]); //function that returns the position of a character it loops through from a alphabet character
				if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
					cout << "Invalid character " << MidNmAr[i] << " ,please try again! Press any key to exit" << endl;
					while (true) {
						if (_kbhit()) {
							LOG << "Session Failed" << endl;
							LOG.close();
							return EXIT_SUCCESS;
						}
					}
				}
			}
			MidNmVal += (tmp % 9) + 1; // for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
									   //Staging - check if the value is being add up correctly
			LOG << i + 1 << ". " << MidNmVal << endl;
		}
		LOG << "Total is " << MidNmVal << endl; //My middle name (filip) should be 6 + 9 + 3 + 9 + 7 = 34, lets see...
	}
	
	cout << "Enter LAST name here >> " << flush;
	cin >> LstNm;
	LOG << "Last Name: " << LstNm << endl;
	char *LstNmAr = const_cast<char*>(LstNm.c_str()); // converts a string into array of chars

	for (unsigned int i=0; i<LstNm.length(); i++) { // check each char in array if its equal to chars from alphabet array and add value associated to that char to FrNmVal integer
		tmp = alphabet.find(LstNmAr[i]); //function that returns the position of a character it loops through from a alphabet character
		if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
			tmp = CAPalphabet.find(LstNmAr[i]); //function that returns the position of a character it loops through from a alphabet character
			if (tmp == string::npos) { // npos (-1) is returned when char we looking for is not in a given string (no position) 
				cout << "Invalid character " << LstNmAr[i] << " ,please try again! Press any key to exit" << endl;
				while (true) {
					if (_kbhit()) {
						LOG << "Session Failed" << endl;
						LOG.close();
						return EXIT_FAILURE;
					}
				}
			}
		}
		LstNmVal += (tmp % 9) + 1; // for example 'c' is in pos 2, 2 % 9 = 2 because 2 / 9 = 0.(2), 2 + 1 = 3. ^Lookup cheatsheet: c = 3.
		//Staging - check if the value is being add up correctly
		LOG << i + 1 << ". " << LstNmVal << endl;
	}
	LOG << "Total is " << LstNmVal << endl; //My surname (myczkowski) should be 4 + 7 + 3 + 8 + 2 + 6 + 5 + 1 + 2 + 9 = 47, lets see...

	c_FrNmVal = FrNmVal;
	c_LstNmVal = LstNmVal;
	c_MidNmVal = MidNmVal;

	while (c_FrNmVal > 9) { //split integer into digits
		dig1 = (c_FrNmVal / 10) % 10;
		dig2 = c_FrNmVal % 10;
		if (c_FrNmVal > 99) {
			dig3 = (c_FrNmVal / 100) % 10;
			c_FrNmVal = dig1 + dig2 + dig3;
			LOG << "Dig1 is: " << dig3 << " , " << flush;
			LOG << "Dig2 is: " << dig1 << " , " << flush;
			LOG << "Dig3 is: " << dig2 << " , " << flush;
			// dig3 is actually the farest number to to left when 3-digit number is called,
			// changing int names would introduce too much mess to the program hence
			// just putting dig3 as dig1 and moving dig1 and dig2 by 1 to the right
		}
		else {
			c_FrNmVal = dig1 + dig2;
			LOG << "Dig1 is: " << dig1 << " , " << flush;
			LOG << "Dig2 is: " << dig2 << " , " << flush;
		}
		//cout << dig1 << endl; //Check if it returns right digit (enable to debug)
		//cout << dig2 << endl; //Check if it returns right digit (enable to debug)
	}
	LOG << "First name digit: " << c_FrNmVal << endl; //Check if it returns right integer (enable to debug)
	
	if (HasMidName == true) {
		while (c_MidNmVal > 9) { //split integer into digits
			dig1 = (c_MidNmVal / 10) % 10;
			dig2 = c_MidNmVal % 10;
			if (c_MidNmVal > 99) {
				dig3 = (c_MidNmVal / 100) % 10;
				c_MidNmVal = dig1 + dig2 + dig3;
				LOG << "Dig1 is: " << dig3 << " , " << flush;
				LOG << "Dig2 is: " << dig1 << " , " << flush;
				LOG << "Dig3 is: " << dig2 << " , " << flush;
				// dig3 is actually the farest number to to left when 3-digit number is called,
				// changing int names would introduce too much mess to the program hence
				// just putting dig3 as dig1 and moving dig1 and dig2 by 1 to the right
			}
			else {
				c_MidNmVal = dig1 + dig2;
				LOG << "Dig1 is: " << dig1 << " , " << flush;
				LOG << "Dig2 is: " << dig2 << " , " << flush;
			}
			//cout << dig1 << endl; //Check if it returns right digit (enable to debug)
			//cout << dig2 << endl; //Check if it returns right digit (enable to debug)
		}
		LOG << "Middle name digit: " << c_MidNmVal << endl; //Check if it returns right integer (enable to debug) 
	}

	while (c_LstNmVal > 9) { //split integer into digits
		dig1 = (c_LstNmVal / 10) % 10;
		dig2 = c_LstNmVal % 10;
		if (c_LstNmVal > 99) {
			dig3 = (c_LstNmVal / 100) % 10;
			c_LstNmVal = dig1 + dig2 + dig3;
			LOG << "Dig1 is: " << dig3 << " , " << flush;
			LOG << "Dig2 is: " << dig1 << " , " << flush;
			LOG << "Dig3 is: " << dig2 << " , " << flush;
			// dig3 is actually the farest number to to left when 3-digit number is called,
			// changing int names would introduce too much mess to the program hence
			// just putting dig3 as dig1 and moving dig1 and dig2 by 1 to the right
		}
		else {
			c_LstNmVal = dig1 + dig2;
			LOG << "Dig1 is: " << dig1 << " , " << flush;
			LOG << "Dig2 is: " << dig2 << " , " << flush;
		}
		//cout << dig1 << endl; //Check if it returns right digit (enable to debug)
		//cout << dig2 << endl; //Check if it returns right digit (enable to debug)
	}
	LOG << "Last name digit: " << c_LstNmVal << endl; //Check if it returns right integer (enable to debug)

	if (HasMidName == true) {
		LuckyNumber = c_FrNmVal + c_LstNmVal + c_MidNmVal;
	}
	else {
		LuckyNumber = c_FrNmVal + c_LstNmVal;
	}

	while (LuckyNumber > 9) { //split integer into digits
		int dig1 = (LuckyNumber / 10) % 10;
		int dig2 = LuckyNumber % 10;
		if (LuckyNumber > 99) {
			int dig3 = (LuckyNumber / 100) % 10;
			LuckyNumber = dig1 + dig2 + dig3;
			LOG << "Dig1 is: " << dig3 << " , " << flush;
			LOG << "Dig2 is: " << dig1 << " , " << flush;
			LOG << "Dig3 is: " << dig2 << " , " << flush;
			// dig3 is actually the farest number to to left when 3-digit number is called,
			// changing int names would introduce too much mess to the program hence
			// just putting dig3 as dig1 and moving dig1 and dig2 by 1 to the right
		}
		else {
			LuckyNumber = dig1 + dig2;
			LOG << "Dig1 is: " << dig1 << " , " << flush;
			LOG << "Dig2 is: " << dig2 << " , " << flush;
		}
		//cout << dig1 << endl; //Check if it returns right digit (enable to debug)
		//cout << dig2 << endl; //Check if it returns right digit (enable to debug)
	}
	LOG << "Your lucky number is: " << LuckyNumber << endl; //Check if it returns right integer (enable to debug)
	if (HasMidName == true) {
		cout << "Okay then " << FrNm << " " << MidNm << " " << LstNm << endl;
	}
	else {
		cout << "Okay then " << FrNm << " " << LstNm << endl;
	}
	cout << "Your lucky number is " << LuckyNumber << "!! What does it tell about about you? What is its meaning?" << endl;
	if ( LuckyNumber == 1) {
		cout << "Number: " << LuckyNumber << " Meaning: " << lucky1 << endl;
	}
	else if ( LuckyNumber == 2) {
		cout << "Number: " << LuckyNumber << " Meaning: " << lucky2 << endl;
	}
	else if ( LuckyNumber == 3) {
			cout << "Number: " << LuckyNumber << " Meaning: " << lucky3 << endl;
	}
	else if ( LuckyNumber == 4) {
			cout << "Number: " << LuckyNumber << " Meaning: " << lucky4 << endl;
	}
	else if ( LuckyNumber == 5) {
			cout << "Number: " << LuckyNumber << " Meaning: " << lucky5 << endl;
	}
	else if ( LuckyNumber == 6) {
			cout << "Number: " << LuckyNumber << " Meaning: " << lucky6 << endl;
	}
	else if ( LuckyNumber == 7) {
			cout << "Number: " << LuckyNumber << " Meaning: " << lucky7 << endl;
	}
	else if ( LuckyNumber == 8) {
			cout << "Number: " << LuckyNumber << " Meaning: " << lucky8 << endl;
	}
	else if ( LuckyNumber == 9) {
			cout << "Number: " << LuckyNumber << " Meaning: " << lucky9 << endl;
	}

	cout << "Press any key to exit" << endl;
	while (true) {
		if (_kbhit()) {
			LOG << "Session succeeded" << endl;
			LOG.close();
			return EXIT_SUCCESS;
		}
	}
	
	LOG.close();
	return 0;
}

