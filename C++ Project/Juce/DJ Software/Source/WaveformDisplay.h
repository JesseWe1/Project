/*
  ==============================================================================

    WaveformDisplay.h
    Created: 22 Mar 2022 12:20:06pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class WaveformDisplay  : public juce::Component,
    public juce::ChangeListener
{
public:
    WaveformDisplay(
        AudioFormatManager& formatManagerToUse,
        AudioThumbnailCache& cacheToUse
    );
    ~WaveformDisplay() override;

    void changeListenerCallback(ChangeBroadcaster* source) override;

    void setTime(double time);
    void paint (juce::Graphics&) override;
    void resized() override;
    void loadURL(URL audioURL);
    void setPositionRelative(double pos);
    void mouseDrag(const juce::MouseEvent& e);


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformDisplay)

        AudioThumbnail audioThumbnail;
    double position;
    bool fileLoaded = false;
    double timeData;

    float mouseX;
    float mouseY;
    float mouseW;
    float mouseH;
};
