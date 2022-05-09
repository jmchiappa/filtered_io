#include "filtered_io.h"

#ifdef DEBUG
#		define DEBUG_PRINTLN(a,b)	{Serial.print(a);Serial.println(b);}
#		define DEBUG_BEGIN	{Serial.begin(115200);}
#else
#		define DEBUG_BEGIN
#		define DEBUG_PRINTLN
#endif

FilteredInput::FilteredInput(uint8_t pin, uint8_t mode) {
	this->PinNumber = pin;
	this->mode = mode;
}

void FilteredInput::begin(uint32_t DebouncerDelay)
{
	DEBUG_BEGIN;
	this->delay=DebouncerDelay;
	if((mode==INPUT)||(mode==INPUT_PULLUP))	{
		pinMode(this->PinNumber, mode);
	} else {
		pinMode(this->PinNumber, INPUT);
	}

	uint8_t currentState = digitalRead(this->PinNumber);
	t0=0;
	DEBUG_PRINTLN("demarrage, pin : ",this->PinNumber);
	DEBUG_PRINTLN("delai : ",this->delay);
	DEBUG_PRINTLN("etat courant : ",currentState);
}

/* Return true if an expected transition occurs
*/
uint8_t FilteredInput::filteredValue(void)
{
	uint8_t state = digitalRead(this->PinNumber);
	if(t0==0){
		if(state != currentState){
			newPotentialState = state;
			t0=millis();
			DEBUG_PRINTLN("nouvel etat possible : ",newPotentialState);
		}		
	}else{
		if( (millis()-t0)>delay ) {
			if(state==newPotentialState) {
				DEBUG_PRINTLN("nouvel etat confirmé : ",newPotentialState);
				currentState = state;
			}
			t0=0;
		}
	}

	return currentState; // no change
}