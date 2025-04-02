import sys
import datetime
from PyQt6.QtWidgets import *
from PyQt6.QtCore import *
from PyQt6.QtGui import *

COLORS = ['#053061', '#2166ac', '#4393c3', '#92c5de', '#d1e5f0',
         '#f7f7f7', '#fddbc7', '#f4a582', '#d6604d', '#b2182b', '#67001f']

class TableModel(QAbstractTableModel):

    def __init__(self, data):
        super().__init__()
        self._data = data
    
    def data(self, index, role):
        # if role == Qt.ItemDataRole.BackgroundRole:
        #     value = self._data[index.row()][index.column()]
        #     if(isinstance(value, int) or isinstance(value, float)): 
        #         value = int(value)
        #         value = max(-5, value)
        #         value = min(5, value)
        #         value += 5
        #         return QColor(COLORS[value])
        #     else: return QColor(COLORS[-1])
        if role == Qt.ItemDataRole.ForegroundRole:
            value = self._data[index.row()][index.column()]
            if(
                (isinstance(value, int) or isinstance(value, float)) and (value < 0)
            ): return QColor("white")
            else: return QColor("blue")
        if role == Qt.ItemDataRole.TextAlignmentRole:
            value = self._data[index.row()][index.column()]
            if isinstance(value, int) or isinstance(value, float): return Qt.AlignmentFlag.AlignVCenter + Qt.AlignmentFlag.AlignRight
        if role == Qt.ItemDataRole.DisplayRole:
            value = self._data[index.row()][index.column()]

            if isinstance(value, datetime.datetime): return value.strftime("%Y-%m-%d")
            if isinstance(value, float): return "%.2f" % value
            if isinstance(value, str): return '"%s"' % value
            return value
        if role == Qt.ItemDataRole.DecorationRole:
            value = self._data[index.row()][index.column()]
            if isinstance(value, datetime.datetime): return QIcon("calendar.png")
            if isinstance(value, bool):
                if value: return QIcon("tick-button.png")
                else: return QIcon("cross-button.png")
            return QColor(COLORS[0])    # remove if using backgroundRole
        
    def rowCount(self, index): return len(self._data)

    def columnCount(self, index): return len(self._data[0])

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()

        self.table = QTableView()

        data = [
            [True, 9, 2],
            [1, 0, -1],
            [3, 5, False],
            [3, 3, 2],
            [datetime.datetime(2019, 5, 4), 8, 9],
        ]

        self.model = TableModel(data)
        self.table.setModel(self.model)

        self.setCentralWidget(self.table)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()