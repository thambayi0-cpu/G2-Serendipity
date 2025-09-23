run-test: mainmenu.o format.o cashier.o invMenu.o reports.o
	g++ -std=c++20 -Wall -Werror -o run-test mainmenu.o format.o cashier.o invMenu.o reports.o

mainmenu.o: mainmenu.cpp format.h
	g++ -std=c++20 -Wall -Werror -c mainmenu.cpp

format.o: format.cpp format.h
	g++ -std=c++20 -Wall -Werror -c format.cpp

cashier.o: cashier.cpp cashier.h
	g++ -std=c++20 -Wall -Werror -c cashier.cpp

invMenu.o: invMenu.cpp invMenu.h
	g++ -std=c++20 -Wall -Werror -c invMenu.cpp

reports.o: reports.cpp reports.h
	g++ -std=c++20 -Wall -Werror -c reports.cpp

clean:
	-rm *.o run-test
