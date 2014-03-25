#ifndef AVERAGEFILTER_H
#define AVERAGEFILTER_H

#include <iostream>
#include <string>
#include <stdlib.h> //malloc

#include "CircularBuffer/CircularBuffer.h"


template <typename T>  
class AverageFilter
{
	private:
	CircularBuffer<T> * cb;
	double sum;
	double average;
	double newValue;

	public:
	explicit AverageFilter(unsigned int size);
	T write(T element);
	T read() const;
	T read(unsigned int index) const;
	
	T getAverage() const {return average;};
	T getSum() const {return sum;};
	unsigned int getSize() const {return cb->getSize();};
	unsigned int getCount() const {return cb->getCount();};
};

#endif //#ifndef AVERAGEFILTER_H