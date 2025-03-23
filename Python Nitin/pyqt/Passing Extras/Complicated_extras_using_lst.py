import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QCheckBox
from PyQt6.QtCore import Qt

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        checkBox = QCheckBox("Check Me !")
        _converter = {Qt.CheckState.Checked: True, Qt.CheckState.Unchecked: False}
        checkBox.stateChanged.connect(
            lambda v: self.result(_converter[Qt.CheckState(v)])
        )
        self.setCentralWidget(checkBox)
    
    def result(self, v):
        print(v)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()