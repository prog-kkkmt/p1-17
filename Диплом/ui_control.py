import ui
import db_control
import excel_control
from PyQt5 import QtWidgets, QtGui


class UiControl(ui.UiWindow, excel_control.ExcelControl):
    def __init__(self, _window):
        """Конструктор класса UiControl"""
        super(UiControl, self).__init__(window=_window)
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

    def set_menu_and_tool_bars(self):
        """Добавление действий в меню и панель инструментов, а также установка триггеров для них"""
        self.data_menu.addAction(self.open_file_action)
        self.analysis.addAction(self.analysis_action)
        self.toolBar.addAction(self.open_file_action)
        self.toolBar.addAction(self.analysis_action)
        self.open_file_action.triggered.connect(self.get_excel_data)
