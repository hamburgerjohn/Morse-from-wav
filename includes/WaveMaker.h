#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <unistd.h>
#include <memory>
#include <map>
#include <cctype>
#include <algorithm>
#include <thread>

namespace Morse{

#define SAMPLE_RATE 44100
#define BIT_DEPTH 16

class WaveMaker{

protected:
        float freq, amp, angle = 0.0f, offset = 0.0f;

        WaveMaker(float, float);
        ~WaveMaker();

        float Process();

};

}