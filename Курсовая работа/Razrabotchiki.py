#======================================================
#Этот модуль показывает разработчиков данной программы
#======================================================

from tkinter import *

def Razrabotchiki():
    window = Toplevel()
    window.geometry("1450x470")
    window.resizable(False, False)
    window.title("Разработчики")
    window.configure(bg = 'black')  
    R = Label(window)
    R.configure(text = 'Разработчики', font = 'Batang 40', bg = 'black', fg = 'white')
    R.place(x = 550, y = 40)   
    Alex = PhotoImage(file = 'Alex.png')
    lbl1 = Label(window)
    lbl1.configure(image = Alex)
    lbl1.place(x = 25, y = 160)
    Fam1 = Label(window)
    Fam1.configure(text = 'Бобнев Алексей Олегович', font = 'Batang 20', bg = 'black', fg = 'white')
    Fam1.place(x = 285, y = 160)
    T1 = Label(window)
    T1.configure(text = '+7 (917) 517-75-27', font = 'Batang 20', bg = 'black', fg = 'white')
    T1.place(x = 285, y = 210)
    P1 = Label(window)
    P1.configure(text = 'alexbob17@yandex.ru', font = 'Batang 20', bg = 'black', fg = 'white')
    P1.place(x = 285, y = 260)    
    Maria = PhotoImage(file = 'Maria.png')
    lbl2 = Label(window)
    lbl2.configure(image = Maria)
    lbl2.place(x = 725, y = 160)
    Fam2 = Label(window)
    Fam2.configure(text = 'Канавская Мария Владимировна', font = 'Batang 20', bg = 'black', fg = 'white')
    Fam2.place(x = 990, y = 160)
    T2 = Label(window)
    T2.configure(text = '+7 (916) 586-96-76', font = 'Batang 20', bg = 'black', fg = 'white')
    T2.place(x = 990, y = 210)
    P2 = Label(window)
    P2.configure(text = 'maria.seledka666@gmail.com', font = 'Batang 20', bg = 'black', fg = 'white')
    P2.place(x = 990, y = 260)
    P22 = Label(window)
    P22.configure(text = 'severdrakon@ya.ru', font = 'Batang 20', bg = 'black', fg = 'white')
    P22.place(x = 990, y = 310)  
    window.mainloop()




















    
