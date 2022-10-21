/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "DeckGUI.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
// you add any child components.
    
    setSize(800, 600);
    formatManager.registerBasicFormats();


    // Some platforms require permissions to open input channels so request that here
    if (RuntimePermissions::isRequired(RuntimePermissions::recordAudio)
        && !RuntimePermissions::isGranted(RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request(RuntimePermissions::recordAudio,
            [&](bool granted) { if (granted)  setAudioChannels(2, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels(0, 2);
    }
    addAndMakeVisible(deck1);
    addAndMakeVisible(deck2);
    addAndMakeVisible(deck3);
    addAndMakeVisible(deck4);
    addAndMakeVisible(playlistComponent);

    //addAndMakeVisible(gainSlider1);
    //addAndMakeVisible(gainSlider2);
    //gainSlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 15);
    //gainSlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 15);
    //gainSlider1.setColour(Slider::thumbColourId, Colours::chocolate);
    //gainSlider2.setColour(Slider::thumbColourId, Colours::chocolate);
    //gainSlider1.setColour(Slider::trackColourId, Colours::white);
    //gainSlider2.setColour(Slider::trackColourId, Colours::white);


}


MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double
    sampleRate)
{
    mixerSource.addInputSource(&player1, false);
    mixerSource.addInputSource(&player2, false);
    mixerSource.addInputSource(&player3, false);
    mixerSource.addInputSource(&player4, false);
    // note that this will call prepareToPlay
    // automatically on the two players
    mixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    // so this is not needed:
    //player1.prepareToPlay(samplesPerBlockExpected, sampleRate);
    //player2.prepareToPlay(samplesPerBlockExpected, sampleRate);
}
void MainComponent::getNextAudioBlock(const AudioSourceChannelInfo&
    bufferToFill)
{
    mixerSource.getNextAudioBlock(bufferToFill);
}
void MainComponent::releaseResources()
{
    mixerSource.removeAllInputs();
    mixerSource.releaseResources();
    player1.releaseResources();
    player2.releaseResources();
    player3.releaseResources();
    player4.releaseResources();
}




//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    float rowH = getWidth() / 4.;
    float widthH = getHeight() / 7;
    float heightH = getHeight() / 4;
    deck1.setBounds(0, 0, rowH, heightH * 3);
    deck2.setBounds(rowH, 0, rowH, heightH * 3);
    deck3.setBounds(rowH * 2, 0, rowH, heightH * 3);
    deck4.setBounds(rowH * 3, 0, rowH, heightH * 3);
    playlistComponent.setBounds(0, heightH * 3, getWidth(), heightH);


    //gainSlider1.setBounds(0, widthH * 6, getWidth()/2, widthH);
    //gainSlider2.setBounds(getWidth() / 2, widthH * 6, getWidth()/2, widthH);
}



void MainComponent::buttonClicked(Button* button)
{

    
}

void MainComponent::sliderValueChanged (Slider *slider)
{


}

/*void MainComponent::loadURL(URL audioURL)
{

    auto* reader = formatManager.createReaderFor(audioURL.createInputStream(false));
    if (reader != nullptr) // good file!
    {       
        std::unique_ptr<AudioFormatReaderSource> newSource (new AudioFormatReaderSource (reader, 
true)); 
        transportSource.setSource (newSource.get(), 0, nullptr, reader->sampleRate);             
        readerSource.reset (newSource.release());          
    }

}*/
