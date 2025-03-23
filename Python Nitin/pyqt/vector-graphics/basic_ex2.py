import sys
from PyQt6.QtWidgets import QGraphicsScene, QGraphicsView, QGraphicsItem, QGraphicsRectItem, QGraphicsEllipseItem, QApplication
from PyQt6.QtGui import QBrush, QPen
from PyQt6.QtCore import Qt

app = QApplication(sys.argv)

scene = QGraphicsScene(0, 0, 400, 200)
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

# ellipse.setZValue(0.01)
# rect.setZValue(0)
# or
rect.stackBefore(ellipse)

scene.addItem(rect)
scene.addItem(ellipse)

ellipse.setFlag(QGraphicsItem.GraphicsItemFlag.ItemIsMovable | QGraphicsItem.GraphicsItemFlag.ItemIsSelectable)

view = QGraphicsView(scene)
view.show()
app.exec()