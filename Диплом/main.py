import sys
from PyQt5 import QtWidgets
import UI


class ExampleApp(QtWidgets.QMainWindow, UI.Ui_MainWindow):
    def __init__(self, interface):
        # Это здесь нужно для доступа к переменным, методам
        # и т.д. в файле design.py
        super().__init__()
        self.setupUi(interface)  # Это нужно для инициализации нашего дизайна


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)  # Новый экземпляр QApplication
    Interface = QtWidgets.QMainWindow()
    window = ExampleApp(Interface)  # Создаём объект класса ExampleApp
    Interface.show()
    app.exec_()
