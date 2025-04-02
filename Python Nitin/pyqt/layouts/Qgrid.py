import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QGridLayout, QWidget
from Color import color

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My QGridApp")
        layout = QGridLayout()

        layout.addWidget(color("red"), 0, 3)
        layout.addWidget(color("green"), 1, 1)
        layout.addWidget(color("orange"), 2, 2)
        layout.addWidget(color("blue"), 3, 0)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
