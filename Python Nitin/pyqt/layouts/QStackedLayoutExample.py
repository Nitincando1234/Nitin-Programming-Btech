import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QWidget, QStackedLayout
from Color import color

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Tabbed Application")
        layout = QStackedLayout()

        layout.addWidget(color("red"))
        layout.addWidget(color("green"))
        layout.addWidget(color("blue"))
        layout.addWidget(color("violet"))
        layout.addWidget(color("pink"))

        layout.setCurrentIndex(3)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()