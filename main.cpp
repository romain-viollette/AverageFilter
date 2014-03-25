#include <iostream>
#include "AverageFilter.h"
using namespace std;


//Define here the size of the buffer, aka the number of stored datas.
#define BUFFERSIZE 10

//Define here what data type you want to use. 
//Tested for int, unsigned int & double. 
//It can even works with char, if you want to calculate the average of a bunch of letters ~:)
typedef int BufferType; 

void printBuffer(AverageFilter<BufferType> * af)
{
	// To display the result quicker, uncomment the following condition:
	//if(af->getCount()%10!=0 && af->getCount() != BUFFERSIZE-1)
	//	return;
		
	unsigned int i;
	for(i=0; i< af->getSize(); i++)
		cout << af->read(i) << ", "; // here we read the average value calculated by the filter
	cout << endl;
	
	cout <<  "the average is " << af->getAverage() << endl;
	cout << "the sum is " << af->getSum() << endl;
	cout << "the count is " << af->getCount() << endl;
	cout << endl;
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
	cout << "\n\nProgram used to test libraries \"AverageFilter\" and \"CircularBuffer\"." << endl;
	cout << "Developped by Romain VIOLLETTE, romain.viollette@gmail.com \n\n";

	AverageFilter<BufferType> af(BUFFERSIZE);
	
	cout << "- - - - - - - - -\ninit:\n";
	
	printBuffer(&af);
	cout << "- - - - - - - - -\n\n";
	
	unsigned int i;
	for (i=0; i<2*BUFFERSIZE; i++)
	{
		//double var = (double)i + 0.1; // for double
		int    var = (int)i; 			// for int
		//unsigned int var = (unsigned int)i;	// for unsigned int
		//char   var = getAsciiLetters(i);	// for char
		
		cout << "adding: " << var << endl;
		
		af.write(var); // here we add a value in the filter
		
		printBuffer(&af);
	}

	return 0;
}