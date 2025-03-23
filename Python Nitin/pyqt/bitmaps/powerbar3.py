import sys
from PyQt6 import QtWidgets, QtGui, QtCore
from PyQt6.QtCore import Qt

class _Bar(QtWidgets.QWidget):
    
    clicked_value = QtCore.pyqtSignal(int)

    def __init__(self, steps, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.setSizePolicy(
            QtWidgets.QSizePolicy.Policy.MinimumExpanding,
            QtWidgets.QSizePolicy.Policy.MinimumExpanding
        )

        if isinstance(steps, list):
            self.n_steps = len(steps)
            self.steps = steps
        
        elif isinstance(steps, int):
            # if the number of bars is given as int -> steps, then defaults to red
            self.n_steps = steps
            self.steps = ["red"] * steps
        
        else: raise TypeError("steps must be a list or int")
    
        self.bar_solid_percent = 0.8
        self.background_color = QtGui.QColor("black")
        self.padding = 4.0  # n-pixels around the edges
    
    def setSizeHint(self): return QtCore.QSize(40, 120)

    def paintEvent(self, e):
        painter = QtGui.QPainter(self)

        brush = QtGui.QBrush()
        brush.setColor(QtGui.QColor("black"))
        brush.setStyle(Qt.BrushStyle.SolidPattern)
        rect = QtCore.QRect(0, 0, painter.device().width(), painter.device().height())
        painter.fillRect(rect, brush)

        parent = self.parent()
        vmin, vmax = parent.minimum(), parent.maximum()
        value = parent.value()

        d_height = painter.device().height() - (self.padding * 2)
        d_width = painter.device().width() - (self.padding * 2)
        step_size = d_height / self.n_steps
        bar_height = step_size * self.bar_solid_percent
        bar_spacer = step_size * (1 - self.bar_solid_percent) / 2

        pc = (value - vmin) / (vmax - vmin)
        n_steps_to_draw = int(pc * self.n_steps)

        for n in range(n_steps_to_draw):
            brush.setColor(QtGui.QColor(self.steps[n]))
            rect = QtCore.QRect(
                int(self.padding),
                int(self.padding + d_height - ((n + 1) * step_size) + bar_spacer),
                int(d_width),
                int(bar_height)
            )
            painter.fillRect(rect, brush)
        painter.end()
    
    def calculate_clicked_value(self, e: QtGui.QMouseEvent):
        import math
        parent = self.parent()
        vmin, vmax = parent.minimum(), parent.maximum()
        d_height = self.height() - (self.padding * 2)
        step_size = d_height / self.n_steps
        click_y = e.position().y() - self.padding

        click_y = max(0, min(click_y, d_height))

        pc = 1 - (click_y / d_height)
        value = vmin + pc * (vmax - vmin)
        self.clicked_value.emit(int(value))

    def mouseMoveEvent(self, event): self.calculate_clicked_value(event)

    def mousePressEvent(self, event): self.calculate_clicked_value(event)

    def _trigger_refresh(self): self.update()

class PowerBar(QtWidgets.QWidget):

    def __init__(self, steps = 5,  *args, **kwargs):
        super().__init__(*args, **kwargs)

        layout = QtWidgets.QVBoxLayout()
        self.bar = _Bar(steps)
        layout.addWidget(self.bar)

        self.dial = QtWidgets.QDial()
        self.dial.setNotchesVisible(True)
        self.dial.setWrapping(False)
        self.dial.valueChanged.connect(self.bar._trigger_refresh)
        self.bar.clicked_value.connect(self.dial.setValue)
        layout.addWidget(self.dial)

        self.setLayout(layout)

    def __getattr__(self, name):
        if name in self.__dict__: return self.__dict__[name]

        try: return getattr(self.dial, name)
        except AttributeError: raise AttributeError(
            "'{}' object has no attribute '{}'".format(self.__class__.__name__, name)
        )
    
    def setColor(self, color):
        self.bar.steps = [color] * self.bar.n_steps
        self.bar.update()

    def setColors(self, colors):
        self.bar.n_steps = len(colors)
        self.bar.steps = colors
        self.bar.update()
    
    def setBarPadding(self, i):
        self.bar.padding = int(i)
        self.bar.update()

    def setBarSolidPercent(self, f):
        self.bar.bar_solid_percent = float(f)
        self.bar.update()

    def setBackgroundColor(self, color):
        self.bar.background_color = QtGui.QColor(color)
        self.bar.update()

app = QtWidgets.QApplication(sys.argv)
volume = PowerBar(["#5e4fa2", "#3288bd", "#66c2a5", "#abdda4", "#e6f598", "#ffffbf", "#fee08b", "#fdae61", "#f46d43", "#d53e4f", "#9e0142"])
# or PowerBar(Val: int)
volume.show()
app.exec()