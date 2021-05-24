import sys
from PyQt5 import QtWidgets
import ui
import db_control


class UiControl(ui.UiWindow, db_control.DbControl):
    def __init__(self, _window):
        super(UiControl, self).__init__(window=_window)


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = QtWidgets.QMainWindow()
    interface = UiControl(window)
    window.show()
    app.exec_()
