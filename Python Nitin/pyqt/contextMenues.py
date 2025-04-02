import sys

from PyQt6.QtGui import QAction, QContextMenuEvent
from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QApplication, QLabel, QMainWindow, QMenu

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
    def contextMenuEvent(self, event: QContextMenuEvent) -> None:
        context = QMenu(self)
        context.addAction(QAction("test 1", self))
        context.addAction(QAction("test 2", self))
        context.addAction(QAction("test 3", self))
        context.exec(event.globalPos())

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()