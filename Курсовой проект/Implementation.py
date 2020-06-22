"""Модуль реализующий работу программы"""
from UI import UiInterface  # Импорт класса реализующего интерфейс
from PyQt5 import QtWidgets, QtCore  # Импорт модулей для работы с интерфейсом


class UiImplementation(UiInterface):
    """Класс реализаии работы интерфейса"""

    def __init__(self, interface):
        """Обработка всех событий в программе"""
        import os  # Импорт модуля для работы с ОС
        if os.path.isfile(os.path.abspath(os.curdir) + "\\Path to hotel DB.txt"):
            with open(os.path.abspath(os.curdir) + "\\Path to hotel DB.txt") as fp:
                self.path = fp.readline()
        else:
            with open(os.path.abspath(os.curdir) + "\\Path to hotel DB.txt", "w") as fp:
                fp.write(os.path.abspath(os.curdir))
                self.path = os.path.abspath(os.curdir)
        self.setup_ui(interface)
        self.btn_exit.clicked.connect(QtWidgets.QApplication.exit)
        self.btn_show_the_tables.clicked.connect(self.open_table)
        self.btn_show_the_tables.clicked.connect(self.load_table)
        self.tables.currentIndexChanged.connect(self.load_table)
        self.btn_back.clicked.connect(self.back)
        self.btn_save.clicked.connect(self.save_table)
        self.btn_append.clicked.connect(self.append)
        self.btn_delete.clicked.connect(self.delete)

    def load_table(self):
        """Загрузка и вывод таблицы на экран"""
        import csv  # Импорт модуля для работы с файлами в формате *.cvs
        self.table.setSortingEnabled(False)
        self.table.setRowCount(0)
        self.table.setColumnCount(0)
        with open(self.path + "\\Hotel data bases\\" + self.tables.itemText(self.tables.currentIndex()) + ".cvs") as f:
            reader = csv.reader(f)
            for row_number, row_data in enumerate(reader):
                if row_number:
                    self.table.setRowCount(row_number)
                    for column_number, column_data in enumerate(row_data):
                        self.table.setItem(row_number - 1, column_number, QtWidgets.QTableWidgetItem(column_data))
                else:
                    self.table.setColumnCount(len(row_data))
                    self.table.setHorizontalHeaderLabels(row_data)
        self.table.setSortingEnabled(True)
        self.table.resizeColumnsToContents()

    def save_table(self):
        """Сохранение таблицы"""
        import csv  # Импорт модуля для работы с файлами в формате *.cvs
        with open(self.path + "\\Hotel data bases\\" + self.tables.itemText(self.tables.currentIndex()) + ".cvs", "w",
                  newline="") as f:
            writer = csv.writer(f)
            row_count = self.table.rowCount()
            column_count = self.table.columnCount()
            header = [self.table.horizontalHeaderItem(column).text() for column in range(column_count)]
            writer.writerow(header)
            for row in range(row_count):
                row_data = list()
                for column in range(column_count):
                    item = self.table.item(row, column)
                    if item and item.text:
                        row_data.append(item.text())
                if row_data:
                    writer.writerow(row_data)

    def append(self):
        """Добавление строки в таблицу"""
        self.table.setRowCount(self.table.rowCount() + 1)

    def delete(self):
        """Удаление выбранных строк из таблицы"""
        index_list = [QtCore.QPersistentModelIndex(model_index)
                      for model_index in self.table.selectionModel().selectedRows()]
        for index in index_list:
            self.table.removeRow(index.row())
        self.save_table()

    def open_table(self):
        """Переход из главного меню в режим работы с таблицами"""
        Interface.setCurrentIndex(1)
        self.tables.setCurrentIndex(0)

    def back(self):
        """Возвращение в главное меню"""
        Interface.setCurrentIndex(0)


if __name__ == "__main__":
    import sys  # Импорт модуля для работы с системой
    QtWidgets.QApplication.setStyle("Fusion")
    app = QtWidgets.QApplication(sys.argv)
    Interface = QtWidgets.QStackedWidget()
    ui = UiImplementation(Interface)
    Interface.show()
    sys.exit(app.exec_())
