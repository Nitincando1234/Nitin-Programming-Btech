import sys, os
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6.QtWebEngineWidgets import *

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()

        navtb = QToolBar("Navigation")
        navtb.setIconSize(QSize(16, 16))
        self.addToolBar(navtb)

        backbutton = QAction(QIcon(os.path.join("icons", "arrow.png")))
        backbutton.setStatusTip("Press to go back")
        backbutton.triggered.connect(self.browser.back)
        navtb.addAction(backbutton)

        nextbutton = QAction(QIcon(os.path.join("icons", "next.png")))
        nextbutton.setStatusTip("Press to goto next page")
        nextbutton.triggered.connect(self.browser.forward)
        navtb.addAction(nextbutton)

        reloadbutton = QAction(QIcon(os.path.join("icons", "reload.png")))
        reloadbutton.setStatusTip("Reload Page")
        reloadbutton.triggered.connect(self.browser.reload)
        navtb.addAction(reloadbutton)

        homebutton = QAction(QIcon(os.path.join("icons", "home.png")))
        homebutton.setStatusTip("Go Home")
        homebutton.triggered.connect(self.navigate_home)
        navtb.addAction(homebutton)

        self.httpsicon = QLabel()
        self.httpsicon.setPixmap(QPixmap(os.path.join("icons", "lock.png")))
        navtb.addWidget(self.httpsicon)                         
        
        self.urlbar = QLineEdit()
        self.urlbar.returnPressed.connect(self.navigate_home)
        navtb.addWidget(self.urlbar)

        stop_btn = QAction(QIcon("icons", "cross-circle.png")) 
        stop_btn.setStatusTip("Stop loading current page")
        stop_btn.triggered.connect(self.browser.stop)
        navtb.addAction(stop_btn)

        self.browser.urlChanged.connect(self.update_urlbar)
        self.browser.loadFinished.connect(self.update_title)

        self.browser = QWebEngineView()
        self.browser.setUrl(QUrl("https://www.google.com"))
        self.setCentralWidget(self.browser)
        self.show()
    
    def update_urlbar(self, q):
        if q.scheme == "https": self.httpsicon.setPixmap(QPixmap(os.path.join("icons", "lock")))
        else: self.httpsicon.setPixmap(QPixmap(os.path.join("icons", "cross.png")))

        self.urlbar.setText(q.toString())
        self.urlbar.setCursorPosition(0)
    
    def update_title(self):
        title = self.browser.page().title()
        self.setWindowTitle("%s -Nitin's Browser" % title)

    def navigate_to_url(self):
        q = QUrl(self.urlbar.text())
        if q.scheme == "": q.setScheme("https")
        self.browser.setUrl(q)

    def navigate_home(self):
        self.browser.setUrl(QUrl("https://www.google.com"))

app = QApplication(sys.argv)
window = MainWindow()
app.exec()