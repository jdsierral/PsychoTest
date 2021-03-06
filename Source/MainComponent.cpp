#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "GUI.h"
#include "AudioPlayer.h"
#include "SpeakerSelector.h"
#include "DataManager.h"

//============================================================================//
class MainContentComponent   : 	public AudioAppComponent,
							   	public ButtonListener,
								public SliderListener,
								public ComboBoxListener,
								public TextEditor::Listener,
                                public Timer
{
public:
//============================================================================//
	MainContentComponent()
	{
		
		setAudioChannels (0, 8);
		deviceManager.getCurrentAudioDevice();
		AudioDeviceManager::AudioDeviceSetup result;
		deviceManager.getAudioDeviceSetup(result);
		result.sampleRate = 192000;
		result.bufferSize = 1024;
		deviceManager.setAudioDeviceSetup(result, true);
		
        
		// ===================== GUI SETUP =============================//
		
		
        
        // ===================== OPTION SCREEN =========================//
		addAndMakeVisible (startButton = new TextButton ("Start Button"));
		startButton->setButtonText (TRANS("start"));
		startButton->addListener (this);
		startButton->setEnabled(false);
		
        addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
        textEditor->setMultiLine (true);
        textEditor->setReturnKeyStartsNewLine (true);
        textEditor->setReadOnly (true);
        textEditor->setScrollbarsShown (false);
        textEditor->setCaretVisible (false);
        textEditor->setPopupMenuEnabled (false);
        textEditor->setText (TRANS("Press 1 if the first signal is the leftmost signal, 2 otherwise"));
        
        addAndMakeVisible (userTextBox = new TextEditor ("User TextBox"));
        userTextBox->setMultiLine (false);
        userTextBox->setReturnKeyStartsNewLine (false);
        userTextBox->setEscapeAndReturnKeysConsumed(false);
        userTextBox->setReadOnly (false);
        userTextBox->setScrollbarsShown (true);
        userTextBox->setCaretVisible (true);
        userTextBox->setPopupMenuEnabled (true);
        userTextBox->setText (TRANS("What is your name?"));
        userTextBox->addListener (this);
        
        addAndMakeVisible (ITDButton = new ToggleButton ("ITD Button"));
        ITDButton->setButtonText (TRANS("ITD"));
        ITDButton->setRadioGroupId (1);
        ITDButton->addListener (this);
        ITDButton->setEnabled(false);
        
        addAndMakeVisible (ILDButton = new ToggleButton ("ILD Button"));
        ILDButton->setButtonText (TRANS("ILD"));
        ILDButton->setRadioGroupId (1);
        ILDButton->addListener (this);
        ILDButton->setEnabled(false);

        
        addAndMakeVisible (posBox = new ComboBox ("Position Box"));
        posBox->setEditableText (false);
        posBox->setJustificationType (Justification::centredLeft);
        posBox->setTextWhenNothingSelected (TRANS("Select Position"));
        posBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
        posBox->addItem (TRANS("Front"), 1);
        posBox->addItem (TRANS("Front Lateral"), 2);
        posBox->addItem (TRANS("Lateral"), 3);
        posBox->addItem (TRANS("Rear Lateral"), 4);
        posBox->addItem (TRANS("Rear"), 5);
        posBox->addListener (this);
        posBox->setEnabled(false);
        
        
        // ===================== TRIAL SCREEN =========================//
		addChildComponent(opt1Button = new TextButton ("Opt1 Button"));
		opt1Button->setButtonText (TRANS("1"));
		opt1Button->addListener (this);
        opt1Button->setEnabled(false);
		
		addChildComponent(opt2Button = new TextButton ("Opt2 Button"));
		opt2Button->setButtonText (TRANS("2"));
		opt2Button->addListener (this);
		opt2Button->setEnabled(false);
        

        //===================== HIDDEN GEMS ==========================//
        //  use these to control the audio?
		addChildComponent (playButton = new TextButton ("Play Button"));
		playButton->setButtonText (TRANS("Play"));
		playButton->addListener (this);
		
		addChildComponent (leftButton = new ToggleButton ("Left Button"));
		leftButton->setButtonText (TRANS("left"));
		leftButton->setRadioGroupId (2);
		leftButton->addListener (this);
		
		addChildComponent (rightButton = new ToggleButton ("Right Button"));
		rightButton->setButtonText (TRANS("right"));
		rightButton->setRadioGroupId (2);
		rightButton->addListener (this);
		rightButton->setToggleState (true, dontSendNotification);
		
		addChildComponent (dlySlider = new Slider ("Dly Slider"));
		dlySlider->setRange (0, 20, 0);
		dlySlider->setSliderStyle (Slider::LinearHorizontal);
		dlySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
		dlySlider->addListener (this);
		
		addChildComponent (gainSlider = new Slider ("Gain Slider"));
		gainSlider->setRange (0, 20, 0);
		gainSlider->setSliderStyle (Slider::LinearHorizontal);
		gainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
		gainSlider->addListener (this);
		
		addChildComponent (volSlider = new Slider ("Volume Slider"));
		volSlider->setRange (-60, 0, 0.1);
		volSlider->setSliderStyle (Slider::LinearBar);
		volSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
		volSlider->addListener (this);
		
		
		
		
		addAndMakeVisible (printData = new TextButton ("Print Data"));
		printData->setButtonText (TRANS("Print Data"));
		printData->addListener (this);
		printData->setVisible (false);
		
		addAndMakeVisible (finishTest = new TextButton ("Finish Test"));
		finishTest->setButtonText (TRANS("Finish"));
		finishTest->addListener (this);
		finishTest->setVisible (false);
		
		addAndMakeVisible (testAudioButton = new TextButton ("Test Audio"));
		testAudioButton->setButtonText (TRANS("Test Me!"));
		testAudioButton->addListener (this);
		
		
		
		setSize (600, 400);
		
	}
	
	~MainContentComponent()
	{
		if (dataManager != NULL)
			delete dataManager;

		startButton = nullptr;
		opt1Button = nullptr;
		opt2Button = nullptr;
		textEditor = nullptr;
		ITDButton = nullptr;
		ILDButton = nullptr;
		playButton = nullptr;
		leftButton = nullptr;
		rightButton = nullptr;
		dlySlider = nullptr;
		gainSlider = nullptr;
		posBox = nullptr;
		volSlider = nullptr;
		userTextBox = nullptr;
		
		printData = nullptr;
		finishTest = nullptr;
		
		shutdownAudio();
	}
	
	void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
	{
		audioPlayer.prepareToPlay(samplesPerBlockExpected, sampleRate);
		spkrSel.prepareToPlay(samplesPerBlockExpected, sampleRate);
	}
	
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
	{
		bufferToFill.buffer->clear();
		audioPlayer.getNextAudioBlock(bufferToFill);
		spkrSel.process(bufferToFill);
		bufferToFill.buffer->applyGain(0.5);
	}
	
	void releaseResources() override{}

	void paint (Graphics& g) override
	{
		g.fillAll (Colours::white);
		g.setColour (Colours::black);
		g.setFont (Font (15.00f, Font::plain));
		
	}
	
	void resized() override
	{

		startButton->setBounds (184, 112, 224, 128);
		opt1Button->setBounds (208, 312, 72, 24);
		opt2Button->setBounds (304, 312, 72, 24);
		textEditor->setBounds (200, 24, 192, 80);
		ITDButton->setBounds (8, 216, 80, 24);
		ILDButton->setBounds (8, 272, 80, 24);
		playButton->setBounds (56, 368, 56, 24);
		leftButton->setBounds (8, 320, 48, 24);
		rightButton->setBounds (56, 320, 56, 24);
		dlySlider->setBounds (56, 216, 120, 32);
		gainSlider->setBounds (56, 272, 120, 32);
		posBox->setBounds (216, 352, 150, 24);
		volSlider->setBounds (472, 368, 118, 24);
		userTextBox->setBounds (224, 264, 150, 24);
		testAudioButton->setBounds(450, 200, 80, 40);
		
		printData->setBounds (450, 260, 80, 40);
		finishTest->setBounds (450, 320, 80, 40);
		
	}
    
    
    void timerCallback () override
    {
        if (orderSwitch == 0){
            audioPlayer.nextSate();
        }else {
            audioPlayer.setState(altOrder[i]);
        }
        i++;
        if  (audioPlayer.getState() == 3){
            stopTimer();
            opt1Button->setEnabled(true);
            opt2Button->setEnabled(true);
        }
    }
    
    void initializeVars()
    {
        numReversals = 0;
        corrAnsCounter = 0;
        lastAnswer = NULL;
        audioPlayer.setDirection(-1);
        if (audioPlayer.getTest() == audioPlayer.testType::LD){
			audioPlayer.setGainDeltaInAmplitude(1);
            dataManager->setValue(1);
        }
        if (audioPlayer.getTest() == audioPlayer.testType::TD){
            audioPlayer.setDelayInSamples(100);
            dataManager->setValue(100);
        }
    }
	
    void playSequence()
    {
        i = 0;
        orderSwitch = rand() % 2;
        startTimer(500);
    }
    
    void calculateNext()
    {

        if (currentAnswer == false){
            //check for reversal
            if (lastAnswer == true){
                numReversals++;
                dataManager->tickReversal();
            }
            dataManager->writeTrial();
            setLevels(2);
        } else { // current answer was right, check if the one before was also
            if (lastAnswer == false){
                numReversals++;
                dataManager->tickReversal();
            }
            dataManager->writeTrial();
            if (corrAnsCounter == 2){
                setLevels(.5);
                corrAnsCounter = 0;
            }
        }
        
        if (numReversals == 5){
            returnToStart();
        }
    }
    
    
    void setLevels(float factor)
    {
        if (audioPlayer.getTest() == audioPlayer.testType::LD){
            currentAmplitude = audioPlayer.getGainInAmplitude()*(factor);
            audioPlayer.setGainDeltaInAmplitude(currentAmplitude);
            dataManager->setValue(audioPlayer.getGainInAmplitude());
        } else if (audioPlayer.getTest() == audioPlayer.testType::TD){
            currentDelay = audioPlayer.getDelayInSamples()*(factor);
            audioPlayer.setDelayInSamples(currentDelay);
            dataManager->setValue(audioPlayer.getDelayInSamples());
        }
    }
    
    void doButtonStuff (int ans)
    {
        opt1Button->setEnabled(false);
        opt2Button->setEnabled(false);
        dataManager->setAnswer(ans);
        
        if (orderSwitch == 0){
            dataManager->setCorrAns(2);
            corrAns = 2;
        }else{
            dataManager->setCorrAns(1);
            corrAns = 1;
        }
        
        lastAnswer = currentAnswer;
        
        if (ans == corrAns){
            currentAnswer = true;
            corrAnsCounter++;
        }else{
            currentAnswer = false;
            corrAnsCounter = 0;
        }
        calculateNext();
        if (numReversals != 5){
            playSequence();
        }
    }
    
    
    void returnToStart()
    {
        startButton->setEnabled(false);
        ITDButton->setEnabled(false);
        ILDButton->setEnabled(false);
        posBox->setEnabled(false);
        hideTrialScreen();
        displayOptionScreen();
    }
    
    void hideOptionScreen()
    {
        startButton->setVisible(false);
        textEditor->setVisible(false);
        ITDButton->setVisible(false);
        ILDButton->setVisible(false);
        userTextBox->setVisible(false);
        posBox->setVisible(false);
    }
    
    void displayOptionScreen()
    {
        startButton->setVisible(true);
        textEditor->setVisible(true);
        ITDButton->setVisible(true);
        ILDButton->setVisible(true);
        userTextBox->setVisible(true);
        posBox->setVisible(true);
    }
    
    void hideTrialScreen()
    {
        opt1Button->setVisible(false);
        opt2Button->setVisible(false);
    }
    
    void displayTrialScreen()
    {
        opt1Button->setVisible(true);
        opt2Button->setVisible(true);
    }
    
    
	void buttonClicked (Button* buttonThatWasClicked) override
	{
		if (buttonThatWasClicked == startButton)
		{
            initializeVars();
            hideOptionScreen();
            displayTrialScreen();
            playSequence();
		}
		else if (buttonThatWasClicked == opt1Button)
		{
            doButtonStuff(1);
		}
		else if (buttonThatWasClicked == opt2Button)
		{
            doButtonStuff(2);
		}
		else if (buttonThatWasClicked == ITDButton)
		{
			audioPlayer.setTest(1);
            dataManager->setTestType(1);
		}
		else if (buttonThatWasClicked == ILDButton)
		{
			audioPlayer.setTest(0);
            dataManager->setTestType(0);
		}
		else if (buttonThatWasClicked == playButton)
		{
			audioPlayer.nextSate();
		}
		else if (buttonThatWasClicked == leftButton)
		{
			audioPlayer.setDirection(audioPlayer.dir::left);
		}
		else if (buttonThatWasClicked == rightButton)
		{
			audioPlayer.setDirection(audioPlayer.dir::right);
		}
		else if (buttonThatWasClicked == testAudioButton)
		{
			if(0 != audioPlayer.getState()) {
				audioPlayer.setState(0);
			} else if (0 == audioPlayer.getState()) {
				audioPlayer.setState(1);
			}
		}
		else if (buttonThatWasClicked == printData)
		{
			DBG("CPU Usage: "<<deviceManager.getCpuUsage());
			AudioDeviceManager::AudioDeviceSetup result;
			deviceManager.getAudioDeviceSetup(result);
			DBG("SR: "<<result.sampleRate);
			DBG("BufSize: "<<result.bufferSize);
			
			DBG("AudioPlayerGain: "<<audioPlayer.getGainInAmplitude());
			DBG("AudioPlayerGaindB: "<<audioPlayer.getGainInDecibels());
			DBG("AudioPlayerTime: "<<audioPlayer.getDelayInSamples());
			DBG("AudioPlayerTime(s): "<<audioPlayer.getDelayInSeconds());
		}
		else if (buttonThatWasClicked == finishTest)
		{
			
		}
	}
	
	void sliderValueChanged (Slider* sliderThatWasMoved) override
	{
		if (sliderThatWasMoved == dlySlider)
		{
			audioPlayer.setDelayInSamples(dlySlider->getValue());
		}
		else if (sliderThatWasMoved == gainSlider)
		{
			audioPlayer.setGainDeltaInDecibels(-gainSlider->getValue());
		}
		else if (sliderThatWasMoved == volSlider)
		{
			vol = volSlider->getValue();
		}
	}
	
	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override
	{
		if (comboBoxThatHasChanged == posBox) {
			spkrSel.setSpeakerSet(posBox->getSelectedItemIndex());
            dataManager->setPosition(posBox->getSelectedItemIndex());
		}
		
	}

	void textEditorReturnKeyPressed (TextEditor& textEditorChanged) override {
		startButton->setEnabled(true);
        ITDButton->setEnabled(true);
        ILDButton->setEnabled(true);
        posBox->setEnabled(true);
		String user = userTextBox->getText();
		if (dataManager != NULL) {
			delete dataManager;
		}
		dataManager = new DataManager(user);
	}
	
	
	
private:
	//==============================================================================
	
	//==================  Private Variables  ===================//
	
	float vol;
    float currentAmplitude;
    bool answerCount;
    bool lastAnswer;
    bool currentAnswer;
    int numReversals;
    int currentDelay;
    int orderSwitch;
    int altOrder[4] = {2,1,0,3};
    int i;
    int corrAns;
    int corrAnsCounter;
	
	//===================  Private Members  ===================//
	
	
	//Thought about using scopedPointer class from juce to create regular
	//pointers as their destruction gets automatically handled
	
	AudioPlayer audioPlayer;
	SpeakerSelector spkrSel;
	DataManager* dataManager;
	
	ScopedPointer<TextButton> startButton;
	ScopedPointer<TextButton> opt1Button;
	ScopedPointer<TextButton> opt2Button;
	ScopedPointer<TextEditor> textEditor;
	ScopedPointer<TextButton> testAudioButton;
	ScopedPointer<TextButton> playButton;
	
	ScopedPointer<ToggleButton> ITDButton;
	ScopedPointer<ToggleButton> ILDButton;
	ScopedPointer<ToggleButton> leftButton;
	ScopedPointer<ToggleButton> rightButton;
	ScopedPointer<Slider> dlySlider;
	ScopedPointer<Slider> gainSlider;
	ScopedPointer<Slider> volSlider;
	ScopedPointer<ComboBox> posBox;
	ScopedPointer<TextEditor> userTextBox;
	
	
	// Just For Dbgn
	ScopedPointer<TextButton> printData;
	ScopedPointer<TextButton> finishTest;
	
	
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
