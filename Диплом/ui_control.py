import PyQt5.Qt

import ui
import excel_control
from PyQt5 import QtWidgets, QtGui, QtCore


class UiControl(ui.UiWindow, excel_control.ExcelControl):
    def __init__(self, _window):
        """Конструктор класса UiControl"""
        super(UiControl, self).__init__(window=_window)
        # Создание меню бара и установка иконок
        self.data_menu = self.menubar.addMenu("&Data")
        self.analysis = self.menubar.addMenu("&Analysis")
        icon_file_bar = QtGui.QIcon()
        icon_file_bar.addPixmap(QtGui.QPixmap("Изображения/free-icon-attached-file-4481159.png"), QtGui.QIcon.Normal,
                                QtGui.QIcon.Off)
        icon_analysis_bar = QtGui.QIcon()
        icon_analysis_bar.addPixmap(QtGui.QPixmap("Изображения/free-icon-statistics-4624025.png"), QtGui.QIcon.Normal,
                                    QtGui.QIcon.Off)
        self.open_file_action = QtWidgets.QAction(icon_file_bar, "&Load data")
        self.analysis_action = QtWidgets.QAction(icon_analysis_bar, "&Start analysis")
        self.set_menu_and_tool_bars()
        # Форматирование таблиц
        self.stud_table_header = ["Код направления подготовки", "Названия направления подготовки", "Уровень обучения",
                                  "Форма обучения", "Дата записи", "Курс", "Всего зачислено",
                                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)",
                                  "Из них на места в рамках квоты целевого приема (всего зачислено)",
                                  "Из них иностранные граждане (всего зачислено)", "Всего отчислено",
                                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)",
                                  "Из них на места в рамках квоты целевого приема (всего отчислено)",
                                  "Из них иностранные граждане (всего отчислено)",
                                  "Зачислено за счет бюджетных ассигнований бюджета субъекта РФ",
                                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено бюджет)",
                                  "Из них на места в рамках квоты целевого приема (зачислено бюджет)",
                                  "Из них иностранные граждане (зачислено бюджет)",
                                  "Зачислено по договорам об оказании платных образовательных услуг",
                                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (зачислено платное)",
                                  "Из них на места в рамках квоты целевого приема (зачислено платное)",
                                  "Из них иностранные граждане (зачислено платное)",
                                  "Отчислено за счет бюджетных ассигнований бюджета субъекта РФ",
                                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено бюджет)",
                                  "Из них на места в рамках квоты целевого приема (отчислено бюджет)",
                                  "Из них иностранные граждане (отчислено бюджет)",
                                  "Отчислено по договорам об оказании платных образовательных услуг",
                                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (отчислено платное)",
                                  "Из них на места в рамках квоты целевого приема (отчислено платное)",
                                  "Из них иностранные граждане (отчислено платное)"]
        self.last_table_header = ["Код направления подготовки", "Названия направления подготовки", "Уровень обучения",
                                  "Форма обучения", "Дата записи", "Курс", "Всего зачислено",
                                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего зачислено)",
                                  "Из них на места в рамках квоты целевого приема (всего зачислено)",
                                  "Из них иностранные граждане (всего зачислено)", "Всего отчислено",
                                  "Из них лица с ОВЗ, инвалиды, дети-инвалиды (всего отчислено)",
                                  "Из них на места в рамках квоты целевого приема (всего отчислено)",
                                  "Из них иностранные граждане (всего отчислено)"]
        # Создание триггеров
        self.tabWidget.currentChanged.connect(self.load_table)
        # Триггеры для бакалавриата
        self.foe_combo_box_b.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_b.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_b.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_b.currentIndexChanged.connect(self.load_table)
        # Триггеры для магистратуры
        self.foe_combo_box_m.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_m.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_m.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_m.currentIndexChanged.connect(self.load_table)
        # Триггеры для специалитета
        self.foe_combo_box_s.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_s.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_s.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_s.currentIndexChanged.connect(self.load_table)
        # Триггеры для ККМТ
        self.foe_combo_box_CSET.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_CSET.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_CSET.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_CSET.currentIndexChanged.connect(self.load_table)
        # Триггеры для ТТД
        self.foe_combo_box_TSTD.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_TSTD.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_TSTD.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_TSTD.currentIndexChanged.connect(self.load_table)
        # Предварительные настройки
        self.load_table()

    def set_menu_and_tool_bars(self):
        """Добавление действий в меню и панель инструментов, а также установка триггеров для них"""
        self.data_menu.addAction(self.open_file_action)
        self.analysis.addAction(self.analysis_action)
        self.toolBar.addAction(self.open_file_action)
        self.toolBar.addAction(self.analysis_action)
        self.open_file_action.triggered.connect(self.get_excel_data)

    def load_table(self):
        """Загрузка данных в таблицу"""
        self.table_widget_last_month.horizontalHeader().setSectionResizeMode(PyQt5.Qt.QHeaderView.ResizeToContents)
        self.table_widget_last_month.horizontalHeader().setMinimumSectionSize(0)
        self.table_widget_last_year.horizontalHeader().setSectionResizeMode(PyQt5.Qt.QHeaderView.ResizeToContents)
        self.table_widget_last_year.horizontalHeader().setMinimumSectionSize(0)
        if self.tabWidget.currentIndex() == 0:
            data = self.get_data("Бакалавриат", self.foe_combo_box_b.currentText(),
                                 self.direction_combo_box_b.currentText(), self.year_combo_box_b.currentText(),
                                 str(self.month_combo_box_b.currentIndex()))
            self.table_widget_b.setSortingEnabled(False)
            self.table_widget_b.setRowCount(0)
            self.table_widget_b.clear()
            self.table_widget_b.setHorizontalHeaderLabels(self.stud_table_header)
            self.table_widget_b.horizontalHeader().setSectionResizeMode(PyQt5.Qt.QHeaderView.ResizeToContents)
            self.table_widget_b.horizontalHeader().setMinimumSectionSize(0)
            if data:
                self.table_widget_b.setRowCount(len(data))
                for row in range(len(data)):
                    for col in range(len(data[0])):
                        item = QtWidgets.QTableWidgetItem(str(data[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        self.table_widget_b.setItem(row, col, item)
            self.table_widget_b.setSortingEnabled(True)
        elif self.tabWidget.currentIndex() == 1:
            data = self.get_data("Магистратура", self.foe_combo_box_m.currentText(),
                                 self.direction_combo_box_m.currentText(), self.year_combo_box_m.currentText(),
                                 str(self.month_combo_box_m.currentIndex()))
            self.table_widget_m.setSortingEnabled(False)
            self.table_widget_m.setRowCount(0)
            self.table_widget_m.clear()
            self.table_widget_m.setHorizontalHeaderLabels(self.stud_table_header)
            self.table_widget_m.horizontalHeader().setSectionResizeMode(PyQt5.Qt.QHeaderView.ResizeToContents)
            self.table_widget_m.horizontalHeader().setMinimumSectionSize(0)
            if data:
                self.table_widget_m.setRowCount(len(data))
                for row in range(len(data)):
                    for col in range(len(data[0])):
                        item = QtWidgets.QTableWidgetItem(str(data[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        self.table_widget_m.setItem(row, col, item)
            self.table_widget_m.setSortingEnabled(True)
        elif self.tabWidget.currentIndex() == 2:
            data = self.get_data("Специалитет", self.foe_combo_box_s.currentText(),
                                 self.direction_combo_box_s.currentText(), self.year_combo_box_s.currentText(),
                                 str(self.month_combo_box_s.currentIndex()))
            self.table_widget_s.setSortingEnabled(False)
            self.table_widget_s.setRowCount(0)
            self.table_widget_s.clear()
            self.table_widget_s.setHorizontalHeaderLabels(self.stud_table_header)
            self.table_widget_s.horizontalHeader().setSectionResizeMode(PyQt5.Qt.QHeaderView.ResizeToContents)
            self.table_widget_s.horizontalHeader().setMinimumSectionSize(0)
            if data:
                self.table_widget_s.setRowCount(len(data))
                for row in range(len(data)):
                    for col in range(len(data[0])):
                        item = QtWidgets.QTableWidgetItem(str(data[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        self.table_widget_s.setItem(row, col, item)
            self.table_widget_s.setSortingEnabled(True)
        elif self.tabWidget.currentIndex() == 3:
            data = self.get_data("ККМТ", self.foe_combo_box_CSET.currentText(),
                                 self.direction_combo_box_CSET.currentText(), self.year_combo_box_CSET.currentText(),
                                 str(self.month_combo_box_CSET.currentIndex()))
            self.table_widget_CSET.setSortingEnabled(False)
            self.table_widget_CSET.setRowCount(0)
            self.table_widget_CSET.clear()
            self.table_widget_CSET.setHorizontalHeaderLabels(self.stud_table_header)
            self.table_widget_CSET.horizontalHeader().setSectionResizeMode(PyQt5.Qt.QHeaderView.ResizeToContents)
            self.table_widget_CSET.horizontalHeader().setMinimumSectionSize(0)
            if data:
                self.table_widget_CSET.setRowCount(len(data))
                for row in range(len(data)):
                    for col in range(len(data[0])):
                        item = QtWidgets.QTableWidgetItem(str(data[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        self.table_widget_CSET.setItem(row, col, item)
            self.table_widget_CSET.setSortingEnabled(True)
        elif self.tabWidget.currentIndex() == 4:
            data = self.get_data("ТТД", self.foe_combo_box_TSTD.currentText(),
                                 self.direction_combo_box_TSTD.currentText(), self.year_combo_box_TSTD.currentText(),
                                 str(self.month_combo_box_TSTD.currentIndex()))
            self.table_widget_TSTD.setSortingEnabled(False)
            self.table_widget_TSTD.setRowCount(0)
            self.table_widget_TSTD.clear()
            self.table_widget_TSTD.setHorizontalHeaderLabels(self.stud_table_header)
            self.table_widget_TSTD.horizontalHeader().setSectionResizeMode(PyQt5.Qt.QHeaderView.ResizeToContents)
            self.table_widget_TSTD.horizontalHeader().setMinimumSectionSize(0)
            if data:
                self.table_widget_TSTD.setRowCount(len(data))
                for row in range(len(data)):
                    for col in range(len(data[0])):
                        item = QtWidgets.QTableWidgetItem(str(data[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        self.table_widget_TSTD.setItem(row, col, item)
            self.table_widget_TSTD.setSortingEnabled(True)
