import sys
from PyQt6.QtWidgets import QGraphicsScene, QGraphicsView, QGraphicsRectItem, QApplication
from PyQt6.QtGui import QBrush, QPen
from PyQt6.QtCore import Qt

app = QApplication(sys.argv)

scene = QGraphicsScene(0, 0, 400, 200)

rect = scene.addRect(0, 0, 200, 50)
rect.setPos(50, 20)

brush = QBrush(Qt.GlobalColor.red)
rect.setBrush(brush)

pen = QPen(Qt.GlobalColor.cyan)
pen.setWidth(10)
rect.setPen(pen)

view = QGraphicsView(scene)
view.show()
app.exec()