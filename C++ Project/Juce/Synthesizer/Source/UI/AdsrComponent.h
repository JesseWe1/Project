/*
  ==============================================================================

    AdsrComponent.h
    Created: 10 Aug 2022 2:13:48pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrComponent  : public juce::Component
{
public:
    AdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void setSliderParams(juce::Slider& slider);

    void setSliderTitle(juce::Slider& slider, juce::Label& label, 
        juce::AudioProcessorValueTreeState& apvts, juce::String paramId, 
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment);


    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decayAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseAttachment;
    //std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;

    juce::Label attackTitle{ "Attack", "Attack" };
    juce::Label decayTitle{ "Decay", "Decay" };
    juce::Label sustainTitle{ "Sustain", "Sustain" };
    juce::Label releaseTitle{ "Release", "Release" };

    juce::String adsrName{ "" };


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)

};
