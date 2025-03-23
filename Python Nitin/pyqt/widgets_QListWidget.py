import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QListWidget

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("APPlication")

        widget = QListWidget()
        widget.addItems(["First", "Second", "Third"] * 10)
        widget.currentItemChanged.connect(self.idx_changed)
        widget.currentTextChanged.connect(self.txt_changed)
        self.setCentralWidget(widget)
    
    def idx_changed(self, idx): print(idx)
    def txt_changed(self, txt): print(txt)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()