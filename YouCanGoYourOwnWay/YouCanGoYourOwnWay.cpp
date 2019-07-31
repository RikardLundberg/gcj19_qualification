// YouCanGoYourOwnWay.cpp : Defines the entry point for the console application.
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
		int gridSize;
		cin >> gridSize;
		string lydiaPath;
		cin >> lydiaPath;

		string myPath = lydiaPath;
		for (auto itr = myPath.begin(); itr != myPath.end(); itr++) {
			if (*itr == 'S')
				*itr = 'E';
			else
				*itr = 'S';
		}

		cout << "Case #" << i + 1 << ": " << myPath << endl;
	}

	return 0;
}
