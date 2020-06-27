rom PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication, QWidget, QTableWidgetItem
import sys

""" 
PyQt5 - библотека для создания графического дизайна, 
окно программы, и всё его содержимое, были созданы
с помощью её функций и методов
"""


# database_ui - основной класс программы, содержащий в себе все функции
class database_ui(QtWidgets.QWidget):

    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        self.setupUi(self)

    """ 
    setupUI - главная функция программы, в ней идёт 
    описание всех элементов графического интерфейса.
    Код setupUI, как и код функции retranslateUi 
    были созданы при конвертации файла типа .ui,
    в файл типа .py с помощью комманды pyuic5
    """
    def setupUi(self, UI_Tool):

        """setObjectName задаётся внутри программы QT Designer,
        позволяет дать имена объектам для более удобного использования"""
        UI_Tool.setObjectName("CEPDB")
        #resize отвечает за открытие окна программы в установленном разрешении
        UI_Tool.resize(610, 431)
        """ QGridLayout, QVBoxLayout - элементы модуля PyQt5,
        отвечающие за расстановку элементов внутри окна по сетке
        и их динамическое расширение при расширении окна программы """
        self.gridLayout = QtWidgets.QGridLayout(UI_Tool)
        self.gridLayout.setObjectName("gridLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        #QLabel - строка текста в окне программы
        self.label = QtWidgets.QLabel(UI_Tool)
        #QFont и setPointSize устанавливают шрифт и размер шрифта
        font = QtGui.QFont()
        font.setPointSize(11)
        """setFont, setLayoutDirection, setScaledContents,setAlignment
        отвечают за свойства и поведение текста в окне программы"""
        self.label.setFont(font)
        self.label.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label.setScaledContents(True)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        #QTabWidget - виджет переключаемых вкладок
        self.tabWidget = QtWidgets.QTabWidget(UI_Tool)
        self.tabWidget.setObjectName("tabWidget")
        self.tab = QtWidgets.QWidget()
        self.tab.setObjectName("tab")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.tab)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        #QTableWidget - виджет таблицы
        self.tableWidget_1 = QtWidgets.QTableWidget(self.tab)
        self.tableWidget_1.setObjectName("tableWidget_1")
        #следующие 2 строки устанавливают колличество изначальных колонок и рядов в таблице
        self.tableWidget_1.setColumnCount(3)
        self.tableWidget_1.setRowCount(1)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setHorizontalHeaderItem(2, item)
        self.tableWidget_1.horizontalHeader().setCascadingSectionResizes(True)
        self.tableWidget_1.horizontalHeader().setSortIndicatorShown(False)
        self.tableWidget_1.horizontalHeader().setStretchLastSection(False)
        self.tableWidget_1.verticalHeader().setVisible(False)
        self.verticalLayout_5.addWidget(self.tableWidget_1)
        #QPushButton - кнопка
        self.pushButton_3 = QtWidgets.QPushButton(self.tab)
        self.pushButton_3.setObjectName("pushButton_3")
        self.verticalLayout_5.addWidget(self.pushButton_3)
        self.tabWidget.addTab(self.tab, "")
        self.tab_2 = QtWidgets.QWidget()
        self.tab_2.setObjectName("tab_2")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(self.tab_2)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.tableWidget_2 = QtWidgets.QTableWidget(self.tab_2)
        self.tableWidget_2.setObjectName("tableWidget_2")
        self.tableWidget_2.setColumnCount(3)
        self.tableWidget_2.setRowCount(1)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(2, item)
        self.tableWidget_2.verticalHeader().setVisible(False)
        self.verticalLayout_4.addWidget(self.tableWidget_2)
        self.pushButton_4 = QtWidgets.QPushButton(self.tab_2)
        self.pushButton_4.setObjectName("pushButton_4")
        self.verticalLayout_4.addWidget(self.pushButton_4)
        self.tabWidget.addTab(self.tab_2, "")
        self.tab_3 = QtWidgets.QWidget()
        self.tab_3.setObjectName("tab_3")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.tab_3)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.tableWidget_3 = QtWidgets.QTableWidget(self.tab_3)
        self.tableWidget_3.setObjectName("tableWidget_3")
        self.tableWidget_3.setColumnCount(4)
        self.tableWidget_3.setRowCount(1)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setHorizontalHeaderItem(3, item)
        self.tableWidget_3.verticalHeader().setVisible(False)
        self.verticalLayout_3.addWidget(self.tableWidget_3)
        self.pushButton_5 = QtWidgets.QPushButton(self.tab_3)
        self.pushButton_5.setObjectName("pushButton_5")
        self.verticalLayout_3.addWidget(self.pushButton_5)
        self.tabWidget.addTab(self.tab_3, "")
        self.horizontalLayout.addWidget(self.tabWidget)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.gridLayout.addLayout(self.verticalLayout, 0, 0, 1, 1)
        self.pushButton = QtWidgets.QPushButton(UI_Tool)
        self.pushButton.setAutoDefault(False)
        self.pushButton.setDefault(False)
        self.pushButton.setFlat(False)
        self.pushButton.setObjectName("pushButton")
        self.gridLayout.addWidget(self.pushButton, 1, 0, 1, 1)
        self.pushButton_2 = QtWidgets.QPushButton(UI_Tool)
        self.pushButton_2.setObjectName("pushButton_2")
        self.gridLayout.addWidget(self.pushButton_2, 2, 0, 1, 1)

        self.retranslateUi(UI_Tool)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(UI_Tool)

    #функция retranslateUi устанавливает текст на элементы окна
    def retranslateUi(self, TPayne_MySQL_Tool):
        _translate = QtCore.QCoreApplication.translate
        #setWindowTitle - название окна (верхний левый угол при открытии)
        TPayne_MySQL_Tool.setWindowTitle(_translate("TPayne_MySQL_Tool", "CEPDB Manager"))
        #setText устанавливает текст на какой - либо элемент
        self.label.setText(_translate("TPayne_MySQL_Tool", "База данных пункта обмена валютой"))
        #HeaderItem устанавливает текст на главные колонки и ряды таблиц
        item = self.tableWidget_1.verticalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "New Row"))
        item = self.tableWidget_1.horizontalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "Код клиента"))
        item = self.tableWidget_1.horizontalHeaderItem(1)
        item.setText(_translate("TPayne_MySQL_Tool", "ФИО"))
        item = self.tableWidget_1.horizontalHeaderItem(2)
        item.setText(_translate("TPayne_MySQL_Tool", "Паспорт"))
        self.pushButton_3.setText(_translate("TPayne_MySQL_Tool", "Добавить ряд для записи"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), _translate("TPayne_MySQL_Tool", "Клиенты"))
        item = self.tableWidget_2.verticalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "1"))
        item = self.tableWidget_2.horizontalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "Код валюты"))
        item = self.tableWidget_2.horizontalHeaderItem(1)
        item.setText(_translate("TPayne_MySQL_Tool", "Название"))
        item = self.tableWidget_2.horizontalHeaderItem(2)
        item.setText(_translate("TPayne_MySQL_Tool", "Курс продажи"))
        self.pushButton_4.setText(_translate("TPayne_MySQL_Tool", "Добавить ряд для записи"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), _translate("TPayne_MySQL_Tool", "Валюта"))
        item = self.tableWidget_3.verticalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "New Row"))
        item = self.tableWidget_3.horizontalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "Код сделки"))
        item = self.tableWidget_3.horizontalHeaderItem(1)
        item.setText(_translate("TPayne_MySQL_Tool", "Код клиента"))
        item = self.tableWidget_3.horizontalHeaderItem(2)
        item.setText(_translate("TPayne_MySQL_Tool", "Код валюты"))
        item = self.tableWidget_3.horizontalHeaderItem(3)
        item.setText(_translate("TPayne_MySQL_Tool", "Сумма"))
        self.pushButton_5.setText(_translate("TPayne_MySQL_Tool", "Добавить ряд для записи"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), _translate("TPayne_MySQL_Tool", "Сделки"))
        self.pushButton.setText(_translate("TPayne_MySQL_Tool", "Определить долю сделок по каждой валюте"))
        self.pushButton_2.setText(_translate("TPayne_MySQL_Tool", "Определить максимальный размер сделки в рублях"))

        #открытие текстовых файлов с данными для считывания из них информации
        db_file_clients = open('database_clients.txt', 'r')
        db_file_curr = open('database_curr.txt', 'r')
        db_file_deals = open('database_deals.txt', 'r')
        # построчное прочтение файла для занесение данных в таблицу Клиенты
        for line_clients in db_file_clients.readlines():
            # метод split разделяет строчку на элементы
            splited = line_clients.split()
            # занесение данных из текстовых файлов в таблицу Клиенты
            for i in range(0, 2):
                self.tableWidget_1.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_1.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_1.insertRow(0)
        # Аналогичная работа. Данные заносятся в таблицу Валюты
        for line_curr in db_file_curr.readlines():
            splited = line_curr.split()
            for i in range(0, 2):
                self.tableWidget_2.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_2.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_2.insertRow(0)
        # Аналогичная работа. Данные заносятся в таблицу Сделки
        for line_deals in db_file_deals.readlines():
            splited = line_deals.split()
            for i in range(0, 2):
                self.tableWidget_3.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_3.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_3.setItem(0, 3, QTableWidgetItem(splited[3]))
            self.tableWidget_3.insertRow(0)

        #прекращение работы с файлами, их закрытие
        db_file_clients.close()
        db_file_curr.close()
        db_file_deals.close()

        #pressed.connect - методы, отвечающие за придание функции кнопкам, при нажатии на них
        self.pushButton.pressed.connect(self.totaldeals)
        self.pushButton_2.pressed.connect(self.maxdeal)
        self.pushButton_3.pressed.connect(self.addrow_1)
        self.pushButton_4.pressed.connect(self.addrow_2)
        self.pushButton_5.pressed.connect(self.addrow_3)

    """функция, считывающая информацию из строки таблицы Клиенты
    и добавляющая ряд в таблицу"""
    def addrow_1(self):
        #открывает файл с информацией по Клиентам
        db_file_clients = open('database_clients.txt', 'a')
        for i in range(0, 3):
            #далее считывает текст из первого ряда таблицы и записывает в файл
            temp = self.tableWidget_1.item(0, i).text()
            db_file_clients.write(temp)
            db_file_clients.write(' ')
        #добавляет новую строку и закрывает файл
        db_file_clients.write('\n')
        db_file_clients.close()
        #добавляет один ряд в таблицу
        self.tableWidget_1.insertRow(0)

    """функция, считывающая информацию из строки таблицы Валюта
    и добавляющая ряд в таблицу"""
    def addrow_2(self):
        #открывает файл с информацией по Валюте
        db_file_curr = open('database_curr.txt', 'a')
        for i in range(0, 3):
            #далее считывает текст из первого ряда таблицы и записывает в файл
            temp = self.tableWidget_2.item(0, i).text()
            db_file_curr.write(temp)
            db_file_curr.write(' ')
        # добавляет новую строку и закрывает файл
        db_file_curr.write('\n')
        db_file_curr.close()
        #добавляет один ряд в таблицу
        self.tableWidget_2.insertRow(0)

    """функция, считывающая информацию из строки таблицы Сделки
    и добавляющая ряд в таблицу"""
    def addrow_3(self):
        #открывает файл с информацией по Сделкам
        db_file_deals = open('database_deals.txt', 'a')
        for i in range(0, 4):
            #далее считывает текст из первого ряда таблицы и записывает в файл
            temp = self.tableWidget_3.item(0, i).text()
            db_file_deals.write(temp)
            db_file_deals.write(' ')
        # добавляет новую строку и закрывает файл
        db_file_deals.write('\n')
        db_file_deals.close()
        #добавляет один ряд в таблицу
        self.tableWidget_3.insertRow(0)

    """функция, определяющая долю сделок по каждой валюте"""
    def totaldeals(self):
        #открыnие файлов с данными по валюте и сделкам
        db_file_curr = open('database_curr.txt', 'r')
        db_file_deals = open('database_deals.txt', 'r')
        #cоздание пустых списков для последующего использования
        exit_list = []
        deals_lines = []
        curr_lines = []
        #переменная overall ссылается на общую сумму с продажи валюты
        overall = 0

        #построчное прочтение файла и занесение в список элементов строк
        for line_deals in db_file_deals.readlines():
            splited_deals = line_deals.split()
            deals_lines.append(splited_deals)

        #вычисление общей суммы продажи валют
        for line_curr in db_file_curr.readlines():
            splited_curr = line_curr.split()
            curr_lines.append(splited_curr)
            curr_code = splited_curr[0]
            curr_price = splited_curr[2]
            for i in range(len(deals_lines)):
                if curr_code == splited_deals[2]:
                    val = float(curr_price) * float(splited_deals[3])
                    overall = overall + val

        #запись в список наименования валют и их долю от общих продаж
        for i in range(len(curr_lines)):
            for j in range(len(deals_lines)):
                if curr_lines[i][0] == deals_lines[j][2]:
                    exit_list.append(curr_lines[i][1])
                    exit_list.append(float(curr_lines[i][2]) * float(deals_lines[j][3]) / float(overall))
        print(*exit_list)

        #прекращение раюоты с файлами, закрытие
        db_file_curr.close()
        db_file_deals.close()

    """функция, определяющая максимальный размер сделки в рублях"""
    def maxdeal(self):
        # открыnие файлов с данными по валюте и сделкам
        db_file_curr = open('database_curr.txt', 'r')
        db_file_deals = open('database_deals.txt', 'r')
        #cоздание пустых списков для последующего использования
        exit_list = []
        deals_lines = []
        curr_lines = []

        # построчное прочтение файла со сделками и занесение в список элементов строк
        for line_deals in db_file_deals.readlines():
            splited_deals = line_deals.split()
            deals_lines.append(splited_deals)

        # построчное прочтение файла с валютой и занесение в список элементов строк
        for line_curr in db_file_curr.readlines():
            splited_curr = line_curr.split()
            curr_lines.append(splited_curr)

        #вычисление размера максимальной сделки
        for i in range(len(curr_lines)):
            for j in range(len(deals_lines)):
                if curr_lines[i][0] == deals_lines[j][2]:
                    exit_list.append(float(curr_lines[i][2]) * float(deals_lines[j][3]))
        print('Размер максимальной сделки:', max(exit_list), 'рублей')

#блок выполнения программы
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = database_ui()
    ex.show()

    sys.exit(app.exec_())
