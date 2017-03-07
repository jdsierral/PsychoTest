/*
  ==============================================================================

    SpeakerSelector.cpp
    Created: 3 Mar 2017 1:28:02pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "SpeakerSelector.h"

SpeakerSelector::SpeakerSelector () : spkrSet(0){
	setSpeakerSet(spkrSet);
}

SpeakerSelector::~SpeakerSelector () {

}

void SpeakerSelector::process (const AudioSourceChannelInfo& bufferToFill) {
	int bufSize = bufferToFill.buffer->getNumSamples();
	if (spkrSet != 0) {
		bufferToFill.buffer->copyFrom(leftDest - 1, 0, *bufferToFill.buffer, 0, 0, bufSize);
		bufferToFill.buffer->copyFrom(rightDest - 1, 0, *bufferToFill.buffer, 1, 0, bufSize);
	}
}

void SpeakerSelector::setSpeakerSet (int newSpeakerSet) {
	spkrSet = newSpeakerSet;
	switch (spkrSet) {
		case rearLeft:
			// Assign to 7 and 5
			leftDest = 7;
			rightDest = 5;
			break;
		case left:
			// Assign to 5 and 3
			leftDest = 5;
			rightDest = 3;
			break;
		case frontLeft:
			// Assign to 3 and 1
			leftDest = 3;
			rightDest = 1;
			break;
		case front:
			// Assign to 1 and 2
			leftDest = 1;
			rightDest = 2;
			break;
		case frontRight:
			// Assign to 2 and 4
			leftDest = 2;
			rightDest = 4;
			break;
		case right:
			// Assign to 4 and 6
			leftDest = 4;
			rightDest = 6;
			break;
		case rearRight:
			// Assign to 6 and 8
			leftDest = 6;
			rightDest = 8;
			break;
		case rear:
			// Assign to 8 and 7
			leftDest = 8;
			rightDest = 7;
			break;
		default:
			break;
	}
}

void SpeakerSelector::nextSpeakerSet () {
	setSpeakerSet(((getSpeakerSet() + 1) + 3) % 8 - 3);
	
}

void SpeakerSelector::nextHalfSpeakerSet () {
	setSpeakerSet((getSpeakerSet()+1)%4);
}

int SpeakerSelector::getSpeakerSet () {
	return spkrSet;
}

