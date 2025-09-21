/*Function Documentation*/

#include <iostream>
#include <iomanip>
#include "format.h"

using namespace std;

void printDash()
{
	cout << right << "+" << setfill('-') << setw(TOTAL_WIDTH) << "+" << setfill(' ') << left << endl;
	return;
}

void printBorder()
{
	cout << left << setw(TOTAL_WIDTH) << "|" << "|" << endl;
	return;
}
