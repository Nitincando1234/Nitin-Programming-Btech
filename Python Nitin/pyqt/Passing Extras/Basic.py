import sys
from PyQt6.QtWidgets import QApplication, QMainWindow

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.windowTitleChanged.connect(self.on_window_title_changed)
        self.windowTitleChanged.connect(lambda x: self.on_window_title_changed_no_params())
        self.windowTitleChanged.connect(lambda x: self.my_custom_functn())
        self.windowTitleChanged.connect(lambda x: self.my_custom_functn(x, 25))
        self.setWindowTitle("My App")
    
    def on_window_title_changed(self, s):
        print(s)
    
    def on_window_title_changed_no_params(self):
        print("Window title changed !")
    
    def my_custom_functn(self, a = "Hello", b = 5):
        print(a, b)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()