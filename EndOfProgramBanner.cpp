#include "mainmenu_header.h"

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






