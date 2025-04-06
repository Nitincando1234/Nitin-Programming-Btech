import sys
from time import strftime, localtime
from PyQt6.QtGui import QGuiApplication
from PyQt6.QtQml import QQmlApplicationEngine

app = QGuiApplication(sys.argv)
engine = QQmlApplicationEngine()
engine.quit.connect(app.quit)
engine.load("main.qml")

currTime = strftime("%H:%M:%S", localtime())
engine.rootObjects()[0].setProperty("currTime", currTime)

sys.exit(app.exec())