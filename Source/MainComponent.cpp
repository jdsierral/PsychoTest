/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "GUI.h"
#include "AudioPlayer.h"
#include "SpeakerSelector.h"
#include "DataManager.h"

//==============================================================================
/*
 *
 *
 *
 * This is a change
 * This is also a change
 * cambio
 * Esto es un cambioooooo
 *
 *
 *
 *
 *
 *
 */
//==============================================================================
class MainContentComponent   : 	public AudioAppComponent,
							   	public ButtonListener,
								public SliderListener,
								public ComboBoxListener,
								public TextEditor::Listener
{
public:
	//==============================================================================
	MainContentComponent()
	{
		
		setAudioChannels (0, 8);

		// ===================== GUI SETUP =============================//
		
		
		addAndMakeVisible (startButton = new TextButton ("Start Button"));
		startButton->setButtonText (TRANS("start"));
		startButton->addListener (this);
		startButton->setEnabled(false);
		
		addAndMakeVisible (opt1Button = new TextButton ("Opt1 Button"));
		opt1Button->setButtonText (TRANS("1"));
		opt1Button->addListener (this);
		
		addAndMakeVisible (opt2Button = new TextButton ("Opt2 Button"));
		opt2Button->setButtonText (TRANS("2"));
		opt2Button->addListener (this);
		
		addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
		textEditor->setMultiLine (true);
		textEditor->setReturnKeyStartsNewLine (true);
		textEditor->setReadOnly (true);
		textEditor->setScrollbarsShown (false);
		textEditor->setCaretVisible (false);
		textEditor->setPopupMenuEnabled (false);
		textEditor->setText (TRANS("Press 1 if the first signal is the leftmost signal, 2 otherwise"));
		
		addAndMakeVisible (ITDButton = new ToggleButton ("ITD Button"));
		ITDButton->setButtonText (TRANS("ITD"));
		ITDButton->setRadioGroupId (1);
		ITDButton->addListener (this);
		
		addAndMakeVisible (ILDButton = new ToggleButton ("ILD Button"));
		ILDButton->setButtonText (TRANS("ILD"));
		ILDButton->setRadioGroupId (1);
		ILDButton->addListener (this);
		
		addAndMakeVisible (playButton = new TextButton ("Play Button"));
		playButton->setButtonText (TRANS("Play"));
		playButton->addListener (this);
		
		addAndMakeVisible (leftButton = new ToggleButton ("Left Button"));
		leftButton->setButtonText (TRANS("left"));
		leftButton->setRadioGroupId (2);
		leftButton->addListener (this);
		
		addAndMakeVisible (rightButton = new ToggleButton ("Right Button"));
		rightButton->setButtonText (TRANS("right"));
		rightButton->setRadioGroupId (2);
		rightButton->addListener (this);
		rightButton->setToggleState (true, dontSendNotification);
		
		addAndMakeVisible (dlySlider = new Slider ("Dly Slider"));
		dlySlider->setRange (0, 20, 0);
		dlySlider->setSliderStyle (Slider::LinearHorizontal);
		dlySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
		dlySlider->addListener (this);
		
		addAndMakeVisible (gainSlider = new Slider ("Gain Slider"));
		gainSlider->setRange (0, 20, 0);
		gainSlider->setSliderStyle (Slider::LinearHorizontal);
		gainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
		gainSlider->addListener (this);
		
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
		
		addAndMakeVisible (volSlider = new Slider ("Volume Slider"));
		volSlider->setRange (-60, 0, 0.1);
		volSlider->setSliderStyle (Slider::LinearBar);
		volSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
		volSlider->addListener (this);
		
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
		
		setSize (600, 400);
		
	}
	
	~MainContentComponent()
	{
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
		shutdownAudio();
	}
	
	//==============================================================================
	void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
	{
		// This function will be called when the audio device is started, or when
		// its settings (i.e. sample rate, block size, etc) are changed.
		
		// You can use this function to initialise any resources you might need,
		// but be careful - it will be called on the audio thread, not the GUI thread.
		
		// For more details, see the help for AudioProcessor::prepareToPlay()
		audioPlayer.prepareToPlay(samplesPerBlockExpected, sampleRate);
		
	}
	
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
	{
		// Your audio-processing code goes here!
		
		// For more details, see the help for AudioProcessor::getNextAudioBlock()
		
		// Right now we are not producing any data, in which case we need to clear the buffer
		// (to prevent the output of random noise)
		bufferToFill.buffer->clear();
		audioPlayer.getNextAudioBlock(bufferToFill);
		spkrSel.process(bufferToFill);
		bufferToFill.buffer->applyGain(0.5);
		
	}
	
	void releaseResources() override
	{
		// This will be called when the audio device stops, or when it is being
		// restarted due to a setting change.
		
		// For more details, see the help for AudioProcessor::releaseResources()
	}
	
	//==============================================================================
	void paint (Graphics& g) override
	{
		// (Our component is opaque, so we must completely fill the background with a solid colour)
		g.fillAll (Colours::white);
		
		g.setColour (Colours::black);
		g.setFont (Font (15.00f, Font::plain));
		g.drawText (TRANS("Just 4 Dbgn"),
					7, 99, 97, 30,
					Justification::centred, true);
		
		
		// You can add your drawing code here!
	}
	
	void resized() override
	{
		// This is called when the MainContentComponent is resized.
		// If you add any child components, this is where you should
		// update their positions.
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
		
	}
	
	void buttonClicked (Button* buttonThatWasClicked) override
	{
		if (buttonThatWasClicked == startButton)
		{
		}
		else if (buttonThatWasClicked == opt1Button)
		{
		}
		else if (buttonThatWasClicked == opt2Button)
		{
		}
		else if (buttonThatWasClicked == ITDButton)
		{
			audioPlayer.setTest(1);
		}
		else if (buttonThatWasClicked == ILDButton)
		{
			audioPlayer.setTest(0);
		}
		else if (buttonThatWasClicked == playButton)
		{
			audioPlayer.nextSate();
		}
		else if (buttonThatWasClicked == leftButton)
		{
			audioPlayer.setDirection(-1);
		}
		else if (buttonThatWasClicked == rightButton)
		{
			audioPlayer.setDirection(1);
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
			audioPlayer.setGainInDecibels(-gainSlider->getValue());
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
		}
		
	}

	void textEditorReturnKeyPressed (TextEditor& textEditorChanged) override {
		startButton->setEnabled(true);
		String user = userTextBox->getText();
		dataManager = new DataManager(user);
	}
	
	
	
private:
	//==============================================================================
	
	void initAudioSettings (){
		/*
		 AudioIODevice* ioDevice = AudioAppComponent::deviceManager.getCurrentAudioDevice();
		 ioDevice->open(2, 2, 48000, 512);
		 ioDevice->getCurrentSampleRate();
		 ioDevice->getAvailableBufferSizes();
		 
		 Initialize AudioEngine
		 
		 void AudioAppComponent::setAudioChannels (int numInputChannels, int numOutputChannels, const XmlElement* const xml)
		 {
			String audioError = deviceManager.initialise (numInputChannels, numOutputChannels, xml, true);
			jassert (audioError.isEmpty());
			
			deviceManager.addAudioCallback (&audioSourcePlayer);
			audioSourcePlayer.setSource (this);
		}
		 */
	}
	//==================  Private Variables  ===================//
	
	float vol;
	
	
	//===================  Private Members  ===================//
	
	
	//Thought about using scopedPointer class from juce to create regular
	//pointers as their destruction gets automatically handled
	
	AudioPlayer audioPlayer;
	SpeakerSelector spkrSel;
	ScopedPointer<DataManager> dataManager;
	
	ScopedPointer<TextButton> startButton;
	ScopedPointer<TextButton> opt1Button;
	ScopedPointer<TextButton> opt2Button;
	ScopedPointer<TextEditor> textEditor;
	ScopedPointer<ToggleButton> ITDButton;
	ScopedPointer<ToggleButton> ILDButton;
	ScopedPointer<TextButton> playButton;
	ScopedPointer<ToggleButton> leftButton;
	ScopedPointer<ToggleButton> rightButton;
	ScopedPointer<Slider> dlySlider;
	ScopedPointer<Slider> gainSlider;
	ScopedPointer<Slider> volSlider;
	ScopedPointer<ComboBox> posBox;
	ScopedPointer<TextEditor> userTextBox;
	
	
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
