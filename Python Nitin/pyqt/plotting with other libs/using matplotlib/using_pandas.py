import sys
import matplotlib
import pandas as pd
matplotlib.use("QtAgg")
from PyQt6 import QtWidgets, QtCore, QtGui
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg, NavigationToolbar2QT as NavigationToolbar
from matplotlib.figure import Figure

class MplCanvas(FigureCanvasQTAgg):

    def __init__(self, parent = None, width = 5, height = 4, dpi = 100):
        fig = Figure(figsize = (width, height), dpi = dpi)
        self.axes = fig.add_subplot(111)
        super().__init__(fig)

class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.setWindowTitle("Pandas Plots")
        self.setWindowIcon(QtGui.QIcon("E:/Nitin-Programming-Btech/Python Nitin/pyqt/fugue-icons-3.5.6/icons/android.png"))

        df = pd.DataFrame([
            [0, 10], [5, 15], [2, 20], [15, 25], [4, 10]
        ], columns = ["A", "B"])
        sc = MplCanvas(self, width = 5, height = 4,  dpi = 100)
        toolbar = NavigationToolbar(sc, self)

        df.plot(ax = sc.axes)

        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(toolbar)
        layout.addWidget(sc)

        widget = QtWidgets.QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)
        self.show()

app = QtWidgets.QApplication([])
window = MainWindow()
app.exec()