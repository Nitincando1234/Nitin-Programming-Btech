import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QComboBox

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My Application")
        widget = QComboBox()
        widget.setMaxCount(10)
        widget.addItems(["First", "Second", "Third"])
        widget.setEditable(True)
        widget.setInsertPolicy(QComboBox.InsertPolicy.InsertAlphabetically)
        widget.currentIndexChanged.connect(self.index_changed)
        widget.currentTextChanged.connect(self.text_changed)
        self.setCentralWidget(widget)
    
    def index_changed(self, idx): print(idx)
    def text_changed(self, txt): print(txt)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
