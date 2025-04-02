import sys
from PyQt6.QtWidgets import QApplication, QDialog, QMainWindow, QPushButton
from OurDialog import CustomDialog

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My App for Custom Dialog")
        
        pushButton = QPushButton("Press Me for the Dialog") 
        pushButton.pressed.connect(self.button_clicked)
        self.setCentralWidget(pushButton)

    def button_clicked(self):
        print("click")
        dlg = CustomDialog(parent = self)
        if dlg.exec():
            print("Success!")
        else:
            print("Cancel!")

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()