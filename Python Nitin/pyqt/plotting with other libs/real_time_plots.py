from PyQt6 import QtWidgets, QtCore
from random import randint
import pyqtgraph as pg
import sys

class MainWindow(QtWidgets.QMainWindow):

    def __init__(self):
        super().__init__()

        self.plot_canvas = pg.PlotWidget()
        self.setCentralWidget(self.plot_canvas)
        self.plot_canvas.setBackground("w")
        self.plot_canvas.setTitle("Temperature v/s Time", color = "b", size = "20pt")
        styles = {"color": "red", "font-size": "18px"}
        self.plot_canvas.setLabel("left", "Temperature(C)", **styles)
        self.plot_canvas.setLabel("bottom", "Time(min)", **styles)
        self.plot_canvas.addLegend()
        self.plot_canvas.showGrid(x = True, y = True)
        pen =  pg.mkPen(color = (255, 0, 0))
        self.plot_canvas.setYRange(20, 40)
        self.time = list(range(10))
        self.temperature = [randint(20, 40) for _ in range(10)]

        self.line_plot = self.plot_canvas.plot(
            self.time,
            self.temperature, 
            name = "Real Time Temperature Sensor Data", 
            pen = pen, 
            symbol = "+", 
            symbolSize = 15, 
            symbolBrush = "b"
        )

        self.timer = QtCore.QTimer()
        self.timer.setInterval(300)
        self.timer.timeout.connect(self.updatePlot)
        self.timer.start()
        
    def updatePlot(self):
        self.time = self.time[1: ]
        self.time.append(self.time[-1] + 1)     # increase the time with a min
        self.temperature = self.temperature[1: ]
        self.temperature.append(randint(20, 40))
        self.line_plot.setData(self.time, self.temperature)

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()