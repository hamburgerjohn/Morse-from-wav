#include "../includes/MorseCodeDecipher.h"

//-----------------------------__________________________________________________--------------------------------------

int main(int argc, char** argv){

    Morse::MorseCodeDecipher* decipher = new Morse::MorseCodeDecipher();
    Morse::MorseCodePlayer* writer = new Morse::MorseCodePlayer();

    int x;
    std::string op;
    while(true){
        std::cout << "1: SetFilename  2: SetPhrase\n3: English to Audio 4: Morse to Audio\n5: Audio to English 6: Audio to Norse\n7: Play Audio\n->: ";
        std::cin >> x;
        std::getchar();

    switch(x)
    {
    
        case 1:
            std::cout << "Enter filename: ";
            std::getline(std::cin, op);
            writer->SetFilename(op);
            decipher->SetFilename(op);
            break;

        case 2:
            std::cout << "Enter phrase: ";
            std::getline(std::cin, op);
            writer->SetPhrase(op);
            decipher->SetPhrase(op);
            break;

        case 3:
    
            writer->InitWAVE();
            writer->ConvertToMorse();
            writer->RecordMorse();
            break;
        
        case 4:

            writer->InitWAVE();
            writer->SetPhrase(writer->GetPhrase());
            writer->RecordMorse();
            break;

        case 5:
            decipher->Decipher();
            std::cout << decipher->ConvertToEnglish() << '\n';
            break;

        case 6:
            decipher->Decipher();
            std::cout << decipher->GetDecipheredCode() << '\n';
            break;

        case 7:
            writer->PlayMorse();
            break;

    }
}
}