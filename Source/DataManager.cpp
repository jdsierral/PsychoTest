/*
  ==============================================================================

    DataManager.cpp
    Created: 6 Mar 2017 12:50:00pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "DataManager.h"

DataManager::DataManager(String newUser) : trialNumber(1), reversal(0), user(newUser) {
	const String fileName = "~/Desktop/PsychoTestFiles/" + user + ".csv";
	const File* file = new File(fileName);
	fos = new FileOutputStream(*file);
	
	assert(fos->openedOk());
	
	if (fos->getPosition() == 0) {
		String sep = ",";
		String s = "user" + sep +
		"testType" + sep +
		"position" + sep +
		"trialNumber" + sep +
		"correctAnswer" + sep +
		"userAnswer" + sep +
		"ansQualifier" + sep +
		"value" + sep +
		"reversal" + "\n";
		fos->writeText(s, false, false);
	}
}

DataManager::~DataManager() {
	// Handle File closing;
}

void DataManager::setTestType(int newTestType) {
	testType = (newTestType? "ITD" : "ILD");
}

void DataManager::setPosition(int newPos) {
	String s;
	switch (newPos) {
		case backLeft:
			s = "Back Left";
			break;
		case left:
			s = "Left";
			break;
		case frontLeft:
			s = "Front Right";
			break;
		case front:
			s = "Front";
			break;
		case frontRight:
			s = "Front Right";
			break;
		case right:
			s = "Right";
			break;
		case backRight:
			s = "Back Right";
			break;
		case back:
			s = "Back";
			break;
		default:
			break;
	}
	position = s;
}

void DataManager::setAnswer(int ans) {
	usrAns = ans;
}

void DataManager::setCorrAns(int ans) {
	corAns = ans;
}

void DataManager::tickReversal() {
	reversal++;
}

void DataManager::computeAnswerData(){
	trialNumber++;
	userAnswer = (usrAns ? "1" : "2");
	correctAnswer = (corAns ? "1" : "2");
	ansQualifier = (usrAns == corAns ? "1" : "0");
}

void DataManager::setValue(double newValue){
	value = newValue;
}



// Private

void DataManager::writeTrial() {
	
	computeAnswerData();
	
	String sep = ",";
	String ln = user + sep +
				testType + sep +
				position + sep +
				(String)trialNumber + sep +
				correctAnswer + sep +
				userAnswer + sep +
				ansQualifier + sep +
				(String)value + sep +
				(String)reversal + "\n";
	
	dumpData(ln);
}

void DataManager::dumpData(String s) {
	fos->writeText(s, false, false);
}

void DataManager::debugWrite() {
	user = "Juan";
	setTestType(LD);
	setPosition(right);
	
	setAnswer(1);
	setCorrAns(2);
	setValue(-3.5);
	
}

