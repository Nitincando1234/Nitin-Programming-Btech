import sys
from PyQt6.QtWidgets import (
    QMainWindow, QApplication,
    QLabel, QToolBar, QStatusBar
)
from PyQt6.QtGui import QAction, QIcon
from PyQt6.QtCore import Qt, QSize

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()

        self.setWindowTitle("My Awesome App")
        label = QLabel("Hello !")
        label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.setCentralWidget(label)

        toolbar = QToolBar("My main toolbar")
        toolbar.setIconSize(QSize(16, 16))
        self.addToolBar(toolbar)

        button_action = QAction(QIcon("bug.png"), "Your button", self)
        button_action.setStatusTip("This is your button")
        button_action.triggered.connect(self.onMyToolBarClicked)
        button_action.setCheckable(True)        # to enable it as checkable
        toolbar.addAction(button_action)
        
        toolbar.addSeparator()

        button_action2 = QAction(QIcon("bug.png"), "Your &button2", self)
        button_action2.setStatusTip("This is your button2")
        button_action2.triggered.connect(self.onMyToolBarClicked)
        button_action2.setCheckable(True)
        toolbar.addAction(button_action2)

        # To add status bar
        self.setStatusBar(QStatusBar(self))
    
    def onMyToolBarClicked(self, s):
        print("clicked ", s)

app = QApplication(sys.argv)
w = MainWindow()
w.show()
app.exec()