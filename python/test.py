#cmake .. && make && python ../test.py
import asyncio
from pickletools import pyunicode
import build.morse
from build.morse import *

decipher = PyMorseCodeDecipher()
writer = PyMorseCodePlayer()

# def func(x: int, dec: PyMorseCodeDecipher, write: PyMorseCodePlayer):
#     if 

while(True):
    x = int(input("1: SetFilename  2: SetPhrase\n3: English to Audio 4: Morse to Audio\n5: Audio to English 6: Audio to Norse\n7: Play Audio\n->: "))

    match x:
        case 1:
            f = input("Enter filename: ")
            writer.SetFilename(f)
            decipher.SetFilename(f)

        case 2:
            f = input("Enter phrase: ")
            writer.SetPhrase(f)
            decipher.SetPhrase(f)

        case 3:
            writer.SetPhrase(f)
            writer.InitWAVE()
            writer.ConvertToMorse()
            writer.RecordMorse()
        
        case 4:
            writer.SetPhrase(f)
            writer.InitWAVE()
            writer.RecordMorse()

        case 5:
            decipher.Decipher()
            print(decipher.ConvertToEnglish())

        case 6:
            decipher.Decipher()
            print(decipher.GetDecipheredCode())
            
        case 7:
            writer.PlayMorse()

