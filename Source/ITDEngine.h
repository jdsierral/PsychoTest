/*
  ==============================================================================

    ITDEngine.h
    Created: 26 Feb 2017 9:31:19pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef ITDENGINE_H_INCLUDED
#define ITDENGINE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class ITD{
public:
	enum dir {
		left = 0,
		right,
		center
	};
	
	void init(int bufferSize);
	void setITD(int samples, dir newDirection);
	void clearITD();
	void getNextAudioBlock (AudioSampleBuffer& buffer);
	
	int getdly();

	
private:
	int dlyL, dlyR;
	int drp, dwp;
	int dlyBufSize;
	dir direction;
	
	const float* dlyRd;
	float* dlyWt;
	
	AudioSampleBuffer dlyBuffer;
};



#endif  // ITDENGINE_H_INCLUDED
