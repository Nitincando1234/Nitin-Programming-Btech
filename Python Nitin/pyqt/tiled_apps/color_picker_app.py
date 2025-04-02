from PyQt6.QtGui import *
from PyQt6.QtWidgets import *

app = QApplication([])
app.setQuitOnLastWindowClosed(False)

icon = QIcon("E:/Nitin-Programming-Btech/Python Nitin\pyqt/fugue-icons-3.5.6/icons/abacus.png")
clipboard = QApplication.clipboard()
dialog = QColorDialog()

def copy_color_hex():
    if dialog.exec():
        color = dialog.currentColor()
        clipboard.setText(color)

def copy_color_rgb():
    if dialog.exec():
        color = dialog.currentColor()
        clipboard.setText("rgb(%d, %d, %d)" % (color.red(), color.green(), color.blue()))

def copy_color_hsv():
    if dialog.exec():
        color = dialog.currentColor()
        clipboard.setText("hsv(%d, %d, %d)" % (color.hue(), color.saturation(), color.value()))

tray = QSystemTrayIcon()
tray.setIcon(icon)
tray.setVisible(True)

menu = QMenu()
action1 = QAction("Hex")
action1.triggered.connect(copy_color_hex)
menu.addAction(action1)

action2 = QAction("RGB")
action2.triggered.connect(copy_color_rgb)
menu.addAction(action2)

action3 = QAction("HSV")
action3.triggered.connect(copy_color_hsv)
menu.addAction(action3)

action4 = QAction("Quit")
action4.triggered.connect(app.quit)
menu.addAction(action4)

tray.setContextMenu(menu)

app.exec()