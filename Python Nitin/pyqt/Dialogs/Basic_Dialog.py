import sys
from PyQt6.QtWidgets import QApplication, QDialog, QMainWindow, QPushButton

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("With Dialogue Box")
        button = QPushButton("Press Me for Dialog !")
        button.clicked.connect(self.onClick)
        self.setCentralWidget(button)
    def onClick(self, s):
        print("click ", s)
        dlg = QDialog(self)
        dlg.setWindowTitle("Hello !")
        dlg.exec()
app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()