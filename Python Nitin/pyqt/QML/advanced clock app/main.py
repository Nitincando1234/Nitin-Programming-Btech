import sys
from time import strftime, localtime
from PyQt6.QtGui import QGuiApplication
from PyQt6.QtQml import QQmlApplicationEngine
from PyQt6.QtCore import QTimer, QObject, pyqtSignal

app = QGuiApplication(sys.argv)
engine = QQmlApplicationEngine()
engine.quit.connect(app.quit)
engine.load("E:\\Nitin-Programming-Btech\\Python Nitin\\pyqt\\QML\\advanced clock app\\main.qml")

class Backend(QObject):

    updated = pyqtSignal(str, arguments = ["time"])
    hms = pyqtSignal(int, int, int, arguments = ["hours", "mins", "seconds"])

    def __init__(self):
        super().__init__()

        self.timer = QTimer()
        self.timer.setInterval(100)
        self.timer.timeout.connect(self.update_time)
        self.timer.start()

    def update_time(self):
        local_time = localtime()
        curr_time = strftime("%H:%M:%S", local_time)
        self.hms.emit(local_time.tm_hour, local_time.tm_min, local_time.tm_sec)
        self.updated.emit(curr_time)
    
backend = Backend()

engine.rootObjects()[0].setProperty("backend", backend)

backend.update_time()
sys.exit(app.exec())