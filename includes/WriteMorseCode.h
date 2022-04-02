#pragma once
#include "WaveMaker.h"


namespace Morse{


class WriteMorseCode : public WaveMaker{

protected:
    std::string filename;

private:
    std::ofstream audio_file;
    double max_amp;
    int pre_au_pos, post_au_pos;

protected:
    WriteMorseCode();
    ~WriteMorseCode();

    void Space(double);
    void Dot();
    void Dash();

    void SetPos();
    void FinalizeWAVE();

private:
    void WriteAudio(double, double);
    void WriteToFile(std::ofstream&, int, int);

public:
    void InitWAVE();

};

}