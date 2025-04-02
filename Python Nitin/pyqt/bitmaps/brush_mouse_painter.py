import sys
from PyQt6 import QtCore, QtGui, QtWidgets, uic
from PyQt6.QtCore import Qt

COLORS = [
# 17 undertones https://lospec.com/palette-list/17undertones
'#000000', '#141923', '#414168', '#3a7fa7', '#35e3e3', '#8fd970', '#5ebb49',
'#458352', '#dcd37b', '#fffee5', '#ffd035', '#cc9245', '#a15c3e', '#a42f3b',
'#f45b7a', '#c24998', '#81588d', '#bcb0c2', '#ffffff',
]

class Canvas(QtWidgets.QLabel):

    def __init__(self):
        super().__init__()
        pixmap = QtGui.QPixmap(1280, 720)
        pixmap.fill(Qt.GlobalColor.white)
        self.setPixmap(pixmap)
        self.last_x, self.last_y = (None, ) * 2
        self.pen_color = QtGui.QColor("#000000")
    
    def set_pen_color(self, c):
        self.pen_color = QtGui.QColor(c)
    
    def mouseMoveEvent(self, e):
        import random
        SPRAY_PARTICLES = 100
        SPRAY_DIAMETER = 10

        if not self.last_x:
            self.last_x, self.last_y = int(e.position().x()), int(e.position().y())
            return
        
        canvas = self.pixmap()
        painter = QtGui.QPainter(canvas)
        painter.setRenderHint(QtGui.QPainter.RenderHint.Antialiasing)
        p = painter.pen()
        p.setWidth(4)
        p.setColor(self.pen_color)
        painter.setPen(p)
        for n in range(SPRAY_PARTICLES):
            x0 = random.gauss(0, SPRAY_DIAMETER)
            y0 = random.gauss(0, SPRAY_DIAMETER)
            painter.drawPoint(
                int(e.position().x() + x0),
                int(e.position().y() + y0)
            )
        painter.end()
        self.setPixmap(canvas)

class QPaletteButton(QtWidgets.QPushButton):

    def __init__(self, color):
        super().__init__()
        self.setFixedSize(QtCore.QSize(24, 24))
        self.color = color
        self.setStyleSheet("Background-color: %s" % color)

class MainWindow(QtWidgets.QMainWindow):

    def __init__(self):
        super().__init__()

        self.canvas = Canvas()

        w = QtWidgets.QWidget()
        l = QtWidgets.QVBoxLayout()
        w.setLayout(l)
        l.addWidget(self.canvas)

        palette = QtWidgets.QHBoxLayout()
        self.add_palette_buttons(palette)
        l.addLayout(palette)

        self.setCentralWidget(w)
    
    def add_palette_buttons(self, layout):
        for c in COLORS:
            b = QPaletteButton(c)
            b.pressed.connect(lambda c = c: self.canvas.set_pen_color(c))
            layout.addWidget(b)
        
app = QtWidgets.QApplication([])
window = MainWindow()
window.show()
app.exec()
