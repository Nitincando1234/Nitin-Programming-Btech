from PyQt6 import QtWidgets
from PyQt6 import QtGui
import sys, os

basedir = os.path.dirname(__file__)
try:
    from ctypes import windll
    myappid = "com.nitin.hello_world_app"
    windll.shell32.SetCurrentProcessExplicitAppUserModelID(myappid)
except: pass

class MainWindow(QtWidgets.QMainWindow):
    
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Hello World")
        l = QtWidgets.QLabel("My Simple App")
        l.setMargin(10)
        self.setCentralWidget(l)
        self.show()
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    w = MainWindow()
    w.setWindowIcon(QtGui.QIcon(os.path.join(basedir, "app.ico")))
    app.exec()