import sys
from PyQt6.QtWidgets import QApplication, QPushButton, QMainWindow

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("MY Application")
        self.button = QPushButton("Press Me !")
        self.button.clicked.connect(self.the_button_was_clicked)

        self.setCentralWidget(self.button)

    def the_button_was_clicked(self):
        self.button.setText("Already Clicked !")
        self.button.setEnabled(False)
        self.setWindowTitle("You Pressed The Button")

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()