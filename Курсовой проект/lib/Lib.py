
class Library_UI(QtWidgets.QWidget):
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
    def setupUi(self, Lib_Tool):
        
        """setObjectName задаётся внутри программы QT Designer,
        позволяет дать имена объектам для более удобного использования"""
        #UI_Tool.setObjectName("CEPDB")
        #resize отвечает за открытие окна программы в установленном разрешении
        #UI_Tool.resize(610, 431)
        """ QGridLayout, QVBoxLayout - элементы модуля PyQt5,
        отвечающие за расстановку элементов внутри окна по сетке
        и их динамическое расширение при расширении окна программы """
        Lib_Tool.setObjectName("TPayne_MySQL_Tool")
        Lib_Tool.resize(610, 431)
        self.gridLayout = QtWidgets.QGridLayout(Lib_Tool)
        self.gridLayout.setObjectName("gridLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label = QtWidgets.QLabel(Lib_Tool)
        font = QtGui.QFont()
        #QTabWidget - виджет переключаемых вкладок
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
        self.tabWidget = QtWidgets.QTabWidget(Lib_Tool)
        self.tabWidget.setObjectName("tabWidget")
        #следующие 2 строки устанавливают колличество изначальных колонок и рядов в таблице
        self.tab = QtWidgets.QWidget()
        self.tab.setObjectName("tab")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.tab)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.tableWidget_1 = QtWidgets.QTableWidget(self.tab)
        self.tableWidget_1.setObjectName("tableWidget_1")
          #QPushButton - кнопка
        self.tableWidget_1.setColumnCount(5)
        self.tableWidget_1.setRowCount(1)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setHorizontalHeaderItem(3, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_1.setHorizontalHeaderItem(4, item)
        self.tableWidget_1.horizontalHeader().setCascadingSectionResizes(True)
        self.tableWidget_1.horizontalHeader().setSortIndicatorShown(False)
        self.tableWidget_1.horizontalHeader().setStretchLastSection(False)
        self.tableWidget_1.verticalHeader().setVisible(False)
        self.verticalLayout_5.addWidget(self.tableWidget_1)
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
        self.tableWidget_2.setColumnCount(4)
        self.tableWidget_2.setRowCount(1)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(3, item)
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
        self.tableWidget_3.setColumnCount(3)
        self.tableWidget_3.setRowCount(1)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_3.setHorizontalHeaderItem(2, item)
        self.tableWidget_3.verticalHeader().setVisible(False)
        self.verticalLayout_3.addWidget(self.tableWidget_3)
        self.pushButton_5 = QtWidgets.QPushButton(self.tab_3)
        self.pushButton_5.setObjectName("pushButton_5")
        self.verticalLayout_3.addWidget(self.pushButton_5)
        self.tabWidget.addTab(self.tab_3, "")
        self.horizontalLayout.addWidget(self.tabWidget)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.gridLayout.addLayout(self.verticalLayout, 0, 0, 1, 1)
        self.pushButton = QtWidgets.QPushButton(Lib_Tool)
        self.pushButton.setAutoDefault(False)
        self.pushButton.setDefault(False)
        self.pushButton.setFlat(False)
        self.pushButton.setObjectName("pushButton")
        self.gridLayout.addWidget(self.pushButton, 1, 0, 1, 1)
        self.pushButton_2 = QtWidgets.QPushButton(Lib_Tool)
        self.pushButton_2.setObjectName("pushButton_2")
        self.gridLayout.addWidget(self.pushButton_2, 2, 0, 1, 1)

        self.retranslateUi(Lib_Tool)
        self.tabWidget.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(Lib_Tool)
        #функция retranslateUi устанавливает текст на элементы окна

    def retranslateUi(self, TPayne_MySQL_Tool):
        _translate = QtCore.QCoreApplication.translate
        TPayne_MySQL_Tool.setWindowTitle(_translate("TPayne_MySQL_Tool", "CEPDB Manager"))
        self.label.setText(_translate("TPayne_MySQL_Tool", ""))
        item = self.tableWidget_1.verticalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "New Row"))
         #setText устанавливает текст на какой - либо элемент
        item = self.tableWidget_1.horizontalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "Код книги"))
        item = self.tableWidget_1.horizontalHeaderItem(1)
        item.setText(_translate("TPayne_MySQL_Tool", "Название"))
        item = self.tableWidget_1.horizontalHeaderItem(2)
        item.setText(_translate("TPayne_MySQL_Tool", "Автор"))
        item = self.tableWidget_1.horizontalHeaderItem(3)
        item.setText(_translate("TPayne_MySQL_Tool", "Жанр"))
        item = self.tableWidget_1.horizontalHeaderItem(4)
        item.setText(_translate("TPayne_MySQL_Tool", "Год издания"))
        self.pushButton_3.setText(_translate("TPayne_MySQL_Tool", "Добавить ряд для записи"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), _translate("TPayne_MySQL_Tool", "Книги"))
        item = self.tableWidget_2.verticalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "1"))
        item = self.tableWidget_2.horizontalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "Код читателя"))
        item = self.tableWidget_2.horizontalHeaderItem(1)
        item.setText(_translate("TPayne_MySQL_Tool", "Фамилия"))
        item = self.tableWidget_2.horizontalHeaderItem(2)
        item.setText(_translate("TPayne_MySQL_Tool", "Имя"))
        item = self.tableWidget_2.horizontalHeaderItem(3)
        item.setText(_translate("TPayne_MySQL_Tool", "Отчество"))
        self.pushButton_4.setText(_translate("TPayne_MySQL_Tool", "Добавить ряд для записи"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), _translate("TPayne_MySQL_Tool", "Читатели"))
        item = self.tableWidget_3.verticalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "New Row"))
        item = self.tableWidget_3.horizontalHeaderItem(0)
        item.setText(_translate("TPayne_MySQL_Tool", "Код читателя"))
        item = self.tableWidget_3.horizontalHeaderItem(1)
        item.setText(_translate("TPayne_MySQL_Tool", "Код книги"))
        item = self.tableWidget_3.horizontalHeaderItem(2)
        item.setText(_translate("TPayne_MySQL_Tool", "Дата выдачи"))
        self.pushButton_5.setText(_translate("TPayne_MySQL_Tool", "Добавить ряд для записи"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), _translate("TPayne_MySQL_Tool", "Выдача"))
        self.pushButton.setText(_translate("TPayne_MySQL_Tool", "Определить наиболее читаемого автора"))
        self.pushButton_2.setText(_translate("TPayne_MySQL_Tool", "Определить выдачу книг по датам"))

        db_file_books = open('database_books.txt', 'r')
        db_file_readers = open('database_readers.txt', 'r')
        db_file_extra = open('database_extra.txt', 'r')

        for line_books in db_file_books.readlines():
            splited = line_books.split()
            for i in range(0, 2):
                self.tableWidget_1.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_1.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_1.insertRow(0)

        for line_readers in db_file_readers.readlines():
            splited = line_readers.split()
            for i in range(0, 2):
                self.tableWidget_2.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_2.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_2.insertRow(0)

        for line_extra in db_file_extra.readlines():
            splited = line_extra.split()
            for i in range(0, 2):
                self.tableWidget_3.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_3.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_3.setItem(0, 3, QTableWidgetItem(splited[3]))
            self.tableWidget_3.insertRow(0)
#открытие текстовых файлов с данными для считывания из них информации
        db_file_books.close()
        db_file_readers.close()
        db_file_extra.close()

        self.pushButton_3.pressed.connect(self.addrow_1)
        self.pushButton_4.pressed.connect(self.addrow_2)
        self.pushButton_5.pressed.connect(self.addrow_3)

    def addrow_1(self):
        db_file_books = open('database_books.txt', 'a')
# занесение данных из текстовых файлов в таблицу Книги
        for i in range(0, 3):
            temp = self.tableWidget_1.item(0, i).text()
            db_file_books.write(temp)
            db_file_books.write(' ')
        db_file_books.write('\n')
        db_file_books.close()
        self.tableWidget_1.insertRow(0)

    def addrow_2(self):
        db_file_readers = open('database_readers.txt', 'a')
        for i in range(0, 3):
            temp = self.tableWidget_2.item(0, i).text()
            db_file_readers.write(temp)
            db_file_readers.write(' ')
        db_file_readers.write('\n')
        db_file_readers.close()
        self.tableWidget_2.insertRow(0)

    def addrow_3(self):
        db_file_extra = open('database_extra.txt', 'a')
        for i in range(0, 4):
            temp = self.tableWidget_3.item(0, i).text()
            db_file_extra.write(temp)
            db_file_extra.write(' ')
        db_file_extra.write('\n')
        db_file_extra.close()
        self.tableWidget_3.insertRow(0)

#блок выполнения программы
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Library_UI()
    ex.show()

    sys.exit(app.exec_())
