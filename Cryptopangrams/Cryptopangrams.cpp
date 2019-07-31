// Cryptopangrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int isPrime(int n);
std::vector<int> getPrimeNumbers(int maxP);
std::string translate(std::vector<int> letters, std::vector<int> alphabet);

using namespace std;

int main()
{
	int testCases;
	cin >> testCases;

	for (int i = 0; i < testCases; ++i) {
		int maxP;
		cin >> maxP;
		int nPairs;
		cin >> nPairs;

		vector<int> primes = getPrimeNumbers(maxP);
		vector<int> letters;
		vector<int> alphabet;

		bool first = true;
		int previousPrime = -1;
		int previousPair;
		int currentPair;
		cin >> previousPair;

		for (int i = 1; i < nPairs; ++i) {
			cin >> currentPair;
			for (auto itr = primes.begin(); itr < primes.end(); ++itr) {
				if (previousPair % *itr == 0 && currentPair % *itr == 0  && (*itr != previousPrime || previousPair == *itr * *itr)) {
					if (first) {
						letters.push_back(previousPair / *itr);
						alphabet.push_back(previousPair / *itr);
						first = false;
					}
					letters.push_back(*itr);
					if (std::find(alphabet.begin(), alphabet.end(), *itr) == alphabet.end())
						alphabet.push_back(*itr);
					previousPair = currentPair;
					previousPrime = *itr;
					break;
				}
			}
		}

		letters.push_back(currentPair / previousPrime);
		if (std::find(alphabet.begin(), alphabet.end(), currentPair / previousPrime) == alphabet.end())
			alphabet.push_back(currentPair / previousPrime);

		sort(alphabet.begin(), alphabet.end());
		string translation = translate(letters, alphabet);
		cout << "Case #" << i + 1 << ": " << translation << endl;
	}

    return 0;
}

string translate(std::vector<int> letters, const std::vector<int> alphabet) {
	string translation;
	for (auto itr = letters.begin(); itr != letters.end(); itr++) {
		if (*itr == alphabet[0]) translation.push_back('A');
		else if (*itr == alphabet[1]) translation.push_back('B');
		else if (*itr == alphabet[2]) translation.push_back('C');
		else if (*itr == alphabet[3]) translation.push_back('D');
		else if (*itr == alphabet[4]) translation.push_back('E');
		else if (*itr == alphabet[5]) translation.push_back('F');
		else if (*itr == alphabet[6]) translation.push_back('G');
		else if (*itr == alphabet[7]) translation.push_back('H');
		else if (*itr == alphabet[8]) translation.push_back('I');
		else if (*itr == alphabet[9]) translation.push_back('J');
		else if (*itr == alphabet[10]) translation.push_back('K');
		else if (*itr == alphabet[11]) translation.push_back('L');
		else if (*itr == alphabet[12]) translation.push_back('M');
		else if (*itr == alphabet[13]) translation.push_back('N');
		else if (*itr == alphabet[14]) translation.push_back('O');
		else if (*itr == alphabet[15]) translation.push_back('P');
		else if (*itr == alphabet[16]) translation.push_back('Q');
		else if (*itr == alphabet[17]) translation.push_back('R');
		else if (*itr == alphabet[18]) translation.push_back('S');
		else if (*itr == alphabet[19]) translation.push_back('T');
		else if (*itr == alphabet[20]) translation.push_back('U');
		else if (*itr == alphabet[21]) translation.push_back('V');
		else if (*itr == alphabet[22]) translation.push_back('W');
		else if (*itr == alphabet[23]) translation.push_back('X');
		else if (*itr == alphabet[24]) translation.push_back('Y');
		else if (*itr == alphabet[25]) translation.push_back('Z');
	}
	return translation;
}

vector<int> getPrimeNumbers(int maxP) {
	vector<int> primes;
	for (int i = 2; i <= maxP; i++)
		if (isPrime(i))
			primes.push_back(i);
	return primes;
}

int isPrime(int n)
{
	for (int i = 2; i <= n / 2; ++i)
		if (n % i == 0)
			return 0;
	return 1;
}
