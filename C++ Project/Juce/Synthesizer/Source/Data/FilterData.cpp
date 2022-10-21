/*
  ==============================================================================

    FilterData.cpp
    Created: 12 Aug 2022 11:01:00pm
    Author:  魏冰冰

  ==============================================================================
*/

#include "FilterData.h"

void FilterData::prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels)
{
    filter.reset();

    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = numChannels;

    filter.prepare(spec);

    isPrepared = true;
}


void FilterData::process(juce::AudioBuffer<float>& buffer) 
{
    jassert(isPrepared);

    juce::dsp::AudioBlock<float> block{ buffer };
    filter.process(juce::dsp::ProcessContextReplacing<float> {block});
}


void FilterData::updateParameters(const int filterType, const float frequency, const float resonance, const float mod)
{
    switch (filterType)
    {
    case 0:
        filter.setType(juce::dsp::StateVariableTPTFilterType::lowpass);
        break;

    case 1:
        filter.setType(juce::dsp::StateVariableTPTFilterType::bandpass);
        break;

    case 2:
        filter.setType(juce::dsp::StateVariableTPTFilterType::highpass);
        break;
    }
    
    float freq_Mod = frequency * mod;
    freq_Mod = std::fmax(freq_Mod, 20);
    freq_Mod = std::fmin(freq_Mod, 20000);

    filter.setCutoffFrequency(freq_Mod);
    filter.setResonance(resonance); 
}


void FilterData::reset()
{
    filter.reset();
}