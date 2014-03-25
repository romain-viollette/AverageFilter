#include "CircularBuffer.h"

using namespace std;

template <typename T> 
CircularBuffer<T>::CircularBuffer(unsigned int pSize) : size(pSize), full(0), first(0), count(0), elements(NULL)
{
	if(pSize<=0)
	{
		if(PRINT_ERROR) cout << "Error: the buffer length could not be less than 1 element.\n";
		exit(-1); //return 0;
	}
	elements = reinterpret_cast<T*>(malloc(size * sizeof(T)));
	if (elements == NULL)
	{
		if(PRINT_ERROR) cout << "Error: Out of memory when allocating circularBuffer\n";
		exit(-1); //return 0;
	}
}

template <typename T> 
unsigned int CircularBuffer<T>::isFull()
{
    return full;
}

template <typename T> 
unsigned int CircularBuffer<T>::isEmpty ()
{
    return count == 0;
}

template <typename T> 
unsigned int CircularBuffer<T>::getNewestElementIndex()
{
	return first;
}

template <typename T> 
unsigned int CircularBuffer<T>::getOldestElementIndex()
{
	if(isFull())
		if(first < size -1)
			return first+1; // the position just after the last added element in the array
		else
			return 0; // beggining of the array
	else
		return 0; // beggining of the array
}
 
template <typename T> 
void CircularBuffer<T>::write(T element)
{		
		if(count > 0) 
			first++;
		if(first >= size)
			first = 0;
			
        elements[first] = element;
		
		count++;
		
		if(!isFull() && count >= getSize())
			full = 1;
		

		//cout << "Added "<< element << " at position " << first << ", count " << count << "\n";
}

template <typename T> 
T CircularBuffer<T>::read()
{
	return read(getOldestElementIndex());
}

template <typename T> 
T CircularBuffer<T>::read(unsigned int pos)
{
	if(pos > size)
		{
			if(PRINT_ERROR) cout << "Error: stack overflow in circularBuffer\n";
			exit(-1); //return 0;
		}
	if(!isFull() && pos >= count)
		return 0;
		
	return elements[pos];
}
 
template <typename T> 
T CircularBuffer<T>::getNewestElement()
{
	return read(getNewestElementIndex());
}
 
template <typename T> 
T CircularBuffer<T>::getOldestElement()
{
	return read(getOldestElementIndex());
}


// Force the compiler to genrerate the code for those type.
// Avoid linking problems.
// If you need an other type, just copy/paste at the end
// @see http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class CircularBuffer<char>;
template class CircularBuffer<int>;
template class CircularBuffer<unsigned int>;
template class CircularBuffer<double>;
