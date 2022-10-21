/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 10 Aug 2022 2:13:48pm
    Author:  魏冰冰

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, 
    juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId)
{

    adsrName = name;

    setSliderTitle(attackSlider, attackTitle, apvts, attackId, attackAttachment);
    setSliderTitle(decaySlider, decayTitle, apvts, decayId, decayAttachment);
    setSliderTitle(sustainSlider, sustainTitle, apvts, sustainId, sustainAttachment);
    setSliderTitle(releaseSlider, releaseTitle, apvts, releaseId, releaseAttachment);
    
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    attackAttachment = std::make_unique<SliderAttachment>(apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<SliderAttachment>(apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<SliderAttachment>(apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<SliderAttachment>(apvts, "RELEASE", releaseSlider);
    attackSlider.setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    attackSlider.setColour(juce::Slider::trackColourId,juce::Colours::white);
    decaySlider.setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    decaySlider.setColour(juce::Slider::trackColourId, juce::Colours::white);
    sustainSlider.setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    sustainSlider.setColour(juce::Slider::trackColourId, juce::Colours::white);
    releaseSlider.setColour(juce::Slider::thumbColourId, juce::Colours::chocolate);
    releaseSlider.setColour(juce::Slider::trackColourId, juce::Colours::white);

    setSliderParams(attackSlider);
    setSliderParams(decaySlider);
    setSliderParams(sustainSlider);
    setSliderParams(releaseSlider);
}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(25);
    g.drawText(adsrName, getLocalBounds().reduced(5).removeFromTop(25).withX(5), juce::Justification::left);
    g.setColour(juce::Colours::chocolate);
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 5, 2);
}

void AdsrComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto sliderW = getLocalBounds().reduced(20).getWidth() / 4 ;
    const auto sliderH = bounds.getHeight()-75;
    const auto sliderX = bounds.getHeight()-175;
    const auto sliderY = 65;
    const auto titleO = 20;
    const auto titleH = 20;
    const auto titleS = sliderY - titleO;

    attackSlider.setBounds(sliderX, sliderY, sliderW, sliderH);
    attackTitle.setBounds(attackSlider.getX(), titleS, sliderW, titleH);

    decaySlider.setBounds(attackSlider.getRight() + 10, sliderY, sliderW, sliderH);
    decayTitle.setBounds(decaySlider.getX(), titleS, sliderW, titleH);

    sustainSlider.setBounds(decaySlider.getRight() + 10, sliderY, sliderW, sliderH);
    sustainTitle.setBounds(sustainSlider.getX(), titleS, sliderW, titleH);

    releaseSlider.setBounds(sustainSlider.getRight() + 10, sliderY, sliderW, sliderH);
    releaseTitle.setBounds(releaseSlider.getX(), titleS, sliderW, titleH);

}

void AdsrComponent::setSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);

}


void AdsrComponent::setSliderTitle(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment)
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