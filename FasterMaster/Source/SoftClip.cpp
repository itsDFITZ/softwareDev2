//
//  SoftClip.cpp
//  ExampleProject - VST3
//
//  Created by Dylan Page on 3/23/21.
//  Copyright © 2021 DFITZ SP. All rights reserved.
//

#include "SoftClip.h"
#include <stdio.h>

using namespace std;
SoftClip::SoftClip(){};

void SoftClip::softClip(float * signal, const int numSamples, const int c){};
//float SoftClip::processSample(float x, int c){
//    return 1.f;
//};

void SoftClip::processSample(float * signal, const int numSamples, const int c) {
    
    float thresh = .99f;
    float x = x;
    

      
       if (x > thresh)
           x = thresh;
       if (x < -thresh)
           x = -thresh;
       
        
    }
}
