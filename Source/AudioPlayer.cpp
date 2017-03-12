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
	buffer->applyGain(baseGain);
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

void AudioPlayer::setGainDeltaInAmplitude (float gainDeltaInAmplitude){
	
	float p = getPFromAmplitude(gainDeltaInAmplitude);
	gains->setILD(p, direction);
}
void AudioPlayer::setGainDeltaInDecibels (float gainDeltaIndB){
	
	float p = getPFromdB(gainDeltaIndB);
	gains->setILD(p, direction);
}

void AudioPlayer::setDirection (int newDirection) {
	direction = newDirection;
//	setDelayInSamples(getDelayInSamples());
//	setGainInAmplitude(getGainInAmplitude());
}


float AudioPlayer::getPFromAmplitude(float x) {
	return 0.5 * (1 - sqrt(2 * pow(x, 2) - pow(x, 4)));
}

float AudioPlayer::getPFromdB(float x) {
	float b = powf(10, 2 * x / 20.f);
	return b/(1+b);
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
	return gains->getGainDelta();
}

float AudioPlayer::getGainInDecibels (){
	return gains->getdBDelta();
}

