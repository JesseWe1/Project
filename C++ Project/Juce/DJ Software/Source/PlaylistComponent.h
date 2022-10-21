/*
  ==============================================================================

    PlaylistComponent.h
    Created: 26 Apr 2022 12:03:58pm
    Author:  魏冰冰

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class PlaylistComponent  : public Component,
                           public TableListBoxModel,
                           public Button::Listener

{
public:

    PlaylistComponent();
    ~PlaylistComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    enum {
        ID_TRACK_TITLE = 1,
        ID_PLAY
    };

    int getNumRows() override;
    void paintRowBackground(
        Graphics&,
        int rowNumber,
        int width,
        int height,
        bool rowIsSelected
    ) override;
    void paintCell(
        Graphics&,
        int rowNumber,
        int columnId,
        int width,
        int height,
        bool rowIsSelected
    ) override;

    Component* refreshComponentForCell(
        int rowNumber,
        int columnId,
        bool isRowSelected,
        Component* existingComponentToUpdate
    ) override;


private:
    TableListBox tableComponent;
    std::vector<std::string> trackTitles;
    void buttonClicked(Button* button) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlaylistComponent)
};
