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
        button = QMessageBox.question(
            self,
            "Question Dialog",
            "The longer Message",
            buttons=QMessageBox.StandardButton.Discard              # optional
            | QMessageBox.StandardButton.NoToAll                    # optional    
            | QMessageBox.StandardButton.Ignore,                    # optional        
            defaultButton=QMessageBox.StandardButton.Discard,       # optional        
        )

        if button == QMessageBox.StandardButton.Ok: print("Ok !")
        else: print("Canceled !")

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()