#include "AverageFilter.h"

using namespace std;

template <typename T> 
AverageFilter<T>::AverageFilter(unsigned int pSize) : sum(0), average(0), newValue(0)
{
	cb = new CircularBuffer<T>(pSize);
}

template <typename T> 
T AverageFilter<T>::write(T newValue)
{
	if(cb->isFull())
		sum -= cb->getOldestElement();
		
  cb->write(newValue);
  
  sum += cb->getNewestElement();

  average = sum / cb->getSize();

  return average;
}

template <typename T> 
T AverageFilter<T>::read() const 
{
	return cb->getOldestElement();
}

template <typename T> 
T AverageFilter<T>::read(unsigned int index) const
{
	return cb->read(index);
}

// Force the compiler to genrerate the code for those type.
// Avoid linking problems.
// If you need an other type, just copy/paste at the end
// @see http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class AverageFilter<char>;
template class AverageFilter<int>;
template class AverageFilter<unsigned int>;
template class AverageFilter<double>;