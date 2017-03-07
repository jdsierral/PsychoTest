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
	~SpeakerSelector();
	
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
	
	/**
	 call to process audio
	 */
	void process (const AudioSourceChannelInfo& bufferToFill);
	
	/**
	 set Speaker set, check confiuration to be sure
	 follos enum in class delcaration
	 */
	void setSpeakerSet (int newSpeakerSet);
	
	/**
	 iterator to go to next speaker set moves arroud
 	 */
	void nextSpeakerSet ();
	
	/**
	 iterator trough half of the circle, just to use half the speakers
	 */
	void nextHalfSpeakerSet ();
	
	/**
	 get value of speaker set following
	 */
	int getSpeakerSet ();
	
private:
	
	int spkrSet;
	int leftDest;
	int rightDest;
};
#endif  // SPEAKERSELECTOR_H_INCLUDED
