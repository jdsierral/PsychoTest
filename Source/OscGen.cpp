/*
  ==============================================================================

    OscGen.cpp
    Created: 26 Feb 2017 9:30:57pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "OscGen.h"

Gen::Gen() : b0(0), b1(0), b2(0), white(0){
}

Gen::~Gen() {
	
}


void Gen::getNextAudioBlock (AudioSampleBuffer& buffer) {
	float* wtPtr = buffer.getWritePointer(0);
	int bufSize = buffer.getNumSamples();
	
	for (int n = 0; n < bufSize; n++) {
		white = random.nextFloat() * 2 - 1;
		b0 = 0.99765 * b0 + white * 0.0990460;
		b1 = 0.96300 * b1 + white * 0.2965164;
		b2 = 0.57000 * b2 + white * 1.0526913;
		wtPtr[n] = b0 + b1 + b2 + white * 0.1848;
	}
}
