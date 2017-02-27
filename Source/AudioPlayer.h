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
	
	enum test {
		TD = 0,
		LD,
		bypass
	};
	
	enum states {
		playRef,
		playTest,
		stop
	};
	
	AudioPlayer();
	~AudioPlayer();
	void prepareToPlay (int samplesPerBlock, double sampleRate) override;
	void releaseResources() override;
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
	
	
	
	void setState (states newState);
	void setTest (test newTest);
	void setDelayInSamples (float delayInSamples);
	void setDelayInSeconds (float dleayInSeconds);
	void setGainInAmplitude (float gainInAmplitude);
	void setGainInDecibels (float gainInDecibels);
	
	
	
	states getState ();
	test getTest ();
	float getDelayInSamples ();
	float getDelayInSeconds ();
	float getGainInAmplitude ();
	float getGainInDecibels ();
	

private:
	ScopedPointer<ITD> delay;
	ScopedPointer<ILD> gains;
	ScopedPointer<Gen> source;
	
	test testType;
	states state;
	
	
};


#endif  // AUDIOPLAYER_H_INCLUDED
