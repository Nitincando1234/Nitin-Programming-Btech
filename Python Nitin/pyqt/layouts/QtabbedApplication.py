import sys 
from PyQt6.QtWidgets import QApplication, QMainWindow, QTabWidget
from Color import color

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("My Tabbed Application")
        tabs = QTabWidget()
        tabs.setDocumentMode(True)      # for MacOS
        tabs.setTabPosition(QTabWidget.TabPosition.West)
        tabs.setMovable(True)

        for c in ["red", "yellow", "blue", "green"]:
            tabs.addTab(color(c), c)
        
        self.setCentralWidget(tabs)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()