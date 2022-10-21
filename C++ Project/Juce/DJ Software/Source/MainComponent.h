/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"
#include "DeckGUI.h"
#include "PlaylistComponent.h"




//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/


class MainComponent   : public AudioAppComponent, 
                        public Button::Listener, 
                        public Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

    /** implement Button::Listener */
    void buttonClicked (Button *) override;

    /** implement Slider::Listener */
    void sliderValueChanged (Slider *slider) override;

private:

    PlaylistComponent playlistComponent;

    AudioFormatManager formatManager;
    AudioThumbnailCache thumbCache{ 20 };


    //Slider gainSlider1;
    //Slider gainSlider2;

    DJAudioPlayer player1{ formatManager };
    DeckGUI deck1{ &player1, formatManager, thumbCache };
    DJAudioPlayer player2{ formatManager };
    DeckGUI deck2{ &player2, formatManager, thumbCache };
    DJAudioPlayer player3{ formatManager };
    DeckGUI deck3{ &player3, formatManager, thumbCache };
    DJAudioPlayer player4{ formatManager };
    DeckGUI deck4{ &player4, formatManager, thumbCache };
    MixerAudioSource mixerSource;
    RotaryColour rotaryColour;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};