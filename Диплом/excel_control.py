import db_control
import pandas as pd
from PyQt5 import QtWidgets, QtGui


def get_file_names():
    """Получение всех файлов выбранных пользователем"""
    filenames, ok = QtWidgets.QFileDialog.getOpenFileNames()
    return filenames, ok


def set_file_name():
    """Получение пути сохранения файла и его названия"""
    filename, ok = QtWidgets.QFileDialog.getSaveFileName(filter=".xlsx")
    return filename, ok


class ExcelControl(db_control.DbControl):
    def __init__(self):
        """Конструктор класса ExcelControl"""
        super(ExcelControl, self).__init__()

    def get_excel_data(self):
        """Получение данных из файлов выбранных пользователем"""
        sheets = ["Контингент (очно)", "Контингент (очно-заочно)", "Контингент (заочно)"]
        files = get_file_names()
        if files[len(files) - 1]:
            for f in range(len(files) - 1):  # Проход по всем файлам
                is_wrong = 0
                for i in range(3):  # Проход по всем листам в файле
                    info = []
                    left_side = 0
                    ride_side = 0
                    data = pd.read_excel('{0}'.format(''.join(files[f])), sheet_name="{0}".format(sheets[i]),
                                         engine="openpyxl")
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
                        else:
                            is_wrong = 1
                        left_side += 24
                        ride_side += 24
                if is_wrong:
                    msg = QtWidgets.QMessageBox()
                    icon_main = QtGui.QIcon()
                    icon_main.addPixmap(QtGui.QPixmap("Изображения/free-icon-binder-4624080.png"), QtGui.QIcon.Normal,
                                        QtGui.QIcon.Off)
                    msg.setWindowTitle("Ошибка")
                    msg.setWindowIcon(icon_main)
                    msg.setText("Файл " + ''.join(files[f]) + " заполнен не правильно")
                    msg.setIcon(QtWidgets.QMessageBox.Critical)
                    msg.exec_()

            msg = QtWidgets.QMessageBox()
            icon_main = QtGui.QIcon()
            icon_main.addPixmap(QtGui.QPixmap("Изображения/free-icon-binder-4624080.png"), QtGui.QIcon.Normal,
                                QtGui.QIcon.Off)
            msg.setWindowTitle("Успешно")
            msg.setWindowIcon(icon_main)
            msg.setText("Информация считана")
            msg.setIcon(QtWidgets.QMessageBox.Information)
            msg.exec_()

    def export_data(self, sheet_1, foe, sheet_2=None, sheet_3=None):
        files = set_file_name()
        if files[len(files) - 1]:
            if foe == "Все":
                data_1 = pd.DataFrame(sheet_1)
                data_2 = pd.DataFrame(sheet_2)
                data_3 = pd.DataFrame(sheet_3)
                sheets = {"Контингент (очно)": data_1,
                          "Контингент (очно-заочно)": data_2,
                          "Контингент (заочно)": data_3}
                writer = pd.ExcelWriter("{0}{1}".format(*files), engine="xlsxwriter")
                for sheet_name in sheets.keys():
                    sheets[sheet_name].to_excel(writer, sheet_name=sheet_name, index=False)
                writer.save()
            elif foe == "Очная":
                data_1 = pd.DataFrame(sheet_1)
                data_1.to_excel("{0}{1}".format(*files), sheet_name="Контингент (очно)", index=False)
            elif foe == "Очно-заочная":
                data_1 = pd.DataFrame(sheet_1)
                data_1.to_excel("{0}{1}".format(*files), sheet_name="Контингент (очно-заочно)", index=False)
            elif foe == "Заочная":
                data_1 = pd.DataFrame(sheet_1)
                data_1.to_excel("{0}{1}".format(*files), sheet_name="Контингент (заочно)", index=False)
