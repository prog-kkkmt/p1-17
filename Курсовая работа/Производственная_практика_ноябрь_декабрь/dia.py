from tkinter import *
import tkinter as tk
import random
import ctypes

def diagnost():
    window = Tk()
    window.resizable(False, False)
    window.title("Диагностика двигателя")
    user32 = ctypes.windll.user32
    widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
    widthButton = widthButtonPlace // 7
    canvas = Canvas(window, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
    canvas.configure(bg = 'lightskyblue')
    canvas.pack()
    window.geometry('900x425')
    stoim = 0

    cilindrov = int(random.uniform(1,13))
    
    if cilindrov == 1:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '        V4\n')
        for i in range (1,5):
            a = str(int(random.uniform(1,13)))
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1
            
        txt.insert(INSERT, '\n')
    if cilindrov == 2:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '   V4 Diesel\n')
        for i in range (1,5):
            a = str(int(random.uniform(1,21))) 
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 3:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '        V6\n')
        for i in range (1,7):
            a = str(int(random.uniform(1,13)))
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 4:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '   V6 Diesel\n')
        for i in range (1,7):
            a = str(int(random.uniform(1,21))) 
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 5:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '        V8\n')
        for i in range (1,9):
            a = str(int(random.uniform(1,13)))
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 6:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '   V8 Diesel\n')
        for i in range (1,9):
            a = str(int(random.uniform(1,21))) 
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 7:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '        V10\n')
        for i in range (1,11):
            a = str(int(random.uniform(1,13)))
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 8:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '   V10 Diesel\n')
        for i in range (1,11):
            a = str(int(random.uniform(1,21))) 
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 9:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '        V12\n')
        for i in range (1,13):
            a = str(int(random.uniform(1,13)))
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 10:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '   V12 Diesel\n')
        for i in range (1,13):
            a = str(int(random.uniform(1,21))) 
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 11:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '        V16\n')
        for i in range (1,17):
            a = str(int(random.uniform(1,13)))
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if cilindrov == 12:
        txt = scrolledtext.ScrolledText(window, width = '14', height = '12', font = 'Batang 20')
        dxd = scrolledtext.ScrolledText(window, width = '21', height = '12', font = 'Batang 20')
        txt.insert(INSERT, '   V16 Diesel\n')
        for i in range (1,17):
            a = str(int(random.uniform(1,21))) 
            i1 = str(i) + ' ' + 'цилиндр' + ' ' + str(a) + '\n'
            txt.insert(INSERT, i1)
            txt.place(x = 20, y = 20)
            if int(a) < 9:
                ia = 'Не работает ' + str(i) + ' ' + 'цилиндр' + '\n'
                dxd.insert(INSERT, ia)
                dxd.place(x = 300, y = 20)
                stoim += 1

    if stoim > 0:
        g1 = Label(window)
        g1.configure(text = str(stoim * 5) + ' 000 руб.', font = 'Batang 20', bg = 'lightskyblue')
        g1.place(x = 700, y = 20)
    else:
        g1 = Label(window)
        g1.configure(text = 'Все работает', font = 'Batang 20', bg = 'lightskyblue')
        g1.place(x = 500, y = 170)
    window.mainloop()
