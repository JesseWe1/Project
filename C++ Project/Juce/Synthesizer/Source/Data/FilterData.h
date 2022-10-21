/*
  ==============================================================================

    FilterData.h
    Created: 12 Aug 2022 11:01:00pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class FilterData
{
public:
    void prepareToPlay( double sampleRate, int samplesPerBlock, int numChannels);
    void process(juce::AudioBuffer<float>& buffer);
    void updateParameters(const int filterType, const float frequency, const float resonance, const float mod = 1.0);
    void reset();


private:
    juce::dsp::StateVariableTPTFilter<float> filter;
    bool isPrepared{ false };
};