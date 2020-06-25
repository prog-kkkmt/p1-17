from tkinter import *  
import ctypes

def razrab():
    window = Tk()
    window.resizable(False, False)
    window.title("О нас")
    user32 = ctypes.windll.user32
    widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
    widthButton = widthButtonPlace // 7
    f = open('proga.txt','r', encoding='utf-8')
    canvas = Canvas(window, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
    canvas.configure(bg = 'pink')
    canvas.pack()
    window.geometry('800x600')
    txt = scrolledtext.ScrolledText(window, height = '15', font = 'Batang 20', width = '49')
    txt.insert(INSERT, f.read())
    txt.place(x = 20, y = 55)  
    window.mainloop()

















    
