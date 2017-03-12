/*
  ==============================================================================

    ILDEngine.h
    Created: 26 Feb 2017 9:31:26pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef ILDENGINE_H_INCLUDED
#define ILDENGINE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class ILD {
public:
	
	enum dir {
		left = -1,
		center = 0,
		right = 1
	};
	
	ILD();
	~ILD();
	
	void setILD(float p, int newDirection);
	void clearILD();
	void getNextAudioBlock (AudioSampleBuffer& buffer);
	
	float getGainDelta();
	float getdBDelta();

private:
	
	float gainL;
	float gainR;
	int direction; // use -1 for left 0 for center 1 for right;
	float baseGain;
};




#endif  // ILDENGINE_H_INCLUDED
