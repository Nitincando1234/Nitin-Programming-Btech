import sys
import time
import traceback

from PyQt6.QtCore import (
    QObject,
    QRunnable,
    QThreadPool,
    QTimer,
    pyqtSignal,
    pyqtSlot,
)
from PyQt6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)

class WorkerSignal(QObject):

    finished = pyqtSignal()
    error = pyqtSignal(tuple)
    result = pyqtSignal(object)
    progress = pyqtSignal(float)

class Worker(QRunnable):

    def __init__(self, fn, *args, **kwargs):
        super().__init__()
        self.fn = fn
        self.args, self.kwargs = args, kwargs
        self.signals = WorkerSignal()
        self.kwargs["progress_callback"] = self.signals.progress
    
    @pyqtSlot()
    def run(self):
        try: result = self.fn(*self.args, **self.kwargs)
        except Exception:
            traceback.print_exc()
            exctype, value = sys.exc_info()[: 2]
            self.signals.error.emit((exctype, value, traceback.format_exc()))
        else: self.signals.result.emit(result)
        finally: self.signals.finished.emit()

class MainWindow(QMainWindow):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.counter = 0
        layout = QVBoxLayout()
        self.label = QLabel("Start")
        button = QPushButton("Danger !")
        button.pressed.connect(self.oh_no)

        layout.addWidget(self.label)
        layout.addWidget(button)

        w = QWidget()
        w.setLayout(layout)
        self.setCentralWidget(w)

        self.threadpool = QThreadPool()
        thread_count = self.threadpool.maxThreadCount()
        print(f"Multithreading with maximum {thread_count} threads")

        self.timer = QTimer()
        self.timer.setInterval(1000)
        self.timer.timeout.connect(self.recurring_counter)
        self.timer.start()
    
    def execute_this_fn(self, progress_callback) -> str:
        for n in range(0, 5):
            time.sleep(1)
            progress_callback.emit(n * 100 / 4)
        return "done."

    def progress_fn(self, n): print(f"{n: .1f}% done")

    def print_output(self, s): print(s)

    def thread_complete(self): print("THREAD COMPLETE !")

    def oh_no(self):
        worker = Worker(self.execute_this_fn)
        worker.signals.result.connect(self.print_output)
        worker.signals.finished.connect(self.thread_complete)
        worker.signals.progress.connect(self.progress_fn)
        self.threadpool.start(worker)
    
    def recurring_counter(self):
        self.counter += 1
        self.label.setText(f"Counter: {self.counter}")


    
app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()

