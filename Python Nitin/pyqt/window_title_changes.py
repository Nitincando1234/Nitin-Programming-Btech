from PyQt6.QtWidgets import QMainWindow, QApplication, QPushButton
import sys, random

window_titles = [
    'My App',
    'My App',
    'Still My App',
    'Still My App',
    'What on earth',
    'What on earth',
    'This is surprising',
    'This is surprising',
    'Something went wrong'
]
class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()
        self.n_time_clicked = 0
        self.setWindowTitle("New App For Random Button Clicks")

        self.button = QPushButton("Press Me!")
        self.button.clicked.connect(self.the_button_was_clicked)
        self.windowTitleChanged.connect(self.the_window_title_changed)
        self.setCentralWidget(self.button)
    def the_button_was_clicked(self):
        print("Clicked !")
        new_title = random.choice(window_titles)
        print("Setting Window Title changed to %s..." % new_title)
        self.setWindowTitle(new_title)
    def the_window_title_changed(self, window_title):
        print("Window Title Changed: %s" % window_title)
        if window_title == "Something went wrong": self.button.setDisabled(True)

app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()