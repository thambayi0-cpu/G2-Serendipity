
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void cashier()
{
	const int TOTAL_WIDTH = 80;
	const int QTY_WIDTH = 3;
	const int ISBN_WIDTH = 13;
	const int TITLE_WIDTH = 37;
	const int PRICE_WIDTH = 8;
	const int PRICE_TOTAL_WIDTH = 8;

	string date;
	string title;
	unsigned int qty;
	string isbn;
	float price;

	float tax;
	float subTotal;
	float total;

	cout << "\033[H\033[2J";

	cout << "Enter Date: ";
	getline(cin, date);
	cout << "Enter Title: ";
	getline(cin, title);
	cout << "Enter ISBN: ";
	getline(cin, isbn);
	cout << "Enter quantity: ";
	cin >> qty;
	cout << "Enter price: ";
	cin >> price;

	subTotal = price*qty;
	tax = subTotal*0.06;
	total = subTotal+tax;

	cout << "\033[H\033[2J";

	cout << setfill('-') << setw(TOTAL_WIDTH) << "-" << endl << setfill(' ');
	cout << left << setw(TOTAL_WIDTH-1) << "-" << "-" << endl;
	cout << setw(TOTAL_WIDTH-1) << "-Serendipity Booksellers" << "-" << endl;
	cout << setw(TOTAL_WIDTH-1) << "-" << "-" << endl;
	cout << "-Date: " << date << right << setw(TOTAL_WIDTH - 7 - date.size()) << "-" << endl;
	cout << setfill('-') << setw(TOTAL_WIDTH) << "-" << endl << setfill(' ');

	cout << fixed << endl;
	cout << "Date: " << date << endl;
	cout << "Quantity of Book: " << setprecision(0) << qty << endl;
	cout << "ISBN: " << isbn << endl;
	cout << "Title: " << title << endl;
	cout << "Price: $" << setprecision(2) << price << endl;

	cout << '\n';
	cout << "Subtotal: $" << subTotal << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Total: $" << total << endl;


	return;
}

#include "cashier.h"
