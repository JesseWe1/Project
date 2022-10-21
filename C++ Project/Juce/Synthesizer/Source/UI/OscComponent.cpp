/*
  ==============================================================================

    OscComponent.cpp
    Created: 10 Aug 2022 10:54:12pm
    Author:  魏冰冰

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, 
    juce::String waveSelectorId, juce::String freqModId, juce::String depthModId)
{
    juce::StringArray choices{ "Sine", "Saw", "Square" };
    oscWaveSelector.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelector);

    oscWaveSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorId, oscWaveSelector);

    setSliderTitle(freqModSlider, freqModTitle, apvts, freqModId, freqModAttachment);
    setSliderTitle(depthModSlider, depthModTitle, apvts, depthModId, depthModAttachment);
    freqModSlider.setLookAndFeel(&rotaryColour);
    depthModSlider.setLookAndFeel(&rotaryColour);
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    g.setFont(25.0);
    g.setColour(juce::Colours::white);
    g.drawText("OSC", getLocalBounds().reduced(5).removeFromTop(25.0f).withX(5), juce::Justification::left);
    g.setFont(15.0);
    g.drawText("Wave Type", getLocalBounds().reduced(5).removeFromTop(80).withX(25), juce::Justification::left);
    g.setColour(juce::Colours::chocolate);
    g.drawRoundedRectangle(getLocalBounds().toFloat(),5.0f,2.0f);
}

void OscComponent::resized()
{
    const auto sliderY = 55;
    const auto sliderW = 100;
    const auto sliderH = 90;
    const auto titleO = 20;
    const auto titleH = 20;


    oscWaveSelector.setBounds(20, sliderY + 5, 80, 20);
    freqModSlider.setBounds(oscWaveSelector.getRight(), sliderY, sliderW, sliderH);
    freqModTitle.setBounds(freqModSlider.getX(), freqModSlider.getY() - titleO, freqModSlider.getWidth(), titleH);

    depthModSlider.setBounds(freqModSlider.getRight(), sliderY, sliderW, sliderH);
    depthModTitle.setBounds(depthModSlider.getX(), depthModSlider.getY() - titleO, depthModSlider.getWidth(), titleH);
}

void OscComponent::setSliderTitle(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, 
    juce::String paramId, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);

    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);

    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setFont(15.0f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}
