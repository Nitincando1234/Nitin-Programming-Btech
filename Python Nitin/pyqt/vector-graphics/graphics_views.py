import sys

from PyQt6.QtCore import Qt
from PyQt6.QtGui import QBrush, QPainter, QPen
from PyQt6.QtWidgets import (
    QApplication,
    QGraphicsEllipseItem,
    QGraphicsItem,
    QGraphicsRectItem,
    QGraphicsScene,
    QGraphicsView,
    QHBoxLayout,
    QPushButton,
    QSlider,
    QVBoxLayout,
    QWidget,
)

class Window(QWidget):

    def __init__(self):
        super().__init__()

        self.scene = QGraphicsScene(0, 0, 400, 200)
        
        rect = QGraphicsRectItem(0, 0, 200, 50)
        rect.setPos(50, 20)
        brush = QBrush(Qt.GlobalColor.red)
        rect.setBrush(brush)

        pen = QPen(Qt.GlobalColor.cyan)
        pen.setWidth(10)
        rect.setPen(pen)

        ellipse = QGraphicsEllipseItem(0, 0, 100, 100)
        ellipse.setPos(75, 30)

        brush = QBrush(Qt.GlobalColor.blue)
        ellipse.setBrush(brush)

        pen = QPen(Qt.GlobalColor.green)
        pen.setWidth(5)
        ellipse.setPen(pen)

        self.scene.addItem(ellipse)
        self.scene.addItem(rect)

        for item in self.scene.items():
            item.setFlag(QGraphicsItem.GraphicsItemFlag.ItemIsMovable)
            item.setFlag(QGraphicsItem.GraphicsItemFlag.ItemIsSelectable)
        
        vbox = QVBoxLayout()

        up = QPushButton("Up")
        up.clicked.connect(self.up)
        vbox.addWidget(up)

        down = QPushButton("Down")
        down.clicked.connect(self.down)
        vbox.addWidget(down)

        rotate = QSlider()
        rotate.setRange(0, 360)
        rotate.valueChanged.connect(self.rotate)
        vbox.addWidget(rotate)

        view = QGraphicsView(self.scene)
        view.setRenderHint(QPainter.RenderHint.Antialiasing)

        hbox = QHBoxLayout(self)
        hbox.addLayout(vbox)
        hbox.addWidget(view)

        self.setLayout(hbox)
    
    def up(self):
        items = self.scene.selectedItems()
        for item in items:
            z = item.zValue()
            item.setZValue(z + 1)

    def down(self):
        items = self.scene.selectedItems()
        for item in items:
            z = item.zValue()
            item.setZValue(z - 1)    
    
    def rotate(self, value):
        items = self.scene.selectedItems()
        for item in items: item.setRotation(value)
    
app = QApplication(sys.argv)
window = Window()
window.show()
app.exec()