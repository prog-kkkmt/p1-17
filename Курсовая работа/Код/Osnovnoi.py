from tkinter import *
from tkinter import messagebox
from tkinter import scrolledtext
from tkinter import ttk
from datetime import datetime
import marshryt, Tipi, instr, Raz
root = Tk()
root.geometry("1280x690")
root.title("Туристский Клуб")
root.resizable(False, False)
c = Canvas(root, width = 1280, height = 730, bg = 'black')
c.pack()
main_menu = Menu()
fon = PhotoImage(file='fon.png')
fon1 = c.create_image(640, 400,image = fon)
mar = PhotoImage(file = 'marsh.png')
tip = PhotoImage(file = 'tipi.png')
ins = PhotoImage(file = 'instr.png')
nas = PhotoImage(file = 'o_nas.png')
Button(root, width = 200, height = 100, font = "Batang 20", text = "Маршрут", command = marshryt.marsh, image = mar).place(x = 750, y = 280)
Button(root, width = 200, height = 100, font = "Batang 20", text = "Типы", command = Tipi.tt, image = tip).place(x = 750, y = 410)
Button(root, width = 200, height = 100, font = "Batang 20", text = "Инструкторы", command = instr.inst, image = ins).place(x = 1000, y = 280)
Button(root, width = 200, height = 100, font = "Batang 20", text = "О нас", command = Raz.razrab, image = nas).place(x = 1000, y = 410)
root.config(menu = main_menu)
root.mainloop()




