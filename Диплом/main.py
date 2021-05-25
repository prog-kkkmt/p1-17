import sys
from ui_control import UiControl
from PyQt5 import QtWidgets


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = QtWidgets.QMainWindow()
    interface = UiControl(window)
    window.show()
    app.exec_()
