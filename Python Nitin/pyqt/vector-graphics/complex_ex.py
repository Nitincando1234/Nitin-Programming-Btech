from PyQt6.QtCore import QPointF, Qt
from PyQt6.QtWidgets import QGraphicsRectItem, QGraphicsScene, QGraphicsView, QApplication
from PyQt6.QtGui import QBrush, QPainter, QPen, QPixmap, QPolygonF
import sys

app = QApplication(sys.argv)

scene = QGraphicsScene(0, 0, 400, 200)

rectItem = QGraphicsRectItem(0, 0, 360, 20)
rectItem.setPos(20, 20)
rectItem.setBrush(QBrush(Qt.GlobalColor.red))
rectItem.setPen(QPen(Qt.GlobalColor.cyan))
scene.addItem(rectItem)

textItem = scene.addText("QGraphics is fun !")
textItem.setPos(100, 100)

scene.addPolygon(
    QPolygonF([
            QPointF(30, 60),        # (x, y) points
            QPointF(270, 40),
            QPointF(400, 200),
            QPointF(20, 150),
        ]), QPen(Qt.GlobalColor.darkGreen)
)

pixmap = QPixmap("E:\\Nitin-Programming-Btech\\Python Nitin\\pyqt\\fugue-icons-3.5.6\\combination.png")
pixmapItem = scene.addPixmap(pixmap)
pixmapItem.setPos(250, 70)

view = QGraphicsView(scene)
view.setRenderHint(QPainter.RenderHint.Antialiasing)
view.show()

app.exec()