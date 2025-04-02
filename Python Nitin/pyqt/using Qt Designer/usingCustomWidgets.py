from PyQt6 import QtWidgets, uic
from pyqtgraph import PlotWidget
import pyqtgraph as pg
import sys

class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        uic.loadUi("pyqtplots_widgets_tut.ui", self)
        self.plot(range(1000), range(1000))
    
    def plot(self, hours, temp):
        self.graphWidget.plot(hours, temp)

def main():
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())

if __name__ == "__main__": main()