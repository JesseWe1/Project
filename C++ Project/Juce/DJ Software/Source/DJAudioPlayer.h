/*
  ==============================================================================

    DJAudioPlayer.h
    Created: 8 Mar 2022 8:00:22pm
    Author: Bingbing Wei

  ==============================================================================
*/

#pragma once
// assumes your JuceHeader file is here
// check your MainComponent.h to see
// how the include is configured on your
// system
#include "../JuceLibraryCode/JuceHeader.h"
class DJAudioPlayer : public AudioSource {
public:
    DJAudioPlayer(AudioFormatManager& formatManager);
    ~DJAudioPlayer();

    /** get the relative position of the play head */
    double getPositionRelative();
    double getPosition();



    void prepareToPlay(int samplesPerBlockExpected, double sampleRate)
        override;
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
        override;
    void releaseResources() override;
    void loadURL(const URL& audioURL);
    void setGain(double gain);
    void setSpeed(double ratio);
    void setPosition(double posInSecs);
    void setPositionRelative(double pos);
    void play();
    void stop();
private:


    AudioFormatManager& formatManager;
    std::unique_ptr<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    ResamplingAudioSource resampleSource{ &transportSource, false, 2 };
};


