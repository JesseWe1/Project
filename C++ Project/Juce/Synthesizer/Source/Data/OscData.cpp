/*
  ==============================================================================

    OscData.cpp
    Created: 10 Aug 2022 7:56:51pm
    Author:  魏冰冰

  ==============================================================================
*/

#include "OscData.h"


void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    frequencyModulationOsc.prepare(spec);
    prepare(spec);

}

void OscData::setWaveType(const int choice)
{
    switch (choice)
    {
    case 0:
        initialise([](float x) {return std::sin(x); }); //Sine wave
        break;

    case 1:
        initialise([](float x) {return x / juce::MathConstants<float>::pi; }); //Saw wave
        break;

    case 2:
        initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f; });//Square wave
        break;

    default:
        jassertfalse;
        break;
    }
}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + frequencyModulationFreq);
    lastMidiNote = midiNoteNumber;
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    for (int ch = 0; ch < block.getNumChannels(); ++ch)
    {
        for (int s = 0; s < block.getNumSamples(); ++s)
        {
            frequencyModulationFreq = frequencyModulationOsc.processSample(block.getSample(ch, s)) * frequencyModulationDepth;
        }

    }

    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscData::setFmParameters(const float depth, const float freq)
{
    frequencyModulationOsc.setFrequency(freq);
    frequencyModulationDepth = depth;
    auto currentF = juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + frequencyModulationFreq;
    setFrequency(currentF >= 0 ? currentF : currentF * -1.0f);

}