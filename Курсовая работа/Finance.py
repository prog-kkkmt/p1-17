#===================================================================
#С помощью этого модуля можно ввести учет финансовой деятельности
#===================================================================

from tkinter import *
from tkinter import messagebox
from tkinter import scrolledtext
from tkinter import ttk
from datetime import datetime
import ctypes

def Finance():
    window = Toplevel()
    window.geometry("1150x810")
    window.title("Финансы")
    window.resizable(False, False)
    
    c = Canvas(window, width = 1920, height = 1080, bg = 'white')
    c.pack()
    osnovnoi_fon = PhotoImage(file='fin2.png')
    osnovnoi_fon1 = c.create_image(700, 400, image = osnovnoi_fon)

    user32 = ctypes.windll.user32
    widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
    widthButton = widthButtonPlace // 7
    
    f = open('bug.txt', 'r', encoding = 'utf-8')
    text = Text()
    text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
    text.insert(INSERT, f.read())
    text.place(x = 465, y = 30)
    f.close()

    def clicked():
        z = open('bug.txt', 'r', encoding = 'utf-8')
        y = z.read()
        x = y.split()
        t = []
        for i in range (len(x)):
            if i%2 == 0:
                u = x[i] + ' ' + x[i+1]
            t.append(u)
        b = txt1.get()
        b1 = txt2.get()

        f = open('bug.txt', 'a', encoding = 'utf-8')
        u11 = txt1.get() + ' ' + txt2.get() + '\n'
        f.write(u11)
        f.close()
        
        
        f = open('bug.txt', 'r', encoding = 'utf-8')
        text = Text()
        text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
        text.insert(INSERT, f.read())
        text.place(x = 465, y = 30)
        f.close()

        
    def clicked1():      
        z = open('bug.txt', 'r', encoding = 'utf-8')
        y = z.read()
        x = y.split()
        t = []
        for i in range (len(x)):
            if i%2 == 0:
                u = x[i] + ' ' + x[i+1]
            t.append(u)
        b = txt3.get()
        b1 = txt4.get()
        v = open('bug.txt','w', encoding = 'utf-8')
        for i in range(len(x)):
            j = t[i].split()
            if i%2 == 0 and j[0] != b:
                v.write(j[0])
                v.write(' ')
                v.write(j[1])
                v.write('\n')
        v.close()
        f = open('bug.txt', 'r', encoding = 'utf-8')
        text = Text()
        text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
        text.insert(INSERT, f.read())
        text.place(x = 465, y = 30)
        f.close()
    
    
    lbl1 = Label(window)
    lbl2 = Label(window)
    lbl1.configure(font = 'Batang 20', text = '    Дата', bg = 'black', fg = 'white')
    lbl1.place(x = 25, y = 21)
    lbl2.configure(font = 'Batang 20', text = '   Сумма', bg = 'black', fg = 'white')
    lbl2.place(x = 200, y = 20)
    txt1 = Entry(window, width = 10, font = 'Batang 20')  
    txt1.place(x = 20, y = 60)
    txt2 = Entry(window, width = 10, font = 'Batang 20')  
    txt2.place(x = 190, y = 60)
    btn = Button(window, text = "Добавить", font = 'Batang 20', command=clicked, bg = 'seagreen')  
    btn.place(x = 105, y = 110)
    
    lbl3 = Label(window)
    lbl4 = Label(window)
    lbl3.configure(font = 'Batang 20', text = '    Дата', bg = 'black', fg = 'white')
    lbl3.place(x = 25, y = 201)
    lbl4.configure(font = 'Batang 20', text = '   Сумма', bg = 'black', fg = 'white')
    lbl4.place(x = 200, y = 200)
    txt3 = Entry(window, width = 10, font = 'Batang 20')  
    txt3.place(x = 20, y = 240)
    txt4 = Entry(window, width = 10, font = 'Batang 20')  
    txt4.place(x = 190, y = 240)
    btn1 = Button(window, text = "Удалить", font = 'Batang 20', command = clicked1, bg = 'red2')  
    btn1.place(x = 105, y = 290)
    window.mainloop()














    
