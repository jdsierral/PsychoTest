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

	
	/**
	 Initializes the AudioPlayer, Initilizes ITD, ILD and Gen engines
	 */
	AudioPlayer();
	
	/**
	 Not really necessary, just in case
	 */
	~AudioPlayer();
	
	/**
	 Call this function before starting the audio stream to setup everything inside the class to match the sampleRate and estimated bufferSize
	 */
	void prepareToPlay (int samplesPerBlock, double sampleRate) override;
	
	/**
	 Call this to release resources
	 */
	void releaseResources() override;
	/**
	 Call this to process audio, pass buffer to fill
	 */
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
	
	
	/**
	 select state, they will follow the state enum being 0 play ref, 1 and 3 stop and 3 playTest. Use next State to iterate freely
	 */
	void setState (int newState);
	
	/**
	 call to next state to iterate
	 */
	void nextSate ();
	
	/**
	 Sets ITD or IID; let ITD be true
	 */
	void setTest (bool isITD);
	
	/**
	 set current delay in samples
	 */
	void setDelayInSamples (int delayInSamples);
	
	/**
	 sets current delay in samples to seconds, be sure to call this after prepare to play
	 */
	void setDelayInSeconds (float dleayInSeconds);
	
	/**
	 sets ampliutde relation in absolute Amplitude
	 */
	void setGainInAmplitude (float gainInAmplitude);
	
	/**
	 sets amplitude relation in dB
	 */
	void setGainInDecibels (float gainInDecibels);
	
	/**
	 set lateral direction for ITD or IID
	 */
	void setDirection (int newDirection);
	
	
	/**
	 getState as an Int => follows enum
	 */
	int getState ();
	
	/**
	 getTest as a bool ==> follows enum
	 */
	bool getTest ();
	
	/**
	 get Delay value in samples
	 */
	int getDelayInSamples ();
	
	/**
	 get Delay in seconds make sure to call after prepare to Play
	 */
	float getDelayInSeconds ();
	
	/**
	 get Amplitude relation in absolute gain
	 */
	float getGainInAmplitude ();
	
	/**
	 get amplitude realtion in dB
	 */
	float getGainInDecibels ();
	
	/**
	 get Direction as int ==> follows 
	 	-1 = left; 
	 	0 = center; 
	 	1 = right
	 */
	int getDirection();
	

private:
	ScopedPointer<ITD> delay;
	ScopedPointer<ILD> gains;
	ScopedPointer<Gen> source;
	
	bool testType; // use 0 for ILD and 1 for ITD
	int direction;
	int state;
	double fs;
	float baseGain = sqrt(0.5f);
};


#endif  // AUDIOPLAYER_H_INCLUDED
