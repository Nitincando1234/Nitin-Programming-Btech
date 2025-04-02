import sys
from PyQt6.QtWidgets import QGraphicsScene, QGraphicsView, QApplication

app = QApplication(sys.argv)
scene = QGraphicsScene(0, 0, 400, 200)

view = QGraphicsView(scene)
view.show()
app.exec()