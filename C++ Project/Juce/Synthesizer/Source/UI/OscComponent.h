/*
  ==============================================================================

    OscComponent.h
    Created: 10 Aug 2022 10:54:12pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RotaryColour : public juce::LookAndFeel_V4
{
public:
    RotaryColour()
    {
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::white);
        setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    }
};


class OscComponent  : public juce::Component
{
public:
    OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId, juce::String freqModId, juce::String depthModId);
    ~OscComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;



private:
    juce::ComboBox oscWaveSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveSelectorAttachment;

    juce::Slider freqModSlider;
    juce::Slider depthModSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> freqModAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> depthModAttachment;

    juce::Label freqModTitle{ "Freq", "Freq" };
    juce::Label depthModTitle{ "Depth", "Depth" };

    void setSliderTitle(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts,
        juce::String paramId, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment);

    RotaryColour rotaryColour;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscComponent)
};
