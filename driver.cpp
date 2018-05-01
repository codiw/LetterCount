#include <iostream>
#include <vector>
using namespace std;

#include "lettercount.h"

int main()
{
	//Testing default constructor and totalCount()
	LetterCount lc;
	cout << "Total letters in new LC:  " << lc.totalCount() << endl;

	//Testing print()
	cout << "Letters in empty LC:  ";
	lc.print();
	cout << endl;

	//Testing single-value constructor
	LetterCount area("area");
	cout << "Letters in \"area\":  ";
	area.print();
	cout << endl;

	//Testing copy constructor
	cout << "Making a copy of \"area\":  ";
	LetterCount copy(area);
	copy.print();
	cout << endl;

	//Testing move constructor
	vector<LetterCount> vec;
	cout << "Moving \"temp\":  ";
	vec.push_back(LetterCount("temp"));
	vec[0].print();
	cout << endl;

	//Testing destructor
	LetterCount* ydd = new LetterCount("yabba dabba doo");
	cout << "Before deleting \"yabba dabba doo\":  ";
	ydd->print();
	cout << endl;
	delete ydd;
	//Note:  next line should cause a seg fault or print garbage data when uncommented
	//cout << "After deleting:  ";  ydd->print();  cout << endl;

	//Testing equals
	LetterCount are("are"), era("era");
	cout << "\"are\"";
	if (are.equals(era))
		cout << " equals \"era\"\n";
	else
		cout << " does not equal \"era\"\n";

	//Testing hasAsMany
	cout << "\"area\"";
	if (area.hasAsMany(are))
		cout << " has as many letters as \"are\"\n";
	else
		cout << " does not have as many letters as \"are\"\n";

	//Testing add
	cout << "\"area\" + \"era\" = ";
	area.add(era);
	area.print();
	cout << endl;

	//Testing subtract
	cout << "\"area\" - \"era\" = ";
	copy.subtract(era);
	copy.print();
	cout << endl;

	return 0;
}