import sys
from PyQt6.QtWidgets import QApplication, QWidget, QMainWindow, QHBoxLayout, QVBoxLayout
from Color import color

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My Nested Layout")

        layout1 = QHBoxLayout()
        layout2 = QVBoxLayout()
        layout3 = QVBoxLayout()

        layout2.addWidget(color("red"))
        layout2.addWidget(color("yellow"))
        layout2.addWidget(color("purple"))

        layout1.setContentsMargins(0, 0, 0, 0)
        layout1.setSpacing(20)
        layout1.addLayout(layout2)

        layout1.addWidget(color("green"))
        
        layout3.addWidget(color("red"))
        layout3.addWidget(color("purple"))

        layout1.addLayout(layout3)

        widget = QWidget()
        widget.setLayout(layout1)
        self.setCentralWidget(widget)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()