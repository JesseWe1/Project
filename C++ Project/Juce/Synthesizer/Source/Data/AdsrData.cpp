/*
  ==============================================================================

    AdsrData.cpp
    Created: 10 Aug 2022 2:14:31pm
    Author:  魏冰冰

  ==============================================================================
*/

#include "AdsrData.h"

void AdsrData::updateADSR(const float attack, const float decay, const float sustain, const float release)
{
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;

    setParameters(adsrParams);

}
