import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QWidget, QHBoxLayout
from PyQt6.QtGui import QColor, QPalette

class Color(QWidget):
    def __init__(self, color):
        super().__init__()
        self.setAutoFillBackground(True)
        palette = self.palette()
        palette.setColor(QPalette.ColorRole.Window, QColor(color))
        self.setPalette(palette)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My V-Box Application")
        layout = QHBoxLayout()
        layout.addWidget(Color("red"))
        layout.addWidget(Color("blue"))
        layout.addWidget(Color("green"))
        widget = QWidget()
        widget.setLayout(layout)     
        self.setCentralWidget(widget)   

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()