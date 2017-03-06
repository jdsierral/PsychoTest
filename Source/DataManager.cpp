/*
  ==============================================================================

    DataManager.cpp
    Created: 6 Mar 2017 12:50:00pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "DataManager.h"

DataManager::DataManager(String newUser) : trialNumber(1), user(newUser) {
	
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


void DataManager::writeTrial() {
	String sep = ",\t";
	String ln = user + sep +
				testType + sep +
				position + sep +
				(String)trialNumber + sep +
				correctAns + sep +
				answer + sep +
				qualifierToString(answrQualifier) + sep +
				(String)value + sep +
				(String)reversal + "\n";
	std::cout<<ln;
}
