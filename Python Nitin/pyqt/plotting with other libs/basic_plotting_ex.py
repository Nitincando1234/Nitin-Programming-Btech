import sys
import pyqtgraph as pg
from PyQt6 import QtWidgets, QtGui

class MainWindow(QtWidgets.QMainWindow):

    def __init__(self):
        super().__init__()

        self.plot_canvas = pg.PlotWidget()
        self.setCentralWidget(self.plot_canvas)
        minutes = [r for r in range(1, 11)]
        temperature = [30, 32, 34, 32, 33, 31, 29, 32, 35, 30]
        # self.plot_canvas.setBackground("w")
        # or also can be hex, rgb, rgba
        # self.plot_canvas.setBackground("#bbccaa")
        # also using QColor
        # self.plot_canvas.setBackground(QtGui.QColor(100, 50, 254, 25))
        # or the palatte of the window
        background_color = self.palette().color(QtGui.QPalette.ColorRole.Window)
        self.plot_canvas.setBackground(background_color)
        self.plot_canvas.plot(minutes, temperature)
        self.show()

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
app.exec()