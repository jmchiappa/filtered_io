/*********************************************************************
	Bistable library

	Author : Jean-Marc Chiappa
	Date   : 30.10.2018
	Rev : 1
	
	*******************************************************************/

#ifndef FILTERED_IO_H
#define FILTERED_IO_H

#include "Arduino.h"


class FilteredInput
{
	public:
		FilteredInput(uint8_t pin,uint8_t mode);
		void begin(uint32_t _DebouncerDelay=50);
		uint8_t filteredValue();
	private:
		uint8_t PinNumber;
		uint8_t mode;
		uint8_t newPotentialState;
		uint8_t currentState;
		uint64_t t0;
		uint32_t debouncerDelay=50; //ms
};

#endif // FILTERED_IO_H