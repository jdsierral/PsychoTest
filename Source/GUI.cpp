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


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    startButton->setBounds (168, 112, 224, 128);
    opt1Button->setBounds (192, 312, 72, 24);
    opt2Button->setBounds (288, 312, 72, 24);
    textEditor->setBounds (200, 24, 192, 80);
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="Start Button" id="9bf53107386741c1" memberName="startButton"
              virtualName="" explicitFocusOrder="0" pos="168 112 224 128" buttonText="start"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Opt1 Button" id="73f09de8d04c1ccd" memberName="opt1Button"
              virtualName="" explicitFocusOrder="0" pos="192 312 72 24" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Opt2 Button" id="d16ed9691b30226d" memberName="opt2Button"
              virtualName="" explicitFocusOrder="0" pos="288 312 72 24" buttonText="2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="af69f34d968c44d7" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="200 24 192 80" initialText="Press 1 if the first signal is the leftmost signal, 2 otherwise"
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
