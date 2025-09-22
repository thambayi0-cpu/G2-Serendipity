#include "mainmenu_header.h"

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




