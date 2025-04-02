from PyQt6.QtGui import *
from PyQt6.QtWidgets import *

app = QApplication([])
app.setQuitOnLastWindowClosed(False)

icon = QIcon("E:/Nitin-Programming-Btech/Python Nitin\pyqt/fugue-icons-3.5.6/icons/abacus.png")

tray = QSystemTrayIcon()
tray.setIcon(icon)
tray.setVisible(True)

menu = QMenu()
action = QAction("A menu item")
menu.addAction(action)

quit = QAction("quit")
quit.triggered.connect(app.quit)
menu.addAction(quit)

tray.setContextMenu(menu)

app.exec()