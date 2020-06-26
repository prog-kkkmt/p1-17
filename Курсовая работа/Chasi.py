#==============================
#Этот модуль показывает время
#==============================

from tkinter import * 
from tkinter.ttk import *
from time import strftime

def clock():
    root = Tk()
    root.resizable(False, False)
    root.title('Часы')
    def time():
        string = strftime('%H:%M:%S %p')
        lbl.config(text = string)
        lbl.after(1000, time)
    lbl = Label(root, font = ('Ubuntu', 40, 'bold'), background = 'black', foreground = 'white')
    lbl.pack(anchor = 'center')
    time()
