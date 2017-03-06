/*
  ==============================================================================

    DataManager.h
    Created: 6 Mar 2017 12:50:00pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef DATAMANAGER_H_INCLUDED
#define DATAMANAGER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class DataManager {
public:
	
	enum position {
		backLeft = -3,
		left,
		frontLeft,
		front,
		frontRight,
		right,
		backRight,
		back
	};
	
	DataManager(String newUser);
	
	void writeTrial();
	void clearTrial();
	
	void setPosition(int newPos);
	void setAnwser(bool ans);
	void setCorrAns(bool ans);
	
	
private:
	
	String qualifierToString(char c) {
		String b1 = (String)(c & 8? 1 : 0) + ",\t";
		String b2 = (String)(c & 4? 1 : 0) + ",\t";
		String b3 = (String)(c & 2? 1 : 0) + ",\t";
		String b4 = (String)(c & 1? 1 : 0) + ",\t";
		String s = b1 + b2 + b3 + b4;
		return s;
	}
	
	
	double 	value;
	int 	trialNumber;
	int 	reversal;
	char 	answrQualifier;
	String 	user;
	String 	position;
	String 	correctAns;
	String 	answer;
	String  testType;
};


/*
 Create a csv file that contains:
 
Header ==>
User,TestT,Position,Trial,CorrectAns,SubjAns,Positive,FalsePositive,Negative,MissTrial,Value,Reversal
	ITD		front		###	1/2	 	1/2			1        0            0         0		###	 Counter
	IID		frontLeft	###
 			frontRight	###
			Right		###
 			backRight	###
 			back		###
 
 */


#endif  // DATAMANAGER_H_INCLUDED
