#=============================================================
#Этот модуль предоставляет ссылки на тест-драйвы автомобилей
#=============================================================

from tkinter import *
import webbrowser

def Test_drive():
    def callback(url):
        webbrowser.open_new(url)

    window = Toplevel()
    window.geometry("690x550")
    window.resizable(False, False)
    window.title("Тест-драйв")
    link1 = Label(window)
    link1.pack()
    link2 = Label(window, text="Audi A4 2016", fg="blue", cursor="hand2", font = '1')
    link2.pack()
    link2.bind("<Button-1>", lambda e: callback("https://www.youtube.com/watch?v=cB-66nJOJ08&feature=emb_logo"))
    link3 = Label(window, text="Audi A5 Coupe 2017", fg="blue", cursor="hand2", font = '1')
    link3.pack()
    link3.bind("<Button-1>", lambda e: callback("https://www.youtube.com/watch?v=dnqR-aopD6Y&feature=emb_logo"))
    link4 = Label(window, text="BMW 530d 2017", fg="blue", cursor="hand2", font = '1')
    link4.pack()
    link4.bind("<Button-1>", lambda e: callback("https://www.youtube.com/watch?v=Nfnwhy0fPzw&feature=emb_logo"))
    link5 = Label(window, text="Chevrolet Tracker (Trax) 2013", fg="blue", cursor="hand2", font = '1')
    link5.pack()
    link5.bind("<Button-1>", lambda e: callback("https://www.youtube.com/watch?v=vHAne0XgScQ&feature=emb_logo"))
    link6 = Label(window, text="Honda CR-V facelift 2015", fg="blue", cursor="hand2", font = '1')
    link6.pack()
    link6.bind("<Button-1>", lambda e: callback("https://www.youtube.com/watch?v=XKPO33mrAgE&feature=emb_logo"))
    link7 = Label(window, text="Infiniti Q50 2014\n", fg="blue", cursor="hand2", font = '1')
    link7.pack()
    link7.bind("<Button-1>", lambda e: callback("https://www.youtube.com/watch?v=o14FDZcvR8c&feature=emb_logo"))
    c = Canvas(window, width = 1200, height = 500, bg = 'white')
    c.pack()
    osnovnoi_fon = PhotoImage(file = 'T_D.png')
    osnovnoi_fon1 = c.create_image(340, 300, image = osnovnoi_fon)
    window.mainloop()
