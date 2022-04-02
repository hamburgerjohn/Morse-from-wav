#pragma once
#include "MorseCodePlayer.h"

namespace Morse{


class MorseCodeDecipher{
    
    long long eof, start;
    std::ifstream fd;
    std::string filename;
    std::string phrase;

public:
    MorseCodeDecipher(const char*);
    MorseCodeDecipher();
    ~MorseCodeDecipher();

    void SetFilename(const std::string&);
    void SetPhrase(const std::string&);
    const std::string& GetPhrase() const;
    const std::string& GetFilename() const;

    const std::string& GetDecipheredCode() const;

    void Decipher();

    const std::string ConvertToEnglish();

private:
    int32_t BytesToLE16(uint8_t*);
    int32_t BytesToBE16(uint8_t*);
    void helper(std::string&, std::string&, int);

};

}