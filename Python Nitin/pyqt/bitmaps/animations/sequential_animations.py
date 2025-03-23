from PyQt6.QtWidgets import QWidget, QApplication
from PyQt6.QtCore import QPropertyAnimation, QSequentialAnimationGroup, QPoint, QSize

class Window(QWidget):
    
    def __init__(self):
        super().__init__()
        self.resize(600, 600)
        self.child = QWidget(self)
        self.child.setStyleSheet("background-color:red; border-radius:15px;")
        self.child.resize(100, 100)
        self.anim = QPropertyAnimation(self.child, b"pos")
        self.anim.setEndValue(QPoint(200, 200))
        self.anim.setDuration(1500)
        self.anim2 = QPropertyAnimation(self.child, b"size")
        self.anim2.setEndValue(QSize(250, 150))
        self.anim2.setDuration(2000)
        self.animGroup = QSequentialAnimationGroup()
        self.animGroup.addAnimation(self.anim)
        self.animGroup.addAnimation(self.anim2)
        self.animGroup.start()

        self.show()
    
app = QApplication([])
window = Window()
app.exec()