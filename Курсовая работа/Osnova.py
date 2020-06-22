#=========================
#Главный модуль программы
#=========================

from tkinter import *
from tkinter import messagebox
from tkinter import scrolledtext
from tkinter import ttk
from datetime import datetime
import ctypes
import Avto_zapchasti, Finance
import Klient, Sotrudniki, Price, Diagnostika
import Razrabotchiki, Chasi, O_prodramme, Test_drive

def Kalkulator():
    root = Tk()
    root.geometry("240x230")
    root.resizable(False, False)
    root.title("Калькулятор")
    root.configure(bg = 'black')

    def calc(key):
        global memory
        if key == "=":
            str1 = "-+0123456789.*/"
            if calc_entry.get()[0] not in str1:
                calc_entry.insert(END, "Первый символ не число")
                messagebox.showerror("Ошибка!", "Вы ввели не число!")

            try:
                result = eval(calc_entry.get())
                calc_entry.insert(END, "=" + str(result))
            except:
                calc_entry.insert(END, "Ошибка!")
                messagebox.showerror("Ошибка!", "Проверьте правильность данных.")

        elif key == "C":
            calc_entry.delete(0, END)

        elif key == "-/+":
            if "=" in calc_entry.get():
                calc_entry.delete(0, END)
                try:
                    if calc_entry.get()[0] == "-":
                        calc_entry.delete(0)
                    else:
                        calc_entry.insert(0, "-")
                except IndexError:
                    pass
        else:
            if "=" in calc_entry.get():
                calc_entry.delete(0, END)
            calc_entry.insert(END, key)


    bttn_list = ["7", "8", "9", "+", "-",
                 "4", "5", "6", "*", "/",
                 "1", "2", "3", "-/+", "=",
                 "0", ".", "C", "", ""]
    r = 1
    c = 0

    for i in bttn_list:
        rel = ""
        cmd = lambda x = i: calc(x)
        b = Button(root, bg = 'black', fg = 'white', font = 20, text = i, width = 4, height = 2, command = cmd).grid(row = r, column = c)
        c += 1
        if c > 4:
            c = 0
            r += 1

    calc_entry = Entry(root, width = 33)
    calc_entry.grid(row = 0, column = 0, columnspan = 5)
    root.mainloop()

def sprav():
    okno1 = Tk()
    okno1.geometry("1600x860")
    okno1.title("Программное обеспечение для автосервиса")
    okno1.resizable(False, False)
    okno1.configure(bg = 'black')
    bttn1 = Label(okno1)
    bttn1.configure(text = 'В разработке', font = ('Batang 20', 70), bg = 'black', fg = 'white')
    bttn1.place(x = 500, y = 400)
    okno1.mainloop()

def system():
    okno1 = Toplevel()
    okno1.geometry("1000x700")
    okno1.title("Системные требования")
    okno1.resizable(False, False)
    okno1.configure(bg = 'black')
    c = Canvas(okno1, width = 1800, height = 800, bg = 'white')
    c.pack()
    osnovnoi_fon = PhotoImage(file = 'Sis.png')
    osnovnoi_fon1 = c.create_image(500, 300, image = osnovnoi_fon)
    sis1 = Label(okno1)
    sis1.configure(text = 'Минимальные требования\n ОС: Windows 7/8/10\n Процессор: 2.0 GHz\n Оперативная память: 4 GB ОЗУ\n Видеокарта: NVIDIA GeForce GT 520\n Место на диске: 4 MB' , font = 'Batang 20', bg = 'black', fg = 'white')
    sis1.place(x = 500, y = 40)
    okno1.mainloop()

def celi():
    okno1 = Toplevel()
    okno1.geometry("1600x860")
    okno1.title("Цели")
    okno1.resizable(False, False)
    okno1.configure(bg = 'black')
    c = Canvas(okno1, width = 1920, height = 1080, bg = 'white')
    c.pack()
    osnovnoi_fon = PhotoImage(file = 'Sis.png')
    osnovnoi_fon1 = c.create_image(700, 400, image = osnovnoi_fon)
    okno1.mainloop()

def Help1():
    okno1 = Toplevel()
    okno1.geometry("1000x600")
    okno1.title("Помощь")
    okno1.resizable(False, False)
    okno1.configure(bg = 'black')
    c = Canvas(okno1, width = 1800, height = 800, bg = 'white')
    c.pack()
    osnovnoi_fon = PhotoImage(file = 'Help1.png')
    osnovnoi_fon1 = c.create_image(500, 300, image = osnovnoi_fon)
    sis1 = Label(okno1)
    sis1.configure(text = 'Позвоните по телефону:\n 8 498 601 22 01\n Сообщите в техническую поддержку:\n версию программы и индивидуальный номер программы\n Верcия 0.0.4\n WBK067JPA' , font = 'Batang 20', bg = 'black', fg = 'white')
    sis1.place(x = 200, y = 40)
    okno1.mainloop()

def clock():
    import sekyndomer

okno1 = Tk()
okno1.geometry("1550x810")
okno1.title("Программное обеспечение для автотехцентра")
okno1.resizable(False, False)
c = Canvas(okno1, width = 1920, height = 1080, bg = 'white')
c.pack()
gg1 = Label(okno1)
gg1.configure(text = 'Технический блок', font = 'Batang 20', bg = 'black', fg = 'white')
gg1.place(x = 965, y = 40)
gg2 = Label(okno1)
gg2.configure(text = 'Руководящий блок', font = 'Batang 20', bg = 'black', fg = 'white')
gg2.place(x = 1265, y = 40)
main_menu = Menu()
osnovnoi_fon = PhotoImage(file='osnovnoi_fon.png')
z = PhotoImage(file = 'avtozapchasti.png')
f = PhotoImage(file = 'finansi.png')
t = PhotoImage(file = 'test_drive.png')
h = PhotoImage(file = 'help.png')
cr = PhotoImage(file = 'razrabotchiki.png')
kl = PhotoImage(file = 'klienti.png')
opr = PhotoImage(file = 'o_programme.png')
prl = PhotoImage(file = 'price_list.png')
s = PhotoImage(file = 'sotrydniki.png')
dd = PhotoImage(file = 'diagnostika.png')
osnovnoi_fon1 = c.create_image(830, 455, image = osnovnoi_fon)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Автозапчасти", command = Avto_zapchasti.Avto_zapchasti, image = z).place(x = 950, y = 80)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Финансы", command = Finance.Finance, image = f).place(x = 1250, y = 220)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Тест - драйв", command = Test_drive.Test_drive, image = t).place(x = 950, y = 360)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "О программе", command = O_prodramme.O_prodramme, image = opr).place(x = 950, y = 500)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Разработчики", command = Razrabotchiki.Razrabotchiki, image = cr).place(x = 1250, y = 640)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Сотрудники", command = Sotrudniki.Sotrudniki, image = s).place(x = 1250, y = 80)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Диагностика\nдвигателя", command = Diagnostika.Diagnostika, image = dd).place(x = 950, y = 220)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Клиенты", command = Klient.Klient, image = kl).place(x = 1250, y = 360)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Прайс - лист", command = Price.Price, image = prl).place(x = 1250, y = 500)
Button(okno1, width = 260, height = 105, font = "Batang 20", text = "Помощь", command = Help1, image = h).place(x = 950, y = 640)


file_menu = Menu(tearoff = 0)
file_menu1 = Menu(tearoff = 0)
file_menu2 = Menu(tearoff = 0)
file_menu3 = Menu(tearoff = 0)
file_menu4 = Menu(tearoff = 0)
file_menu.add_command(label = "Калькулятор", command = Kalkulator)
file_menu1.add_command(label = "Требования", command = system)
file_menu3.add_command(label = "Часы", command = Chasi.clock)
main_menu.add_cascade(label="Инструменты", menu = file_menu)
main_menu.add_cascade(label="Системные требования", menu = file_menu1)
main_menu.add_cascade(label="Время", menu = file_menu3)
okno1.config(menu = main_menu)
okno1.mainloop()



