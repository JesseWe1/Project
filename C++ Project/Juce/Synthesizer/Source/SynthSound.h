/*
  ==============================================================================

    SynthSound.h
    Created: 9 Aug 2022 5:12:07pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiChannel) override { return true; } 


};

