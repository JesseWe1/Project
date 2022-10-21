/*
  ==============================================================================

    DJAudioPlayer.cpp
    Created: 8 Mar 2022 8:00:22pm
    Author:  魏冰冰

  ==============================================================================
*/

#include "DJAudioPlayer.h"
DJAudioPlayer::DJAudioPlayer(AudioFormatManager& afm)
    : formatManager(afm)
{
    //formatManager.registerBasicFormats();
}
DJAudioPlayer::~DJAudioPlayer()
{
}

double DJAudioPlayer::getPositionRelative()
{
    return transportSource.getCurrentPosition() / transportSource.getLengthInSeconds();
}

double DJAudioPlayer::getPosition() 
{
    return transportSource.getCurrentPosition();
}

void DJAudioPlayer::prepareToPlay(int samplesPerBlockExpected, double
    sampleRate)
{
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    resampleSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}
void DJAudioPlayer::getNextAudioBlock(const AudioSourceChannelInfo&
    bufferToFill)
{
    resampleSource.getNextAudioBlock(bufferToFill);
}
void DJAudioPlayer::releaseResources()
{
    transportSource.releaseResources();
    resampleSource.releaseResources();
}
void DJAudioPlayer::loadURL(const URL& audioURL)
{
    auto* reader =
        formatManager.createReaderFor(audioURL.createInputStream(false));
    if (reader) // good file!
    {
        std::unique_ptr<AudioFormatReaderSource> newSource(new
            AudioFormatReaderSource(reader, true));
        transportSource.setSource(newSource.get(), 0, nullptr, reader -> sampleRate);
        readerSource.reset(newSource.release());
    }
}
void DJAudioPlayer::setGain(double gain)
{
    transportSource.setGain(gain);
}
void DJAudioPlayer::setSpeed(double ratio)
{
    if (ratio <= 0.)
    {
        std::cout << "DJAudioPlayer::setSpeed ratio must be greater than 0"
            << std::endl;
    }
    else {
        resampleSource.setResamplingRatio(ratio);
    }
}
void DJAudioPlayer::setPosition(double posInSecs)
{
    if (posInSecs < 0 || posInSecs > transportSource.getLengthInSeconds()) {
        std::cout
            << "DJAudioPlayer::setPosition: warning set position " <<
            posInSecs
            << " greater than length " << transportSource.getLengthInSeconds()
            << std::endl;
        return;
    }
    transportSource.setPosition(posInSecs);
}

void DJAudioPlayer::setPositionRelative(double pos)
{
    if (pos < 0 || pos > 1.0)
    {
        std::cout << "DJAudioPlayer::setPositionRelative pos should be between 0 and 1" << std::endl;
    }
    else {
        double posInSecs = transportSource.getLengthInSeconds() * pos;
        setPosition(posInSecs);
    }
}
void DJAudioPlayer::play()
{
    transportSource.start();
}
void DJAudioPlayer::stop()
{
    transportSource.stop();
}
