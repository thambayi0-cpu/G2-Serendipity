/*Program header*/

#ifndef INVMENU_H
#define INVMENU_H

int invMenu(bool &keepInvMenuActive);

int lookUpBook(bool &keepInvMenuActive, bool &keeplookUpBookMenuActive);

int addBook(bool &keepInvMenuActive, bool &keepAddBookMenuActive);

int editBook(bool &keepInvMenuActive, bool &keepeditBookMenuActive);

int deleteBook(bool &keepInvMenuActive, bool &keepdeleteBookMenuActive);

#endif
