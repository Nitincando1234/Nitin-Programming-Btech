import sys
import time
from PyQt6.QtCore import QTimer, QRunnable, QThreadPool, pyqtSlot
from PyQt6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)

class Worker(QRunnable):
    
    @pyqtSlot()
    def run(self):
        print("Thread Starts")
        time.sleep(5)
        print("Thread Complete")

class MainWindow(QMainWindow):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.counter = 0

        layout = QVBoxLayout()

        self.label = QLabel("Start")
        button = QPushButton("Danger !")
        button.pressed.connect(self.oh_no)
        c = QPushButton("?")
        c.pressed.connect(self.change_message)

        layout.addWidget(self.label)
        layout.addWidget(button)
        layout.addWidget(c)

        w = QWidget()
        w.setLayout(layout)
        self.setCentralWidget(w)
        self.show()

        self.timer = QTimer()
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.recurring_timer)
        self.timer.start()

        self.threadpool = QThreadPool()
        thread_count = self.threadpool.maxThreadCount()
        print(f"Multithreading with maximum {thread_count} threads.")

    def change_message(self):
        self.message = "Oh No check !"

    def oh_no(self):
        worker = Worker()
        self.threadpool.start(worker)
    
    def recurring_timer(self):
        self.counter += 1
        self.label.setText(f"Counter: {self.counter}")

app = QApplication(sys.argv)
window = MainWindow()
app.exec()