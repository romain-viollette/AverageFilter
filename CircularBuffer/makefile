SHELL=C:/Windows/System32/cmd.exe

all: main

main: CircularBuffer.o main.cpp
	g++ -W -Wall -c main.cpp
	g++ -W -Wall CircularBuffer.o main.o -o main.exe
	
circularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	g++ -W -Wall -c CircularBuffer.cpp
	
clean:
	rm -f *.o
	
cleanAll:
	rm -f *.o *.exe
	