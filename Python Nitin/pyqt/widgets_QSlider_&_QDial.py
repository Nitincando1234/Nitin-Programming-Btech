import sys
from PyQt6.QtWidgets import QMainWindow, QApplication, QSlider, QDial
from PyQt6.QtCore import Qt

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        # widget = QSlider(Qt.Orientation.Horizontal)
        widget = QDial()
        widget.setMinimum(-9)   #
                                # or window.setRange(-inf, inf)
        widget.setMaximum(9)    #
        widget.setSingleStep(1)
        widget.valueChanged.connect(self.value_changed)
        widget.sliderMoved.connect(self.slider_position)
        widget.sliderPressed.connect(self.slider_pressed)
        widget.sliderReleased.connect(self.slider_released)

        self.setCentralWidget(widget)

    def value_changed(self, i):
        print(i)

    def slider_position(self, p):
        print("Position", p)

    def slider_pressed(self):
        print("Pressed!")

    def slider_released(self):
        print("Released")        

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()