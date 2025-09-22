run-test: mainmenu.o format.o cashier.o
	g++ -std=c++20 -Wall -Werror -o run-test mainmenu.o format.o cashier.o

mainmenu.o: mainmenu.cpp format.h
	g++ -std=c++20 -Wall -Werror -c mainmenu.cpp

format.o: format.cpp format.h
	g++ -std=c++20 -Wall -Werror -c format.cpp

cashier.o: cashier.cpp cashier.h
	g++ -std=c++20 -Wall -Werror -c cashier.cpp

clean:
	-rm *.o run-test
