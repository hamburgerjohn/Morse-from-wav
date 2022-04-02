#include "../includes/MorseCodePlayer.h"

using namespace Morse;

MorseCodePlayer::MorseCodePlayer(const char* phrase) : WriteMorseCode(){ this->phrase = phrase;}
MorseCodePlayer::MorseCodePlayer() : WriteMorseCode(){}
MorseCodePlayer::~MorseCodePlayer(){}


void MorseCodePlayer::SetPhrase(const std::string& phrase){
    this->phrase = " " + phrase;
}

void MorseCodePlayer::SetFilename(const std::string& filename){
    this->filename = filename;
}

const std::string& MorseCodePlayer::GetFilename() const{
    return this->filename;
}

const std::string&  MorseCodePlayer::GetPhrase() const{
    return this->phrase;
}

void MorseCodePlayer::RecordMorse(){
        
    FormatCode();
    SetPos();

    for(auto i = 0; i < phrase.length(); i++){
            
        if(phrase[i] == '.') Dot(); 

        else if(phrase[i] == '-') Dash();

        else{
            Space(.25);
        } 
    }
    FinalizeWAVE();
}

void MorseCodePlayer::PlayMorse(){

    std::thread th(&MorseCodePlayer::Execute,this,"cvlc --play-and-exit " + filename);

    th.join();
}

const std::string MorseCodePlayer::ConvertToMorse() {

    std::string temp = phrase;  
     
    this->phrase = "";

    for(auto i=0; i < temp.length(); i++){
        this->phrase += m_map.find(toupper(temp[i]))->second;
            
    }
    
    return this->phrase;
}
    
void MorseCodePlayer::FormatCode(){
    
    for(auto i = 0; i < phrase.length(); i++){
        if(phrase[i] == '_' || phrase[i] == '-'){
            phrase[i] = '-';
        }
    }
}

void MorseCodePlayer::Execute(std::string cmd){
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
}