import sys
import pyqtgraph as pg
from PyQt6 import QtWidgets, QtCore

class MainWindow(QtWidgets.QMainWindow):

    def __init__(self):
        super().__init__()
        self.plot_canvas = pg.PlotWidget()
        self.setCentralWidget(self.plot_canvas)
        self.plot_canvas.setBackground("w")
        pen = pg.mkPen(color = (255, 0, 0), width = 5, style = QtCore.Qt.PenStyle.DashLine)

        time = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        temperature = [30, 32, 34, 32, 33, 31, 29, 32, 35, 45]

        self.plot_canvas.plot(time, temperature, pen = pen, symbol = "o", symbolSize = 20, symbolBrush = "b")
        # self.plot_canvas.setTitle("Temperature v/s Time", color = "b", size = "20pt")
        # or it can be HTML 
        self.plot_canvas.setTitle(
            '<span style="color: blue; font-size: 20pt">Temperature v/s Time</span>'
        )

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()