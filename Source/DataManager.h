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
	
	enum testT {
		LD = 0,
		TD
	};
	
	DataManager (String newUser);
	~DataManager();
	
	void writeTrial ();
	void clearTrial ();
	
	void setTestType (int newTestType);
	void setPosition (int newPos);
	void setAnswer (int ans);
	void setCorrAns (int ans);
	void tickReversal();
	void setValue(double newValue);
	
private:
	
	void computeAnswerData();
	void dumpData(String s);
	void debugWrite();

	double 	value;
	int 	trialNumber;
	int 	reversal;
	
	int 	usrAns;
	int		corAns;
	
	String 	user;
	String 	position;
	String 	userAnswer;
	String 	correctAnswer;
	String  ansQualifier;
	String  testType;
	ScopedPointer<FileOutputStream> fos;
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
