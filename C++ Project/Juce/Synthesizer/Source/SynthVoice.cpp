/*
  ==============================================================================

    SynthVoice.cpp
    Created: 9 Aug 2022 5:11:55pm
    Author:  魏冰冰

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;

}


void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchwheelPosition)
{
    osc.setWaveFrequency(midiNoteNumber);
    adsr.noteOn();
    adsr_Mod.noteOn();

}


void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    adsr.noteOff();
    adsr_Mod.noteOff();

    if (!allowTailOff || !adsr.isActive())
        clearCurrentNote();

}


void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{


}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{

}

void SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels)
{


    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;

    osc.prepareToPlay(spec);
    adsr.setSampleRate(sampleRate);
    filter.prepareToPlay(sampleRate, samplesPerBlock, outputChannels);
    adsr_Mod.setSampleRate(sampleRate);
    gain.prepare(spec);

 
    gain.setGainLinear(0.3f);



    isPrepared = true;
}

void SynthVoice::updateADSR(const float attack, const float decay, const float sustain, const float release)
{
    adsr.updateADSR(attack, decay, sustain, release);

}
void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    jassert (isPrepared);

    if (! isVoiceActive())
        return;

    synthBuffer.setSize(outputBuffer.getNumChannels(), numSamples, false, false, true);
    adsr_Mod.applyEnvelopeToBuffer(synthBuffer, 0, numSamples);
    synthBuffer.clear();


    juce::dsp::AudioBlock<float> audioBlock{ synthBuffer };
    osc.getNextAudioBlock(audioBlock);
    adsr.applyEnvelopeToBuffer(synthBuffer, 0, synthBuffer.getNumSamples());
    filter.process(synthBuffer);
    gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));

   


    for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
    {
        outputBuffer.addFrom(channel, startSample, synthBuffer, channel, 0, numSamples);

        if (!adsr.isActive())
            clearCurrentNote();

    }
}

void SynthVoice::updateFilter(const int filterType, const float cutoff, const float resonance)
{
    float mod = adsr_Mod.getNextSample();
    filter.updateParameters(filterType, cutoff, resonance, mod);
}

void SynthVoice::updateAdsr_Mod(const float attack, const float decay, const float sustain, const float release)
{
    adsr_Mod.updateADSR(attack, decay, sustain, release);
}
