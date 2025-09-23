/***************************************************************************
* PROGRAMMED BY : Ahmer Yasin & Thokozile Hambayi
* ID            : A00349012   & 127485
* CLASS         : CS1B
* SECTION       : TTh 1:30pm
* MODULE        : 2
* GROUP PROJECT : 2
* PROGRAM NAME  : Menus (Navigation & Stubs)
* PURPOSE       : Bookstore POS
* DUE DATE      : 09/23/2025
****************************************************************************/

#include "format.h"
#include "reports.h"


void reports (bool &keepReportsMenuActive)
{
	// Constants
	const string INPUT_PROMPT     = "Enter Your Choice: ";
	const string INPUT_PRINT      = "You selected item ";
	const short  INPUT_PRINT_FILL = 44;
	const string INVALID_INPUT    = "Invalid input. Enter a number range 1 - 7.";
	const string CLEAR_SCREEN     = "\x1b[H\x1b[2J";
	const string RESET            = "\x1b[0m";
	const string RED              = "\x1b[31m";
	const string GREEN            = "\x1b[32m";



	// Variables
	string         headingString;              // OUT  - class heading
	string         endOfProgramString;         // OUT  - end of program statement
	string         printReportsMenuString;		 // OUT  - report menu print
	char           choice;							 // PROC - choice switch selection
	string			choiceString;					 // IN   - input

	bool           invalidInputBool;				 // IN   - error check bool

	bool           keepRepListingMenuActive;   // PROC - bool for repListing() while loop
	bool           keepRepWholesaleMenuActive; // PROC - bool for repWholesale() while loop
	bool           keepRepRetailMenuActive;    // PROC - bool for repRetail() while loop
	bool           keepRepQtyMenuActive;       // PROC - bool for repQty() while loop
	bool           keepRepCostMenuActive;      // PROC - bool for repCost() while loop
	bool           keepRepAgeMenuActive;       // PROC - bool for repAge() while loop

	short          inputPrintHeight;				 // FORM - cursor position
	short          inputPrintRow;					 // FORM - cursor position

   short          inputPromptHeight;			 // FORM - cursor position
	short          inputPromptRow;				 // FORM - cursor position

	ostringstream  inputPrompt;					 // PROC - cursor position and prompt stores inputPromptStr
	string         inputPromptStr;				 // OUT  - input prompt

	ostringstream  inputPrint;						 // PROC - cursor position and input selection print stores in inputPrintStr
	string         inputPrintStr;					 // OUT  - input selection print

	ostringstream  invalidInput;					 // // PROC - cursor position and error message stores in invalidInputStr
	string			invalidInputStr;				 // OUT  - error message

	ostringstream  pressEnter;						 // PROC - cursor position and press enter prompt stores in pressEnterStr
	string         pressEnterStr;					 // OUT  - press enter prompt


	// INITIALIZATIONS
	headingString           = OutputClassHeading();
	endOfProgramString      = EndOfProgramBanner();
	printReportsMenuString  = PrintReportsMenu();


	inputPrintHeight   = 19;
	inputPrintRow      = 30;
   inputPromptHeight  = 19;
	inputPromptRow     = 28;

	inputPrompt        << "\x1b[" << inputPromptRow << ";" << inputPromptHeight << "H" << setfill(' ') << setw(INPUT_PROMPT.length())
							 << "\x1b[" << inputPromptRow << ";" << inputPromptHeight << "H" << INPUT_PROMPT;
	inputPromptStr     = inputPrompt.str();

	inputPrint         << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ') << setw(INPUT_PRINT_FILL)
							 << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << INPUT_PRINT;
	inputPrintStr      = inputPrint.str();

	invalidInput       << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ') << setw(INPUT_PRINT_FILL)
							 << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << INVALID_INPUT;
	invalidInputStr    = invalidInput.str();

	pressEnter         << "\x1b[34;14H" << "\x1b[5m" << "\x1b[1m" << "\x1b[37m" << "\x1b[44m" << "    Press  E N T E R  to continue    " << RESET;
	pressEnterStr      = pressEnter.str();







	// INPUT - Inventory Menu Input Prompt for "Choice"
	while (keepReportsMenuActive)
	{
		// Clear Screen
		cout << CLEAR_SCREEN;

		// OUTPUT HEADING - Class heading output
		cout << headingString;


		// INPUT - Reports Menu Display
		cout << printReportsMenuString;

		invalidInputBool = true;

		choice = 0;
		do
		{
			// Input menu selection
			cout << inputPromptStr;
			getline(cin, choiceString);

			// Cleans input buffer
			while (!choiceString.empty()        &&
				   ( choiceString.back() == '\r' ||
					  choiceString.back() == '\n' ||
					  choiceString.back() == '\t' ||
					  choiceString.back() == ' '  ))
			{
				choiceString.pop_back();
			}

			// Error Checking
			if(choiceString.size() == 1 && choiceString[0] >= '1' && choiceString[0] <= '7')
			{
				choice = choiceString[0];
				invalidInputBool = false;
			}
			else
			{
				cout << CLEAR_SCREEN << headingString << printReportsMenuString << inputPromptStr << RED << invalidInputStr << RESET;
			}

		} while (invalidInputBool);


		// Selection statement for inventory menu selection
		switch (choice)
		{

			// RepListing
			case '1':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				keepRepListingMenuActive = true;
				repListing(keepReportsMenuActive, keepRepListingMenuActive);
				break;

			// RepWholesale
			case '2':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				keepRepWholesaleMenuActive = true;
				repWholesale(keepReportsMenuActive, keepRepWholesaleMenuActive);
				break;

			// RepRetail
			case '3':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				keepRepRetailMenuActive = true;
				repRetail(keepReportsMenuActive, keepRepRetailMenuActive);
				break;

			// RepQty
			case '4':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				keepRepQtyMenuActive = true;
				repQty(keepReportsMenuActive, keepRepQtyMenuActive);
				break;

			// RepCost
			case '5':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				keepRepCostMenuActive = true;
				repCost(keepReportsMenuActive, keepRepCostMenuActive);
				break;

			// RepAge
			case '6':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				keepRepAgeMenuActive = true;
				repAge(keepReportsMenuActive, keepRepAgeMenuActive);
				break;

			// Exit return to main menu
			case '7':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				keepReportsMenuActive = false;
				break;

			// Error message
			default:
				cout << RED << invalidInputStr << RESET;
				break;
		}

	}


}

