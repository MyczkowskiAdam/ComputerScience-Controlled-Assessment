//============================================================================
// Name        : LuckyNumbers.cpp
// Author      : Adam Myczkowski
// Version     : 1.1
// Description : Lucky number calculator
//============================================================================

//==========CHEATSHEET================
//	1	2	3	4	5	6	7	8	9
//	a	b	c	d	e	f	g	h	i
//	j	k	l	m	n	o	p	q	r
//	s	t	u	v	w	x	y	z
//====================================

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

// VARIABLES USED
string lucky1 = "Natural leader";
string lucky2 = "Natural peacemaker";
string lucky3 = "Creative and optimistic";
string lucky4 = "Hard worker";
string lucky5 = "Value freedom";
string lucky6 = "Carer and provider";
string lucky7 = "Thinker";
string lucky8 = "Have diplomatic skills";
string lucky9 = "Selfless and generous";

int FrNmVal = 0; //Total value of First Name converted from letter to number values
int LstNmVal = 0; //Total value of Last Name converted from letter to number values
char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; //Letters of alphabet used throughout the program
char CAPalphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }; //Capital letters of alphabet used throughout the program

//main prog
int main() {

	cout << "Hi there! This program is here to calculate your lucky number and give you its meaning!! Please follow the instructions to find out what our lucky number is! :)" << endl;

	cout << "Enter FIRST name here >> " << flush;
	string FrNm;
	cin >> FrNm;
	char *FrNmAr = const_cast<char*>(FrNm.c_str()); // converts a string into array of chars

	for (unsigned int i=0; i<FrNm.length(); i++) { // check each char in array if its equal to chars from alphabet array and add value associated to that char to FrNmVal integer
		if (FrNmAr[i] == alphabet[0] || FrNmAr[i] == alphabet[9] || FrNmAr[i] == alphabet[18] || FrNmAr[i] == CAPalphabet[0] || FrNmAr[i] == CAPalphabet[9] || FrNmAr[i] == CAPalphabet[18]) {
			FrNmVal += 1;
		}
		else if (FrNmAr[i] == alphabet[1] || FrNmAr[i] == alphabet[10] || FrNmAr[i] == alphabet[19] || FrNmAr[i] == CAPalphabet[1] || FrNmAr[i] == CAPalphabet[10] || FrNmAr[i] == CAPalphabet[19]) {
			FrNmVal += 2;
		}
		else if (FrNmAr[i] == alphabet[2] || FrNmAr[i] == alphabet[11] || FrNmAr[i] == alphabet[20] || FrNmAr[i] == CAPalphabet[2] || FrNmAr[i] == CAPalphabet[11] || FrNmAr[i] == CAPalphabet[20]) {
			FrNmVal += 3;
		}
		else if (FrNmAr[i] == alphabet[3] || FrNmAr[i] == alphabet[12] || FrNmAr[i] == alphabet[21] || FrNmAr[i] == CAPalphabet[3] || FrNmAr[i] == CAPalphabet[12] || FrNmAr[i] == CAPalphabet[21]) {
			FrNmVal += 4;
		}
		else if (FrNmAr[i] == alphabet[4] || FrNmAr[i] == alphabet[13] || FrNmAr[i] == alphabet[22] || FrNmAr[i] == CAPalphabet[4] || FrNmAr[i] == CAPalphabet[13] || FrNmAr[i] == CAPalphabet[22]) {
			FrNmVal += 5;
		}
		else if (FrNmAr[i] == alphabet[5] || FrNmAr[i] == alphabet[14] || FrNmAr[i] == alphabet[23] || FrNmAr[i] == CAPalphabet[5] || FrNmAr[i] == CAPalphabet[14] || FrNmAr[i] == CAPalphabet[23] ) {
			FrNmVal += 6;
		}
		else if (FrNmAr[i] == alphabet[6] || FrNmAr[i] == alphabet[15] || FrNmAr[i] == alphabet[24] || FrNmAr[i] == CAPalphabet[6] || FrNmAr[i] == CAPalphabet[15] || FrNmAr[i] == CAPalphabet[24]) {
			FrNmVal += 7;
		}
		else if (FrNmAr[i] == alphabet[7] || FrNmAr[i] == alphabet[16] || FrNmAr[i] == alphabet[25] || FrNmAr[i] == CAPalphabet[7] || FrNmAr[i] == CAPalphabet[16] || FrNmAr[i] == CAPalphabet[25]) {
			FrNmVal += 8;
		}
		else if (FrNmAr[i] == alphabet[8] || FrNmAr[i] == alphabet[17] || FrNmAr[i] == CAPalphabet[8] || FrNmAr[i] == CAPalphabet[17] ) {
			FrNmVal += 9;
		}
		else {
			cout << "Invalid character " << FrNmAr[i] << " ,please try again!";
		}
		//Staging - check if the value is being add up correctly
		//cout << i << ". " << FrNmVal << endl;
	}
	//cout << "Total is " << FrNmVal << endl; //My name (adam) should be 1 + 4 + 1 + 4 = 10, lets see...


	cout << "Enter LAST name here >> " << flush;
	string LstNm;
	cin >> LstNm;
	char *LstNmAr = const_cast<char*>(LstNm.c_str()); // converts a string into array of chars

	for (unsigned int i=0; i<LstNm.length(); i++) { // check each char in array if its equal to chars from alphabet array and add value associated to that char to FrNmVal integer
		if (LstNmAr[i] == alphabet[0] || LstNmAr[i] == alphabet[9] || LstNmAr[i] == alphabet[18] || LstNmAr[i] == CAPalphabet[0] || LstNmAr[i] == CAPalphabet[9] || LstNmAr[i] == CAPalphabet[18]) {
			LstNmVal += 1;
		}
		else if (LstNmAr[i] == alphabet[1] || LstNmAr[i] == alphabet[10] || LstNmAr[i] == alphabet[19] || LstNmAr[i] == CAPalphabet[1] || LstNmAr[i] == CAPalphabet[10] || LstNmAr[i] == CAPalphabet[19]) {
			LstNmVal += 2;
		}
		else if (LstNmAr[i] == alphabet[2] || LstNmAr[i] == alphabet[11] || LstNmAr[i] == alphabet[20] || LstNmAr[i] == CAPalphabet[2] || LstNmAr[i] == CAPalphabet[11] || LstNmAr[i] == CAPalphabet[20]) {
			LstNmVal += 3;
		}
		else if (LstNmAr[i] == alphabet[3] || LstNmAr[i] == alphabet[12] || LstNmAr[i] == alphabet[21] || LstNmAr[i] == CAPalphabet[3] || LstNmAr[i] == CAPalphabet[12] || LstNmAr[i] == CAPalphabet[21]) {
			LstNmVal += 4;
		}
		else if (LstNmAr[i] == alphabet[4] || LstNmAr[i] == alphabet[13] || LstNmAr[i] == alphabet[22] || LstNmAr[i] == CAPalphabet[4] || LstNmAr[i] == CAPalphabet[13] || LstNmAr[i] == CAPalphabet[22] ) {
			LstNmVal += 5;
		}
		else if (LstNmAr[i] == alphabet[5] || LstNmAr[i] == alphabet[14] || LstNmAr[i] == alphabet[23] || LstNmAr[i] == CAPalphabet[5] || LstNmAr[i] == CAPalphabet[14] || LstNmAr[i] == CAPalphabet[23] ) {
			LstNmVal += 6;
		}
		else if (LstNmAr[i] == alphabet[6] || LstNmAr[i] == alphabet[15] || LstNmAr[i] == alphabet[24] || LstNmAr[i] == CAPalphabet[6] || LstNmAr[i] == CAPalphabet[15] || LstNmAr[i] == CAPalphabet[24] ) {
			LstNmVal += 7;
		}
		else if (LstNmAr[i] == alphabet[7] || LstNmAr[i] == alphabet[16] || LstNmAr[i] == alphabet[25] || LstNmAr[i] == CAPalphabet[7] || LstNmAr[i] == CAPalphabet[16] || LstNmAr[i] == CAPalphabet[25] ) {
			LstNmVal += 8;
		}
		else if (LstNmAr[i] == alphabet[8] || LstNmAr[i] == alphabet[17] || LstNmAr[i] == CAPalphabet[8] || LstNmAr[i] == CAPalphabet[17]) {
			LstNmVal += 9;
		}
		else {
			cout << "Invalid character " << LstNmAr[i] << " ,please try again!";
		}
		//Staging - check if the value is being add up correctly
		//cout << i << ". " << LstNmVal << endl;
	}
	//cout << "Total is " << LstNmVal << endl; //My surname (myczkowski) should be 4 + 7 + 3 + 8 + 2 + 6 + 5 + 1 + 2 + 9 = 47, lets see...


	int c_FrNmVal = FrNmVal;
	int c_LstNmVal = LstNmVal;

	while (c_FrNmVal > 9) { //split integer into digits
		int dig1 = (c_FrNmVal / 10) % 10;
		int dig2 = c_FrNmVal % 10;
		c_FrNmVal = dig1 + dig2;
		//cout << dig1 << endl; //Check if it returns right digit (enable to debug)
		//cout << dig2 << endl; //Check if it returns right digit (enable to debug)
	}
	//cout << c_FrNmVal << endl; //Check if it returns right integer (enable to debug)

	while (c_LstNmVal > 9) { //split integer into digits
		int dig1 = (c_LstNmVal / 10) % 10;
		int dig2 = c_LstNmVal % 10;
		c_LstNmVal = dig1 + dig2;
		//cout << dig1 << endl; //Check if it returns right digit (enable to debug)
		//cout << dig2 << endl; //Check if it returns right digit (enable to debug)
	}
	//cout << c_LstNmVal << endl; //Check if it returns right integer (enable to debug)

	int LuckyNumber = c_FrNmVal + c_LstNmVal;

	while (LuckyNumber > 9) { //split integer into digits
		int dig1 = (LuckyNumber / 10) % 10;
		int dig2 = LuckyNumber % 10;
		LuckyNumber = dig1 + dig2;
		//cout << dig1 << endl; //Check if it returns right digit (enable to debug)
		//cout << dig2 << endl; //Check if it returns right digit (enable to debug)
	}
	cout << "Okay then " << FrNm << " " << LstNm << endl;
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

	return 0;
}

