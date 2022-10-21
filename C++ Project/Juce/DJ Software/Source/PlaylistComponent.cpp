/*
  ==============================================================================

    PlaylistComponent.cpp
    Created: 26 Apr 2022 12:03:59pm
    Author:  魏冰冰

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PlaylistComponent.h"

//==============================================================================
PlaylistComponent::PlaylistComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    addAndMakeVisible(tableComponent);
    tableComponent.getHeader().addColumn("Track title", ID_TRACK_TITLE, 400);
    tableComponent.getHeader().addColumn("Play", ID_PLAY, 400);
    tableComponent.setModel(this);
    trackTitles.push_back("Track 1");
    trackTitles.push_back("Track 2");
    trackTitles.push_back("Track 3");
    trackTitles.push_back("Track 4");


}

PlaylistComponent::~PlaylistComponent()
{
}

void PlaylistComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("PlaylistComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void PlaylistComponent::resized()
{
    tableComponent.setBounds(0, 0, getWidth(), getHeight());
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

int PlaylistComponent::getNumRows()
{
    return trackTitles.size();
}

void PlaylistComponent::paintRowBackground(
    Graphics& g,
    int rowNumber,
    int width,
    int height,
    bool rowIsSelected
) {
    // just highlight selected rows
    if (rowIsSelected)
    {
        g.fillAll(Colours::chocolate);
    }
    else {
        g.fillAll(Colours::darkgrey);
    }
}

void PlaylistComponent::paintCell(
    Graphics& g,
    int rowNumber,
    int columnId,
    int width,
    int height,
    bool rowIsSelected
) {
    g.drawText(
        trackTitles[rowNumber], // the important bit
        2, 0,
        width - 4, height,
        Justification::centredLeft,
        true
    );
}

Component* PlaylistComponent::refreshComponentForCell(
    int rowNumber,
    int columnId,
    bool isRowSelected,
    Component* existingComponentToUpdate
) {
    if (ID_PLAY == columnId)
    {
        if (!existingComponentToUpdate)
        {
            auto* btn = new TextButton("play");
            existingComponentToUpdate = btn;
            btn->addListener(this);
            btn->setComponentID(std::to_string(rowNumber));
        }
    }
    return existingComponentToUpdate;
}

void PlaylistComponent::buttonClicked(Button* button)
{
    int id = std::stoi(button->getComponentID().toStdString());
    std::cout << "PlaylistComponent::buttonClicked " << trackTitles[id] <<
        std::endl;
}


