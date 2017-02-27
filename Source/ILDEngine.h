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
		left = 0,
		right,
		center
	};
	
	void setILD(float gain, dir newDirection);
	void clearILD();
	void getNextAudioBlock (AudioSampleBuffer& buffer);
	
	float getLevel();

private:
	float gainL;
	float gainR;
	dir direction;
};




#endif  // ILDENGINE_H_INCLUDED
