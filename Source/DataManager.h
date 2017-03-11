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
	
	DataManager (String newUser);
	
	void writeTrial ();
	void clearTrial ();
	
	void setTestType (bool newTestType);
	void setPosition (int newPos);
	void setAnswer (bool ans);
	void setCorrAns (bool ans);
	void tickReversal();
	void setValue(double newValue);
	
private:
	
	
	void dumpData(String s) {
		fos->writeText(s, false, false);
	}

	void debugWrite() {
		user = "Juan";
		setTestType(false);
		setPosition(0);
		setAnswer(false);
		setCorrAns(false);
		setValue(-3.5);
		
	}

	ScopedPointer<FileOutputStream> fos;
	
	void computeAnswerData();
	
	double 	value;
	int 	trialNumber;
	int 	reversal;
	
	bool 	usrAns;
	bool	corAns;
	
	String 	user;
	String 	position;
	String 	userAnswer;
	String 	correctAnswer;
	String  ansQualifier;
	String  testType;
};


/*
 Create a csv file that contains:
 
Header ==>
1		1	1
User,TestT,Position,Trial,CorrectAns,SubjAns,Positive,FalsePositive,Negative,MissTrial,Value,Reversal
	ITD		front		###	1/2	 	1/2			1        0            0         0		###	 Counter
	IID		frontLeft	###
 			frontRight	###
			Right		###
 			backRight	###
 			back		###
 
 */


#endif  // DATAMANAGER_H_INCLUDED
