#========================================================
#С помощью этого модуля можно ввести учет автозапчастей
#========================================================
from tkinter import *
import tkinter as tk
import random
from tkinter import scrolledtext
import ctypes

def Avto_zapchasti():
    window = Toplevel()
    window.resizable(False, False)
    window.title("Склад")
    window.geometry('1100x700')
 
    user32 = ctypes.windll.user32
    widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
    widthButton = widthButtonPlace // 7
    canvas = Canvas(window, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
    canvas.configure(bg = 'black')
    canvas.pack()
    
    f = open('skl.txt', 'r', encoding = 'utf-8')
    text = Text()
    text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
    text.insert(INSERT, f.read())
    text.place(x = 425, y = 80)
    f.close()

    def clicked_dobavlenie():
        z = open('skl.txt', 'r', encoding = 'utf-8')
        y = z.read()
        x = y.split()
        t = []
        for i in range (len(x)):
            if i%2 == 0:
                u = x[i] + ' ' + x[i+1]
            t.append(u)
        b = txt1.get()
        b1 = int(txt2.get())
        v = open('skl.txt','w', encoding = 'utf-8')
        for i in range(len(x)):
            j = t[i].split()
            if i%2 == 0 and j[0] != b:
                v.write(j[0])
                v.write(' ')
                v.write(j[1])
                v.write('\n')
            if j[0] == b and i%2 == 0:
                v.write(j[0])
                l = int(j[1]) + b1
                v.write(' ')
                v.write(str(l))
                v.write('\n')
        v.close()
        f = open('skl.txt', 'r', encoding = 'utf-8')
        text = Text()
        text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
        text.insert(INSERT, f.read())
        text.place(x = 425, y = 80)
        f.close()

        
    def clicked_delete():      
        z = open('skl.txt', 'r', encoding = 'utf-8')
        y = z.read()
        x = y.split()
        t = []
        for i in range (len(x)):
            if i%2 == 0:
                u = x[i] + ' ' + x[i+1]
            t.append(u)
        b = txt3.get()
        b1 = int(txt4.get())
        v = open('skl.txt','w', encoding = 'utf-8')
        for i in range(len(x)):
            j = t[i].split()
            if i%2 == 0 and j[0] != b:
                v.write(j[0])
                v.write(' ')
                v.write(j[1])
                v.write('\n')
            if j[0] == b and i%2 == 0:
                v.write(j[0])
                l = int(j[1]) - b1
                v.write(' ')
                v.write(str(l))
                v.write('\n')
        v.close()
        f = open('skl.txt', 'r', encoding = 'utf-8')
        text = Text()
        text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
        text.insert(INSERT, f.read())
        text.place(x = 425, y = 80)
        f.close()
    
    
    lbl1 = Label(window)
    lbl2 = Label(window)
    lbl1.configure(font = 'Batang 20', text = 'Название\nтовара', bg = 'black', fg = 'white')
    lbl1.place(x = 40, y = 51)
    lbl2.configure(font = 'Batang 20', text = 'Кол-во', bg = 'black', fg = 'white')
    lbl2.place(x = 225, y = 80)
    txt1 = Entry(window, width = 10, font = 'Batang 20')  
    txt1.place(x = 20, y = 120)
    txt2 = Entry(window, width = 10, font = 'Batang 20')  
    txt2.place(x = 190, y = 120)
    btn = Button(window, text = "Добавить", font = 'Batang 20', command = clicked_dobavlenie, bg = 'seagreen')  
    btn.place(x = 105, y = 170)
    
    lbl3 = Label(window)
    lbl4 = Label(window)
    lbl3.configure(font = 'Batang 20', text = 'Название\nтовара', bg = 'black', fg = 'white')
    lbl3.place(x = 40, y = 251)
    lbl4.configure(font = 'Batang 20', text = 'Кол-во', bg = 'black', fg = 'white')
    lbl4.place(x = 225, y = 280)
    txt3 = Entry(window, width = 10, font = 'Batang 20')  
    txt3.place(x = 20, y = 320)
    txt4 = Entry(window, width = 10, font = 'Batang 20')  
    txt4.place(x = 190, y = 320)
    btn1 = Button(window, text = "Удалить", font = 'Batang 20', command = clicked_delete, bg = 'red2')  
    btn1.place(x = 105, y = 370)
    def Help():
        window = Toplevel()
        window.resizable(False, False)
        window.title("Помощь")
        window.geometry('555x120')
        user32 = ctypes.windll.user32
        widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
        widthButton = widthButtonPlace // 7
        canvas = Canvas(window, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
        canvas.configure(bg = 'black')
        canvas.pack()
        lbl1 = Label(window)
        lbl1.configure(font = 'Batang 30', text = 'Вернитесь в главное меню и\n нажмите "Помощь"', bg = 'black', fg = 'white')
        lbl1.place(x = 10, y = 10)
    Button(window, width = 15, height = 2, font = "Batang 20", text = "Help", command = Help, bg = 'Red2', fg = 'Black').place(x = 30, y = 500)
