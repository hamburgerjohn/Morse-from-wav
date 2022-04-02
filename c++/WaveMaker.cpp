#include "../includes/WaveMaker.h"

using namespace Morse;

WaveMaker::WaveMaker(float freq, float amp) : freq(freq), amp(amp){
    offset = 2 * M_PI * freq / SAMPLE_RATE;
}

WaveMaker::~WaveMaker(){}

float WaveMaker::Process(){
    auto sample = amp * sin(angle);
    angle += offset;
    return sample;
}