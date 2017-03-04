/*
  ==============================================================================

    SpeakerSelector.h
    Created: 3 Mar 2017 1:28:02pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SPEAKERSELECTOR_H_INCLUDED
#define SPEAKERSELECTOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class SpeakerSelector
{
public:
	
	SpeakerSelector();
	
	enum speakerSet {
		rearLeft = -3,
		left,
		frontLeft,
		front,
		frontRight,
		right,
		rearRight,
		rear
	};
	
	void process(const AudioSourceChannelInfo& bufferToFill);
	
	void setSpeakerSet (int newSpeakerSet);
	void nextSpeakerSet ();
	void nextHalfSpeakerSet ();
	int getSpeakerSet ();
	
private:
	
	int spkrSet;
	int leftDest;
	int rightDest;
};
#endif  // SPEAKERSELECTOR_H_INCLUDED
