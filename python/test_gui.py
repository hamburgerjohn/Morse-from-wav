from tkinter import font
import build.morse
from build.morse import *
from tkinter import *
import asyncio
from pickletools import pyunicode

root = Tk()

e1 = Text(root, width=46, height=1,borderwidth=5, font=("Ariel, 24"))
e2 = Text(root, width=75, height=2,borderwidth=5, font=("Ariel, 16"))
text = Text(root, state='disabled', width=100, height=25, borderwidth=5, font=("Ariel, 12"))
e1.grid(row=1, column=2)
e2.grid(row=3, column=2)
text.grid(row=5, column=2)


l1 = Label(root, padx=20,pady=20, font=("Ariel", 15),text= "Result")

l1.grid(row=4, column=2)

decipher = PyMorseCodeDecipher()
writer = PyMorseCodePlayer()


def func(b):
    

    if b == 0:
        writer.SetFilename(e1.get("1.0", END+"-1c"))
        decipher.SetFilename(e1.get("1.0",END+"-1c"))

    if b == 1:
        writer.SetPhrase(e2.get("1.0",END+"-1c"))
        decipher.SetPhrase(e2.get("1.0",END+"-1c"))
    
    if b == 2:
        print(e2.get("1.0",END+"-1c"))
        writer.SetPhrase(e2.get("1.0",END+"-1c"))
        writer.InitWAVE()
        writer.ConvertToMorse()
        writer.RecordMorse()
    
    if b == 3:
        writer.SetPhrase(e2.get("1.0",END+"-1c"))
        writer.InitWAVE()
        writer.RecordMorse()
    
    if b == 4:
        decipher.Decipher()
        text.configure(state="normal")
        text.insert(INSERT, decipher.ConvertToEnglish() + '\n')
        text.configure(state="disabled")
    
    if b == 5:
        decipher.Decipher()
        text.configure(state="normal")
        text.insert(INSERT, decipher.GetDecipheredCode() + '\n')
        text.configure(state="disabled")

    if b == 6:
        writer.PlayMorse()

b1=Button(root, text="Set Filename",padx=65, pady=20,font=("Ariel", 12),command=lambda m=0 : func(0)).grid(row=0,column=2)
b2=Button(root, text="Set Phrase",padx=65, pady=20,font=("Ariel", 12),command=lambda m=0 : func(1)).grid(row=2,column=2)
b3=Button(root, text="English to audio",padx=50, pady=20,font=("Ariel", 12),command=lambda m=0 : func(2)).grid(row=1,column=1)
b4=Button(root, text="Morse to audio",padx=54, pady=20,font=("Ariel", 12),command=lambda m=0 : func(3)).grid(row=3,column=1)
b5=Button(root, text="English from audio",padx=44, pady=20,font=("Ariel", 12),command=lambda m=0 : func(4)).grid(row=1,column=0)
b6=Button(root, text="Morse from audio",padx=48, pady=20,font=("Ariel", 12),command=lambda m=0 : func(5)).grid(row=3,column=0)
b7=Button(root, text="Play audio",padx=65, pady=20,font=("Ariel", 12),command=lambda m=0 : func(6)).grid(row=5,column=0)

root.mainloop()