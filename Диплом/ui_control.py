import PyQt5.Qt
import dialog_ui
import dialog_simple_ui
import main_ui
import excel_control
from PyQt5 import QtWidgets, QtGui, QtCore


class UiControl(main_ui.UiWindow, excel_control.ExcelControl):
    def __init__(self, _window):
        """Конструктор класса UiControl"""
        super(UiControl, self).__init__(window=_window)
        # Создание меню бара и установка иконок
        self.data_menu = self.menubar.addMenu("&Данные")
        self.report = self.menubar.addMenu("&Отчет")
        self.settings = self.menubar.addMenu("&Настройки")
        icon_file_bar = QtGui.QIcon()
        icon_file_bar.addPixmap(QtGui.QPixmap("Изображения/free-icon-import-724839.png"), QtGui.QIcon.Normal,
                                QtGui.QIcon.Off)
        icon_all_export = QtGui.QIcon()
        icon_all_export.addPixmap(QtGui.QPixmap("Изображения/free-icon-export-724836.png"), QtGui.QIcon.Normal,
                                  QtGui.QIcon.Off)
        icon_disabled_export = QtGui.QIcon()
        icon_disabled_export.addPixmap(QtGui.QPixmap("Изображения/free-icon-disabled-person-2707234.png"),
                                       QtGui.QIcon.Normal, QtGui.QIcon.Off)
        icon_target_export = QtGui.QIcon()
        icon_target_export.addPixmap(QtGui.QPixmap("Изображения/free-icon-target-audience-2282175.png"),
                                     QtGui.QIcon.Normal, QtGui.QIcon.Off)
        icon_foreigners_export = QtGui.QIcon()
        icon_foreigners_export.addPixmap(QtGui.QPixmap("Изображения/free-icon-tourist-925642.png"), QtGui.QIcon.Normal,
                                         QtGui.QIcon.Off)
        icon_user_export = QtGui.QIcon()
        icon_user_export.addPixmap(QtGui.QPixmap("Изображения/free-icon-check-4676065.png"), QtGui.QIcon.Normal,
                                   QtGui.QIcon.Off)
        icon_settings = QtGui.QIcon()
        icon_settings.addPixmap(QtGui.QPixmap("Изображения/free-icon-font-size-1634828.png"), QtGui.QIcon.Normal,
                                QtGui.QIcon.Off)
        self.open_file_action = QtWidgets.QAction(icon_file_bar, "&Загрузить данные")
        self.customizable_report_action = QtWidgets.QAction(icon_user_export, "&Настраиваемый отчет")
        self.settings_action = QtWidgets.QAction(icon_settings, "&Шрифт")
        self.report_all_action = QtWidgets.QAction(icon_all_export, "&Полный отчет  ")
        self.report_disabled_action = QtWidgets.QAction(icon_disabled_export, "&Лица с ОВЗ, инвалиды, дети-инвалиды")
        self.report_target_action = QtWidgets.QAction(icon_target_export, "&Места в рамках квоты целевого приема")
        self.report_foreigners_action = QtWidgets.QAction(icon_foreigners_export, "&Иностранные граждане")
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
        # Создание общих триггеров
        self.tabWidget.currentChanged.connect(self.load_table)
        self.back_button.clicked.connect(self.open_page_1)
        self.open_file_action.triggered.connect(self.update_table)
        self.report_all_action.triggered.connect(lambda: self.open_dialog_simple("Все"))
        self.report_disabled_action.triggered.connect(lambda: self.open_dialog_simple("Инвалиды"))
        self.report_target_action.triggered.connect(lambda: self.open_dialog_simple("Целевеки"))
        self.report_foreigners_action.triggered.connect(lambda: self.open_dialog_simple("Иностранцы"))
        self.customizable_report_action.triggered.connect(self.open_dialog)
        self.settings_action.triggered.connect(self.user_settings)
        self.left_click = QtCore.pyqtSignal()
        self.right_click = QtCore.pyqtSignal()
        # Триггеры для бакалавриата
        self.foe_combo_box_b.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_b.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_b.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_b.currentIndexChanged.connect(self.load_table)
        self.table_widget_b.doubleClicked.connect(self.open_page_2)
        # Триггеры для магистратуры
        self.foe_combo_box_m.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_m.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_m.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_m.currentIndexChanged.connect(self.load_table)
        self.table_widget_m.doubleClicked.connect(self.open_page_2)
        # Триггеры для специалитета
        self.foe_combo_box_s.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_s.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_s.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_s.currentIndexChanged.connect(self.load_table)
        self.table_widget_s.doubleClicked.connect(self.open_page_2)
        # Триггеры для ККМТ
        self.foe_combo_box_CSET.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_CSET.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_CSET.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_CSET.currentIndexChanged.connect(self.load_table)
        self.table_widget_CSET.doubleClicked.connect(self.open_page_2)
        # Триггеры для ТТД
        self.foe_combo_box_TSTD.currentIndexChanged.connect(self.load_table)
        self.direction_combo_box_TSTD.currentIndexChanged.connect(self.load_table)
        self.year_combo_box_TSTD.currentIndexChanged.connect(self.load_table)
        self.month_combo_box_TSTD.currentIndexChanged.connect(self.load_table)
        self.table_widget_TSTD.doubleClicked.connect(self.open_page_2)
        # Предварительные настройки
        self.load_table()
        self.direction_combo_box_b.addItems(self.get_directions("Бакалавриат"))
        self.direction_combo_box_m.addItems(self.get_directions("Магистратура"))
        self.direction_combo_box_s.addItems(self.get_directions("Специалитет"))
        self.direction_combo_box_CSET.addItems(self.get_directions("ККМТ"))
        self.direction_combo_box_TSTD.addItems(self.get_directions("ТТД"))
        self.year_combo_box_b.addItems(self.get_years("Бакалавриат"))
        self.year_combo_box_m.addItems(self.get_years("Магистратура"))
        self.year_combo_box_s.addItems(self.get_years("Специалитет"))
        self.year_combo_box_CSET.addItems(self.get_years("ККМТ"))
        self.year_combo_box_TSTD.addItems(self.get_years("ТТД"))

    def set_menu_and_tool_bars(self):
        """Добавление действий в меню и панель инструментов, а также установка триггеров для них"""
        self.data_menu.addAction(self.open_file_action)
        report = self.report.addMenu("&Встроенный отчет")
        self.report.addAction(self.customizable_report_action)
        report.addAction(self.report_all_action)
        report.addAction(self.report_disabled_action)
        report.addAction(self.report_target_action)
        report.addAction(self.report_foreigners_action)
        self.settings.addAction(self.settings_action)
        self.toolBar.addAction(self.open_file_action)
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.report_all_action)
        self.toolBar.addAction(self.report_disabled_action)
        self.toolBar.addAction(self.report_target_action)
        self.toolBar.addAction(self.report_foreigners_action)
        self.toolBar.addAction(self.customizable_report_action)
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.settings_action)
        self.toolBar.setMovable(False)

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
            self.table_widget_b.setColumnCount(len(self.stud_table_header))
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
            self.table_widget_m.setColumnCount(len(self.stud_table_header))
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
            self.table_widget_s.setColumnCount(len(self.stud_table_header))
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
            self.table_widget_CSET.setColumnCount(len(self.stud_table_header))
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
            self.table_widget_TSTD.setColumnCount(len(self.stud_table_header))
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

    def data_analysis(self):
        """Анализирует информацию о движении контингента"""
        if self.tabWidget.currentIndex() == 0:
            for idx in self.table_widget_b.selectionModel().selectedIndexes():
                row_index = idx.row()
                # Анализ за прошлый месяц
                data_old = self.get_data_old_month(row_index)
                data_new = self.get_data_new(row_index)
                self.table_widget_last_month.setSortingEnabled(False)
                self.table_widget_last_month.setRowCount(0)
                self.table_widget_last_month.setColumnCount(len(self.last_table_header))
                self.table_widget_last_month.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_month.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_month.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_month.setRowCount(len(data_new))
                self.set_style_last_month(data_new, data_old)
                # Анализ за прошлый год
                data_old = self.get_data_old_year(row_index)
                self.table_widget_last_year.setSortingEnabled(False)
                self.table_widget_last_year.setRowCount(0)
                self.table_widget_last_year.setColumnCount(len(self.last_table_header))
                self.table_widget_last_year.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_year.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_year.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_year.setRowCount(len(data_new))
                self.set_style_last_year(data_new, data_old)
        elif self.tabWidget.currentIndex() == 1:
            for idx in self.table_widget_m.selectionModel().selectedIndexes():
                row_index = idx.row()
                # Анализ за прошлый месяц
                data_old = self.get_data_old_month(row_index)
                data_new = self.get_data_new(row_index)
                self.table_widget_last_month.setSortingEnabled(False)
                self.table_widget_last_month.setRowCount(0)
                self.table_widget_last_month.setColumnCount(len(self.last_table_header))
                self.table_widget_last_month.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_month.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_month.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_month.setRowCount(len(data_new))
                self.set_style_last_month(data_new, data_old)
                # Анализ за прошлый год
                data_old = self.get_data_old_year(row_index)
                self.table_widget_last_year.setSortingEnabled(False)
                self.table_widget_last_year.setRowCount(0)
                self.table_widget_last_year.setColumnCount(len(self.last_table_header))
                self.table_widget_last_year.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_year.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_year.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_year.setRowCount(len(data_new))
                self.set_style_last_year(data_new, data_old)
        elif self.tabWidget.currentIndex() == 2:
            for idx in self.table_widget_s.selectionModel().selectedIndexes():
                row_index = idx.row()
                # Анализ за прошлый месяц
                data_old = self.get_data_old_month(row_index)
                data_new = self.get_data_new(row_index)
                self.table_widget_last_month.setSortingEnabled(False)
                self.table_widget_last_month.setRowCount(0)
                self.table_widget_last_month.setColumnCount(len(self.last_table_header))
                self.table_widget_last_month.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_month.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_month.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_month.setRowCount(len(data_new))
                self.set_style_last_month(data_new, data_old)
                # Анализ за прошлый год
                data_old = self.get_data_old_year(row_index)
                self.table_widget_last_year.setSortingEnabled(False)
                self.table_widget_last_year.setRowCount(0)
                self.table_widget_last_year.setColumnCount(len(self.last_table_header))
                self.table_widget_last_year.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_year.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_year.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_year.setRowCount(len(data_new))
                self.set_style_last_year(data_new, data_old)
        elif self.tabWidget.currentIndex() == 3:
            for idx in self.table_widget_CSET.selectionModel().selectedIndexes():
                row_index = idx.row()
                # Анализ за прошлый месяц
                data_old = self.get_data_old_month(row_index)
                data_new = self.get_data_new(row_index)
                self.table_widget_last_month.setSortingEnabled(False)
                self.table_widget_last_month.setRowCount(0)
                self.table_widget_last_month.setColumnCount(len(self.last_table_header))
                self.table_widget_last_month.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_month.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_month.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_month.setRowCount(len(data_new))
                self.set_style_last_month(data_new, data_old)
                # Анализ за прошлый год
                data_old = self.get_data_old_year(row_index)
                self.table_widget_last_year.setSortingEnabled(False)
                self.table_widget_last_year.setRowCount(0)
                self.table_widget_last_year.setColumnCount(len(self.last_table_header))
                self.table_widget_last_year.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_year.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_year.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_year.setRowCount(len(data_new))
                self.set_style_last_year(data_new, data_old)
        else:
            for idx in self.table_widget_TSTD.selectionModel().selectedIndexes():
                row_index = idx.row()
                # Анализ за прошлый месяц
                data_old = self.get_data_old_month(row_index)
                data_new = self.get_data_new(row_index)
                self.table_widget_last_month.setSortingEnabled(False)
                self.table_widget_last_month.setRowCount(0)
                self.table_widget_last_month.setColumnCount(len(self.last_table_header))
                self.table_widget_last_month.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_month.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_month.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_month.setRowCount(len(data_new))
                self.set_style_last_month(data_new, data_old)
                # Анализ за прошлый год
                data_old = self.get_data_old_year(row_index)
                self.table_widget_last_year.setSortingEnabled(False)
                self.table_widget_last_year.setRowCount(0)
                self.table_widget_last_year.setColumnCount(len(self.last_table_header))
                self.table_widget_last_year.setHorizontalHeaderLabels(self.last_table_header)
                self.table_widget_last_year.horizontalHeader().setSectionResizeMode(
                    PyQt5.Qt.QHeaderView.ResizeToContents)
                self.table_widget_last_year.horizontalHeader().setMinimumSectionSize(0)
                self.table_widget_last_year.setRowCount(len(data_new))
                self.set_style_last_year(data_new, data_old)

    def set_style_last_month(self, data_new, data_old):
        """Установка стиля для таблицы с анализом за предыдущий месяц"""
        if data_old:
            for row in range(len(data_new)):
                for col in range(0, 6):
                    item = QtWidgets.QTableWidgetItem(str(data_new[row][col]))
                    item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_month.setItem(row, col, item)
                for col in range(6, 10):
                    if data_new[row][col] - data_old[row][col] < 0:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(255, 0, 0))
                    elif data_new[row][col] - data_old[row][col] > 0:
                        item = QtWidgets.QTableWidgetItem("+" + str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(0, 128, 0))
                    else:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_month.setItem(row, col, item)
                for col in range(10, 14):
                    if data_new[row][col] - data_old[row][col] > 0:
                        item = QtWidgets.QTableWidgetItem("+" + str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(255, 0, 0))
                    elif data_new[row][col] - data_old[row][col] < 0:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(0, 128, 0))
                    else:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_month.setItem(row, col, item)
        else:
            for row in range(len(data_new)):
                for col in range(0, 6):
                    item = QtWidgets.QTableWidgetItem(str(data_new[row][col]))
                    item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_month.setItem(row, col, item)
                for col in range(6, 10):
                    if data_new[row][col] - 0 < 0:
                        item = QtWidgets.QTableWidgetItem("-" + str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(255, 0, 0))
                    elif data_new[row][col] - 0 > 0:
                        item = QtWidgets.QTableWidgetItem("+" + str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(0, 128, 0))
                    else:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_month.setItem(row, col, item)
                for col in range(10, 14):
                    if data_new[row][col] - 0 > 0:
                        item = QtWidgets.QTableWidgetItem("+" + str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(255, 0, 0))
                    elif data_new[row][col] - 0 < 0:
                        item = QtWidgets.QTableWidgetItem("-" + str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(0, 128, 0))
                    else:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_month.setItem(row, col, item)

    def set_style_last_year(self, data_new, data_old):
        """Установка стиля для таблицы с анализом за предыдущий год"""
        if data_old:
            for row in range(len(data_new)):
                for col in range(0, 6):
                    item = QtWidgets.QTableWidgetItem(str(data_new[row][col]))
                    item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_year.setItem(row, col, item)
                for col in range(6, 10):
                    if data_new[row][col] - data_old[row][col] < 0:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(255, 0, 0))
                    elif data_new[row][col] - data_old[row][col] > 0:
                        item = QtWidgets.QTableWidgetItem("+" + str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(0, 128, 0))
                    else:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_year.setItem(row, col, item)
                for col in range(10, 14):
                    if data_new[row][col] - data_old[row][col] > 0:
                        item = QtWidgets.QTableWidgetItem("+" + str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(255, 0, 0))
                    elif data_new[row][col] - data_old[row][col] < 0:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(0, 128, 0))
                    else:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - data_old[row][col]))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_year.setItem(row, col, item)
        else:
            for row in range(len(data_new)):
                for col in range(0, 6):
                    item = QtWidgets.QTableWidgetItem(str(data_new[row][col]))
                    item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_year.setItem(row, col, item)
                for col in range(6, 10):
                    if data_new[row][col] - 0 < 0:
                        item = QtWidgets.QTableWidgetItem("-" + str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(255, 0, 0))
                    elif data_new[row][col] - 0 > 0:
                        item = QtWidgets.QTableWidgetItem("+" + str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(0, 128, 0))
                    else:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_year.setItem(row, col, item)
                for col in range(10, 14):
                    if data_new[row][col] - 0 > 0:
                        item = QtWidgets.QTableWidgetItem("+" + str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(255, 0, 0))
                    elif data_new[row][col] - 0 < 0:
                        item = QtWidgets.QTableWidgetItem("-" + str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                        item.setForeground(QtGui.QColor(0, 128, 0))
                    else:
                        item = QtWidgets.QTableWidgetItem(str(data_new[row][col] - 0))
                        item.setTextAlignment(QtCore.Qt.AlignCenter)
                    self.table_widget_last_year.setItem(row, col, item)

    def get_data_old_month(self, row_index):
        """Возвращает данные за предыдущий месяц"""
        if self.tabWidget.currentIndex() == 0:
            data_old = self.get_data(self.table_widget_b.item(row_index, 2).text(),
                                     self.table_widget_b.item(row_index, 3).text(),
                                     self.table_widget_b.item(row_index, 1).text(),
                                     self.table_widget_b.item(row_index, 4).text().split('-')[0],
                                     str(int(self.table_widget_b.item(row_index, 4).text().
                                             split('-')[1]) - 1))
        elif self.tabWidget.currentIndex() == 1:
            data_old = self.get_data(self.table_widget_m.item(row_index, 2).text(),
                                     self.table_widget_m.item(row_index, 3).text(),
                                     self.table_widget_m.item(row_index, 1).text(),
                                     self.table_widget_m.item(row_index, 4).text().split('-')[0],
                                     str(int(self.table_widget_m.item(row_index, 4).text().
                                             split('-')[1]) - 1))
        elif self.tabWidget.currentIndex() == 2:
            data_old = self.get_data(self.table_widget_s.item(row_index, 2).text(),
                                     self.table_widget_s.item(row_index, 3).text(),
                                     self.table_widget_s.item(row_index, 1).text(),
                                     self.table_widget_s.item(row_index, 4).text().split('-')[0],
                                     str(int(self.table_widget_s.item(row_index, 4).text().
                                             split('-')[1]) - 1))
        elif self.tabWidget.currentIndex() == 3:
            data_old = self.get_data(self.table_widget_CSET.item(row_index, 2).text(),
                                     self.table_widget_CSET.item(row_index, 3).text(),
                                     self.table_widget_CSET.item(row_index, 1).text(),
                                     self.table_widget_CSET.item(row_index, 4).text().split('-')[0],
                                     str(int(self.table_widget_CSET.item(row_index, 4).text().
                                             split('-')[1]) - 1))
        else:
            data_old = self.get_data(self.table_widget_TSTD.item(row_index, 2).text(),
                                     self.table_widget_TSTD.item(row_index, 3).text(),
                                     self.table_widget_TSTD.item(row_index, 1).text(),
                                     self.table_widget_TSTD.item(row_index, 4).text().split('-')[0],
                                     str(int(self.table_widget_TSTD.item(row_index, 4).text().
                                             split('-')[1]) - 1))
        return data_old

    def get_data_old_year(self, row_index):
        """Возвращает данные за прошлый год выбранного месяца"""
        if self.tabWidget.currentIndex() == 0:
            data_old = self.get_data(self.table_widget_b.item(row_index, 2).text(),
                                     self.table_widget_b.item(row_index, 3).text(),
                                     self.table_widget_b.item(row_index, 1).text(),
                                     str(int(self.table_widget_b.item(row_index, 4).text().
                                             split('-')[0]) - 1),
                                     self.table_widget_b.item(row_index, 4).text().split('-')[1])
        elif self.tabWidget.currentIndex() == 1:
            data_old = self.get_data(self.table_widget_m.item(row_index, 2).text(),
                                     self.table_widget_m.item(row_index, 3).text(),
                                     self.table_widget_m.item(row_index, 1).text(),
                                     str(int(self.table_widget_m.item(row_index, 4).text().
                                             split('-')[0]) - 1),
                                     self.table_widget_m.item(row_index, 4).text().split('-')[1])
        elif self.tabWidget.currentIndex() == 2:
            data_old = self.get_data(self.table_widget_s.item(row_index, 2).text(),
                                     self.table_widget_s.item(row_index, 3).text(),
                                     self.table_widget_s.item(row_index, 1).text(),
                                     str(int(self.table_widget_s.item(row_index, 4).text().
                                             split('-')[0]) - 1),
                                     self.table_widget_s.item(row_index, 4).text().split('-')[1])
        elif self.tabWidget.currentIndex() == 3:
            data_old = self.get_data(self.table_widget_CSET.item(row_index, 2).text(),
                                     self.table_widget_CSET.item(row_index, 3).text(),
                                     self.table_widget_CSET.item(row_index, 1).text(),
                                     str(int(self.table_widget_CSET.item(row_index, 4).text().
                                             split('-')[0]) - 1),
                                     self.table_widget_CSET.item(row_index, 4).text().split('-')[1])
        else:
            data_old = self.get_data(self.table_widget_TSTD.item(row_index, 2).text(),
                                     self.table_widget_TSTD.item(row_index, 3).text(),
                                     self.table_widget_TSTD.item(row_index, 1).text(),
                                     str(int(self.table_widget_TSTD.item(row_index, 4).text().
                                             split('-')[0]) - 1),
                                     self.table_widget_TSTD.item(row_index, 4).text().split('-')[1])
        return data_old

    def get_data_new(self, row_index):
        """Возварщает данные за выбранный период"""
        if self.tabWidget.currentIndex() == 0:
            data_new = self.get_data(self.table_widget_b.item(row_index, 2).text(),
                                     self.table_widget_b.item(row_index, 3).text(),
                                     self.table_widget_b.item(row_index, 1).text(),
                                     self.table_widget_b.item(row_index, 4).text().split('-')[0],
                                     self.table_widget_b.item(row_index, 4).text().split('-')[1])
        elif self.tabWidget.currentIndex() == 1:
            data_new = self.get_data(self.table_widget_m.item(row_index, 2).text(),
                                     self.table_widget_m.item(row_index, 3).text(),
                                     self.table_widget_m.item(row_index, 1).text(),
                                     self.table_widget_m.item(row_index, 4).text().split('-')[0],
                                     self.table_widget_m.item(row_index, 4).text().split('-')[1])
        elif self.tabWidget.currentIndex() == 2:
            data_new = self.get_data(self.table_widget_s.item(row_index, 2).text(),
                                     self.table_widget_s.item(row_index, 3).text(),
                                     self.table_widget_s.item(row_index, 1).text(),
                                     self.table_widget_s.item(row_index, 4).text().split('-')[0],
                                     self.table_widget_s.item(row_index, 4).text().split('-')[1])
        elif self.tabWidget.currentIndex() == 3:
            data_new = self.get_data(self.table_widget_CSET.item(row_index, 2).text(),
                                     self.table_widget_CSET.item(row_index, 3).text(),
                                     self.table_widget_CSET.item(row_index, 1).text(),
                                     self.table_widget_CSET.item(row_index, 4).text().split('-')[0],
                                     self.table_widget_CSET.item(row_index, 4).text().split('-')[1])
        else:
            data_new = self.get_data(self.table_widget_TSTD.item(row_index, 2).text(),
                                     self.table_widget_TSTD.item(row_index, 3).text(),
                                     self.table_widget_TSTD.item(row_index, 1).text(),
                                     self.table_widget_TSTD.item(row_index, 4).text().split('-')[0],
                                     self.table_widget_TSTD.item(row_index, 4).text().split('-')[1])
        return data_new

    def open_page_1(self):
        """Открывает 1 лист программы"""
        self.stackedWidget.setCurrentIndex(0)

    def open_page_2(self):
        """Открывает 2 лист программы"""
        self.stackedWidget.setCurrentIndex(1)
        self.data_analysis()

    def update_table(self):
        """Добавляет информацию в БД и обновляет текущую таблицу"""
        self.get_excel_data()
        self.load_table()
        self.update_interface()

    def update_interface(self):
        """Обновление информации в combo box"""
        self.direction_combo_box_b.blockSignals(True)
        self.direction_combo_box_b.clear()
        self.direction_combo_box_b.addItems(["Все", *self.get_directions("Бакалавриат")])
        self.direction_combo_box_b.blockSignals(False)
        self.direction_combo_box_m.blockSignals(True)
        self.direction_combo_box_m.clear()
        self.direction_combo_box_m.addItems(["Все", *self.get_directions("Магистратура")])
        self.direction_combo_box_m.blockSignals(False)
        self.direction_combo_box_s.blockSignals(True)
        self.direction_combo_box_s.clear()
        self.direction_combo_box_s.addItems(["Все", *self.get_directions("Специалитет")])
        self.direction_combo_box_s.blockSignals(False)
        self.direction_combo_box_CSET.blockSignals(True)
        self.direction_combo_box_CSET.clear()
        self.direction_combo_box_CSET.addItems(["Все", *self.get_directions("ККМТ")])
        self.direction_combo_box_CSET.blockSignals(False)
        self.direction_combo_box_TSTD.blockSignals(True)
        self.direction_combo_box_TSTD.clear()
        self.direction_combo_box_TSTD.addItems(["Все", *self.get_directions("ТТД")])
        self.direction_combo_box_TSTD.blockSignals(False)
        self.year_combo_box_b.blockSignals(True)
        self.year_combo_box_b.clear()
        self.year_combo_box_b.addItems(["Все", *self.get_years("Бакалавриат")])
        self.year_combo_box_b.blockSignals(False)
        self.year_combo_box_m.blockSignals(True)
        self.year_combo_box_m.clear()
        self.year_combo_box_m.addItems(["Все", *self.get_years("Магистратура")])
        self.year_combo_box_m.blockSignals(False)
        self.year_combo_box_s.blockSignals(True)
        self.year_combo_box_s.clear()
        self.year_combo_box_s.addItems(["Все", *self.get_years("Специалитет")])
        self.year_combo_box_s.blockSignals(False)
        self.year_combo_box_CSET.blockSignals(True)
        self.year_combo_box_CSET.clear()
        self.year_combo_box_CSET.addItems(["Все", *self.get_years("ККМТ")])
        self.year_combo_box_CSET.blockSignals(False)
        self.year_combo_box_TSTD.blockSignals(True)
        self.year_combo_box_TSTD.clear()
        self.year_combo_box_TSTD.addItems(["Все", *self.get_years("ТТД")])
        self.year_combo_box_TSTD.blockSignals(False)

    def user_settings(self):
        """Выбор пользователем шрифта для таблиц и его установка"""
        icon_main = QtGui.QIcon()
        icon_main.addPixmap(QtGui.QPixmap("Изображения/free-icon-binder-4624080.png"), QtGui.QIcon.Normal,
                            QtGui.QIcon.Off)
        dialog = QtWidgets.QFontDialog()
        dialog.setWindowIcon(icon_main)
        font, ok = dialog.getFont(self.table_widget_b.font())
        if ok:
            self.table_widget_b.setFont(font)
            self.table_widget_m.setFont(font)
            self.table_widget_s.setFont(font)
            self.table_widget_CSET.setFont(font)
            self.table_widget_TSTD.setFont(font)
            self.table_widget_last_month.setFont(font)
            self.table_widget_last_year.setFont(font)

    def open_dialog(self):
        """Открытие окна пользовательского отчета"""
        self.dialog = QtWidgets.QDialog(flags=QtCore.Qt.WindowCloseButtonHint)
        self.window = dialog_ui.UiDialog(self.dialog)
        self.dialog.show()

    def open_dialog_simple(self, trigger):
        """Открытие окна для встроенных отчетов"""
        self.dialog_simple = QtWidgets.QDialog(flags=QtCore.Qt.WindowCloseButtonHint)
        self.window_simple = dialog_simple_ui.UiDialogSimple(self.dialog_simple, trigger)
        self.dialog_simple.show()
