#include "lettercount.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;
/*
* filename: lettercount.cpp
* use your understanding of objects in C++ to implement
* a LetterCount class capable of keeping track of how many times each letter
* appears in a word or phrase.
*/

LetterCount::LetterCount()
{
	letterCounts = new int[NUM_LETTERS];   //allocating array

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		letterCounts[i] = 0;    //filling array with 0s
	}
}

LetterCount::LetterCount(const char* string)
{
	letterCounts = new int[NUM_LETTERS];

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		letterCounts[i] = 0;
	}

	for (unsigned int i = 0; i<strlen(string); i++)
	{
		if (!isalpha(string[i]))   //if current position in string is not alphabetical move to next position
			continue;

		char currentChar = string[i];
		currentChar = tolower(currentChar);  //changing current char to lowercase, treating LC and UC as equal
		int letterIndex = string[i] - 'a';

		letterCounts[letterIndex]++;

	}
}

LetterCount::LetterCount(const LetterCount &someLetterCount)
{
	letterCounts = new int[NUM_LETTERS];
	int* otherLetterCount = someLetterCount.letterCounts;

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		letterCounts[i] = otherLetterCount[i];
	}
}

LetterCount::LetterCount(LetterCount &someLetterCount)
{
	letterCounts = new int[NUM_LETTERS];
	int* otherLetterCount = someLetterCount.letterCounts;

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		letterCounts[i] = otherLetterCount[i];
	}
}

LetterCount::~LetterCount() 
{
	delete[] letterCounts;
}

int LetterCount::totalCount()   
{
	int count = 0;
	for (int i = 0; i<NUM_LETTERS; i++)
	{
		count = count + letterCounts[i];
	}
	return count;
}

void LetterCount::add(LetterCount otherLetterCount) 
{
	int* otherCounts = otherLetterCount.letterCounts;

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		letterCounts[i] = letterCounts[i] + otherCounts[i];
	}
}

void LetterCount::subtract(LetterCount otherLetterCount)
{
	int* otherCount = otherLetterCount.letterCounts;

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		if (letterCounts[i] - otherCount[i] < 0)
			continue;

		letterCounts[i] = letterCounts[i] - otherCount[i];
	}
}

bool LetterCount::equals(LetterCount otherLetterCount)
{
	int* otherCount = otherLetterCount.letterCounts;

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		if (letterCounts[i] != otherCount[i])
			return false;
	}
	return true;
}

bool LetterCount::hasAsMany(LetterCount otherLetterCount)
{
	int* otherCount = otherLetterCount.letterCounts;

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		if (letterCounts[i] - otherCount[i] < 0)
			return false;
	}
	return true;
}

void LetterCount::print()
{
	int total = totalCount();

	if (total == 0)
	{
		cout << "None";
		return;
	}

	for (int i = 0; i<NUM_LETTERS; i++)
	{
		if (letterCounts[i] > 0)
		{
			cout << (char)('a' + i) << " " << letterCounts[i] << " ";
		}
	}
}
