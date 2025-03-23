from PyQt6 import QtWidgets, uic
import sys

app = QtWidgets.QApplication(sys.argv)

window = uic.loadUi("basic.ui")
window.show()
app.exec()
