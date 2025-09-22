/*Function Documentation*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
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




/******************************************************************************
* FUNCTION OutputClassHeading
*------------------------------------------------------------------------------
* Receives a length for heading column, a name for the programmer, title for the
* class, a section for the days and time the class takes place, assignment
* type assignment name, and the number for the assignment, character for
* class heading border, size for left border spacing, length of border
*
*------------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need a defined value passed in
* HEADING_COL    : length for the class heading asterisk line
* TITLE_COL      : setw for header titles
* PROGRAMMER     : Name of the programmer
* CLASS          : Class the assignment is for
* SECTION        : section day and time of class
* MODULE         : module number
* PURPOSE        : purpose of program
* DUE_DATE       : due date of assignment
* AS_TYPE        : type of assignment (assignment or a lab)
* AS_NAME        : Assignment name
* AS_NUM         : lab number
* BORDER_CHAR    : character for border
* BORDER_SPACING : spacing between character and text
* LINE_LENGTH    : border length
*
* POST-CONDITIONS
* ==> Returns nothing - This will output the class heading for the assignment
*
*******************************************************************************/

string OutputClassHeading
(const short  HEADING_COL   ,   // IN - asterisk string length
 const int    TITLE_COL     ,   // IN - setw for header titles
 const string PROGRAMMER    ,   // IN - name of programmer
 const string ID            ,   // IN - student IDs
 const string CLASS         ,   // IN - class title
 const string SECTION       ,   // IN - day and time of class
 const string MODULE        ,   // IN - module number
 const string PURPOSE       ,   // IN - purpose of program
 const string DUE_DATE      ,   // IN - submission due date
 const string AS_TYPE       ,   // IN - assigment type
 const string AS_NAME       ,   // IN - assignment name
 const short  AS_NUM        ,   // IN - lab number
 const char   BORDER_CHAR   ,   // IN - border character
 const short  BORDER_SPACING,   // IN - border formatting
 const short  LINE_LENGTH   )   // IN - border length

{

/***************************************************************************
* VARIABLES
****************************************************************************/
ostringstream leftBorder;    // ASGN & PROC - variable to format left border
ostringstream out;           // ASGN & OUT - variable to assign output string
string        topBotStr;     // ASGN & OUT - top/bottom character string
string        leftBorderStr; // ASGN & OUT - left border for class heading

//Assigns string of character to a variable
topBotStr = OutputStringOfCharacter(HEADING_COL) + '\n';

//Assigns border and spacing into a variable
leftBorder << left << setw(BORDER_SPACING + 1 ) << BORDER_CHAR;

//Assigns string into a variable
leftBorderStr = leftBorder.str();

// Sets justification left
out << left;

//Top border
out << topBotStr;

//Class Heading titles and info formatted
out << leftBorderStr << setw(TITLE_COL) << "PROGRAMMED BY" << ": "
<< PROGRAMMER
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "ID"            << ": "
<< ID
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "CLASS"         << ": "
<< CLASS
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "SECTION"       << ": "
<< SECTION
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "MODULE"        << ": "
<< MODULE
<< endl;
out << leftBorderStr << setw(TITLE_COL) << AS_TYPE         << ": "
<< AS_NUM
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "PROGRAM NAME"  << ": "
<< AS_NAME
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "PURPOSE"       << ": "
<< PURPOSE
<< endl;
out << leftBorderStr << setw(TITLE_COL) << "DUE DATE"      << ": "
<< DUE_DATE
<< endl;
//Bottom border
out << topBotStr;

//Spacing
out << endl;

//Reset justification
out << right;

//Returns output as a string
return out.str();
}



/*******************************************************************************
* FUNCTION OutputStringOfCharacter
* ------------------------------------------------------------------------------
* Receives character to be output and length that character will fill
* ------------------------------------------------------------------------------
* PRE-CONDITIONS
* The following need a defined value passed in
* CHARACTER : character for the string
* CHAR_SIZE : length of the string
*
* POST-CONDITIONS
* ==> Returns a string of a character
*
*******************************************************************************/

string OutputStringOfCharacter
(const short CHAR_SIZE, // IN - length of string
 const char  CHARACTER) // IN - character for string
{
ostringstream out;

//OUTPUT string of a character
out << setfill(CHARACTER) << setw(CHAR_SIZE) << CHARACTER;

// Resets the setfill back to default
out << setfill(' ');

return out.str();
}




/******************************************************************************
* FUNCTION EndOfProgramBanner
*******************************************************************************/

string EndOfProgramBanner
(const short  HEADING_COL   ,   // IN - asterisk string length
 const char   BORDER_CHAR   ,   // IN - border character
 const short  BORDER_SPACING,   // IN - border formatting
 const short  LINE_LENGTH )

{
/***************************************************************************
* CONSTANTS
****************************************************************************/
 const string END_STATEMENT = "E N D   O F   P R O G R A M";

/***************************************************************************
* VARIABLES
****************************************************************************/
ostringstream leftBorder;    // ASGN & PROC - variable to format left border
ostringstream out;           // ASGN & OUT - variable to assign output string
string        topBotStr;     // ASGN & OUT - top/bottom character string
string        leftBorderStr; // ASGN & OUT - left border for class heading

ostringstream         centerPadding;
ostringstream         leftCenterPadding;
ostringstream         rightCenterPadding;
string                leftCenterPaddingStr;
string                rightCenterPaddingStr;

//Assigns string of character to a variable
topBotStr = OutputStringOfCharacter(HEADING_COL) + '\n';

//Assigns border and spacing into a variable
leftBorder         << left << setw(BORDER_SPACING + 1 ) << BORDER_CHAR;

leftCenterPadding  << left << setw( ((HEADING_COL - END_STATEMENT.length()) / 2) - 2 ) << " ";

rightCenterPadding << left << setw( ((HEADING_COL - END_STATEMENT.length()) / 2))      << " ";


//Assigns string into a variable
leftBorderStr = leftBorder.str();

leftCenterPaddingStr  = leftCenterPadding.str();

rightCenterPaddingStr = rightCenterPadding.str();

// Sets justification left
out << left;

// OUTPUTS  end of program banner

//Top border
out << endl << endl << topBotStr;

//end of program statement
out << BORDER_CHAR << setfill(' ') << setw(HEADING_COL -1) << right << BORDER_CHAR;
out << endl << leftBorderStr << leftCenterPaddingStr << END_STATEMENT;
out << rightCenterPaddingStr << leftBorderStr << endl;
out << BORDER_CHAR << setfill(' ') << setw(HEADING_COL -1) << right << BORDER_CHAR;
out << endl;


//Bottom border
out << topBotStr;

//Spacing
out << endl;

//Reset justification
out << right;

//Returns output as a string
return out.str();
}


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

