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

        self.plot_canvas.addLegend()
        self.plot_canvas.plot(time, temperature, pen = pen, name = "Temperature Sensor", symbol = "o", symbolSize = 20, symbolBrush = "b")
        # self.plot_canvas.setTitle("Temperature v/s Time", color = "b", size = "20pt")
        # or it can be HTML 
        self.plot_canvas.setTitle(
            '<span style="color: blue; font-size: 20pt">Temperature v/s Time</span>'
        )

        # styles = {"color": "red", "font-size": "18px"}
        # self.plot_canvas.setLabel("left", "Temerature(C)", **styles)
        # self.plot_canvas.setLabel("bottom", "Time(min)", **styles)
        # also can use the HTML
        self.plot_canvas.setLabel(
            "left",
            '<span style="color: red; font-size: 18px">Temperature(C)</span>'
        )
        self.plot_canvas.setLabel(
            "bottom",
            '<span style="color: red; font-size: 18px">Time(min)</span>'
        )
        self.plot_canvas.showGrid(x = True, y = False)
        self.plot_canvas.setXRange(0, 10)
        self.plot_canvas.setYRange(0, 40)

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()