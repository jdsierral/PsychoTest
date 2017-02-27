/*
 ==============================================================================
 
 AudioPlayer.cpp
 Created: 26 Feb 2017 11:58:06pm
 Author:  Juan David Sierra
 
 ==============================================================================
 */

#include "AudioPlayer.h"




AudioPlayer::AudioPlayer(){
	delay = new ITD();
	gains = new ILD();
	source = new Gen();
}

AudioPlayer::~AudioPlayer(){
}

void AudioPlayer::prepareToPlay (int samplesPerBlock, double sampleRate){
	delay->init(samplesPerBlock);
	gains->clearILD();
}

void AudioPlayer::releaseResources(){
}

void AudioPlayer::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill){
	if (state != stop) {
		source->getNextAudioBlock(*bufferToFill.buffer); // This is probably going to be wrong :/
		if (state == states::playRef) {
			if (testType == test::TD) {
				delay->getNextAudioBlock(*bufferToFill.buffer);
			} else if (testType == test::LD) {
				gains->getNextAudioBlock(*bufferToFill.buffer);
			}
		}
	} else {
		bufferToFill.buffer->clear();
	}
}





void AudioPlayer::setState (states newState){
	state = newState;
}

void AudioPlayer::setTest (test newTest){
	testType = newTest;
}
void AudioPlayer::setDelayInSamples (float delayInSamples){
	delay->setITD(delayInSamples, ITD::left);
}
void AudioPlayer::setDelayInSeconds (float delayInSeconds){
	// do some transformation to get samples
	float delayInSamples = delayInSeconds;
	delay->setITD(delayInSamples, ITD::left);
}

void AudioPlayer::setGainInAmplitude (float gainInAmplitude){
	gains->setILD(gainInAmplitude, ILD::left);
}
void AudioPlayer::setGainInDecibels (float gainInDecibels){
	float gainInAmplitude = Decibels::decibelsToGain(gainInDecibels);
	gains->setILD(gainInAmplitude, ILD::left);
}





AudioPlayer::states AudioPlayer::getState (){
	return state;
}
AudioPlayer::test AudioPlayer::getTest (){
	return testType;
}

float AudioPlayer::getDelayInSamples (){
	return delay->getdly();
}

float AudioPlayer::getDelayInSeconds (){
	// Do some conversion to return seconds
	return delay->getdly();
}
float AudioPlayer::getGainInAmplitude (){
	return gains->getLevel();
}

float AudioPlayer::getGainInDecibels (){
	return Decibels::gainToDecibels(gains->getLevel());
}

