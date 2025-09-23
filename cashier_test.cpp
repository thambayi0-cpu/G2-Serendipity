//FOR TESTING CASHIER.CPP ONLY. DO NOT INCLUDE IN MAKEFILE OR BUILD

#include <iostream>
#include <iomanip>
#include "cashier.h"

using namespace std;

int main()
{
	cout << "\033[H\033[2J";
	cout << "PRESS ENTER TO CONTINUE";
	cin.get();
	cashier();
	cout << "Thank you!";
	return 0;
}
