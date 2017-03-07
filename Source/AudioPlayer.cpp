/*
 ==============================================================================
 
 AudioPlayer.cpp
 Created: 26 Feb 2017 11:58:06pm
 Author:  Juan David Sierra
 
 ==============================================================================
 */

#include "AudioPlayer.h"




AudioPlayer::AudioPlayer() : testType(LD), state(stop2) {
	delay = new ITD();
	gains = new ILD();
	source = new Gen();
}

AudioPlayer::~AudioPlayer(){
}

void AudioPlayer::prepareToPlay (int samplesPerBlock, double sampleRate){
	fs = sampleRate;
	delay->init(samplesPerBlock);
	gains->clearILD();
}

void AudioPlayer::releaseResources(){
}

void AudioPlayer::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill){
	AudioSampleBuffer* buffer = bufferToFill.buffer;
	
	if (state == stop1 || state == stop2) {
		buffer->clear();
		return;
	}
	
	source->getNextAudioBlock(*buffer);
	int bufSize = buffer->getNumSamples();
	buffer->copyFrom(1, 0, *buffer, 0, 0, bufSize);
	
	if (state == playTest) {
		if (testType == LD) {
			gains->getNextAudioBlock(*buffer);
		} else if (testType == TD) {
			delay->getNextAudioBlock(*buffer);
		}
	}
}





void AudioPlayer::setState (int newState){
	state = newState;
}

void AudioPlayer::nextSate () {
	++state %= totalStates;
}

void AudioPlayer::setTest (bool isITD){
	testType = isITD;
}

void AudioPlayer::setDelayInSamples (int delayInSamples){
	delay->setITD(delayInSamples, direction);
}
void AudioPlayer::setDelayInSeconds (float delayInSeconds){
	float delayInSamples = delayInSeconds * fs;
	delay->setITD(delayInSamples, direction);
}

void AudioPlayer::setGainInAmplitude (float gainInAmplitude){
	gains->setILD(gainInAmplitude, direction);
}
void AudioPlayer::setGainInDecibels (float gainInDecibels){
	float gainInAmplitude = Decibels::decibelsToGain(gainInDecibels);
	gains->setILD(gainInAmplitude, direction);
}

void AudioPlayer::setDirection (int newDirection) {
	direction = newDirection;
	setDelayInSamples(getDelayInSamples());
	setGainInAmplitude(getGainInAmplitude());
}


int AudioPlayer::getState (){
	return state;
}
bool AudioPlayer::getTest (){
	return testType;
}

int AudioPlayer::getDelayInSamples (){
	return delay->getdly();
}

float AudioPlayer::getDelayInSeconds (){
	return delay->getdly()/fs;
}
float AudioPlayer::getGainInAmplitude (){
	return gains->getLevel();
}

float AudioPlayer::getGainInDecibels (){
	return Decibels::gainToDecibels(gains->getLevel());
}

