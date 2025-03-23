import sys
from Color import color
from PyQt6.QtWidgets import(
    QApplication,
    QMainWindow,
    QWidget,
    QStackedLayout,
    QVBoxLayout,
    QHBoxLayout,
    QPushButton
)

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("MY Application")

        pageLayout = QVBoxLayout()
        buttonLayout = QHBoxLayout()
        self.stackLayout = QStackedLayout()

        pageLayout.addLayout(buttonLayout)
        pageLayout.addLayout(self.stackLayout)

        btn = QPushButton("red")
        btn.pressed.connect(self.activateTab_1)
        buttonLayout.addWidget(btn)
        self.stackLayout.addWidget(color("red"))

        btn = QPushButton("green")
        btn.pressed.connect(self.activateTab_2)
        buttonLayout.addWidget(btn)
        self.stackLayout.addWidget(color("green"))

        btn = QPushButton("blue")
        btn.pressed.connect(self.activateTab_3)
        buttonLayout.addWidget(btn)
        self.stackLayout.addWidget(color("blue"))

        widget = QWidget()
        widget.setLayout(pageLayout)
        self.setCentralWidget(widget)

    def activateTab_1(self):
        self.stackLayout.setCurrentIndex(0)
    
    def activateTab_2(self):
        self.stackLayout.setCurrentIndex(1)

    def activateTab_3(self):
        self.stackLayout.setCurrentIndex(2)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()