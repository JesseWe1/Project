/*
  ==============================================================================

    ModAdsrComponent.h
    Created: 13 Aug 2022 3:56:38am
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ModAdsrComponent  : public juce::Component
{
public:
    ModAdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId);
    ~ModAdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void setModSliderParams(juce::Slider& slider);

    void setModSliderTitle(juce::Slider& slider, juce::Label& label,
        juce::AudioProcessorValueTreeState& apvts, juce::String paramId,
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment);


    juce::Slider attack_ModSlider;
    juce::Slider decay_ModSlider;
    juce::Slider sustain_ModSlider;
    juce::Slider release_ModSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attack_ModAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decay_ModAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustain_ModAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> release_ModAttachment;
    //std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;

    juce::Label attack_ModTitle{ "Attack", "Attack" };
    juce::Label decay_ModTitle{ "Decay", "Decay" };
    juce::Label sustain_ModTitle{ "Sustain", "Sustain" };
    juce::Label release_ModTitle{ "Release", "Release" };

    juce::String adsr_ModName{ "" };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModAdsrComponent)
};
