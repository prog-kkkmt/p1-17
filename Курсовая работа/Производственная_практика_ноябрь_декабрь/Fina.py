from tkinter import *  
from tkinter import scrolledtext
import ctypes
def finance():
    window = Tk()
    window.resizable(False, False)
    window.title("Финансы")
    window.geometry('1100x700')

    user32 = ctypes.windll.user32
    widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
    widthButton = widthButtonPlace // 7

    canvas = Canvas(window, width = user32.GetSystemMetrics(0), height = user32.GetSystemMetrics(1))
    canvas.configure(bg = 'lightskyblue')
    canvas.pack()
    
    f = open('bug.txt', 'r', encoding = 'utf-8')
    text = Text()
    text = scrolledtext.ScrolledText(window, height = '17', font = 'Batang 20', width = '40')
    text.insert(INSERT, f.read())
    text.place(x = 425, y = 80)
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
        text.place(x = 425, y = 80)
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
        text.place(x = 425, y = 80)
        f.close()
    
    
    lbl1 = Label(window)
    lbl2 = Label(window)
    lbl1.configure(font = 'Batang 20', text = '    Дата', bg = 'lightskyblue')
    lbl1.place(x = 25, y = 81)
    lbl2.configure(font = 'Batang 20', text = '   Сумма', bg = 'lightskyblue')
    lbl2.place(x = 200, y = 80)
    txt1 = Entry(window, width = 10, font = 'Batang 20')  
    txt1.place(x = 20, y = 120)
    txt2 = Entry(window, width = 10, font = 'Batang 20')  
    txt2.place(x = 190, y = 120)
    btn = Button(window, text = "Добавить", font = 'Batang 20', command=clicked)  
    btn.place(x = 105, y = 170)
    
    lbl3 = Label(window)
    lbl4 = Label(window)
    lbl3.configure(font = 'Batang 20', text = '    Дата', bg = 'lightskyblue')
    lbl3.place(x = 25, y = 281)
    lbl4.configure(font = 'Batang 20', text = '   Сумма', bg = 'lightskyblue')
    lbl4.place(x = 200, y = 280)
    txt3 = Entry(window, width = 10, font = 'Batang 20')  
    txt3.place(x = 20, y = 320)
    txt4 = Entry(window, width = 10, font = 'Batang 20')  
    txt4.place(x = 190, y = 320)
    btn1 = Button(window, text = "Удалить", font = 'Batang 20', command=clicked1)  
    btn1.place(x = 105, y = 370)














    
