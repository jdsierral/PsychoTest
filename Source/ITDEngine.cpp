/*
  ==============================================================================

    ITDEngine.cpp
    Created: 26 Feb 2017 9:31:19pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "ITDEngine.h"

ITD::ITD(){
}

ITD::~ITD(){
}


void ITD::init(int bufferSize){
	dlyBufSize = 2 * bufferSize;
	
	dlyBuffer.setSize(1, dlyBufSize);
	dlyBuffer.clear();
	
	dlyRd = dlyBuffer.getReadPointer(0);
	dlyWt = dlyBuffer.getWritePointer(0);
	
}

void ITD::setITD(int samples, dir newDirection){
	direction = newDirection;
	if (direction == dir::left) {
		dlyL = 0;
		dlyR = samples;
	} else if (direction == dir::right) {
		dlyR = 0;
		dlyL = samples;
	}
	dwp = (drp + samples + dlyBufSize) % dlyBufSize;
}

void ITD::clearITD(){
	direction = center;
	dlyL = dlyR = 0;
	dwp = drp;
}

int ITD::getdly(){
	return abs(dlyL - dlyR);
}


void ITD::getNextAudioBlock (AudioSampleBuffer& buffer) {
	int bufSize = buffer.getNumSamples();
	const float* dataRd = buffer.getReadPointer(0);
	float* dataWtL = buffer.getWritePointer(0);
	float* dataWtR = buffer.getWritePointer(1);
	
	for (int n = 0; n < bufSize; n++) {
		dlyWt[dwp] = dataRd[n];
		if (direction == left) {
			dataWtL[n] = dlyRd[dwp];
			dataWtR[n] = dlyRd[drp];
		} else if (direction == right) {
			dataWtR[n] = dlyRd[dwp];
			dataWtL[n] = dlyRd[drp];
		} else if (direction == center) {
			dataWtL[n] = dataWtR[n] = dlyRd[dwp];
		}
		
		if (++dwp >= dlyBufSize)
			dwp %= dlyBufSize;
		if (++drp >= dlyBufSize)
			drp %= dlyBufSize;
	}
}

