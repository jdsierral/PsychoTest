/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUI::GUI ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (startButton = new TextButton ("Start Button"));
    startButton->setButtonText (TRANS("start"));
    startButton->addListener (this);

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
    dlySlider->setRange (0, 10, 0);
    dlySlider->setSliderStyle (Slider::LinearHorizontal);
    dlySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    dlySlider->addListener (this);

    addAndMakeVisible (gainSlider = new Slider ("Gain Slider"));
    gainSlider->setRange (0, 10, 0);
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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

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


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Just 4 Dbgn"),
                39, 176, 97, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

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
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == startButton)
    {
        //[UserButtonCode_startButton] -- add your button handler code here..
        //[/UserButtonCode_startButton]
    }
    else if (buttonThatWasClicked == opt1Button)
    {
        //[UserButtonCode_opt1Button] -- add your button handler code here..
        //[/UserButtonCode_opt1Button]
    }
    else if (buttonThatWasClicked == opt2Button)
    {
        //[UserButtonCode_opt2Button] -- add your button handler code here..
        //[/UserButtonCode_opt2Button]
    }
    else if (buttonThatWasClicked == ITDButton)
    {
        //[UserButtonCode_ITDButton] -- add your button handler code here..
        //[/UserButtonCode_ITDButton]
    }
    else if (buttonThatWasClicked == ILDButton)
    {
        //[UserButtonCode_ILDButton] -- add your button handler code here..
        //[/UserButtonCode_ILDButton]
    }
    else if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == leftButton)
    {
        //[UserButtonCode_leftButton] -- add your button handler code here..
        //[/UserButtonCode_leftButton]
    }
    else if (buttonThatWasClicked == rightButton)
    {
        //[UserButtonCode_rightButton] -- add your button handler code here..
        //[/UserButtonCode_rightButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == dlySlider)
    {
        //[UserSliderCode_dlySlider] -- add your slider handling code here..
        //[/UserSliderCode_dlySlider]
    }
    else if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == volSlider)
    {
        //[UserSliderCode_volSlider] -- add your slider handling code here..
        //[/UserSliderCode_volSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUI::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == posBox)
    {
        //[UserComboBoxCode_posBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_posBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUI" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="39 176 97 30" fill="solid: ff000000" hasStroke="0" text="Just 4 Dbgn"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <TEXTBUTTON name="Start Button" id="9bf53107386741c1" memberName="startButton"
              virtualName="" explicitFocusOrder="0" pos="184 112 224 128" buttonText="start"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Opt1 Button" id="73f09de8d04c1ccd" memberName="opt1Button"
              virtualName="" explicitFocusOrder="0" pos="208 312 72 24" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Opt2 Button" id="d16ed9691b30226d" memberName="opt2Button"
              virtualName="" explicitFocusOrder="0" pos="304 312 72 24" buttonText="2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="af69f34d968c44d7" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="200 24 192 80" initialText="Press 1 if the first signal is the leftmost signal, 2 otherwise"
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TOGGLEBUTTON name="ITD Button" id="12f3e1aefb2efdc3" memberName="ITDButton"
                virtualName="" explicitFocusOrder="0" pos="8 216 80 24" buttonText="ITD"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="ILD Button" id="4cf2796c28036bc5" memberName="ILDButton"
                virtualName="" explicitFocusOrder="0" pos="8 272 80 24" buttonText="ILD"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <TEXTBUTTON name="Play Button" id="316e149109cce41d" memberName="playButton"
              virtualName="" explicitFocusOrder="0" pos="56 368 56 24" buttonText="Play"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Left Button" id="572f485053259c08" memberName="leftButton"
                virtualName="" explicitFocusOrder="0" pos="8 320 48 24" buttonText="left"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="Right Button" id="1434f08086b6eb86" memberName="rightButton"
                virtualName="" explicitFocusOrder="0" pos="56 320 56 24" buttonText="right"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="1"/>
  <SLIDER name="Dly Slider" id="c9020fe0f6093ded" memberName="dlySlider"
          virtualName="" explicitFocusOrder="0" pos="56 216 120 32" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Gain Slider" id="eb0d63f51b45bef2" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="56 272 120 32" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <COMBOBOX name="Position Box" id="3115378778036870" memberName="posBox"
            virtualName="" explicitFocusOrder="0" pos="216 352 150 24" editable="0"
            layout="33" items="Front&#10;Front Lateral&#10;Lateral&#10;Rear Lateral&#10;Rear"
            textWhenNonSelected="Select Position" textWhenNoItems="(no choices)"/>
  <SLIDER name="Volume Slider" id="83158b992b2ad04d" memberName="volSlider"
          virtualName="" explicitFocusOrder="0" pos="472 368 118 24" min="-60"
          max="0" int="0.10000000000000000555" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
