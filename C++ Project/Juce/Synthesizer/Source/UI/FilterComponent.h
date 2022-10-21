/*
  ==============================================================================

    FilterComponent.h
    Created: 13 Aug 2022 1:40:15am
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RotaryColour1 : public juce::LookAndFeel_V4
{
public:
    RotaryColour1()
    {
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::white);
        setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    }
};



class FilterComponent  : public juce::Component
{
public:
    FilterComponent(juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeSelId,
        juce::String cutoffId, juce::String resonanceId);
    ~FilterComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox filterTypeSel{ "Filter Type" };
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeSelAttachment;


    juce::Slider cutoffSlider;
    juce::Slider resonanceSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutoffAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> resonanceAttachment;

    juce::Label cutoffTitle{ "Freq Cutoff", "Freq Cutoff" };
    juce::Label resonanceTitle{ "Resonance", "Resonance" };
    
   

    void setSliderTitle(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts,
        juce::String paramId, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment);
    
    RotaryColour1 rotaryColour1;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
