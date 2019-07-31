// DatBae.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
void execute(string inStr);

int main()
{
	int testCases;
	cin >> testCases;

	for (int i = 0; i < testCases; ++i) {
		int nWorkers;
		cin >> nWorkers;
		int nBroken;
		cin >> nBroken;
		int sendCount;
		cin >> sendCount;

		string firstSend;
		double half = nWorkers / 2;
		for (int i = 0; i < nWorkers; i++) {
			if (i >= half)
				firstSend.push_back('0');
			else
				firstSend.push_back('1');
		}

		cout << firstSend << endl;

		string inStr;
		cin >> inStr;

		execute(inStr);

	}

    return 0;
}

void execute(string inStr) {
	
}

