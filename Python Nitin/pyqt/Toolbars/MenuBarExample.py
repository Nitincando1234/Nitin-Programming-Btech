import sys
from PyQt6.QtWidgets import (
    QApplication,
    QMainWindow,
    QWidget,
    QToolBar,
    QStatusBar,
    QLabel,
    QCheckBox
)
from PyQt6.QtGui import QIcon, QAction, QKeySequence
from PyQt6.QtCore import QSize, Qt

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Menu Bar Example")

        label = QLabel("Hello !")
        label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.setCentralWidget(label)

        toolbar = QToolBar("My Main Toolbar")
        toolbar.setIconSize(QSize(16, 16))
        self.addToolBar(toolbar)

        button_action = QAction(QIcon("bug.png"), "Your Button 1", self)
        button_action.setStatusTip("This is ur button")
        button_action.setCheckable(True)
        button_action.triggered.connect(self.onMyToolBarClicked)
        button_action.setShortcut(QKeySequence("Ctrl+P"))
        toolbar.addAction(button_action)
        toolbar.addSeparator()
        button_action2 = QAction(QIcon("bug.png"), "Your Button 2", self)
        button_action2.setStatusTip("This is ur button 2")
        button_action2.setCheckable(True)
        button_action2.triggered.connect(self.onMyToolBarClicked)
        toolbar.addAction(button_action2)        

        toolbar.addWidget(QLabel("Hello"))
        toolbar.addWidget(QCheckBox())

        self.setStatusBar(QStatusBar(self))

        menu = self.menuBar()
        file_menu = menu.addMenu("&File")
        file_menu.addAction(button_action)
        file_menu.addSeparator()
        # file_menu.addAction(button_action2)
        file_submenu = file_menu.addMenu("SubMenu")
        file_submenu.addAction(button_action2)

    def onMyToolBarClicked(self, s):
        print("clicked ", s)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()