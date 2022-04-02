#include "../includes/WriteMorseCode.h"

using namespace Morse;

WriteMorseCode::WriteMorseCode() : WaveMaker(440, 0.5){}

WriteMorseCode::~WriteMorseCode(){}

void WriteMorseCode::Space(double duration){
    WriteAudio(duration, 0);
}

void WriteMorseCode::Dot(){
    WriteAudio(.1, max_amp);
    Space(.05);    
}

void WriteMorseCode::Dash(){
    WriteAudio(.2, max_amp);
    Space(.05);
}

void WriteMorseCode::SetPos(){
    pre_au_pos = audio_file.tellp();
}

void WriteMorseCode::FinalizeWAVE(){
    
    audio_file.seekp(pre_au_pos - 4);
    WriteToFile(audio_file, post_au_pos - pre_au_pos, 4);
    audio_file.seekp(4, std::ios::beg);
    WriteToFile(audio_file, post_au_pos - 8, 4);
    audio_file.close();
       
}




void WriteMorseCode::WriteAudio(double duration, double l_max_amp){
        
    for(int i = 0; i < SAMPLE_RATE * duration; i++)
    {
                
        auto sample = Process();
        int intSample = static_cast<int>(sample * l_max_amp);
                
        audio_file.write(reinterpret_cast<char*>(&intSample), 2);
        WriteToFile(audio_file, intSample, 2);
                
    }
}

void WriteMorseCode::WriteToFile(std::ofstream &file, int value, int size){
    file.write(reinterpret_cast<const char*>(&value), size);
}



void WriteMorseCode::InitWAVE(){
    audio_file.open(filename, std::ios::binary);
        //Header chunk
    audio_file << "RIFF";
    audio_file << "----";
    audio_file << "WAVE";

        //fORMAT chunk
    audio_file << "fmt ";
    WriteToFile(audio_file, 16, 4);  //size
    WriteToFile(audio_file, 1, 2); //Compression code
    WriteToFile(audio_file, 2, 2);   //Number of channels
    WriteToFile(audio_file, SAMPLE_RATE, 4); //sample rate
    WriteToFile(audio_file, SAMPLE_RATE * BIT_DEPTH /8, 4); //byte rate
    WriteToFile(audio_file, BIT_DEPTH/8, 2); //BLOCK aligin
    WriteToFile(audio_file, BIT_DEPTH, 2); //bit depth

    audio_file << "data";
    audio_file << "----";

    max_amp = pow(2,BIT_DEPTH -1) -1;
}
    