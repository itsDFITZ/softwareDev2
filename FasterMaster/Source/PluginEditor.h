/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SimpleMeter.h"


//==============================================================================
/**
*/
class FasterMasterAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                            public juce::Slider::Listener,
                                            public juce::Button::Listener,
                                            public juce::Timer
{
public:
    FasterMasterAudioProcessorEditor (FasterMasterAudioProcessor&);
    ~FasterMasterAudioProcessorEditor() override;

    //==============================================================================
    void timerCallback() override;
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider * slider) override;
    void buttonClicked(juce::Button * button) override;
    
    SimpleMeter meterIn;
    
    SimpleMeter meterOut;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FasterMasterAudioProcessor& audioProcessor;
    
    juce::Slider mixSlider;
    
    juce::ToggleButton muteButton;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FasterMasterAudioProcessorEditor)
};
