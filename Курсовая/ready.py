from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication, QWidget, QTableWidgetItem
import sys

class database_ui(QtWidgets.QWidget):

    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        self.setupUi(self)

    def setupUi(self, UI_Tool):
        UI_Tool.setObjectName("TPayne_MySQL_Tool")
        UI_Tool.resize(610, 431)
        self.gridLayout = QtWidgets.QGridLayout(UI_Tool)
        self.gridLayout.setObjectName("gridLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label = QtWidgets.QLabel(UI_Tool)
        font = QtGui.QFont()
        font.setPointSize(11)
        self.label.setFont(font)
        self.label.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label.setScaledContents(True)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.tabWidget = QtWidgets.QTabWidget(UI_Tool)
        self.tabWidget.setObjectName("tabWidget")
        self.tab = QtWidgets.QWidget()
        self.tab.setObjectName("tab")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.tab)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.tableWidget_1 = QtWidgets.QTableWidget(self.tab)
        self.tableWidget_1.setObjectName("tableWidget_1")
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

    def retranslateUi(self, TPayne_MySQL_Tool):
        _translate = QtCore.QCoreApplication.translate
        TPayne_MySQL_Tool.setWindowTitle(_translate("TPayne_MySQL_Tool", "CEPDB Manager"))
        self.label.setText(_translate("TPayne_MySQL_Tool", "База данных пункта обмена валютой"))
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

        db_file_clients = open('database_clients.txt', 'r')
        db_file_curr = open('database_curr.txt', 'r')
        db_file_deals = open('database_deals.txt', 'r')

        for line_clients in db_file_clients.readlines():
            splited = line_clients.split()
            for i in range(0, 2):
                self.tableWidget_1.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_1.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_1.insertRow(0)

        for line_curr in db_file_curr.readlines():
            splited = line_curr.split()
            for i in range(0, 2):
                self.tableWidget_2.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_2.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_2.insertRow(0)

        for line_deals in db_file_deals.readlines():
            splited = line_deals.split()
            for i in range(0, 2):
                self.tableWidget_3.setItem(0, i, QTableWidgetItem(splited[i]))
            self.tableWidget_3.setItem(0, 2, QTableWidgetItem(splited[2]))
            self.tableWidget_3.setItem(0, 3, QTableWidgetItem(splited[3]))
            self.tableWidget_3.insertRow(0)

        db_file_clients.close()
        db_file_curr.close()
        db_file_deals.close()

        self.pushButton.pressed.connect(self.totaldeals)
        self.pushButton_2.pressed.connect(self.maxdeal)
        self.pushButton_3.pressed.connect(self.addrow_1)
        self.pushButton_4.pressed.connect(self.addrow_2)
        self.pushButton_5.pressed.connect(self.addrow_3)

    def addrow_1(self):
        db_file_clients = open('database_clients.txt', 'a')
        for i in range(0, 3):
            temp = self.tableWidget_1.item(0, i).text()
            db_file_clients.write(temp)
            db_file_clients.write(' ')
        db_file_clients.write('\n')
        db_file_clients.close()
        self.tableWidget_1.insertRow(0)

    def addrow_2(self):
        db_file_curr = open('database_curr.txt', 'a')
        for i in range(0, 3):
            temp = self.tableWidget_2.item(0, i).text()
            db_file_curr.write(temp)
            db_file_curr.write(' ')
        db_file_curr.write('\n')
        db_file_curr.close()
        self.tableWidget_2.insertRow(0)

    def addrow_3(self):
        db_file_deals = open('database_deals.txt', 'a')
        for i in range(0, 4):
            temp = self.tableWidget_3.item(0, i).text()
            db_file_deals.write(temp)
            db_file_deals.write(' ')
        db_file_deals.write('\n')
        db_file_deals.close()
        self.tableWidget_3.insertRow(0)

    def totaldeals(self):

        db_file_curr = open('database_curr.txt', 'r')
        db_file_deals = open('database_deals.txt', 'r')
        exit_list = []
        deals_lines = []
        curr_lines = []
        overall = 0

        for line_deals in db_file_deals.readlines():
            splited_deals = line_deals.split()
            deals_lines.append(splited_deals)

        for line_curr in db_file_curr.readlines():
            splited_curr = line_curr.split()
            curr_lines.append(splited_curr)
            curr_code = splited_curr[0]
            curr_price = splited_curr[2]
            for i in range(len(deals_lines)):
                if curr_code == splited_deals[2]:
                    val = float(curr_price) * float(splited_deals[3])
                    overall = overall + val

        for i in range(len(curr_lines)):
            for j in range(len(deals_lines)):
                if curr_lines[i][0] == deals_lines[j][2]:
                    exit_list.append(curr_lines[i][1])
                    exit_list.append(float(curr_lines[i][2])*float(deals_lines[j][3])/float(overall))
        print(*exit_list)

        db_file_curr.close()
        db_file_deals.close()

    def maxdeal(self):

        db_file_curr = open('database_curr.txt', 'r')
        db_file_deals = open('database_deals.txt', 'r')
        exit_list = []
        deals_lines = []
        curr_lines = []

        for line_deals in db_file_deals.readlines():
            splited_deals = line_deals.split()
            deals_lines.append(splited_deals)

        for line_curr in db_file_curr.readlines():
            splited_curr = line_curr.split()
            curr_lines.append(splited_curr)

        for i in range(len(curr_lines)):
            for j in range(len(deals_lines)):
                if curr_lines[i][0] == deals_lines[j][2]:
                    exit_list.append(float(curr_lines[i][2])*float(deals_lines[j][3]))
        print('Размер максимальной сделки:', max(exit_list), 'рублей')


if __name__ == '__main__':

    app = QApplication(sys.argv)
    ex = database_ui()
    ex.show()

    sys.exit(app.exec_())