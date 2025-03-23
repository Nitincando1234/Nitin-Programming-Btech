import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QMessageBox, QPushButton

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("App")

        button = QPushButton("Press For Dialog")
        button.pressed.connect(self.onClick)
        self.setCentralWidget(button)

    def onClick(self):
        dlg = QMessageBox(self)
        dlg.setText("This is a simple Dialog")
        dlg.setWindowTitle("Questionaire")
        dlg.setStandardButtons(QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No)
        dlg.setIcon(QMessageBox.Icon.Question)
        button = dlg.exec()

        if button == QMessageBox.StandardButton.Ok: print("Ok !")
        else: print("Canceled !")

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()