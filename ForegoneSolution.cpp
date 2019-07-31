// ForegoneSolution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	int testCases;
	cin >> testCases;

	for (int i = 0; i < testCases; ++i) {
		string prize;
		cin >> prize;
		
		int firstValue = 0;
		int factor = 1;
		for (auto itr = prize.rbegin(); itr != prize.rend(); itr++) {
			if (*itr == '4') {
				*itr = '2';
				firstValue += 2 * factor;
			}
			factor = factor * 10;
		}
		cout << "Case #" << i + 1 << ": " << firstValue << " " << prize << endl;
	}

    return 0;
}

