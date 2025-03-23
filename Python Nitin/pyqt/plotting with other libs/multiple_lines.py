from PyQt6 import QtWidgets
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
        self.plot_canvas.setXRange(0, 10)
        self.plot_canvas.setYRange(0, 40)
        minutes = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        temp_1 = [30, 32, 34, 32, 33, 31, 29, 32, 35, 30]
        temp_2 = [32, 35, 40, 22, 38, 32, 27, 38, 32, 38]
        pen =  pg.mkPen(color = (255, 0, 0))
        self.plot_line("Temperature sensor 1", minutes, temp_1, pen, "b")
        pen = pg.mkPen(color = (0, 0, 255))
        self.plot_line("Temperature sensor 2", minutes, temp_2, pen, "r")
    
    def plot_line(self, name, minutes, temperature, pen, brush):
        self.plot_canvas.plot(
            minutes,
            temperature, 
            name = name, 
            pen = pen, 
            symbol = "+", 
            symbolSize = 15, 
            symbolBrush = brush
        )

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()