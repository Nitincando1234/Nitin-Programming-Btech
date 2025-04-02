import sys
from PyQt6 import QtWidgets, QtGui, QtCore
from PyQt6.QtCore import Qt

class _Bar(QtWidgets.QWidget):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.setSizePolicy(
            QtWidgets.QSizePolicy.Policy.MinimumExpanding,
            QtWidgets.QSizePolicy.Policy.MinimumExpanding
        )
    
    def setSizeHint(self): return QtCore.QSize(40, 120)

    def paintEvent(self, e):
        painter = QtGui.QPainter(self)

        brush = QtGui.QBrush()
        brush.setColor(QtGui.QColor("black"))
        brush.setStyle(Qt.BrushStyle.SolidPattern)
        rect = QtCore.QRect(0, 0, painter.device().width(), painter.device().height())
        painter.fillRect(rect, brush)

        dial = self.parent().dial
        vmin, vmax = dial.minimum(), dial.maximum()
        value = dial.value()

        padding = 5
        d_height = painter.device().height() - (padding * 2)
        d_width = painter.device().width() - (padding * 2)
        step_size = d_height / 5
        bar_height = step_size * 0.6
        bar_spacer = step_size * 0.4 / 2

        pc = (value - vmin) / (vmax - vmin)
        n_steps_to_draw = int(pc * 5)

        brush.setColor(QtGui.QColor("red"))
        for n in range(n_steps_to_draw):
            rect = QtCore.QRect(
                int(padding),
                int(padding + d_height - ((n + 1) * step_size) + bar_spacer),
                int(d_width),
                int(bar_height)
            )
            painter.fillRect(rect, brush)
        painter.end()
    
    def _trigger_refresh(self): self.update()


class PowerBar(QtWidgets.QWidget):

    def __init__(self, steps = 5,  *args, **kwargs):
        super().__init__(*args, **kwargs)

        layout = QtWidgets.QVBoxLayout()
        self.bar = _Bar()
        layout.addWidget(self.bar)

        self.dial = QtWidgets.QDial()
        self.dial.valueChanged.connect(self.bar._trigger_refresh)
        layout.addWidget(self.dial)

        self.setLayout(layout)

app = QtWidgets.QApplication(sys.argv)
volume = PowerBar()
volume.show()
app.exec()