import excel_control
from PyQt5 import QtCore, QtGui, QtWidgets


class UiDialogSimple(excel_control.ExcelControl):
    def __init__(self, dialog, trigger):
        """Конструктор класса UiDialog_simple"""
        super(UiDialogSimple, self).__init__()
        self.dialog = dialog
        self.trigger = trigger
        dialog.setObjectName("Dialog")
        dialog.resize(343, 542)
        dialog.setMinimumSize(QtCore.QSize(343, 542))
        dialog.setMaximumSize(QtCore.QSize(343, 542))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("Изображения/free-icon-binder-4624080.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        dialog.setWindowIcon(icon)
        self.gridLayout_2 = QtWidgets.QGridLayout(dialog)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.month_label_md = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.month_label_md.setFont(font)
        self.month_label_md.setAlignment(QtCore.Qt.AlignCenter)
        self.month_label_md.setObjectName("month_label_md")
        self.gridLayout.addWidget(self.month_label_md, 16, 1, 1, 1)
        self.loe_label_md = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.loe_label_md.setFont(font)
        self.loe_label_md.setAlignment(QtCore.Qt.AlignCenter)
        self.loe_label_md.setObjectName("loe_label_md")
        self.gridLayout.addWidget(self.loe_label_md, 1, 1, 1, 1)
        self.course_combo_box_md = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.course_combo_box_md.setFont(font)
        self.course_combo_box_md.setObjectName("course_combo_box_md")
        self.course_combo_box_md.addItem("")
        self.course_combo_box_md.addItem("")
        self.course_combo_box_md.addItem("")
        self.course_combo_box_md.addItem("")
        self.course_combo_box_md.addItem("")
        self.course_combo_box_md.addItem("")
        self.course_combo_box_md.addItem("")
        self.gridLayout.addWidget(self.course_combo_box_md, 11, 1, 1, 1)
        self.line_2 = QtWidgets.QFrame(dialog)
        self.line_2.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_2.setMidLineWidth(0)
        self.line_2.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_2.setObjectName("line_2")
        self.gridLayout.addWidget(self.line_2, 15, 1, 1, 1)
        self.line_3 = QtWidgets.QFrame(dialog)
        self.line_3.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_3.setMidLineWidth(0)
        self.line_3.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_3.setObjectName("line_3")
        self.gridLayout.addWidget(self.line_3, 12, 1, 1, 1)
        self.loe_combo_box_md = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.loe_combo_box_md.setFont(font)
        self.loe_combo_box_md.setObjectName("loe_combo_box_md")
        self.loe_combo_box_md.addItem("")
        self.loe_combo_box_md.addItem("")
        self.loe_combo_box_md.addItem("")
        self.loe_combo_box_md.addItem("")
        self.loe_combo_box_md.addItem("")
        self.loe_combo_box_md.addItem("")
        self.gridLayout.addWidget(self.loe_combo_box_md, 2, 1, 1, 1)
        self.foe_combo_box_md = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foe_combo_box_md.setFont(font)
        self.foe_combo_box_md.setObjectName("foe_combo_box_md")
        self.foe_combo_box_md.addItem("")
        self.foe_combo_box_md.addItem("")
        self.foe_combo_box_md.addItem("")
        self.foe_combo_box_md.addItem("")
        self.gridLayout.addWidget(self.foe_combo_box_md, 8, 1, 1, 1)
        self.month_combo_box_md = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.month_combo_box_md.setFont(font)
        self.month_combo_box_md.setObjectName("month_combo_box_md")
        self.month_combo_box_md.addItem("")
        self.gridLayout.addWidget(self.month_combo_box_md, 17, 1, 1, 1)
        self.course_label_md = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.course_label_md.setFont(font)
        self.course_label_md.setAlignment(QtCore.Qt.AlignCenter)
        self.course_label_md.setObjectName("course_label_md")
        self.gridLayout.addWidget(self.course_label_md, 10, 1, 1, 1)
        self.year_combo_box_md = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.year_combo_box_md.setFont(font)
        self.year_combo_box_md.setObjectName("year_combo_box_md")
        self.year_combo_box_md.addItem("")
        self.gridLayout.addWidget(self.year_combo_box_md, 14, 1, 1, 1)
        self.year_label_md = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.year_label_md.setFont(font)
        self.year_label_md.setAlignment(QtCore.Qt.AlignCenter)
        self.year_label_md.setObjectName("year_label_md")
        self.gridLayout.addWidget(self.year_label_md, 13, 1, 1, 1)
        self.direction_combo_box_md = QtWidgets.QComboBox(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.direction_combo_box_md.setFont(font)
        self.direction_combo_box_md.setObjectName("direction_combo_box_md")
        self.direction_combo_box_md.addItem("")
        self.gridLayout.addWidget(self.direction_combo_box_md, 5, 1, 1, 1)
        self.line_5 = QtWidgets.QFrame(dialog)
        self.line_5.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_5.setMidLineWidth(0)
        self.line_5.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_5.setObjectName("line_5")
        self.gridLayout.addWidget(self.line_5, 6, 1, 1, 1)
        self.line_4 = QtWidgets.QFrame(dialog)
        self.line_4.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_4.setMidLineWidth(0)
        self.line_4.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_4.setObjectName("line_4")
        self.gridLayout.addWidget(self.line_4, 9, 1, 1, 1)
        self.back_button_md = QtWidgets.QPushButton(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.back_button_md.setFont(font)
        self.back_button_md.setObjectName("back_button_md")
        self.gridLayout.addWidget(self.back_button_md, 20, 1, 1, 1)
        self.line = QtWidgets.QFrame(dialog)
        self.line.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line.setMidLineWidth(0)
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setObjectName("line")
        self.gridLayout.addWidget(self.line, 18, 1, 1, 1)
        self.foe_label_md = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.foe_label_md.setFont(font)
        self.foe_label_md.setAlignment(QtCore.Qt.AlignCenter)
        self.foe_label_md.setObjectName("foe_label_md")
        self.gridLayout.addWidget(self.foe_label_md, 7, 1, 1, 1)
        self.direction_label_md = QtWidgets.QLabel(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.direction_label_md.setFont(font)
        self.direction_label_md.setAlignment(QtCore.Qt.AlignCenter)
        self.direction_label_md.setObjectName("direction_label_md")
        self.gridLayout.addWidget(self.direction_label_md, 4, 1, 1, 1)
        self.line_6 = QtWidgets.QFrame(dialog)
        self.line_6.setFrameShadow(QtWidgets.QFrame.Raised)
        self.line_6.setMidLineWidth(0)
        self.line_6.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_6.setObjectName("line_6")
        self.gridLayout.addWidget(self.line_6, 3, 1, 1, 1)
        self.continue_button_md = QtWidgets.QPushButton(dialog)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.continue_button_md.setFont(font)
        self.continue_button_md.setObjectName("continue_button_md")
        self.gridLayout.addWidget(self.continue_button_md, 19, 1, 1, 1)
        self.gridLayout_2.addLayout(self.gridLayout, 0, 0, 1, 1)

        self.retranslate_ui(dialog)
        QtCore.QMetaObject.connectSlotsByName(dialog)
        dialog.setTabOrder(self.loe_combo_box_md, self.direction_combo_box_md)
        dialog.setTabOrder(self.direction_combo_box_md, self.foe_combo_box_md)
        dialog.setTabOrder(self.foe_combo_box_md, self.course_combo_box_md)
        dialog.setTabOrder(self.course_combo_box_md, self.year_combo_box_md)
        dialog.setTabOrder(self.year_combo_box_md, self.month_combo_box_md)
        dialog.setTabOrder(self.month_combo_box_md, self.back_button_md)
        # Триггеры для встроенных отчетов
        self.loe_combo_box_md.currentIndexChanged.connect(self.set_combo_boxes)
        self.back_button_md.clicked.connect(self.close_window)
        self.continue_button_md.clicked.connect(self.get_condition)
        # Предварительная донастройка
        self.set_combo_boxes()

    def retranslate_ui(self, dialog):
        """Установка всех встроенных названий"""
        _translate = QtCore.QCoreApplication.translate
        dialog.setWindowTitle(_translate("Dialog", "StudInStudOut"))
        self.month_label_md.setText(_translate("Dialog", "Месяц"))
        self.loe_label_md.setText(_translate("Dialog", "Уровень образования"))
        self.course_combo_box_md.setItemText(0, _translate("Dialog", "Все"))
        self.course_combo_box_md.setItemText(1, _translate("Dialog", "1"))
        self.course_combo_box_md.setItemText(2, _translate("Dialog", "2"))
        self.course_combo_box_md.setItemText(3, _translate("Dialog", "3"))
        self.course_combo_box_md.setItemText(4, _translate("Dialog", "4"))
        self.course_combo_box_md.setItemText(5, _translate("Dialog", "5"))
        self.course_combo_box_md.setItemText(6, _translate("Dialog", "6"))
        self.loe_combo_box_md.setItemText(0, _translate("Dialog", "Все"))
        self.loe_combo_box_md.setItemText(1, _translate("Dialog", "Бакалавриат"))
        self.loe_combo_box_md.setItemText(2, _translate("Dialog", "Магистратура"))
        self.loe_combo_box_md.setItemText(3, _translate("Dialog", "Специалитет"))
        self.loe_combo_box_md.setItemText(4, _translate("Dialog", "ККМТ"))
        self.loe_combo_box_md.setItemText(5, _translate("Dialog", "ТТД"))
        self.foe_combo_box_md.setItemText(0, _translate("Dialog", "Все"))
        self.foe_combo_box_md.setItemText(1, _translate("Dialog", "Очная"))
        self.foe_combo_box_md.setItemText(2, _translate("Dialog", "Очно-заочная"))
        self.foe_combo_box_md.setItemText(3, _translate("Dialog", "Заочная"))
        self.month_combo_box_md.setItemText(0, _translate("Dialog", "Все"))
        self.course_label_md.setText(_translate("Dialog", "Курс"))
        self.year_combo_box_md.setItemText(0, _translate("Dialog", "Все"))
        self.year_label_md.setText(_translate("Dialog", "Год"))
        self.direction_combo_box_md.setItemText(0, _translate("Dialog", "Все"))
        self.back_button_md.setText(_translate("Dialog", "Назад"))
        self.foe_label_md.setText(_translate("Dialog", "Форма обучения"))
        self.direction_label_md.setText(_translate("Dialog", "Название направления подготовки"))
        self.continue_button_md.setText(_translate("Dialog", "Продолжить"))

    def close_window(self):
        """Закрывает окно диалога"""
        self.dialog.close()

    def set_combo_boxes(self):
        """Устанавливает встроенные значения combo box"""
        self.direction_combo_box_md.blockSignals(True)
        self.direction_combo_box_md.clear()
        self.direction_combo_box_md.addItems(["Все", *self.get_directions(self.loe_combo_box_md.currentText())])
        self.direction_combo_box_md.blockSignals(False)
        self.year_combo_box_md.blockSignals(True)
        self.year_combo_box_md.clear()
        self.year_combo_box_md.addItems(["Все", *self.get_years(self.loe_combo_box_md.currentText())])
        self.year_combo_box_md.blockSignals(False)
        self.month_combo_box_md.blockSignals(True)
        self.month_combo_box_md.clear()
        self.month_combo_box_md.addItems(["Все", *self.get_months(self.loe_combo_box_md.currentText())])
        self.month_combo_box_md.blockSignals(False)

    def get_condition(self):
        """Получение данных необходимых для экспорта"""
        if self.trigger == "Все":
            book_1 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Всего зачислено": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                      "Из них на места в рамках квоты целевого приема (всего зачислено)": [],
                      "Из них иностранные граждане (всего зачислено)": [], "Всего отчислено": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                      "Из них на места в рамках квоты целевого приема (всего отчислено)": [],
                      "Из них иностранные граждане (всего отчислено)": [],
                      "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                      "Из них на места в рамках квоты целевого приема (зачислено бюджет)": [],
                      "Из них иностранные граждане (зачислено бюджет)": [],
                      "Зачислено по договорам об оказании платных образовательных услуг": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                      "Из них на места в рамках квоты целевого приема (зачислено платное)": [],
                      "Из них иностранные граждане (зачислено платное)": [],
                      "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                      "Из них на места в рамках квоты целевого приема (отчислено бюджет)": [],
                      "Из них иностранные граждане (отчислено бюджет)": [],
                      "Отчислено по договорам об оказании платных образовательных услуг": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": [],
                      "Из них на места в рамках квоты целевого приема (отчислено платное)": [],
                      "Из них иностранные граждане (отчислено платное)": []}
            book_2 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Всего зачислено": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                      "Из них на места в рамках квоты целевого приема (всего зачислено)": [],
                      "Из них иностранные граждане (всего зачислено)": [], "Всего отчислено": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                      "Из них на места в рамках квоты целевого приема (всего отчислено)": [],
                      "Из них иностранные граждане (всего отчислено)": [],
                      "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                      "Из них на места в рамках квоты целевого приема (зачислено бюджет)": [],
                      "Из них иностранные граждане (зачислено бюджет)": [],
                      "Зачислено по договорам об оказании платных образовательных услуг": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                      "Из них на места в рамках квоты целевого приема (зачислено платное)": [],
                      "Из них иностранные граждане (зачислено платное)": [],
                      "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                      "Из них на места в рамках квоты целевого приема (отчислено бюджет)": [],
                      "Из них иностранные граждане (отчислено бюджет)": [],
                      "Отчислено по договорам об оказании платных образовательных услуг": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": [],
                      "Из них на места в рамках квоты целевого приема (отчислено платное)": [],
                      "Из них иностранные граждане (отчислено платное)": []}
            book_3 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Всего зачислено": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                      "Из них на места в рамках квоты целевого приема (всего зачислено)": [],
                      "Из них иностранные граждане (всего зачислено)": [], "Всего отчислено": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                      "Из них на места в рамках квоты целевого приема (всего отчислено)": [],
                      "Из них иностранные граждане (всего отчислено)": [],
                      "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                      "Из них на места в рамках квоты целевого приема (зачислено бюджет)": [],
                      "Из них иностранные граждане (зачислено бюджет)": [],
                      "Зачислено по договорам об оказании платных образовательных услуг": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                      "Из них на места в рамках квоты целевого приема (зачислено платное)": [],
                      "Из них иностранные граждане (зачислено платное)": [],
                      "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                      "Из них на места в рамках квоты целевого приема (отчислено бюджет)": [],
                      "Из них иностранные граждане (отчислено бюджет)": [],
                      "Отчислено по договорам об оказании платных образовательных услуг": [],
                      "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": [],
                      "Из них на места в рамках квоты целевого приема (отчислено платное)": [],
                      "Из них иностранные граждане (отчислено платное)": []}
            if self.foe_combo_box_md.currentText() == "Все":
                data = self.get_data(self.loe_combo_box_md.currentText(), "Очная",
                                     self.direction_combo_box_md.currentText(), self.year_combo_box_md.currentText(),
                                     self.month_combo_box_md.currentText(), self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1, 1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                data = self.get_data(self.loe_combo_box_md.currentText(), "Очно-заочная",
                                     self.direction_combo_box_md.currentText(), self.year_combo_box_md.currentText(),
                                     self.month_combo_box_md.currentText(), self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_2, 1):
                    for recording in data:
                        book_2[chapter].append(recording[k])
                book_2 = {key: item for key, item in book_2.items() if item}
                data = self.get_data(self.loe_combo_box_md.currentText(), "Заочная",
                                     self.direction_combo_box_md.currentText(), self.year_combo_box_md.currentText(),
                                     self.month_combo_box_md.currentText(), self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_3, 1):
                    for recording in data:
                        book_3[chapter].append(recording[k])
                book_3 = {key: item for key, item in book_3.items() if item}
                self.export_data(book_1, "Все", book_2, book_3)
            elif self.foe_combo_box_md.currentText() == "Очная":
                data = self.get_data(self.loe_combo_box_md.currentText(), "Очная",
                                     self.direction_combo_box_md.currentText(), self.year_combo_box_md.currentText(),
                                     self.month_combo_box_md.currentText(), self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1, 1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Очная")
            elif self.foe_combo_box_md.currentText() == "Очно-заочная":
                data = self.get_data(self.loe_combo_box_md.currentText(), "Очно-заочная",
                                     self.direction_combo_box_md.currentText(), self.year_combo_box_md.currentText(),
                                     self.month_combo_box_md.currentText(), self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1, 1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Очно-заочная")
            elif self.foe_combo_box_md.currentText() == "Заочная":
                data = self.get_data(self.loe_combo_box_md.currentText(), "Заочная",
                                     self.direction_combo_box_md.currentText(), self.year_combo_box_md.currentText(),
                                     self.month_combo_box_md.currentText(), self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1, 1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Заочная")
        elif self.trigger == "Инвалиды":
            book_1 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": []}
            book_2 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": []}
            book_3 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)": [],
                      "Лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)": []}
            if self.foe_combo_box_md.currentText() == "Все":
                data = self.get_disabled(self.loe_combo_box_md.currentText(), "Очная",
                                         self.direction_combo_box_md.currentText(),
                                         self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                         self.course_combo_box_md.currentText())
                print(data)
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                data = self.get_disabled(self.loe_combo_box_md.currentText(), "Очно-заочная",
                                         self.direction_combo_box_md.currentText(),
                                         self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                         self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_2):
                    for recording in data:
                        book_2[chapter].append(recording[k])
                book_2 = {key: item for key, item in book_2.items() if item}
                data = self.get_disabled(self.loe_combo_box_md.currentText(), "Заочная",
                                         self.direction_combo_box_md.currentText(),
                                         self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                         self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_3):
                    for recording in data:
                        book_3[chapter].append(recording[k])
                book_3 = {key: item for key, item in book_3.items() if item}
                self.export_data(book_1, "Все", book_2, book_3)
            elif self.foe_combo_box_md.currentText() == "Очная":
                data = self.get_disabled(self.loe_combo_box_md.currentText(), "Очная",
                                         self.direction_combo_box_md.currentText(),
                                         self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                         self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Очная")
            elif self.foe_combo_box_md.currentText() == "Очно-заочная":
                data = self.get_disabled(self.loe_combo_box_md.currentText(), "Очно-заочная",
                                         self.direction_combo_box_md.currentText(),
                                         self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                         self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Очно-заочная")
            elif self.foe_combo_box_md.currentText() == "Заочная":
                data = self.get_disabled(self.loe_combo_box_md.currentText(), "Заочная",
                                         self.direction_combo_box_md.currentText(),
                                         self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                         self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Заочная")
        elif self.trigger == "Целевеки":
            book_1 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "На места в рамках квоты целевого приема (всего зачислено)": [],
                      "На места в рамках квоты целевого приема (всего отчислено)": [],
                      "На места в рамках квоты целевого приема (зачислено бюджет)": [],
                      "На места в рамках квоты целевого приема (зачислено платное)": [],
                      "На места в рамках квоты целевого приема (отчислено бюджет)": [],
                      "На места в рамках квоты целевого приема (отчислено платное)": []}
            book_2 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "На места в рамках квоты целевого приема (всего зачислено)": [],
                      "На места в рамках квоты целевого приема (всего отчислено)": [],
                      "На места в рамках квоты целевого приема (зачислено бюджет)": [],
                      "На места в рамках квоты целевого приема (зачислено платное)": [],
                      "На места в рамках квоты целевого приема (отчислено бюджет)": [],
                      "На места в рамках квоты целевого приема (отчислено платное)": []}
            book_3 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "На места в рамках квоты целевого приема (всего зачислено)": [],
                      "На места в рамках квоты целевого приема (всего отчислено)": [],
                      "На места в рамках квоты целевого приема (зачислено бюджет)": [],
                      "На места в рамках квоты целевого приема (зачислено платное)": [],
                      "На места в рамках квоты целевого приема (отчислено бюджет)": [],
                      "На места в рамках квоты целевого приема (отчислено платное)": []}
            if self.foe_combo_box_md.currentText() == "Все":
                data = self.get_target(self.loe_combo_box_md.currentText(), "Очная",
                                       self.direction_combo_box_md.currentText(),
                                       self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                       self.course_combo_box_md.currentText())
                print(data)
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                data = self.get_target(self.loe_combo_box_md.currentText(), "Очно-заочная",
                                       self.direction_combo_box_md.currentText(),
                                       self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                       self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_2):
                    for recording in data:
                        book_2[chapter].append(recording[k])
                book_2 = {key: item for key, item in book_2.items() if item}
                data = self.get_target(self.loe_combo_box_md.currentText(), "Заочная",
                                       self.direction_combo_box_md.currentText(),
                                       self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                       self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_3):
                    for recording in data:
                        book_3[chapter].append(recording[k])
                book_3 = {key: item for key, item in book_3.items() if item}
                self.export_data(book_1, "Все", book_2, book_3)
            elif self.foe_combo_box_md.currentText() == "Очная":
                data = self.get_target(self.loe_combo_box_md.currentText(), "Очная",
                                       self.direction_combo_box_md.currentText(),
                                       self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                       self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Очная")
            elif self.foe_combo_box_md.currentText() == "Очно-заочная":
                data = self.get_target(self.loe_combo_box_md.currentText(), "Очно-заочная",
                                       self.direction_combo_box_md.currentText(),
                                       self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                       self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Очно-заочная")
            elif self.foe_combo_box_md.currentText() == "Заочная":
                data = self.get_target(self.loe_combo_box_md.currentText(), "Заочная",
                                       self.direction_combo_box_md.currentText(),
                                       self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                       self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Заочная")
        elif self.trigger == "Иностранцы":
            book_1 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Иностранные граждане (всего зачислено)": [],
                      "Иностранные граждане (всего отчислено)": [],
                      "Иностранные граждане (зачислено бюджет)": [],
                      "Иностранные граждане (зачислено платное)": [],
                      "Иностранные граждане (отчислено бюджет)": [],
                      "Иностранные граждане (отчислено платное)": []}
            book_2 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Иностранные граждане (всего зачислено)": [],
                      "Иностранные граждане (всего отчислено)": [],
                      "Иностранные граждане (зачислено бюджет)": [],
                      "Иностранные граждане (зачислено платное)": [],
                      "Иностранные граждане (отчислено бюджет)": [],
                      "Иностранные граждане (отчислено платное)": []}
            book_3 = {"Названия направления подготовки": [],
                      "Уровень обучения": [], "Форма обучения": [], "Дата записи": [], "Курс": [],
                      "Иностранные граждане (всего зачислено)": [],
                      "Иностранные граждане (всего отчислено)": [],
                      "Иностранные граждане (зачислено бюджет)": [],
                      "Иностранные граждане (зачислено платное)": [],
                      "Иностранные граждане (отчислено бюджет)": [],
                      "Иностранные граждане (отчислено платное)": []}
            if self.foe_combo_box_md.currentText() == "Все":
                data = self.get_foreigners(self.loe_combo_box_md.currentText(), "Очная",
                                           self.direction_combo_box_md.currentText(),
                                           self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                           self.course_combo_box_md.currentText())
                print(data)
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                data = self.get_foreigners(self.loe_combo_box_md.currentText(), "Очно-заочная",
                                           self.direction_combo_box_md.currentText(),
                                           self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                           self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_2):
                    for recording in data:
                        book_2[chapter].append(recording[k])
                book_2 = {key: item for key, item in book_2.items() if item}
                data = self.get_foreigners(self.loe_combo_box_md.currentText(), "Заочная",
                                           self.direction_combo_box_md.currentText(),
                                           self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                           self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_3):
                    for recording in data:
                        book_3[chapter].append(recording[k])
                book_3 = {key: item for key, item in book_3.items() if item}
                self.export_data(book_1, "Все", book_2, book_3)
            elif self.foe_combo_box_md.currentText() == "Очная":
                data = self.get_foreigners(self.loe_combo_box_md.currentText(), "Очная",
                                           self.direction_combo_box_md.currentText(),
                                           self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                           self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Очная")
            elif self.foe_combo_box_md.currentText() == "Очно-заочная":
                data = self.get_foreigners(self.loe_combo_box_md.currentText(), "Очно-заочная",
                                           self.direction_combo_box_md.currentText(),
                                           self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                           self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Очно-заочная")
            elif self.foe_combo_box_md.currentText() == "Заочная":
                data = self.get_foreigners(self.loe_combo_box_md.currentText(), "Заочная",
                                           self.direction_combo_box_md.currentText(),
                                           self.year_combo_box_md.currentText(), self.month_combo_box_md.currentText(),
                                           self.course_combo_box_md.currentText())
                for k, chapter in enumerate(book_1):
                    for recording in data:
                        book_1[chapter].append(recording[k])
                book_1 = {key: item for key, item in book_1.items() if item}
                self.export_data(book_1, "Заочная")
