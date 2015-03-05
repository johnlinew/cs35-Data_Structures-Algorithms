/*
 * computeAverage.cpp : Allows user to enter up to 10 positive integers and computes the average.
 * CS35 Fall 2013
 * 9/3/2013
 * Camden Wagner
 */

#include<iostream>
using namespace std;

int main() {

	double total, average;
	int x;
	int j = 0;
	cout << "Enter up to ten values to compute the average of those values. To enter less, type the last number <= 0.\n";
	for (int i = 0; i < 10; i++) {
		cin >> x;
		if (x <= 0) {
			break;
		} else {
			total += x;
			j++;
		}
	}
	average = total/j;
	cout << "Average = " << average << endl;

}
