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
	if (fos->getPosition() == 0) {
		String sep = ",\t";
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

void DataManager::setTestType(bool newTestType) {
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

void DataManager::setAnswer(bool ans) {
	usrAns = ans;
}

void DataManager::setCorrAns(bool ans) {
	corAns = ans;
}

void DataManager::tickReversal() {
	reversal++;
}

void DataManager::computeAnswerData(){
	trialNumber++;
	userAnswer = (usrAns ? "1" : "2");
	correctAnswer = (corAns ? "1" : "2");
	
	// Ha I think this doesn't make any sense O.o
	
	if (usrAns == false && corAns == false) {
		ansQualifier = "correct";
	}
	else if (usrAns == false && corAns == true) {
		ansQualifier = "fail";
	}
	else if (usrAns == true && corAns == false) {
		ansQualifier = "fail";
	}
	else if (usrAns == true && corAns == true) {
		ansQualifier = "correct";
	}
	
	
}

void DataManager::setValue(double newValue){
	value = newValue;
}

void DataManager::writeTrial() {
	
	debugWrite();
	
	computeAnswerData();
	
	String sep = ",\t";
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
