/*
 * grade.cpp : Returns a letter grade from a numerical grade value
 * CS35 - Fall 2013
 * 9/7/2013
 * Camden Wagner
 */

#include<iostream>
using namespace std;

void convertToLetter(int score);

int main() {

	int score = -1;
	int letter;
	while (score < 0 || score > 100) {
		cout << "Enter a valid test score :: ";
		cin >> score;
	}
	convertToLetter(score);

}

void convertToLetter(int score) {

	if (score >= 90) {
		cout << "A" << endl;
	} else if (score >= 80) {
		cout << "B" << endl;
	} else if (score >= 70) {
		cout << "C" << endl;
	} else if (score >= 60) {
		cout << "D" << endl;
	} else {
		cout << "F" << endl;
	}

}
