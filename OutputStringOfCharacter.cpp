#include "mainmenu_header.h"

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

