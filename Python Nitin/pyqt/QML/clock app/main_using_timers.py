import sys
from time import strftime, localtime
from PyQt6.QtGui import QGuiApplication
from PyQt6.QtQml import QQmlApplicationEngine
from PyQt6.QtCore import QTimer

app = QGuiApplication(sys.argv)
engine = QQmlApplicationEngine()
engine.quit.connect(app.quit)
engine.load("main.qml")

def update_time():
    curr_time = strftime("%H:%M:%S", localtime())
    engine.rootObjects()[0].setProperty("currTime", curr_time)

timer = QTimer()
timer.setInterval(100)
timer.timeout.connect(update_time)

update_time()
sys.exit(app.exec())