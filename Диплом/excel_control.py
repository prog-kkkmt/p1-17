import db_control
import pandas as pd
from PyQt5 import QtWidgets


def get_file_names():
    """Получение всех файлов выбранных пользователем"""
    filenames, ok = QtWidgets.QFileDialog.getOpenFileNames()
    return filenames


class ExcelControl(db_control.DbControl):
    def __init__(self):
        """Конструктор класса ExcelControl"""
        super(ExcelControl, self).__init__()

    def get_excel_data(self):
        """Получение данных из файлов выбранных пользователем"""
        sheets = ["Контингент (очно)", "Контингент (очно-заочно)", "Контингент (заочно)"]
        files = get_file_names()
        for f in range(len(files)):  # Проход по всем файлам
            for i in range(3):  # Проход по всем листам в файле
                info = []
                left_side = 0
                ride_side = 0
                data = pd.read_excel("{0}".format(files[f]), engine="openpyxl",
                                     sheet_name="{0}".format(sheets[i]))
                for j in range(5):  # Считывание информации для распределения
                    pars = data.iloc[[2], [j]]
                    info.append(*pars[pars.columns.tolist()[0]].tolist())
                for course in range(6):  # Проход по всем курсам
                    statistic = []
                    for k in range(5 + left_side, 29 + ride_side):
                        pars = data.iloc[[2], [k]]
                        statistic.append(*pars[pars.columns.tolist()[0]].tolist())
                    if info[0] == info[0]:  # Добавление существующих данных в БД
                        self.insert_data(course + 1, info, statistic[4:12] + statistic[16:24])
                    left_side += 24
                    ride_side += 24
