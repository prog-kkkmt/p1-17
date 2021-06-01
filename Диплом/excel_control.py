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
            for f in range(len(files)):  # Проход по всем файлам
                is_wrong = 0
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
                    msg.setText("Файл " + files[f] + " заполнен не правильно")
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

    def export_all(self, book):
        """Экспорт полных данных"""
        data = pd.DataFrame(book)
        files = set_file_name()
        if files[len(files) - 1]:
            data.to_excel("{0}{1}".format(*files), sheet_name="Контингент (очно)", index=False)

    def export_disabled(self):
        data = pd.DataFrame({"Названия направления подготовки": [],
                             "Уровень обучения": [],
                             "Форма обучения": [],
                             "Дата записи": [],
                             "Курс": [],
                             "Всего зачислено": [],
                             "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                             "Всего отчислено": [],
                             "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                             "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                             "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                             "Зачислено по договорам об оказании платных образовательных услуг": [],
                             "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                             "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                             "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                             "Отчислено по договорам об оказании платных образовательных услуг": [],
                             "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": []})
        files = set_file_name()
        if files[len(files) - 1]:
            data.to_excel("{0}{1}".format(*files), sheet_name="Контингент (очно)", index=False)

    def export_target(self):
        data = pd.DataFrame({"Названия направления подготовки": [],
                             "Уровень обучения": [],
                             "Форма обучения": [],
                             "Дата записи": [],
                             "Курс": [],
                             "Всего зачислено": [],
                             "Из них на места в рамках квоты целевого приема (всего зачислено)": [],
                             "Всего отчислено": [],
                             "Из них на места в рамках квоты целевого приема (всего отчислено)": [],
                             "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                             "Из них на места в рамках квоты целевого приема (зачислено бюджет)": [],
                             "Зачислено по договорам об оказании платных образовательных услуг": [],
                             "Из них на места в рамках квоты целевого приема (зачислено платное)": [],
                             "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                             "Из них на места в рамках квоты целевого приема (отчислено бюджет)": [],
                             "Отчислено по договорам об оказании платных образовательных услуг": [],
                             "Из них на места в рамках квоты целевого приема (отчислено платное)": []})
        files = set_file_name()
        if files[len(files) - 1]:
            data.to_excel("{0}{1}".format(*files), sheet_name="Контингент (очно)", index=False)

    def export_foreigners(self):
        """Экспорт полных данных"""
        data = pd.DataFrame({"Названия направления подготовки": [],
                             "Уровень обучения": [],
                             "Форма обучения": [],
                             "Дата записи": [],
                             "Курс": [],
                             "Всего зачислено": [],
                             "Из них иностранные граждане (всего зачислено)": [],
                             "Всего отчислено": [],
                             "Из них иностранные граждане (всего отчислено)": [],
                             "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                             "Из них иностранные граждане (зачислено бюджет)": [],
                             "Зачислено по договорам об оказании платных образовательных услуг": [],
                             "Из них иностранные граждане (зачислено платное)": [],
                             "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                             "Из них иностранные граждане (отчислено бюджет)": [],
                             "Отчислено по договорам об оказании платных образовательных услуг": [],
                             "Из них иностранные граждане (отчислено платное)": []})
        files = set_file_name()
        if files[len(files) - 1]:
            data.to_excel("{0}{1}".format(*files), sheet_name="Контингент (очно)", index=False)
