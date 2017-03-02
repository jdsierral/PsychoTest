/*
 ==============================================================================
 
 ILDEngine.cpp
 Created: 26 Feb 2017 9:31:26pm
 Author:  Juan David Sierra
 
 ==============================================================================
 */

#include "ILDEngine.h"


ILD::ILD() : gainL(1), gainR(1), direction(center) {
}

ILD::~ILD(){
}

void ILD::setILD(float gain, int newDirection){
	direction = newDirection;
	if (direction == left) {
		gainL = 1;
		gainR = gain;
	} else if (direction == right) {
		gainR = 1;
		gainL = gain;
	} else if (direction == center) {
		gainL = gainR = 1;
	}
}

void ILD::clearILD(){
	direction = center;
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
