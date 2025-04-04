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
        self.setCentralWidget(self.label)
        self.draw_text()
    
    def draw_line(self):
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        painter.drawLine(10, 10, 300, 200)
        painter.end()
        self.label.setPixmap(canvas)
    
    def draw_point(self):
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        pen = QtGui.QPen()
        pen.setWidth(40)
        pen.setColor(QtGui.QColor("red"))
        painter.setPen(pen)
        painter.drawPoint(200, 150)
        painter.end()
        self.label.setPixmap(canvas)
    
    def draw_messy(self):
        from random import randint, choice
        colors = ['#FFD141', '#376F9F', '#0D1F2D', '#E9EBEF', '#EB5160']

        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        pen = QtGui.QPen()
        pen.setWidth(3)
        painter.setPen(pen)

        for n in range(10000):
            # using "pen = painter.pen()" can be used if want to retrieve the pen from the painter
            pen.setColor(QtGui.QColor(choice(colors)))
            painter.setPen(pen)
            painter.drawPoint(
                200 + randint(-100, 100),
                150 + randint(-100, 100)
            )
        
        painter.end()
        self.label.setPixmap(canvas)
    
    def draw_line(self):
        from random import randint
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        pen = QtGui.QPen()
        pen.setWidth(15)
        pen.setColor(QtGui.QColor("blue"))
        painter.setPen(pen)
        painter.drawLine(
            QtCore.QPoint(100, 100), 
            QtCore.QPoint(300, 200)
        )
        painter.end()
        self.label.setPixmap(canvas)

    def draw_rectangle(self):
        from random import randint
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        pen = QtGui.QPen()
        pen.setWidth(3)
        pen.setColor(QtGui.QColor("red"))
        painter.setPen(pen)

        brush = QtGui.QBrush()
        brush.setColor(QtGui.QColor("yellow"))
        brush.setStyle(Qt.BrushStyle.Dense1Pattern)
        painter.setBrush(brush)
        
        # painter.drawRect(50, 50, 100, 100)
        # painter.drawRect(60, 60, 150, 100)
        # painter.drawRect(70, 70, 100, 150)
        # painter.drawRect(80, 80, 150, 100)
        # painter.drawRect(90, 90, 100, 150)        
        # or

        painter.drawRects(
            QtCore.QRect(50, 50, 100, 100),
            QtCore.QRect(60, 60, 150, 100),
            QtCore.QRect(70, 70, 100, 150),
            QtCore.QRect(80, 80, 150, 100),
            QtCore.QRect(90, 90, 100, 150),        
        )

        painter.end()
        self.label.setPixmap(canvas)   

    def draw_rounded_rects(self):
        from random import randint
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        painter.setRenderHint(QtGui.QPainter.RenderHint.Antialiasing)
        
        pen = QtGui.QPen()
        pen.setWidth(3)
        pen.setColor(QtGui.QColor("blue"))
        painter.setPen(pen)

        painter.drawRoundedRect(40, 40, 100, 100, 10, 10)
        painter.drawRoundedRect(80, 80, 100, 100, 10, 50)
        painter.drawRoundedRect(120, 120, 100, 100, 50, 10)
        painter.drawRoundedRect(160, 160, 100, 100, 50, 50)

        painter.end()    
        self.label.setPixmap(canvas)
    
    def draw_ellipse(self):
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)
        painter.setRenderHint(QtGui.QPainter.RenderHint.Antialiasing)

        pen = QtGui.QPen()
        pen.setWidth(3)
        pen.setColor(QtGui.QColor(204,0,0))  # r, g, b
        painter.setPen(pen)

        # painter.drawEllipse(10, 10, 100, 100)
        # painter.drawEllipse(10, 10, 150, 200)
        # painter.drawEllipse(10, 10, 200, 300)
        # or

        painter.drawEllipse(QtCore.QPoint(100, 100), 10, 10)
        painter.drawEllipse(QtCore.QPoint(100, 100), 15, 20)
        painter.drawEllipse(QtCore.QPoint(100, 100), 20, 30)
        painter.drawEllipse(QtCore.QPoint(100, 100), 25, 40)
        painter.drawEllipse(QtCore.QPoint(100, 100), 30, 50)
        painter.drawEllipse(QtCore.QPoint(100, 100), 35, 60)

        painter.end()
        self.label.setPixmap(canvas)

    def draw_text(self):
        canvas = self.label.pixmap()
        painter = QtGui.QPainter(canvas)

        pen = QtGui.QPen()
        # pen.setWidth(1)
        pen.setColor(QtGui.QColor("green"))
        painter.setPen(pen)

        font = QtGui.QFont()
        font.setFamily("Times")
        font.setBold(True)
        font.setPointSize(40)
        painter.setFont(font)

        # painter.drawText(QtCore.QPoint(100, 100), "Hello World")
        # and also for bounded-box text
        painter.drawText(100, 100, 100, 100, Qt.AlignmentFlag.AlignHCenter, "Hello, World !")
        
        painter.end()
        self.label.setPixmap(canvas)
    
app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()