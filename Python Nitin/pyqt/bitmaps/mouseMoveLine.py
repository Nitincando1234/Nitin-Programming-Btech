import sys
from PyQt6 import QtCore, QtGui, QtWidgets, uic
from PyQt6.QtCore import Qt

class MainWindow(QtWidgets.QMainWindow):

    def __init__(self):
        super().__init__()

        self.label = QtWidgets.QLabel()
        canvas = QtGui.QPixmap(400, 300)
        canvas.fill(Qt.GlobalColor.white)
        self.label.setPixmap(canvas)
        self.setMouseTracking(True)
        self.setCentralWidget(self.label)

        self.last_x, self.last_y = (None,) * 2
    
    def mouseMoveEvent(self, e):
        if not self.last_x:
            self.last_x = int(e.position().x())
            self.last_y = int(e.position().y())
            return
        
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        painter.setRenderHint(QtGui.QPainter.RenderHint.Antialiasing)
        painter.drawLine(
            int(self.last_x), int(self.last_y), int(e.position().x()), int(e.position().y())
        )
        painter.end()
        self.label.setPixmap(canvas)

        self.last_x = int(e.position().x())
        self.last_y = int(e.position().y())
        
    def mouseReleaseEvent(self, e):
        self.last_x, self.last_y = (None, ) * 2

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()