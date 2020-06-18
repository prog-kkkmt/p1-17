from tkinter import *
from tkinter import ttk
from tkinter import scrolledtext
import ctypes
import tkinter as tk
import random

def tt():
    window = Tk()
    window.resizable(False, False)
    window.title("Типы")
    window.geometry('1100x700')

    user32 = ctypes.windll.user32
    widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
    widthButton = widthButtonPlace // 7

    canvas = Canvas(window, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
    canvas.configure(bg = 'pink')
    canvas.pack()

    f = open('tipi.txt', 'r', encoding = 'utf-8')
    text = Text()
    text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
    text.insert(INSERT, f.read())
    text.place(x = 425, y = 80)
    f.close()

    def clicked_dobavlenie():
        z = open('tipi.txt', 'r', encoding = 'utf-8')
        y = z.read()
        x = y.split()
        tipi = []
        for i in range (0, len(x), 2):
            u = x[i] + ' ' + x[i+1]
            tipi.append(u)
        b = txt1.get()
        

        f = open('tipi.txt', 'a', encoding = 'utf-8')
        u11 = txt1.get() + ' ' + com.get() + '\n'
        f.write(u11)
        f.close()
        
        
        f = open('tipi.txt', 'r', encoding = 'utf-8')
        text = Text()
        text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
        text.insert(INSERT, f.read())
        text.place(x = 425, y = 80)
        f.close()

        
    def clicked_delete():      
        z = open('tipi.txt', 'r', encoding = 'utf-8')
        y = z.read()
        x = y.split()
        tipi = []
        for i in range (len(x)):
            if i % 2 == 0:
                u = x[i] + ' ' + x[i+1]
            tipi.append(u)
        b = txt3.get()
        b1 = com.get()
        v = open('tipi.txt','w', encoding = 'utf-8')
        for i in range(len(x)):
            j = tipi[i].split()
            if i%2 == 0 and j[0] != b:
                v.write(j[0])
                v.write(' ')
                v.write(j[1])
                v.write('\n')
        v.close()
        f = open('tipi.txt', 'r', encoding = 'utf-8')
        text = Text()
        text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
        text.insert(INSERT, f.read())
        text.place(x = 425, y = 80)
        f.close()
    
    
    lbl1 = Label(window)
    lbl2 = Label(window)
    lbl1.configure(font = 'Batang 20', text = '  Стоимость', bg = 'pink', fg = 'crimson')
    lbl1.place(x = 10, y = 81)
    lbl2.configure(font = 'Batang 20', text = '  Тип отдыха', bg = 'pink', fg = 'crimson')
    lbl2.place(x = 180, y = 80)
    txt1 = Entry(window, width = 10, font = 'Batang 20')  
    txt1.place(x = 20, y = 120)
    btn = Button(window, text = "Добавить", font = 'Batang 20', command = clicked_dobavlenie, bg = 'hotpink')  
    btn.place(x = 105, y = 170)
    
    lbl3 = Label(window)
    lbl4 = Label(window)
    lbl3.configure(font = 'Batang 20', text = '  Стоимость', bg = 'pink', fg = 'crimson')
    lbl3.place(x = 10, y = 281)
    lbl4.configure(font = 'Batang 20', text = '  Тип отдыха', bg = 'pink', fg = 'crimson')
    lbl4.place(x = 180, y = 280)
    txt3 = Entry(window, width = 10, font = 'Batang 20')  
    txt3.place(x = 20, y = 320)
    btn1 = Button(window, text = "Удалить", font = 'Batang 20', command = clicked_delete, bg = 'hotpink')  
    btn1.place(x = 105, y = 370)
    com = ttk.Combobox(window)
    com.place(x = 190, y = 120, height = 37, width = 155)
    com['values'] = ['Рюкзаки', 'Скалолазание', 'Рыбалка', 'Каяки', 'Восхождения', 'Яхтинг']
    com.current(0)
    com2 = ttk.Combobox(window)
    com2.place(x = 190, y = 320, height = 37, width = 155)
    com2['values'] = ['Рюкзаки', 'Скалолазание', 'Рыбалка', 'Каяки', 'Восхождения', 'Яхтинг']
    com2.current(0)


  
    












    
