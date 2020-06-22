"""Модуль реалиующий интерфейс программы"""
from PyQt5 import QtCore, QtGui, QtWidgets  # Импорт модулей для работы с интерфейсом


class UiInterface(object):
    def setup_ui(self, interface):
        """Создает интерфейс"""
        interface.setObjectName("Interface")
        interface.resize(994, 657)

        self.setup_main_menu_page()

        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.MainMenuPage)
        self.verticalLayout_2.setObjectName("verticalLayout_2")

        self.setup_name()

        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setVerticalSpacing(50)
        self.gridLayout.setObjectName("gridLayout")

        self.setup_btn_exit()

        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem, 2, 0, 1, 1)

        self.setup_btn_show_the_tables()

        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem1, 2, 2, 1, 1)

        self.setup_btn_new_check_in()

        self.setup_made_by()

        interface.addWidget(self.MainMenuPage)

        self.setup_tables_page()

        self.verticalLayout = QtWidgets.QVBoxLayout(self.TablesPage)
        self.verticalLayout.setObjectName("verticalLayout")

        self.setup_tables()

        self.setup_table()

        self.gridLayout_3 = QtWidgets.QGridLayout()
        self.gridLayout_3.setObjectName("gridLayout_3")

        self.setup_btn_save()

        self.setup_btn_append()

        self.setup_btn_delete()

        self.setup_btn_back()

        interface.addWidget(self.TablesPage)

        self.fill_in_ui(interface)
        interface.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(interface)

    def setup_main_menu_page(self):
        """Создает страницу главного меню"""
        self.MainMenuPage = QtWidgets.QWidget()
        self.MainMenuPage.setAutoFillBackground(False)
        self.MainMenuPage.setStyleSheet("background-color: rgb(200, 200, 200);")
        self.MainMenuPage.setObjectName("MainMenuPage")

    def setup_name(self):
        """Создает метку 'название программы'"""
        self.name = QtWidgets.QLabel(self.MainMenuPage)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(72)
        font.setItalic(False)
        self.name.setFont(font)
        self.name.setAlignment(QtCore.Qt.AlignCenter)
        self.name.setObjectName("name")
        self.verticalLayout_2.addWidget(self.name)

    def setup_btn_exit(self):
        """Создает кнопку выхода из программы"""
        self.btn_exit = QtWidgets.QPushButton(self.MainMenuPage)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.btn_exit.sizePolicy().hasHeightForWidth())
        self.btn_exit.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.btn_exit.setFont(font)
        self.btn_exit.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_exit.setObjectName("btn_exit")
        self.gridLayout.addWidget(self.btn_exit, 2, 1, 1, 1)

    def setup_btn_show_the_tables(self):
        """Создает кнопку 'Tables'"""
        self.btn_show_the_tables = QtWidgets.QPushButton(self.MainMenuPage)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.btn_show_the_tables.sizePolicy().hasHeightForWidth())
        self.btn_show_the_tables.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.btn_show_the_tables.setFont(font)
        self.btn_show_the_tables.setAcceptDrops(False)
        self.btn_show_the_tables.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_show_the_tables.setObjectName("btn_show_the_tables")
        self.gridLayout.addWidget(self.btn_show_the_tables, 1, 1, 1, 1)

    def setup_btn_new_check_in(self):
        """Создает кнопку 'New check in' - в разработке"""
        self.btn_new_check_in = QtWidgets.QPushButton(self.MainMenuPage)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.btn_new_check_in.setFont(font)
        self.btn_new_check_in.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_new_check_in.setObjectName("btn_new_check_in")
        self.gridLayout.addWidget(self.btn_new_check_in, 0, 1, 1, 1)
        self.verticalLayout_2.addLayout(self.gridLayout)

    def setup_made_by(self):
        """Создает метку о создателе"""
        self.made_by = QtWidgets.QLabel(self.MainMenuPage)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(10)
        self.made_by.setFont(font)
        self.made_by.setAlignment(QtCore.Qt.AlignBottom | QtCore.Qt.AlignLeading | QtCore.Qt.AlignLeft)
        self.made_by.setObjectName("made_by")
        self.verticalLayout_2.addWidget(self.made_by)

    def setup_tables_page(self):
        """Создает страницу с таблицами"""
        self.TablesPage = QtWidgets.QWidget()
        self.TablesPage.setStyleSheet("background-color: rgb(200, 200, 200);")
        self.TablesPage.setObjectName("TablesPage")

    def setup_tables(self):
        """Создает ComboBox для выбора таблицы"""
        self.tables = QtWidgets.QComboBox(self.TablesPage)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.tables.sizePolicy().hasHeightForWidth())
        self.tables.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.tables.setFont(font)
        self.tables.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.tables.setTabletTracking(False)
        self.tables.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.tables.setAutoFillBackground(False)
        self.tables.setStyleSheet("background-color: rgb(255, 255, 255);\n"
                                  "selection-background-color: rgb(0, 85, 255);\n"
                                  "color: rgb(0, 0, 0);")
        self.tables.setFrame(False)
        self.tables.setModelColumn(0)
        self.tables.setObjectName("tables")
        self.tables.addItem("")
        self.tables.addItem("")
        self.tables.addItem("")
        self.verticalLayout.addWidget(self.tables)

    def setup_table(self):
        """Создает поле для отображения таблиц"""
        self.table = QtWidgets.QTableWidget(self.TablesPage)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.table.setFont(font)
        self.table.setSizeAdjustPolicy(QtWidgets.QAbstractScrollArea.AdjustIgnored)
        self.table.setWordWrap(True)
        self.table.setCornerButtonEnabled(False)
        self.table.setObjectName("table")
        self.table.setColumnCount(0)
        self.table.setRowCount(0)
        self.table.horizontalHeader().setCascadingSectionResizes(True)
        self.table.verticalHeader().setCascadingSectionResizes(True)
        self.verticalLayout.addWidget(self.table)

    def setup_btn_save(self):
        """Создает кнопку 'Save'"""
        self.btn_save = QtWidgets.QPushButton(self.TablesPage)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.btn_save.setFont(font)
        self.btn_save.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_save.setObjectName("btn_save")
        self.gridLayout_3.addWidget(self.btn_save, 0, 1, 1, 1)

    def setup_btn_append(self):
        """Создает кнопку 'Append'"""
        self.btn_append = QtWidgets.QPushButton(self.TablesPage)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.btn_append.setFont(font)
        self.btn_append.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_append.setObjectName("btn_append")
        self.gridLayout_3.addWidget(self.btn_append, 0, 0, 1, 1)

    def setup_btn_delete(self):
        """Создает кнопку 'Delete'"""
        self.btn_delete = QtWidgets.QPushButton(self.TablesPage)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.btn_delete.setFont(font)
        self.btn_delete.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_delete.setObjectName("btn_delete")
        self.gridLayout_3.addWidget(self.btn_delete, 2, 0, 1, 1)

    def setup_btn_back(self):
        """Создает кнопку 'Back'"""
        self.btn_back = QtWidgets.QPushButton(self.TablesPage)
        font = QtGui.QFont()
        font.setFamily("Times New Roman")
        font.setPointSize(16)
        self.btn_back.setFont(font)
        self.btn_back.setContextMenuPolicy(QtCore.Qt.PreventContextMenu)
        self.btn_back.setToolTipDuration(-1)
        self.btn_back.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_back.setObjectName("btn_back")
        self.gridLayout_3.addWidget(self.btn_back, 2, 1, 1, 1)
        self.verticalLayout.addLayout(self.gridLayout_3)

    def fill_in_ui(self, interface):
        """Заполняет все элементы нужными подпиями лекция 31 32 лз 38"""
        _translate = QtCore.QCoreApplication.translate
        interface.setWindowTitle(_translate("Interface", "Hotel Helper"))
        self.name.setText(_translate("Interface", "Hotel Helper"))
        self.btn_exit.setText(_translate("Interface", "Exit"))
        self.btn_show_the_tables.setText(_translate("Interface", "Tables"))
        self.btn_new_check_in.setText(_translate("Interface", "Under construction"))
        self.made_by.setText(_translate("Interface", "Ver. 0.6 11.06.2020 by Nikita Yushakov"))
        self.tables.setItemText(0, _translate("Interface", "Check in"))
        self.tables.setItemText(1, _translate("Interface", "Guests"))
        self.tables.setItemText(2, _translate("Interface", "Rooms"))
        self.table.setStyleSheet(_translate("Interface", "background-color: rgb(255, 255, 255);"))
        self.table.setSortingEnabled(False)
        self.btn_save.setText(_translate("Interface", "Save"))
        self.btn_append.setText(_translate("Interface", "Append"))
        self.btn_delete.setText(_translate("Interface", "Delete"))
        self.btn_back.setText(_translate("Interface", "Back"))
