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
#include "cashier.h"
#include "invMenu.h"
#include "reports.h"


int main()
{
	// Constants
	const string INPUT_PROMPT     = "Enter Your Choice: ";
	const string INPUT_PRINT      = "You selected item ";
	const short  INPUT_PRINT_FILL = 44;
	const string INVALID_INPUT    = "Invalid input. Enter a number range 1 - 4.";
	const string CLEAR_SCREEN     = "\x1b[H\x1b[2J";
	const string RESET            = "\x1b[0m";
	const string RED              = "\x1b[31m";
	const string GREEN            = "\x1b[32m";



	// Variables
	string         headingString;              // OUT  - class heading
	string         endOfProgramString;         // OUT  - end of program statement
	string         printMainMenuString;
	string         printInvMenuString;
	char           choice;
	string			choiceString;
	bool           invalidInputBool;
	bool				keepActive;
	bool				keepInvMenuActive;
	bool				keepReportsMenuActive;
	short          inputPrintHeight;
	short          inputPrintRow;
   short          inputPromptHeight;
	short          inputPromptRow;
	ostringstream  inputPrompt;
	string         inputPromptStr;
	ostringstream  inputPrint;
	string         inputPrintStr;
	ostringstream  invalidInput;
	string			invalidInputStr;
	ostringstream  pressEnter;
	string         pressEnterStr;


	// INITIALIZATIONS
	headingString       = OutputClassHeading();
	endOfProgramString  = EndOfProgramBanner();
	printMainMenuString = PrintMainMenu();
	printInvMenuString  = PrintInvMenu();

	keepActive         = true;
	inputPrintHeight   = 19;
	inputPrintRow      = 27;
   inputPromptHeight  = 19;
	inputPromptRow     = 25;
	inputPrompt        << "\x1b[" << inputPromptRow << ";" << inputPromptHeight << "H" << setfill(' ') << setw(INPUT_PROMPT.length())
							 << "\x1b[" << inputPromptRow << ";" << inputPromptHeight << "H" << INPUT_PROMPT;
	inputPromptStr     = inputPrompt.str();
	inputPrint         << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ') << setw(INPUT_PRINT_FILL)
							 << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << INPUT_PRINT;
	inputPrintStr      = inputPrint.str();
	invalidInput       << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ') << setw(INPUT_PRINT_FILL)
							 << "\x1b[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << INVALID_INPUT;
	invalidInputStr    = invalidInput.str();
	pressEnter         << "\x1b[31;14H" << "\x1b[5m" << "\x1b[1m" << "\x1b[37m" << "\x1b[44m" << "    Press  E N T E R  to contiue    " << RESET;
	pressEnterStr      = pressEnter.str();

	keepInvMenuActive     = false;
	keepReportsMenuActive = false;




	// INPUT - Main Menu Input Prompt for "Choice"
	do
	{

		// Clear Screen
		cout << CLEAR_SCREEN;


		// OUTPUT HEADING - Class heading output
		cout << headingString;


		// INPUT - Main Menu Display
		cout << printMainMenuString;

		// INPUT - Menu Prompt
		invalidInputBool = true;
		choice = 0;

		do
		{
			cout << inputPromptStr;
			getline(cin, choiceString);

			while (!choiceString.empty()        &&
				   ( choiceString.back() == '\r' ||
					  choiceString.back() == '\n' ||
					  choiceString.back() == '\t' ||
					  choiceString.back() == ' '  ))
			{
				choiceString.pop_back();
			}

			if(choiceString.size() == 1 && choiceString[0] >= '1' && choiceString[0] <= '4')
			{
				choice = choiceString[0];
				invalidInputBool = false;
			}
			else
			{
				cout << CLEAR_SCREEN << headingString << printMainMenuString << inputPromptStr << RED << invalidInputStr << RESET;
			}

		} while (invalidInputBool);

		// Selection statment for menu options
		switch (choice)
		{
			case '1':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cashier();
				break;
			case '2':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				keepInvMenuActive = true;
				invMenu(keepInvMenuActive);
				break;
			case '3':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				keepReportsMenuActive = true;
				reports(keepReportsMenuActive);
				break;
			case '4':
				cout << GREEN << inputPrintStr << choice << "." << RESET;
				cout << pressEnterStr;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				keepActive = false;
				break;
			default:
				cout << RED << invalidInputStr << RESET;
				break;
		}

	} while (keepActive);

	// Good bye message
	cout << "\x1b[31;14H" << setfill(' ') << setw(36)   << " ";
	cout << "\x1b[31;14H" << "\x1b[30m" << "\x1b[43m" << setfill(' ') << setw(37) << " ";
	cout << "\x1b[32;14H" << "\x1b[30m" << "\x1b[43m" << "     S e e  y o u  l a t e r  : )    ";
	cout << "\x1b[33;14H" << "\x1b[30m" << "\x1b[43m" << setfill(' ') << setw(37) << "  " << RESET;


	// OUTPUT - End of Program Banner
	cout << endl << endl << endl << endl << endOfProgramString  << endl << endl;
	return 0;
}

