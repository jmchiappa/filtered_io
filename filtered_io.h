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
		Bistable(uint8_t pin);
		void begin(uint32_t DebouncerDelay=50);
		bool filteredValue();
	private:
		uint8_t PinNumber;
		uint8_t mode;
		uint8_t newPotentialState;
		uint8_t currentState;
		uint64_t t0;
		uint32_t delay=50; //ms
	    bool Update=false;
};

#endif // FILTERED_IO_H