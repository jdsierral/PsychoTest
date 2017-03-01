/*
 ==============================================================================
 
 ILDEngine.cpp
 Created: 26 Feb 2017 9:31:26pm
 Author:  Juan David Sierra
 
 ==============================================================================
 */

#include "ILDEngine.h"


void ILD::setILD(float gain, dir newDirection){
	direction = newDirection;
	if (direction == dir::left) {
		gainL = 1;
		gainR = gain;
	} else if (direction == dir::right) {
		gainR = 1;
		gainL = gain;
	} else if (direction == dir::center) {
		gainL = gainR = 1;
	}
}

void ILD::clearILD(){
	direction = dir::center;
	gainL = gainR = 1;
}

float ILD::getLevel() {
	return 1 - fabs(gainL - gainR);
}


void ILD::getNextAudioBlock (AudioSampleBuffer& buffer){
	int bufSize = buffer.getNumSamples();
	const float* dataRd = buffer.getReadPointer(0);
	float* dataWtL = buffer.getWritePointer(0);
	float* dataWtR = buffer.getWritePointer(1);
	
	for (int n = 0; n < bufSize; n++) {
		float sample;
		sample = dataRd[n];
		dataWtL[n] = sample * gainL;
		dataWtR[n] = sample * gainR;
	}
	
}