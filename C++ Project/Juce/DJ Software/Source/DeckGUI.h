/*
  ==============================================================================

    DeckGUI.h
    Created: 8 Mar 2022 9:21:58pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DJAudioPlayer.h"
#include "WaveformDisplay.h"

//==============================================================================
/*
*/

class RotaryColour : public LookAndFeel_V4
{
public:
    RotaryColour()
    {
        setColour(Slider::rotarySliderOutlineColourId, Colours::chocolate);
        setColour(Slider::rotarySliderFillColourId, Colours::white);
        setColour(Slider::thumbColourId, Colours::black);
    }
};

class DeckGUI  :
    public Component,
    public Button::Listener,
    public Slider::Listener,
    public FileDragAndDropTarget,
    public Timer

{
public:
    //DeckGUI(DJAudioPlayer* _djAudioPlayer);
    DeckGUI(
        DJAudioPlayer* djAudioPlayer,
        AudioFormatManager& formatManagerToUse,
        AudioThumbnailCache& cacheToUse
    );

    ~DeckGUI() override;
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void sliderValueChanged(Slider* slider) override;
    bool isInterestedInFileDrag(const StringArray& files) override;
    void filesDropped(const StringArray& files, int x, int y) override;
    void timerCallback() override;

    


private:
    TextButton playButton{"PLAY"};
    TextButton stopButton{ "STOP" };
    TextButton loadButton{ "LOAD" };
    Slider volumeSlider;
    Slider positionSlider;
    Slider speedSlider;
    WaveformDisplay waveformDisplay;
    //WaveformDisplay waveform;



    DJAudioPlayer* djAudioPlayer;

    RotaryColour rotaryColour;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DeckGUI)
};
