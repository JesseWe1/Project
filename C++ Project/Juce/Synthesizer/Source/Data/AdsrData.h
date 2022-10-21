/*
  ==============================================================================

    AdsrData.h
    Created: 10 Aug 2022 2:14:31pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);




private:
    juce::ADSR::Parameters adsrParams;


};
