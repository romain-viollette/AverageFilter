/* Circular Buffer implementing a queue */

#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <iostream>
#include <string>
#include <stdlib.h> //malloc

#define PRINT_ERROR 1

template <typename T>  
class CircularBuffer
{
	
	private:
	unsigned int size;
	unsigned int full;
	unsigned int first;  // position of first element
	//int end;  // position of last element
	/* Tracking start and end of buffer would waste
	 * one position. A full buffer would always have
	 * to leave last position empty or otherwise
	 * it would look empty. Instead this buffer uses
	 * count to track if buffer is empty or full
	 */
	unsigned int count; // number of elements in buffer
	T *elements;
	
	
	public:
	explicit CircularBuffer(unsigned int);
	void write(T element);
	T read();
	T read(unsigned int pos);
	unsigned int isEmpty();
	unsigned int isFull();
	unsigned int getSize()const {return size;};
	unsigned int getCount()const {return count;};
	unsigned int getNewestElementIndex();
	unsigned int getOldestElementIndex();
	T getNewestElement();
	T getOldestElement();
	
};

#endif //ifndef CIRCULARBUFFER_H