#include "maximilian.h"

maxiOsc myCounter,mySwitchableOsc;//
int CurrentCount;//
double myOscOutput,myCurrentVolume;//
double myEnvelopeData[4] = {1,0,0,500};//this data will be used to make an envelope. Value and time to value in ms.
maxiEnvelope myEnvelope;


void setup() {//some inits
	myEnvelope.amplitude=myEnvelopeData[0]; //initialise the envelope
}

void play(double *output) {
	
	myCurrentVolume=myEnvelope.line(4,myEnvelopeData);
	
	CurrentCount=myCounter.phasor(1, 1, 9);//phasor can take three arguments; frequency, start value and end value.
	
	if (CurrentCount<5)//simple if statement
		
		myOscOutput=mySwitchableOsc.square(CurrentCount*100);
	
	else if (CurrentCount>=5)//and the 'else' bit.
		
		myOscOutput=mySwitchableOsc.sinewave(CurrentCount*50);//one osc object can produce whichever waveform you want. 
	
	if (CurrentCount==1) 
		
		myEnvelope.trigger(0,myEnvelopeData[0]); //trigger the envelope
	
	*output=myOscOutput*myCurrentVolume;//point me at your speakers and fire.
}
