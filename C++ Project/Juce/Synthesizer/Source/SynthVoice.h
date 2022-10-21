/*
  ==============================================================================

    SynthVoice.h
    Created: 9 Aug 2022 5:11:55pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "Data/AdsrData.h"
#include "Data/OscData.h"
#include "Data/FilterData.h"

class SynthVoice : public juce::SynthesiserVoice
{
public :
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchwheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

    void updateADSR (const float attack, const float decay, const float sustain, const float release);
    void updateFilter(const int filterType, const float cutoff, const float resonance);
    void updateAdsr_Mod(const float attack, const float decay, const float sustain, const float release);

    OscData& getOscillator() { return osc; }

private:
    
    juce::AudioBuffer<float> synthBuffer;

    OscData osc;
    AdsrData adsr;
    FilterData filter;
    AdsrData adsr_Mod;
    juce::dsp::Gain<float> gain;

    bool isPrepared{ false };

    //These are values of wave
    //return std::sin(x);//sine wave
    //return x / juce::MathConstants<float>::pi; //saw wave
    //return x < 0.0f ? -1.0f : 1.0f; //square wave

};