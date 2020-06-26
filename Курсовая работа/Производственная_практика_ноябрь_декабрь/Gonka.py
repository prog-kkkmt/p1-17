from tkinter import *
import tkinter as tk
import ctypes

def drag():
    window = Tk()
    window.resizable(False, False)
    window.title("Дрэг-рейсинг")
    window.geometry('1100x375')

    user32 = ctypes.windll.user32
    widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
    widthButton = widthButtonPlace // 7

    canvas = Canvas(window, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
    canvas.configure(bg = 'lightskyblue')
    canvas.pack()
    
    def clicked():
        lb = Label(window)
        b = 0
        ba = 0
        if int(txt3.get())/int(txt2.get()) < int(txt8.get())/int(txt7.get()):
            b += 1
        if int(txt3.get())/int(txt2.get()) > int(txt8.get())/int(txt7.get()):
            ba += 1
        if int(txt4.get()) > int(txt9.get()):
            b += 1
        if int(txt4.get()) < int(txt9.get()):
            ba += 1
        if int(txt5.get()) > int(txt10.get()):
            ba += 1
        if int(txt5.get()) < int(txt10.get()):
            b += 1
        if b > ba:
                text = Text(window)
                vod = 'Быстрее ' + txt1.get()
                text.insert(INSERT, vod)
                text.configure(height = '1', font = 'Batang 20', width = '20')
                text.place(x = 395, y = 300)
                
        if b < ba:
                text = Text(window)
                vod = 'Быстрее ' + txt6.get()
                text.insert(INSERT, vod)
                text.configure(height = '1', font = 'Batang 20', width = '20')
                text.place(x = 395, y = 300) 
        if b == ba:
                text = Text(window)
                vod = 'Ровно'
                text.insert(INSERT, vod)
                text.configure(height = '1', font = 'Batang 20', width = '20')
                text.place(x = 395, y = 300) 
        
    b1 = Label(window)
    b2 = Label(window)
    b3 = Label(window)
    b4 = Label(window)
    b5 = Label(window)
    b1.configure(text = 'Авто', font = 'Batang 20', bg = 'lightskyblue')
    b1.place(x = 145, y = 80)
    b2.configure(text = 'Л.с.', font = 'Batang 20', bg = 'lightskyblue')
    b2.place(x = 340, y = 80)
    b3.configure(text = 'Масса', font = 'Batang 20', bg = 'lightskyblue')
    b3.place(x = 505, y = 80)
    b4.configure(text = 'Крутящий\nмомент', font = 'Batang 20', bg = 'lightskyblue')
    b4.place(x = 680, y = 55)
    b5.configure(text = 'Высота\nавто', font = 'Batang 20', bg = 'lightskyblue')
    b5.place(x = 885, y = 55)
    txt1 = Entry(window, width = 10, font = 'Batang 20')  
    txt1.place(x = 95, y = 120)
    txt2 = Entry(window, width = 10, font = 'Batang 20')  
    txt2.place(x = 285, y = 120)
    txt3 = Entry(window, width = 10, font = 'Batang 20')  
    txt3.place(x = 475, y = 120)
    txt4 = Entry(window, width = 10, font = 'Batang 20')  
    txt4.place(x = 665, y = 120)
    txt5 = Entry(window, width = 10, font = 'Batang 20')  
    txt5.place(x = 855, y = 120)
    txt6 = Entry(window, width = 10, font = 'Batang 20')  
    txt6.place(x = 95, y = 170)
    txt7 = Entry(window, width = 10, font = 'Batang 20')  
    txt7.place(x = 285, y = 170)
    txt8 = Entry(window, width = 10, font = 'Batang 20')  
    txt8.place(x = 475, y = 170)
    txt9 = Entry(window, width=10, font = 'Batang 20')  
    txt9.place(x = 665, y = 170)
    txt10 = Entry(window, width = 10, font = 'Batang 20')  
    txt10.place(x = 855, y = 170)
    btn = Button(window, text = "Клик!", command = clicked, font = 'Batang 20')  
    btn.place(x = 510, y = 220)














    
