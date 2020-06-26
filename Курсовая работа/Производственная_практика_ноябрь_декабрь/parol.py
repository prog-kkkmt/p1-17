import ctypes
from tkinter import *

import Cena # Импортируем модули
import Fina
import Gonka
import Klient
import Raz
import dia
import sklad
import sotr
import V023

window = Tk()
window.resizable(False, False)
window.title("Безопасность")
window.geometry('600x300')# Задаем размер окна

user32 = ctypes.windll.user32
widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
widthButton = widthButtonPlace // 7

# user32.GetSystemMetrics(0) - ширина
# user32.GetSystemMetrics(1) - длина

canvas = Canvas(window, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
canvas.configure(bg = 'lightskyblue')# Цвет окна
canvas.pack()

fontSize = user32.GetSystemMetrics(0) // 80 
fontParameters = "Batang " + str(fontSize)

txt1 = Entry(width = 10, font = 'Batang 20')  
txt1.place(x = 95, y = 120)
txt2 = Entry(width = 10, font = 'Batang 20')
txt2.config(show="*")
txt2.place(x = 285, y = 120)

def read():# Функция для чтения из файла
    t = open('login.txt', 'r')
    z = t.read()
    t1 = open('password.txt', 'r')
    z1 = t1.read()
    if z == txt1.get() and txt2.get() == z1:
        V023.osnova()
    else:
        df = Tk()
        df.resizable(False, False)
        df.title("Ошибка")
        df.geometry('250x150')# Задаем размер окна

        user32 = ctypes.windll.user32
        widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
        widthButton = widthButtonPlace // 7

        canvas = Canvas(df, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
        canvas.configure(bg = 'lightskyblue')
        canvas.pack()
        l3 = Label(df)
        l3.configure(text = 'Неверно', font = 'Batang 20', bg = 'lightskyblue')
        l3.place(x = 60, y = 60)

def login():
    t = open('login.txt', 'w')
    t.write(txt1.get())

def password():
    t = open('password.txt', 'w')
    t.write(txt2.get())


l1 = Label()# Метки
l2 = Label()
l1.configure(text = 'Логин', font = 'Batang 20', bg = 'lightskyblue')
l1.place(x = 130, y = 80)
l2.configure(text = 'Пароль', font = 'Batang 20', bg = 'lightskyblue')
l2.place(x = 320, y = 80)
btn = Button(text = "Войти", command = read,  font = 'Batang 13')  
btn.place(x = 475, y = 120)
btn1 = Button(text = "Изменить логин", command = login,  font = 'Batang 13')  
btn1.place(x = 100, y = 180)
btn1 = Button(text = "Изменить пароль", command = password,  font = 'Batang 13')  
btn1.place(x = 290, y = 180)

window.mainloop()



















    
