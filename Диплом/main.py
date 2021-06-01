import sys
from ui_control import UiControl
from PyQt5 import QtWidgets, QtCore


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = QtWidgets.QMainWindow()
    interface = UiControl(window)
    window.showMaximized()
    sys.exit(app.exec_())
