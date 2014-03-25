#include <iostream>
#include "CircularBuffer.h"

using namespace std;

#define BUFFERSIZE 20

typedef double BufferType; //tested for char, int, unsigned int & double.


void printBuffer(CircularBuffer<BufferType> cb)
{
		unsigned int i;
		for(i=0; i< cb.getSize(); i++)
			cout << cb.read(i) << ", ";
		cout << "\n\n";
}

char getAsciiLetters(unsigned int index)
{
	index %= 26*2;
	if(index < 26)
		return 'A'+index;
	else
		return 'a'+index-26;
}

int main()
{
	CircularBuffer<BufferType> cb(BUFFERSIZE);
	
	printBuffer(cb);
	
	unsigned int i;
	for (i=0; i<3*BUFFERSIZE; i++)
	{
		//cb.write(getAsciiLetters(i));  //for char
		//cb.write(i);	//for int
		cb.write((double)i + 0.3);	//for double
		printBuffer(cb);
	}

	return 0;
}