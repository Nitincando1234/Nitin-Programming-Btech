import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QCheckBox
from PyQt6.QtCore import Qt

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        checkBox = QCheckBox()
        def check_to_bool(state):
            if Qt.CheckState(state) == Qt.CheckState.Checked: return self.result(True)
            return self.result(False)
        checkBox.stateChanged.connect(check_to_bool)
        self.setCentralWidget(checkBox)
    
    def result(self, v):
        print(v)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()