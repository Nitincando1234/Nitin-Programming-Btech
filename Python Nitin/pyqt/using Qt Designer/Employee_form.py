import sys
from PyQt6.QtWidgets import QApplication, QDialog, QMainWindow, QPushButton
from Employee_dlg import Ui_Dialog
from PyQt6 import uic

class Window(QMainWindow):
    
    def __init__(self, parent = None):
        super().__init__(parent)

        self.centralWidget = QPushButton("Employee...")
        self.centralWidget.clicked.connect(self.onEmployeeBtnClicked)
        self.setCentralWidget(self.centralWidget)

    def onEmployeeBtnClicked(self):
        dlg = EmployeeDialog(self)
        dlg.exec()

class EmployeeDialog(QDialog):

    def __init__(self, parent = None):
        super().__init__(parent)
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
        # uic.loadUi("form-button.ui", self)      # less preffered (only for small-apps)
    
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec())    
