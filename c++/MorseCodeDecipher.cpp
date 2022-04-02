#include "../includes/MorseCodeDecipher.h"


using namespace Morse;

MorseCodeDecipher::MorseCodeDecipher(const char* filename) : filename(filename){}
MorseCodeDecipher::MorseCodeDecipher(){}
MorseCodeDecipher::~MorseCodeDecipher(){}

void MorseCodeDecipher::SetPhrase(const std::string& phrase){
    this->phrase = phrase;
}

void MorseCodeDecipher::SetFilename(const std::string& filename){
    this->filename = filename;
        
}

const std::string& MorseCodeDecipher::GetPhrase() const{
    return this->phrase;
}

const std::string& MorseCodeDecipher::GetFilename() const{
    return this->filename;
}

const std::string& MorseCodeDecipher::GetDecipheredCode() const{
    return this->phrase;
}

void MorseCodeDecipher::Decipher(){
        
    fd.open(filename, std::ios::in|std::ios::binary|std::ios::ate);
    phrase = "";

    fd.seekg(0, std::ios::end);
    eof = fd.tellg();

    fd.seekg(44);
    start = fd.tellg();

    int on=0, off=0;

    char * signal = new char[2];

    for(int32_t i=start; i<eof; i += 120){
		
        fd.read(signal, 2);
        uint32_t decoded = BytesToLE16((uint8_t*)signal);
            
        if(decoded != 0)
        {
            if(off > 500)
                phrase += "   ";
            else if(off > 200)
                phrase += " "; 
            on++;
            off = 0;
        }
                    
        else
        {
            if(on > 200)
                phrase += "-";
            else if(on > 100)
                phrase += ".";

            off++;
            on = 0;
        }

        fd.seekg(i);
			
	}

    fd.close();
    delete[] signal;

}

const std::string MorseCodeDecipher::ConvertToEnglish(){
    
    std::string temp1 = "", temp2 = this->phrase;
    int space_count=0;

    this->phrase = "";

    for(auto i=0; i < temp2.length(); i++){

        if(phrase[i] != 32){
            temp1 += phrase[i];
            space_count = 0;
        }
        else{
            space_count++;
            helper(this->phrase, temp1, space_count);
                    
            temp1 = "";
        }

    }
    helper(this->phrase, temp1, space_count);
    return this->phrase;
}



int32_t MorseCodeDecipher::BytesToLE16(uint8_t byte[2]){
 	return byte[0] | byte[1] << 8;
}

int32_t MorseCodeDecipher::BytesToBE16(uint8_t byte[2]){
 	return byte[1] | byte[0] << 8;
}

void MorseCodeDecipher::helper(std::string& english, std::string& temp, int space_count){
        
    auto findResult = std::find_if(std::begin(m_map), std::end(m_map), [&](const std::pair<int, const char*> &pair)
            {
                return pair.second == temp + " ";
            });

    if(findResult->first != 27)
        english += findResult->first;
            
    else english += 32;
}