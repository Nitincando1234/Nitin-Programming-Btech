import sys
import json
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic

qt_creator_file = "mainwindow.ui"
tick = QImage("tick-button.png")
Ui_MainWindow, QtBaseClass = uic.loadUiType(qt_creator_file)

class TodoModel(QAbstractListModel):

    def __init__(self, *args, todos = None, **kwargs):
        super().__init__(*args, **kwargs)
        self.todos = todos or []    # stores the tuple: (bool, str) = (todo_completed?, todo_name)
    
    def data(self, index, role):
        if role == Qt.ItemDataRole.DisplayRole:
            _, text = self.todos[index.row()]
            return text
        
        if role == Qt.ItemDataRole.DecorationRole:
            status, _ = self.todos[index.row()]
            if status: return tick
        
    def rowCount(self, index): return len(self.todos)

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)

        self.setupUi(self)
        self.model = TodoModel()
        self.load()
        self.setWindowTitle("My ToDo")

        self.todoView.setModel(self.model)

        self.addButton.pressed.connect(self.add)
        self.deleteButton.pressed.connect(self.delete)
        self.completeButton.pressed.connect(self.complete)
    
    def add(self):
        text = self.todoEdit.text()
        if text:
            self.model.todos.append((False, text))
            self.model.layoutChanged.emit()
            self.todoEdit.setText("")
        self.save()

    def delete(self):
        indexes = self.todoView.selectedIndexes()
        if indexes:
            index = indexes[0]
            del self.model.todos[index.row()]
            self.model.layoutChanged.emit()
            self.todoView.clearSelection()
        self.save()
    
    def complete(self):
        indexes = self.todoView.selectedIndexes()
        if indexes:
            index = indexes[0]
            row = index.row()
            status, text = self.model.todos[row]
            self.model.todos[row] = (True, text)
            self.model.dataChanged.emit(index, index)
            self.todoView.clearSelection()
        self.save()

    # Persistant-store
    def load(self):
        try:
            with open("data.db", "r") as file:
                self.model.todos = json.load(file)
        except Exception: sys.stderr.write("Exception occured while the data loaded !")
    
    def save(self):
        with open("data.db", "w") as file:
            json.dump(self.model.todos, file)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
