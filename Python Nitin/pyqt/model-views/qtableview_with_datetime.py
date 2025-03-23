import sys
import datetime
from PyQt6.QtWidgets import *
from PyQt6.QtCore import *
from PyQt6.QtGui import *

class TableModel(QAbstractTableModel):

    def __init__(self, data):
        super().__init__()
        self._data = data
    
    def data(self, index, role):
        if role == Qt.ItemDataRole.BackgroundRole and index.row() == 2: return QColor("blue")
        if role == Qt.ItemDataRole.ForegroundRole:
            value = self._data[index.row()][index.column()]
            if(
                (isinstance(value, int) or isinstance(value, float)) and (value < 0)
            ): return QColor("red")
        if role == Qt.ItemDataRole.TextAlignmentRole:
            value = self._data[index.row()][index.column()]
            if isinstance(value, int) or isinstance(value, float): return Qt.AlignmentFlag.AlignVCenter + Qt.AlignmentFlag.AlignRight
        if role == Qt.ItemDataRole.DisplayRole:
            value = self._data[index.row()][index.column()]

            if isinstance(value, datetime.datetime): return value.strftime("%Y-%m-%d")
            if isinstance(value, float): return "%.2f" % value
            if isinstance(value, str): return '"%s"' % value
            return value
        
    def rowCount(self, index): return len(self._data)

    def columnCount(self, index): return len(self._data[0])

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()

        self.table = QTableView()

        data = [
            [4, 9, 2],
            [1, -1, 'hello'],
            [3.023, 5, -5],
            [3, 3, datetime.datetime(2017,10,1)],
            [7.555, 8, 9],
        ]

        self.model = TableModel(data)
        self.table.setModel(self.model)

        self.setCentralWidget(self.table)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()