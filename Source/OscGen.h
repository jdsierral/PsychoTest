/*
  ==============================================================================

    OscGen.h
    Created: 26 Feb 2017 9:30:57pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef OSCGEN_H_INCLUDED
#define OSCGEN_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class Gen
{
public:
	Gen();
	~Gen();
	void getNextAudioBlock (AudioSampleBuffer& buffer);
private:
	float b0, b1, b2, white;
	Random random;
	
};

#endif  // OSCGEN_H_INCLUDED
