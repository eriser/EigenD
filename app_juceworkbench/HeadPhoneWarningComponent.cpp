/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
/*
 Copyright 2012-2014 Eigenlabs Ltd.  http://www.eigenlabs.com

 This file is part of EigenD.

 EigenD is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 EigenD is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with EigenD.  If not, see <http://www.gnu.org/licenses/>.
*/
//[/Headers]

#include "HeadPhoneWarningComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
HeadPhoneWarningComponent::HeadPhoneWarningComponent (String msg)
    : msg_(msg)
{
    addAndMakeVisible (okButton = new TextButton ("okButton"));
    okButton->setExplicitFocusOrder (1);
    okButton->setButtonText (TRANS("OK"));
    okButton->addListener (this);
    okButton->setColour (TextButton::buttonColourId, Colour (0xffaeaeae));

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("WARNING!\n")));
    label->setFont (Font (22.30f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           String::empty));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (disagreeButton = new TextButton ("disagreeButton"));
    disagreeButton->setButtonText (TRANS("Cancel"));
    disagreeButton->addListener (this);
    disagreeButton->setColour (TextButton::buttonColourId, Colour (0xffaeaeae));


    //[UserPreSize]
    okPressed_=false;
    label2->setText(msg_,dontSendNotification);
    //[/UserPreSize]

    setSize (400, 175);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

HeadPhoneWarningComponent::~HeadPhoneWarningComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    okButton = nullptr;
    label = nullptr;
    label2 = nullptr;
    disagreeButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void HeadPhoneWarningComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setGradientFill (ColourGradient (Colour (0xff060505),
                                       96.0f, 24.0f,
                                       Colour (0xff757775),
                                       100.0f, 100.0f,
                                       false));
    g.fillRect (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void HeadPhoneWarningComponent::resized()
{
    okButton->setBounds (120, 128, 71, 24);
    label->setBounds (64, 16, 272, 24);
    label2->setBounds (24, 48, 352, 64);
    disagreeButton->setBounds (216, 128, 64, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void HeadPhoneWarningComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == okButton)
    {
        //[UserButtonCode_okButton] -- add your button handler code here..
        DialogWindow* dw =findParentComponentOfClass<DialogWindow>();
        if(dw!=0)
        {
            okPressed_=true;
            dw->exitModalState(0);
        }

        //[/UserButtonCode_okButton]
    }
    else if (buttonThatWasClicked == disagreeButton)
    {
        //[UserButtonCode_disagreeButton] -- add your button handler code here..
        okPressed_=false;
        DialogWindow* dw =findParentComponentOfClass<DialogWindow>();
        if(dw!=0)
        {
            dw->exitModalState(0);
        }

        //[/UserButtonCode_disagreeButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
bool HeadPhoneWarningComponent::okPressed()
{
    return okPressed_;
}

void HeadPhoneWarningComponent::closeButtonPressed()
{
    okPressed_=false;
    DialogWindow* dw =findParentComponentOfClass<DialogWindow>();
    if(dw!=0)
    {
        dw->exitModalState(0);
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="HeadPhoneWarningComponent"
                 componentName="" parentClasses="public Component" constructorParams="String msg"
                 variableInitialisers="msg_(msg)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="400"
                 initialHeight="175">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="0 0 100% 100%" fill="linear: 96 24, 100 100, 0=ff060505, 1=ff757775"
          hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="okButton" id="e2aadca74a756fb3" memberName="okButton" virtualName=""
              explicitFocusOrder="1" pos="120 128 71 24" bgColOff="ffaeaeae"
              buttonText="OK" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="cf632a1aa060f6f0" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="64 16 272 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="WARNING!&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="22.300000000000000711" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="82dddf9486afd219" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="24 48 352 64" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="disagreeButton" id="ef4e97d5ba986992" memberName="disagreeButton"
              virtualName="" explicitFocusOrder="0" pos="216 128 64 24" bgColOff="ffaeaeae"
              buttonText="Cancel" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]