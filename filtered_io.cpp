#include "filtered_io.h"


FilteredInput::FilteredInput(uint8_t pin, uint8_t mode) {
	this->PinNumber = pin;
	this->mode = mode;
}

void FilteredInput::begin(uint64_t DebouncerDelay)
{
	this->delay=DebouncerDelay;
	if((mode==INPUT)||(mode==INPUT_PULLUP))	{
		pinMode(Pin, mode);
	} else {
		pinMode(Pin, INPUT);
	}

	uint8_t currentState = digitalRead(this->PinNumber);
	t0=0;
}

/* Return true if an expected transition occurs
*/
bool FilteredInput::filteredValue(void)
{
	uint8_t state = digitalRead(this->PinNumber);
	if(state != currentState){
		newPotentialState = state;
		t0=millis();
	}
	if((millis()-t0)>delay) {
		if(state==newPotentialState) {
			currentState = state;
		}
		t0=millis();
	}

	//Last_input_state = state;
//	Serial.println();
	Update=true;
	return ret; // no change
}