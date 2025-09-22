#include "mainmenu_header.h"

/******************************************************************************
* FUNCTION PrintMainMenu
*******************************************************************************/

string PrintMainMenu()

{
	/***************************************************************************
	* CONSTANTS
	****************************************************************************/
 	const string VERTICAL_BORDER     = "\xE2\x94\x80";
 	const string HORIZONTAL_BORDER   = "\xE2\x94\x82";
 	const string TOP_LEFT_BORDER     = "\xE2\x94\x8C";
 	const string TOP_RIGHT_BORDER    = "\xE2\x94\x90";
 	const string BOTTOM_LEFT_BORDER  = "\xE2\x94\x94";
 	const string BOTTOM_RIGHT_BORDER = "\xE2\x94\x98";
 	const string COMPANY_NAME        = "Serendipity Booksellers";
 	const string TITLE               = "Main Menu";
 	const string SELECTION_ONE       = "1. Cashier Module";
 	const string SELECTION_TWO       = "2. Inventory Database Module";
 	const string SELECTION_THREE     = "3. Report Module";
 	const string SELECTION_FOUR      = "4. Exit";
	const string INPUT_PROMPT        = "Enter Your Choice: ";
 	const string INPUT_PROMPT_RANGE  = "Please enter a number in the range 1 - 4.";
	/***************************************************************************
	* VARIABLES
	****************************************************************************/
	ostringstream out;           // ASGN & OUT - variable to assign output string
	string        topBotStr;     // ASGN & OUT - top/bottom border string

	// Inserts many border characters into string

	for (int i = 0; i < 61; i++)
	{
		topBotStr += VERTICAL_BORDER;
	}


	// Sets justification left
	out << left;


	// Top border output
	out << endl << endl << TOP_LEFT_BORDER << topBotStr << TOP_RIGHT_BORDER << endl;

	// Menu titles and selection info

	out << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(20) << " "   << COMPANY_NAME       << setfill(' ') << setw(21) << right << HORIZONTAL_BORDER
   	 << endl
	    << HORIZONTAL_BORDER << setfill(' ') << setw(28) << " "   << TITLE              << setfill(' ') << setw(27) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_ONE      << setfill(' ') << setw(30) << right << HORIZONTAL_BORDER
	 	 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_TWO      << setfill(' ') << setw(19) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_THREE    << setfill(' ') << setw(31) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << SELECTION_FOUR     << setfill(' ') << setw(40) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << INPUT_PROMPT       << setfill(' ') << setw(28) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(17) << " "   << INPUT_PROMPT_RANGE << setfill(' ') << setw(6)  << right << HORIZONTAL_BORDER
		 << endl
		 << HORIZONTAL_BORDER << setfill(' ') << setw(64) << right << HORIZONTAL_BORDER
		 << endl;


	// Bottom border
	out << BOTTOM_LEFT_BORDER << topBotStr << BOTTOM_RIGHT_BORDER;

	// Spacing
	out << endl;

	// Reset justification
	out << right;

	// Returns output as a string
	return out.str();
}






