#ifndef LETTER_COUNT_H
#define LETTER_COUNT_H

//#include <ctype>
#include <string>
using namespace std;

const int NUM_LETTERS = 26;

class LetterCount
{
public:
	LetterCount();   //default
	LetterCount(const char* string);   //cstring
	LetterCount(const LetterCount &someLetterCount);   //copy
	LetterCount(LetterCount &someLetterCount);  //move
	~LetterCount();    //destructor
	int totalCount();  
	void add(LetterCount otherLetterCount);
	void subtract(LetterCount otherLetterCount);
	bool equals(LetterCount otherLetterCount);
	bool hasAsMany(LetterCount otherLetterCount);
	void print();

private:
	int* letterCounts;

};

#endif