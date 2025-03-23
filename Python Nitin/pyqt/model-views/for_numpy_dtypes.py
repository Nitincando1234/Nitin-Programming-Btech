import sys
import numpy as np
from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.QtWidgets import *

class TableModel(QAbstractTableModel):

    def __init__(self, data):
        super().__init__()
        self._data = data
    
    def data(self, index, role):
        if role == Qt.ItemDataRole.DisplayRole:
            value = self._data[index.row()][index.column()]
            return str(value)
    
    def rowCount(self, index): return self._data.shape[0]

    def columnCount(self, index): return self._data.shape[1]

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()
        self.setWindowTitle("NumPy Table")

        self.table = QTableView()
        data = np.array([
            [1, 9, 2],
            [1, 0, -1],
            [3, 5, 2],
            [3, 3, 2],
            [5, 8, 9],
        ])
        self.model = TableModel(data)
        self.table.setModel(self.model)

        self.setCentralWidget(self.table)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()