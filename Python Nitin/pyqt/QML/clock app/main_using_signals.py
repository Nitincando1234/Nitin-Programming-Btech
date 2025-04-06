import sys
from time import strftime, localtime
from PyQt6.QtGui import QGuiApplication
from PyQt6.QtQml import QQmlApplicationEngine
from PyQt6.QtCore import QTimer, QObject, pyqtSignal

app = QGuiApplication(sys.argv)
engine = QQmlApplicationEngine()
engine.quit.connect(app.quit)
engine.load("main_using_signals.qml")

class Backend(QObject):

    updated = pyqtSignal(str, arguments = ["time"])
    def __init__(self):
        super().__init__()

        self.timer = QTimer()
        self.timer.setInterval(100)
        self.timer.timeout.connect(self.update_time)
        self.timer.start()

    def update_time(self):
        curr_time = strftime("%H:%M:%S", localtime())
        self.updated.emit(curr_time)
    
backend = Backend()

engine.rootObjects()[0].setProperty("backend", backend)

backend.update_time()
sys.exit(app.exec())