/*
  ==============================================================================

    ModAdsrComponent.cpp
    Created: 13 Aug 2022 3:56:38am
    Author:  魏冰冰

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ModAdsrComponent.h"

//==============================================================================
ModAdsrComponent::ModAdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId)
{
    adsr_ModName = name;

    setModSliderTitle(attack_ModSlider, attack_ModTitle, apvts, attackId, attack_ModAttachment);
    setModSliderTitle(decay_ModSlider, decay_ModTitle, apvts, decayId, decay_ModAttachment);
    setModSliderTitle(sustain_ModSlider, sustain_ModTitle, apvts, sustainId, sustain_ModAttachment);
    setModSliderTitle(release_ModSlider, release_ModTitle, apvts, releaseId, release_ModAttachment);

    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    attack_ModAttachment = std::make_unique<SliderAttachment>(apvts, "ATTACK_MOD", attack_ModSlider);
    decay_ModAttachment = std::make_unique<SliderAttachment>(apvts, "DECAY_MOD", decay_ModSlider);
    sustain_ModAttachment = std::make_unique<SliderAttachment>(apvts, "SUSTAIN_MOD", sustain_ModSlider);
    release_ModAttachment = std::make_unique<SliderAttachment>(apvts, "RELEASE_MOD", release_ModSlider);
    attack_ModSlider.setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    attack_ModSlider.setColour(juce::Slider::trackColourId, juce::Colours::white);
    decay_ModSlider.setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    decay_ModSlider.setColour(juce::Slider::trackColourId, juce::Colours::white);
    sustain_ModSlider.setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    sustain_ModSlider.setColour(juce::Slider::trackColourId, juce::Colours::white);
    release_ModSlider.setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    release_ModSlider.setColour(juce::Slider::trackColourId, juce::Colours::white);

    setModSliderParams(attack_ModSlider);
    setModSliderParams(decay_ModSlider);
    setModSliderParams(sustain_ModSlider);
    setModSliderParams(release_ModSlider);

}

ModAdsrComponent::~ModAdsrComponent()
{
}

void ModAdsrComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(25);
    g.drawText(adsr_ModName, getLocalBounds().reduced(5).removeFromTop(25).withX(5), juce::Justification::left);
    g.setColour(juce::Colours::chocolate);
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 5, 2);
}

void ModAdsrComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto sliderW = getLocalBounds().reduced(20).getWidth() / 4;
    const auto sliderH = bounds.getHeight() - 75;
    const auto sliderX = bounds.getHeight() - 175;
    const auto sliderY = 65;
    const auto titleO = 20;
    const auto titleH = 20;
    const auto titleS = sliderY - titleO;

    attack_ModSlider.setBounds(sliderX, sliderY, sliderW, sliderH);
    attack_ModTitle.setBounds(attack_ModSlider.getX(), titleS, sliderW, titleH);

    decay_ModSlider.setBounds(attack_ModSlider.getRight() + 10, sliderY, sliderW, sliderH);
    decay_ModTitle.setBounds(decay_ModSlider.getX(), titleS, sliderW, titleH);

    sustain_ModSlider.setBounds(decay_ModSlider.getRight() + 10, sliderY, sliderW, sliderH);
    sustain_ModTitle.setBounds(sustain_ModSlider.getX(), titleS, sliderW, titleH);

    release_ModSlider.setBounds(sustain_ModSlider.getRight() + 10, sliderY, sliderW, sliderH);
    release_ModTitle.setBounds(release_ModSlider.getX(), titleS, sliderW, titleH);
}

void ModAdsrComponent::setModSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}


void ModAdsrComponent::setModSliderTitle(juce::Slider& slider, juce::Label& label,
    juce::AudioProcessorValueTreeState& apvts, juce::String paramId,
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment) 
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);

    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);

    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setFont(15.0f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);

}