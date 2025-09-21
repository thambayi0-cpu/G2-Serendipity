
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void cashier()
{
	const int TOTAL_WIDTH = 79;
	const int QTY_WIDTH = 3;
	const int ISBN_WIDTH = 13;
	const int TITLE_WIDTH = 37;
	const int PRICE_WIDTH = 8;
	const int PRICETOTAL_WIDTH = 8;

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

	cout << right << "+" << setfill('-') << setw(TOTAL_WIDTH) << "+" << endl << setfill(' ') << left;

	cout << setw(TOTAL_WIDTH) << "|" << "|" << endl;

	cout << setw(TOTAL_WIDTH) << "|Serendipity Booksellers" << "|" << endl;

	cout << setw(TOTAL_WIDTH) << "|" << "|" << endl;

	cout << "|Date: " << date << right << setw(TOTAL_WIDTH - 6 - date.size()) << "|" << endl;

	cout << left << setw(TOTAL_WIDTH) << "|" << "|" << endl;

	cout << right << "+" << setfill('-') << setw(TOTAL_WIDTH) << "+" << endl << setfill(' ') << left;

	cout << "|Qty  " << setw(ISBN_WIDTH) << "ISBN" << " " << setw(TITLE_WIDTH) << "Title" << " " << setw(PRICE_WIDTH) << "Price" << "    " << setw(PRICETOTAL_WIDTH) << "Total" << " |" << endl;

	cout << right << "+" << setfill('-') << setw(TOTAL_WIDTH) << "+" << endl << setfill(' ') << left;

	cout << fixed;

	cout << "|" << right << setprecision(0) << setw(QTY_WIDTH) << qty << "  " << left << setw(ISBN_WIDTH) << isbn << " " << setw(TITLE_WIDTH) << title << " $" << right << setw(PRICE_WIDTH-1) << setprecision(2) << price << "    $" << setw(PRICETOTAL_WIDTH-1) << subTotal << " |" << left << endl;

	cout << setw(TOTAL_WIDTH) << "|" << "|" << endl;

	cout << setw(TOTAL_WIDTH) << "|" << "|" << endl;

	cout << left << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+5) << "|" << setw(PRICE_WIDTH) << "Subtotal" << "    $" << right << setw(PRICETOTAL_WIDTH-1) << subTotal << " |" << left << endl;

	cout << left << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+5) << "|" << setw(PRICE_WIDTH) << "Tax" << "    $" << right << setw(PRICETOTAL_WIDTH-1) << tax << " |" << left << endl;

	cout << left << setw(QTY_WIDTH+ISBN_WIDTH+TITLE_WIDTH+5) << "|" << setw(PRICE_WIDTH) << "Total" << "    $" << right << setw(PRICETOTAL_WIDTH-1) << total << " |" << left << endl;

	cout << setw(TOTAL_WIDTH) << "|" << "|" << endl;

	cout << setw(TOTAL_WIDTH) << "| Thank you for shopping at Serendipity!" << "|" << endl;

	cout << right << "+" << setfill('-') << setw(TOTAL_WIDTH) << "+" << endl << setfill(' ') << left;

	return;
}
