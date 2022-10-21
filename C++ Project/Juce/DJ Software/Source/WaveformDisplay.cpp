/*
  ==============================================================================

    WaveformDisplay.cpp
    Created: 22 Mar 2022 12:20:06pm
    Author:  魏冰冰

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WaveformDisplay.h"

//==============================================================================
WaveformDisplay::WaveformDisplay(AudioFormatManager& formatManagerToUse,
    AudioThumbnailCache& cacheToUse)
    : audioThumbnail(1000, formatManagerToUse,
        cacheToUse),
    fileLoaded(false),position(0),timeData(0), mouseX(0),mouseY(0),mouseW(0),mouseH(0)
{
    audioThumbnail.addChangeListener(this);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

WaveformDisplay::~WaveformDisplay()
{
}

void WaveformDisplay::loadURL(URL audioURL)
{
    audioThumbnail.clear();
    fileLoaded = audioThumbnail.setSource(new URLInputSource(audioURL));
}

void WaveformDisplay::setPositionRelative(double pos)
{
    if (pos > 0. && pos != position)
    {
        position = pos;
        repaint();
    }
}

void WaveformDisplay::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour
    (ResizableWindow::backgroundColourId));
    g.setColour(Colours::white);
    g.drawRect(getLocalBounds(), 1);
    g.setColour(Colours::white);

    if (fileLoaded)
    {
        audioThumbnail.drawChannel(g, getLocalBounds(), 0,
            audioThumbnail.getTotalLength(), 0, 1.0f);
        //g.setColour(Colours::mediumpurple);
        //g.drawRect(0 * getWidth(), 0, getWidth() / 2, getHeight());
        g.setColour(Colours::chocolate);
        g.drawLine(position * getWidth(), getHeight(), position * getWidth(), 0);
        g.setColour(Colours::red);
        juce::String timeString(timeData, 2);
        g.drawText(timeString, getLocalBounds(), juce::Justification::centred, true);


        g.setColour(juce::Colours::chocolate);
        g.setOpacity(0.3);
        g.fillRect(position * getWidth(), 0, (audioThumbnail.getTotalLength() - position) * getWidth(), getHeight());

        mouseH = getHeight();
        if ((mouseX + mouseW) > mouseX) {
            g.setColour(juce::Colours::darkcyan);
            g.setOpacity(0.3);
            g.fillRect(mouseX, 0., mouseW, mouseH);
            g.fillRect(mouseX, 0., mouseW, mouseH);
        }
    }
    //else if (mouseDoubleClicked)
    //{
        //g.setColour(Colours::darkcyan);
        //g.drawRect(position * getWidth(), 0, getWidth() / 20, getHeight());
   // }
    else
    {
        g.fillAll(getLookAndFeel().findColour
        (ResizableWindow::backgroundColourId)); // clear the background
        g.setColour(Colours::chocolate);
        g.setFont(20.0f);
        g.drawText("Load the file!!", getLocalBounds(),
            Justification::centred, true); // draw some placeholder text
    }

}

void WaveformDisplay::setTime(double time) {
    if (time > 0. && time != timeData)
    {
        timeData = time;
    }
}

void WaveformDisplay::changeListenerCallback
(ChangeBroadcaster* source)
{
    std::cout << "wfd: change received!" << std::endl;
    repaint();
}



void WaveformDisplay::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


void WaveformDisplay::mouseDrag(const juce::MouseEvent& e) {

    mouseX = e.getMouseDownX();
    mouseW = e.getDistanceFromDragStartX();

}