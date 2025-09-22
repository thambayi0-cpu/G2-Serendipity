run-test: mainmenu.o OutputClassHeading.o OutputStringOfCharacter.o EndOfProgramBanner.o PrintMainMenu.o
	g++ -std=c++20 -Wall -Werror -o run-test mainmenu.o OutputClassHeading.o OutputStringOfCharacter.o EndOfProgramBanner.o PrintMainMenu.o

mainmenu.o: mainmenu.cpp mainmenu_header.h
	g++ -std=c++20 -Wall -Werror -c mainmenu.cpp

OutputClassHeading.o: OutputClassHeading.cpp mainmenu_header.h
	g++ -std=c++20 -Wall -Werror -c OutputClassHeading.cpp

OutputStringOfCharacter.o: OutputStringOfCharacter.cpp OutputClassHeading.cpp mainmenu_header.h
	g++ -std=c++20 -Wall -Werror -c OutputStringOfCharacter.cpp

EndOfProgramBanner.o: EndOfProgramBanner.cpp mainmenu_header.h
	g++ -std=c++20 -Wall -Werror -c EndOfProgramBanner.cpp

PrintMainMenu.o: PrintMainMenu.cpp mainmenu_header.h
	g++ -std=c++20 -Wall -Werror -c PrintMainMenu.cpp


clean:
	-rm *.o run-test
