//
//  RMSComp.cpp
//  ExampleProject - VST3
//
//  Created by Dylan Page on 3/23/21.
//  Copyright © 2021 DFITZ SP. All rights reserved.
//

#include <stdio.h>
#include "RMSComp.h"
#include <math.h>

using namespace std;

RMSComp::RMSComp(){};

void RMSComp::rmsComp(float * x, const int numSamples, const int c){};
//float RMSComp::processSignal(float buffer, int channel){
 

void RMSComp::processSample(float x, int channel){
//    float RMS = rms(dry);
    
    
//    float avgRMS = sum(RMS)/2;
//    float dynT = (avgRMS/.02);
    float newThreshold = -6.f; //(-1.35*(12-dynT));
//    newThreshold = -6.f; // I aim to make this variable based on RMS of input with a potential lookahead feature
    setAttack = 3.f;
    setRelease = .3f;
    setRatio = 20.f;
    gainSmoothPrev = 0.f;
    
    alphaA = exp(-log(9)/(Fs * setAttack));
    alphaR = exp(-log(9)/(Fs * setRelease));
    
   for (int n = 0; n <buffer.getNumSamples; n++){
        float x  = dry ;
        x_dB  = 20.f * log10(abs(x ));
        if (x_dB  < -96.f)
            x_dB  = -96.f;
        
        
        if (x_dB  > newThreshold)
            gainSC  = newThreshold + (x_dB - newThreshold)/setRatio;
        else
            gainSC  = x_dB ;
      
        gainChange_dB = gainSC  - x_dB ;
        
        if (gainChange_dB < gainSmoothPrev)
                gainSmooth = -sqrt(((1-alphaA)*gainChange_dB^2.f)+(alphaA*gainSmoothPrev^2.f));
            else
                gainSmooth = -sqrt(((1-alphaR)*gainChange_dB^2.f)+(alphaR*gainSmoothPrev^2.f));
           
            
            lin_A  = 10.f^(gainChange_dB/20.f);
            
            compOut  = lin_A  * dry ;
            
            gainSmoothPrev = gainSmooth;
     
    }
};

//void RMSComp::processSignal(float * signal, const int numSamples, const int c) {
    

        
    
}
