/*
 * funStrings.cpp : This program takes in a series of words from the user and outputs a string with the words in reverse order.
 *                  Loop stops at word entry "done".
 * CS35 Fall 2013
 * 9/3/2013
 * Camden Wagner
 */

#include<iostream>
using namespace std;

int main() {

	string output, input;
	input = "";
	while (input != "done") {
		output = input + " " + output;
		cin >> input;
	}
	cout << output << endl;

}
