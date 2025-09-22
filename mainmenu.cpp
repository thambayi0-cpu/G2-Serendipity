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


int main()
{
	// Constants
	const string INPUT_PROMPT     = "Enter Your Choice: ";
	const string INPUT_PRINT      = "You selected item ";
	const short  INPUT_PRINT_FILL = 44;
	const string INVALID_INPUT    = "Invalid input. Enter a number range 1 - 4.";
	const string CLEAR_SCREEN     = "\033[H\033[2J";
	const string NOCOLOR          = "\033[0m";
	const string RED              = "\033[31m";
	const string GREEN            = "\033[32m";


	// Variables
	string         headingString;              // OUT  - class heading
	string         endOfProgramString;         // OUT  - end of program statement
	string         printMainMenuStr;
	char           choice;
	string			choiceString;
	bool           invalidInputBool;
	bool				keepActive;
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


	// INITIALIZATIONS
	headingString      = OutputClassHeading();
	endOfProgramString = EndOfProgramBanner();
	printMainMenuStr   = PrintMainMenu();
	keepActive         = true;
	inputPrintHeight   = 19;
	inputPrintRow      = 27;
   inputPromptHeight  = 19;
	inputPromptRow     = 25;
	inputPrompt        << "\033[" << inputPromptRow << ";" << inputPromptHeight << "H" << setfill(' ') << setw(INPUT_PROMPT.length())
							 << "\033[" << inputPromptRow << ";" << inputPromptHeight << "H" << INPUT_PROMPT;
	inputPromptStr     = inputPrompt.str();
	inputPrint         << "\033[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ') << setw(INPUT_PRINT_FILL)
							 << "\033[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << INPUT_PRINT;
	inputPrintStr      = inputPrint.str();
	invalidInput       << "\033[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << setfill(' ') << setw(INPUT_PRINT_FILL)
							 << "\033[" << inputPrintRow  << ";" << inputPrintHeight  << "H" << INVALID_INPUT;
	invalidInputStr    = invalidInput.str();


	// Clear Screen
	cout << CLEAR_SCREEN;


	// OUTPUT HEADING - Class heading output
	cout << headingString;


	// INPUT - Main Menu Display
	cout << printMainMenuStr;

	// INPUT - Main Menu Input Prompt for "Choice"
	do
	{
		invalidInputBool = true;
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
				cout << CLEAR_SCREEN << headingString << printMainMenuStr << inputPromptStr << RED << invalidInputStr << NOCOLOR;
			}

		} while (invalidInputBool);

		switch (choice)
		{
			case '1':
				cout << GREEN << inputPrintStr << choice << "." << NOCOLOR;
				cashier();
				break;
			case '2':
				cout << GREEN << inputPrintStr << choice << "." << NOCOLOR;
				break;
			case '3':
				cout << GREEN << inputPrintStr << choice << "." << NOCOLOR;
				break;
			case '4':
				cout << GREEN << inputPrintStr << choice << "." << NOCOLOR;
				keepActive = false;
				break;
			default:
				cout << RED << invalidInputStr << NOCOLOR;
				break;
		}

	} while (keepActive);



	// PROCESSING

	// OUTPUT




	// OUTPUT - End of Program Banner
	cout << endl << endl << endl << endl << endOfProgramString  << endl << endl;
	return 0;
}

