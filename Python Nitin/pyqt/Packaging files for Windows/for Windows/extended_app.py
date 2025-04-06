from PyQt6.QtWidgets import QMainWindow, QApplication, QLabel, QVBoxLayout, QPushButton, QWidget
from PyQt6.QtGui import QIcon
import sys, os

basedir = os.path.dirname(__file__)

try:
    from ctypes import windll
    myappid = "com.nitin.extended_app"
    windll.shell32.SetCurrentProcessExplicitAppUserModelID(myappid)
except: pass

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()

        self.setWindowTitle("Extended App")
        layout = QVBoxLayout()
        label = QLabel("This is an extended app.")
        label.setMargin(10)
        layout.addWidget(label)

        button = QPushButton("Push to Close")
        button.setIcon(QIcon(os.path.join(basedir, "icons", "flash.ico")))
        button.pressed.connect(self.close)
        layout.addWidget(button)

        container = QWidget()
        container.setLayout(layout)

        self.setCentralWidget(container)
        self.show()
    
if __name__ == "__main__":
    app = QApplication(sys.argv)
    app.setWindowIcon(QIcon(os.path.join(basedir, "icons", "app.ico")))
    w = MainWindow()
    app.exec()
