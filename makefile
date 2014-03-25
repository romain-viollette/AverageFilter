SHELL=C:/Windows/System32/cmd.exe

all: main
	
main: CircularBuffer.o AverageFilter.o main.cpp
	g++ -ansi -pedantic -Wall -Wextra -Weffc++ -c main.cpp
	g++ -ansi -pedantic -Wall -Wextra -Weffc++ CircularBuffer.o AverageFilter.o main.o -o main.exe
	
CircularBuffer.o: CircularBuffer/CircularBuffer.cpp CircularBuffer/CircularBuffer.h
	g++ -ansi -pedantic -Wall -Wextra -Weffc++ -c CircularBuffer/CircularBuffer.cpp

AverageFilter.o: AverageFilter.cpp AverageFilter.h
	g++ -ansi -pedantic -Wall -Wextra -Weffc++ -c AverageFilter.cpp
	
clean:
	rm -f *.o
	
cleanAll:
	rm -f *.o *.exe
	