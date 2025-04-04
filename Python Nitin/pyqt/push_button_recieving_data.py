import sys
from PyQt6.QtWidgets import QApplication, QPushButton, QMainWindow

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My App")
        button = QPushButton("Press Me!")
        button.setCheckable(True)
        button.clicked.connect(self.the_button_was_toggled)
        button.clicked.connect(self.the_button_was_clicked)
        self.setCentralWidget(button)

    def the_button_was_clicked(self):
        print("Clicked!")
    def the_button_was_toggled(self, checked):
        self.button_is_checked = checked
        print("Checked?")
        print(self.button_is_checked)

app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
    