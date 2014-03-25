SHELL=C:/Windows/System32/cmd.exe

all: main
	
main: CircularBuffer.o AverageFilter.o main.cpp
	g++ -W -Wall -c main.cpp
	g++ -W -Wall CircularBuffer.o AverageFilter.o main.o -o main.exe
	
CircularBuffer.o: CircularBuffer/CircularBuffer.cpp CircularBuffer/CircularBuffer.h
	g++ -W -Wall -c CircularBuffer/CircularBuffer.cpp

AverageFilter.o: AverageFilter.cpp AverageFilter.h
	g++ -W -Wall -c AverageFilter.cpp
	
clean:
	rm -f *.o
	
cleanAll:
	rm -f *.o *.exe
	