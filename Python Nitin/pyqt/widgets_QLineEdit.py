import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QLineEdit

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Application")

        self.widget = QLineEdit()
        self.widget.setInputMask('000.000.000.000;_')
        self.widget.setMaxLength(10)
        self.widget.setPlaceholderText("Enter your text")

        self.widget.returnPressed.connect(self.return_pressed)
        self.widget.selectionChanged.connect(self.selection_changed)
        self.widget.textChanged.connect(self.text_changed)
        self.widget.textEdited.connect(self.text_edited)

        self.setCentralWidget(self.widget)
    
    def return_pressed(self):
        print("Return pressed!")
        self.centralWidget().setText("BOOM!")

    def selection_changed(self):
        print("Selection changed")
        print(self.centralWidget().selectedText())

    def text_changed(self, s):
        print("Text changed...")
        print(s)

    def text_edited(self, s):
        print("Text edited...")
        print(s)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()