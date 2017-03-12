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
		left = -1,
		center = 0,
		right =1
	};
	
	ITD();
	~ITD();
	
	void init(int bufferSize);
	void setITD(int samples, int newDirection);
	void clearITD();
	void getNextAudioBlock (AudioSampleBuffer& buffer);
	
	int getdly();

	
private:
	int dlyL, dlyR;
	int drp, dwp;
	int dlyBufSize;
	int direction;
	
	const float* dlyRd;
	float* dlyWt;
	
	int MaxBufSize = 1024;
	
	AudioSampleBuffer dlyBuffer;
};



#endif  // ITDENGINE_H_INCLUDED
