/*
 ==============================================================================
 
 ILDEngine.cpp
 Created: 26 Feb 2017 9:31:26pm
 Author:  Juan David Sierra
 
 ==============================================================================
 */

#include "ILDEngine.h"


ILD::ILD() : gainL(1), gainR(1), direction(center) {
	baseGain = sqrt(0.5);
}

ILD::~ILD(){
}

void ILD::setILD(float p, int newDirection){
	p = jlimit<float>(0, 1, p);
	
	direction = newDirection;
	if (direction == left) {
		gainL = sqrt(1-p);
		gainR = sqrt(p);
	} else if (direction == right) {
		gainR = sqrt(1-p);
		gainL = sqrt(p);
	} else if (direction == center) {
		gainL = gainR = 1;
	}
	DBG(gainL);
	DBG(gainR);
}

void ILD::clearILD(){
	direction = center;
	gainL = gainR = 1;
}

float ILD::getGainDelta() {
	return fabs(gainL - gainR);
}

float ILD::getdBDelta() {
	return 20 * log10(gainL/gainR);
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

// ========================================================= //
