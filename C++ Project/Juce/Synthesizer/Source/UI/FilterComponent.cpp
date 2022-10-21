/*
  ==============================================================================

    FilterComponent.cpp
    Created: 13 Aug 2022 1:40:15am
    Author:  魏冰冰

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent(juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeSelId,
    juce::String cutoffId, juce::String resonanceId)
{
    juce::StringArray choices{ "Low Pass", "Band Pass", "High Pass" };
    filterTypeSel.addItemList(choices, 1);
    addAndMakeVisible(filterTypeSel);

    filterTypeSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, filterTypeSelId, filterTypeSel);

    setSliderTitle(cutoffSlider, cutoffTitle, apvts, cutoffId, cutoffAttachment);
    setSliderTitle(resonanceSlider, resonanceTitle, apvts, resonanceId, resonanceAttachment);
    cutoffSlider.setLookAndFeel(&rotaryColour1);
    resonanceSlider.setLookAndFeel(&rotaryColour1);

}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    g.setFont(25.0);
    g.setColour(juce::Colours::white);
    g.drawText("FILTER", getLocalBounds().reduced(5).removeFromTop(25).withX(5), juce::Justification::left);
    g.setFont(15.0);
    g.drawText("Filter Type", getLocalBounds().reduced(5).removeFromTop(80).withX(20), juce::Justification::left);
    g.setColour(juce::Colours::chocolate);
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 5.0f, 2.0f);
}

void FilterComponent::resized()
{
    const auto sliderY = 55;
    const auto sliderW = 100;
    const auto sliderH = 90;
    const auto titleO = 20;
    const auto titleH = 20;


    filterTypeSel.setBounds(10, sliderY + 5, 90, 20);
    cutoffSlider.setBounds(filterTypeSel.getRight(), sliderY, sliderW, sliderH);
    cutoffTitle.setBounds(cutoffSlider.getX(), cutoffSlider.getY() - titleO, cutoffSlider.getWidth(), titleH);

    resonanceSlider.setBounds(cutoffSlider.getRight(), sliderY, sliderW, sliderH);
    resonanceTitle.setBounds(resonanceSlider.getX(), resonanceSlider.getY() - titleO, resonanceSlider.getWidth(), titleH);

}

void FilterComponent::setSliderTitle(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts,
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