/*
  ==============================================================================

    AudioPlayer.h
    Created: 26 Feb 2017 11:58:06pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef AUDIOPLAYER_H_INCLUDED
#define AUDIOPLAYER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "ITDEngine.h"
#include "ILDEngine.h"
#include "OscGen.h"

class AudioPlayer		:	public AudioSource
{
public:
	
	enum testType {
		LD = 0,
		TD
	};
	
	enum states {
		playRef = 0,
		stop1,
		playTest,
		stop2,
		
		totalStates
	};
	
	enum dir {
		left = -1,
		center = 0,
		right = 1
	};
	
	AudioPlayer();
	~AudioPlayer();
	void prepareToPlay (int samplesPerBlock, double sampleRate) override;
	void releaseResources() override;
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
	
	
	
	void setState (int newState);
	void nextSate ();
	
	void setTest (bool newTest);
	
	void setDelayInSamples (int delayInSamples);
	void setDelayInSeconds (float dleayInSeconds);
	void setGainInAmplitude (float gainInAmplitude);
	void setGainInDecibels (float gainInDecibels);
	void setDirection (int newDirection);
	
	
	
	int getState ();
	bool getTest ();
	int getDelayInSamples ();
	float getDelayInSeconds ();
	float getGainInAmplitude ();
	float getGainInDecibels ();
	int getDirection();
	

private:
	ScopedPointer<ITD> delay;
	ScopedPointer<ILD> gains;
	ScopedPointer<Gen> source;
	
	bool testType; // use 0 for ILD and 1 for ITD
	int direction;
	int state;
	double fs;
	
};


#endif  // AUDIOPLAYER_H_INCLUDED
