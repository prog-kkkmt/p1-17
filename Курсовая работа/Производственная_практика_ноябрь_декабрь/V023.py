import ctypes
from tkinter import *

import Cena
import Fina
import Gonka
import Klient
import Raz
import dia
import sklad
import sotr


def osnova():
    user32 = ctypes.windll.user32
    widthButtonPlace = (user32.GetSystemMetrics(0) // 15)
    widthButton = widthButtonPlace // 7

    window = Tk()
    window.state("zoomed")  # Полноэкранный режим окна
    window.title("Программное обеспечение для автосервиса")

    canvas = Canvas(window, width=user32.GetSystemMetrics(0), height=user32.GetSystemMetrics(1))
    canvas.create_line(-710, 875, user32.GetSystemMetrics(0), 875, width=420, fill="wheat")
    canvas.configure(bg='lightskyblue')  # Фон окна
    canvas.pack()

    fontSize = user32.GetSystemMetrics(0) // 80
    fontParameters = "Batang " + str(
        fontSize)  # Устанавливаем шрифт, в качестве его размера указываем предыдущую переменную

    btnDiagnosis = Button(window, text="Диагностика\nдвигателя", width=widthButton, height=2, font=fontParameters,
                          command=dia.diagnost).place(x=(widthButtonPlace * 4), y=widthButtonPlace)
    btnFinance = Button(window, text="Финансы", width=widthButton, height=2, font=fontParameters,
                        command=Fina.finance).place(x=(widthButtonPlace * 4), y=widthButtonPlace * 2)
    btnClient = Button(window, text="Клиенты", width=widthButton, height=2, font=fontParameters,
                       command=Klient.client).place(x=(widthButtonPlace * 8), y=widthButtonPlace)
    btnDrag = Button(window, text="Дрэг-рейсинг", width=widthButton, height=2, font=fontParameters,
                     command=Gonka.drag).place(x=(widthButtonPlace * 8), y=widthButtonPlace * 2)
    btnAbout = Button(window, text="О программе", width=widthButton, height=2, font=fontParameters,
                      command=Raz.razrab).place(x=(widthButtonPlace * 4), y=widthButtonPlace * 3)
    btnPrice = Button(window, text="Прайс-лист", width=widthButton, height=2, font=fontParameters,
                      command=Cena.price).place(x=(widthButtonPlace * 8), y=widthButtonPlace * 3)
    btnStaff = Button(window, text="Сотрудники", width=widthButton, height=2, font=fontParameters,
                      command=sotr.sotrudniki).place(x=(widthButtonPlace * 4), y=widthButtonPlace * 4)
    btnStorage = Button(window, text="Склад", width=widthButton, height=2, font=fontParameters,
                        command=sklad.sklad).place(x=(widthButtonPlace * 8), y=widthButtonPlace * 4)

    window.mainloop()
