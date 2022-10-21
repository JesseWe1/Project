/*
  ==============================================================================

    DeckGUI.cpp
    Created: 8 Mar 2022 9:21:58pm
    Author:  魏冰冰

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DeckGUI.h"

//==============================================================================
DeckGUI::DeckGUI(
    DJAudioPlayer* _djAudioPlayer, AudioFormatManager& formatManagerToUse, AudioThumbnailCache& cacheToUse) : 
    djAudioPlayer(_djAudioPlayer), 
    waveformDisplay(formatManagerToUse, cacheToUse) 
{
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(loadButton);
    addAndMakeVisible(volumeSlider);
    addAndMakeVisible(positionSlider);
    addAndMakeVisible(speedSlider);
    addAndMakeVisible(waveformDisplay);

    playButton.setColour(juce::TextButton::buttonColourId, juce::Colours::chocolate);
    stopButton.setColour(juce::TextButton::buttonColourId, juce::Colours::darkcyan);
    loadButton.setColour(juce::TextButton::buttonColourId, juce::Colours::mediumpurple);


    speedSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    positionSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    speedSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 15);
    positionSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 15);
    volumeSlider.setColour(Slider::thumbColourId, Colours::chocolate);
    volumeSlider.setColour(Slider::trackColourId, Colours::white);
    speedSlider.setLookAndFeel(&rotaryColour);
    positionSlider.setLookAndFeel(&rotaryColour);

    playButton.addListener(this);
    stopButton.addListener(this);
    volumeSlider.addListener(this);
    positionSlider.addListener(this);
    speedSlider.addListener(this);
    loadButton.addListener(this);

    startTimer(200);

}


DeckGUI::~DeckGUI()
{
    stopTimer();

}

void DeckGUI::buttonClicked(Button* button)
{
    if (&playButton == button)
    {
        djAudioPlayer->setPosition(0);
        djAudioPlayer->play();
    }
    if (&stopButton == button)
    {
        djAudioPlayer->stop();
    }
    if (&loadButton == button)
    {
        FileChooser chooser{ "Select a file..." };
        if (chooser.browseForFileToOpen())
        {
            auto audioURL = URL{ chooser.getResult() };
            djAudioPlayer->loadURL(audioURL);
            waveformDisplay.loadURL(audioURL);
        }
    }

}


void DeckGUI::sliderValueChanged(Slider* slider)
{
    if (&volumeSlider == slider)
    {
        djAudioPlayer->setGain(slider->getValue());
    }
    if (&positionSlider == slider)
    {
        djAudioPlayer->setPositionRelative(slider->getValue());
    }
    if (&speedSlider == slider)
    {
        djAudioPlayer->setSpeed(slider->getValue());
    }
}

void DeckGUI::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour
    (ResizableWindow::backgroundColourId)); // clear the background
}


void DeckGUI::resized()
{
    float rowH = getHeight() / 7;
    playButton.setBounds(0, 0, getWidth(), rowH);
    stopButton.setBounds(0, rowH * 1, getWidth(), rowH);
    loadButton.setBounds(0, rowH * 2, getWidth(), rowH);
    volumeSlider.setBounds(0, rowH * 3, getWidth(), rowH);
    positionSlider.setBounds(0, rowH * 4, getWidth(), rowH);
    speedSlider.setBounds(0, rowH * 5, getWidth(), rowH);
    waveformDisplay.setBounds(0, rowH * 6, getWidth(), rowH);

    volumeSlider.setRange(0.0, 1.0);
    speedSlider.setRange(0.8, 3.0);
    positionSlider.setRange(0.0, 1.0);
}


bool DeckGUI::isInterestedInFileDrag(const StringArray& files)
{
    std::cout << "DeckGUI::isInterestedInFileDrag" << std::endl;
    return true;
}


void DeckGUI::filesDropped(const StringArray& files, int x, int y)
{
    for (const auto& filename : files)
    {
        std::cout << "DeckGUI::filesDropped " << filename << std::endl;
        URL fileURL = URL{ File{filename} };
        djAudioPlayer->loadURL(fileURL);
        return;
    }
}

void DeckGUI::timerCallback()
{
    std::cout << "DeckGUI::timerCallback" << std::endl;
    waveformDisplay.setPositionRelative(djAudioPlayer->getPositionRelative());
    waveformDisplay.setTime(djAudioPlayer->getPosition());
}

