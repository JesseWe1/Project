/*
  ==============================================================================

    OscData.h
    Created: 10 Aug 2022 7:56:51pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>



class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    void setWaveType(const int choice);
    void setWaveFrequency(const int midiNoteNumber);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);
    void setFmParameters(const float depth, const float freq);

private:
    juce::dsp::Oscillator<float> frequencyModulationOsc{ [](float x) {return std::sin(x); } };
    float frequencyModulationFreq{ 0.0f };
    float frequencyModulationDepth{ 0.0f };
    int lastMidiNote{ 0 };

};