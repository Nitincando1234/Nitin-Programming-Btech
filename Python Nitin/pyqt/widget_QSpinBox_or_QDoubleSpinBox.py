import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QSpinBox, QDoubleSpinBox

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        widget = QSpinBox()     # or QDoubleSpinBox
        widget.setMinimum(-9)
        widget.setMaximum(10)
        widget.setPrefix("$")
        widget.setSuffix("c")
        widget.setSingleStep(2)
        widget.setReadOnly(True)
        widget.valueChanged.connect(self.value_changed)
        widget.textChanged.connect(self.value_changed_str)

        self.setCentralWidget(widget)
    
    def value_changed(self, i):
        print("value changed: ", i)

    def value_changed_str(self, s):
        print("text changed: ", s)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()