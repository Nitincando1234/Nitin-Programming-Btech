import sys
from PyQt6.QtWidgets import QPushButton, QMainWindow, QApplication

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.button_isChecked = True
        self.setWindowTitle("My Application")
        self.button = QPushButton("Press Me !")
        self.button.setCheckable(True)
        self.button.released.connect(self.the_buttion_was_released)
        self.button.setChecked(self.button_isChecked)
        self.setCentralWidget(self.button)
    def the_buttion_was_released(self):
        self.button_is_checked = self.button.isChecked()
        print(self.button_is_checked)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
