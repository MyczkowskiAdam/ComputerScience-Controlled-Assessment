//============================================================================
// Name        : LuckyNumbers.cpp
// Author      : Adam Myczkowski
// Version     : 0.2
// Description : Lucky number calculator (WIP)
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
int FrNmVal = 0; //Total value of First Name converted from letter to number values
int LstNmVal = 0; //Total value of Last Name converted from letter to number values
char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; //Letters of alphabet used throughout the program

//main prog
int main() {

	cout << "Enter FIRST name here >> " << flush;
	string FrNm;
	cin >> FrNm;
	char *FrNmAr = const_cast<char*>(FrNm.c_str()); // converts a string into array of chars

	for (int i=0; i<FrNm.length(); i++) {
		if (FrNmAr[i] == alphabet[0] || FrNmAr[i] == alphabet[9] || FrNmAr[i] == alphabet[18] ) {
			FrNmVal += 1;
		}
		else if (FrNmAr[i] == alphabet[1] || FrNmAr[i] == alphabet[10] || FrNmAr[i] == alphabet[19] ) {
			FrNmVal += 2;
		}
		else if (FrNmAr[i] == alphabet[2] || FrNmAr[i] == alphabet[11] || FrNmAr[i] == alphabet[20] ) {
			FrNmVal += 3;
		}
		else if (FrNmAr[i] == alphabet[3] || FrNmAr[i] == alphabet[12] || FrNmAr[i] == alphabet[21] ) {
			FrNmVal += 4;
		}
		else if (FrNmAr[i] == alphabet[4] || FrNmAr[i] == alphabet[13] || FrNmAr[i] == alphabet[22] ) {
			FrNmVal += 5;
		}
		else if (FrNmAr[i] == alphabet[5] || FrNmAr[i] == alphabet[14] || FrNmAr[i] == alphabet[23] ) {
			FrNmVal += 6;
		}
		else if (FrNmAr[i] == alphabet[6] || FrNmAr[i] == alphabet[15] || FrNmAr[i] == alphabet[24] ) {
			FrNmVal += 7;
		}
		else if (FrNmAr[i] == alphabet[7] || FrNmAr[i] == alphabet[16] || FrNmAr[i] == alphabet[25] ) {
			FrNmVal += 8;
		}
		else if (FrNmAr[i] == alphabet[8] || FrNmAr[i] == alphabet[17] ) {
			FrNmVal += 9;
		}
		else {
			cout << "Invalid character " << FrNmAr[i] << " ,please try again!";
		}
		//Staging - check if the value is being add up correctly
		cout << i << ". " << FrNmVal << endl;
	}
	cout << "Total is " << FrNmVal << endl; //My name (adam) should be 1 + 4 + 1 + 4 = 10, lets see...


	cout << "Enter LAST name here >> " << flush;
	string LstNm;
	cin >> LstNm;
	char *LstNmAr = const_cast<char*>(LstNm.c_str()); // converts a string into array of chars

	for (int i=0; i<LstNm.length(); i++) {
		if (LstNmAr[i] == alphabet[0] || LstNmAr[i] == alphabet[9] || LstNmAr[i] == alphabet[18] ) {
			LstNmVal += 1;
		}
		else if (LstNmAr[i] == alphabet[1] || LstNmAr[i] == alphabet[10] || LstNmAr[i] == alphabet[19] ) {
			LstNmVal += 2;
		}
		else if (LstNmAr[i] == alphabet[2] || LstNmAr[i] == alphabet[11] || LstNmAr[i] == alphabet[20] ) {
			LstNmVal += 3;
		}
		else if (LstNmAr[i] == alphabet[3] || LstNmAr[i] == alphabet[12] || LstNmAr[i] == alphabet[21] ) {
			LstNmVal += 4;
		}
		else if (LstNmAr[i] == alphabet[4] || LstNmAr[i] == alphabet[13] || LstNmAr[i] == alphabet[22] ) {
			LstNmVal += 5;
		}
		else if (LstNmAr[i] == alphabet[5] || LstNmAr[i] == alphabet[14] || LstNmAr[i] == alphabet[23] ) {
			LstNmVal += 6;
		}
		else if (LstNmAr[i] == alphabet[6] || LstNmAr[i] == alphabet[15] || LstNmAr[i] == alphabet[24] ) {
			LstNmVal += 7;
		}
		else if (LstNmAr[i] == alphabet[7] || LstNmAr[i] == alphabet[16] || LstNmAr[i] == alphabet[25] ) {
			LstNmVal += 8;
		}
		else if (LstNmAr[i] == alphabet[8] || LstNmAr[i] == alphabet[17] ) {
			LstNmVal += 9;
		}
		else {
			cout << "Invalid character " << LstNmAr[i] << " ,please try again!";
		}
		//Staging - check if the value is being add up correctly
		cout << i << ". " << LstNmVal << endl;
	}
	cout << "Total is " << LstNmVal << endl; //My surname (myczkowski) should be 4 + 7 + 3 + 8 + 2 + 6 + 5 + 1 + 2 + 9 = 47, lets see...

	//TODO
	// Separate digits in the number into an array

	return 0;
}
