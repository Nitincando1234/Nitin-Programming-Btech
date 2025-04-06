import sys, os
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6.QtWebEngineWidgets import *
from PyQt6.QtPrintSupport import QPrintPreviewDialog

class AboutDialog(QDialog):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        QBtn = QDialogButtonBox.StandardButton.Ok
        self.buttonbox = QDialogButtonBox(QBtn)
        self.buttonbox.accepted.connect(self.accept)
        self.buttonbox.rejected.connect(self.reject)

        layout = QVBoxLayout()

        title = QLabel("Browser Created by Nitin")
        font = title.font()
        font.setPointSize(28)
        title.setFont(font)

        layout.addWidget(title)

        logo = QLabel()
        logo.setPixmap(QPixmap(os.path.join("icons", "ma-icon-128.png")))
        
        layout.addWidget(logo)

        layout.addWidget(QLabel("Version 1.1.1.1.1.1.11.1.1..1.1..11...1.1.11..1.1.1:)"))
        layout.addWidget(QLabel("CopyRight Free"))

        for i in range(0, layout.count()): layout.itemAt(i).setAlignment(Qt.AlignmentFlag.AlignHCenter)
        
        layout.addWidget(self.buttonbox)

        self.setLayout(layout)


class MainWindow(QMainWindow):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.setMinimumSize(800, 600)

        self.tabs = QTabWidget()
        self.tabs.setDocumentMode(True)
        self.tabs.tabBarDoubleClicked.connect(self.tab_open_doubleclick)
        self.tabs.currentChanged.connect(self.current_tab_changed)
        self.tabs.setTabsClosable(True)
        self.tabs.tabCloseRequested.connect(self.close_current_tab)

        navtb = QToolBar("Navigation")
        navtb.setIconSize(QSize(16, 16))
        self.addToolBar(navtb)

        backbutton = QAction(QIcon(os.path.join("icons", "arrow.png")), "Back", self)
        backbutton.setStatusTip("Press to go back")
        backbutton.triggered.connect(lambda: self.tabs.currentWidget().back())
        navtb.addAction(backbutton)

        nextbutton = QAction(QIcon(os.path.join("icons", "next.png")), "Forward", self)
        nextbutton.setStatusTip("Press to goto next page")
        nextbutton.triggered.connect(lambda: self.tabs.currentWidget().forward())
        navtb.addAction(nextbutton)

        reloadbutton = QAction(QIcon(os.path.join("icons", "reload.png")), "Reload", self)
        reloadbutton.setStatusTip("Reload Page")
        reloadbutton.triggered.connect(lambda: self.tabs.currentWidget().reload())
        navtb.addAction(reloadbutton)

        homebutton = QAction(QIcon(os.path.join("icons", "home.png")), "Home", self)
        homebutton.setStatusTip("Go Home")
        homebutton.triggered.connect(self.navigate_home)
        navtb.addAction(homebutton)
        navtb.addSeparator()

        self.httpsicon = QLabel()
        self.httpsicon.setPixmap(QPixmap(os.path.join("icons", "lock.png")))
        navtb.addWidget(self.httpsicon)                         
        
        self.urlbar = QLineEdit()
        self.urlbar.returnPressed.connect(self.navigate_to_url)
        navtb.addWidget(self.urlbar)

        stop_btn = QAction(QIcon(os.path.join("icons", "cross-circle.png")), 
                           "Stop", 
                           self) 
        stop_btn.setStatusTip("Stop loading current page")
        stop_btn.triggered.connect(lambda: self.tabs.currentWidget().stop())
        navtb.addAction(stop_btn)

        file_menu = self.menuBar().addMenu("&File")

        new_tab_action = QAction(QIcon(os.path.join("icons", "tab_plus.png")), "New Tab", self)
        new_tab_action.triggered.connect(lambda _: self.add_new_tab())
        file_menu.addAction(new_tab_action)

        open_file_action = QAction(QIcon(os.path.join("icons", "./images/disk.png")), 
                                   "Open file...", 
                                   self)
        open_file_action.setStatusTip("Open from file")
        open_file_action.triggered.connect(self.open_file)
        file_menu.addAction(open_file_action)

        save_file_action = QAction(QIcon(os.path.join("icons", "./images/disk_pencil.png")), 
                                   "Save Page As...", 
                                   self)
        save_file_action.setStatusTip("Save Current page to file")
        save_file_action.triggered.connect(self.save_file)
        file_menu.addAction(save_file_action)

        help_menu = self.menuBar().addMenu("&Help")

        about_action = QAction(QIcon(os.path.join("icons", "question.png")), "About the Browser Created by Nitin", self)
        about_action.setStatusTip("Find out more about the Browser created by Nitin")
        about_action.triggered.connect(self.about)
        help_menu.addAction(about_action)

        navigate_browser_action = QAction(QIcon(os.path.join("icons", "lifebuoy.png")), "Nitin's Browser Guide", self)
        navigate_browser_action.setStatusTip("Go to Nitin's Browser Guide")
        navigate_browser_action.triggered.connect(self.navigate_nitins_browser)
        help_menu.addAction(navigate_browser_action)

        self.setWindowTitle("Nitin' s Browser")
        self.setWindowIcon(QIcon(os.path.join("icons", "ma-icon-128.png")))
        self.setCentralWidget(self.tabs)
        self.add_new_tab(QUrl("https://www.google.com"))

        self.show()
    
    def update_urlbar(self, q, browser = None):
        if browser != self.tabs.currentWidget(): return
        if q.scheme == "https": self.httpsicon.setPixmap(QPixmap(os.path.join("icons", "lock")))
        else: self.httpsicon.setPixmap(QPixmap(os.path.join("icons", "cross.png")))

        self.urlbar.setText(q.toString())
        self.urlbar.setCursorPosition(0)
    
    def update_title(self, browser):
        if browser != self.tabs.currentWidget(): return 
        title = browser.page().title()
        self.setWindowTitle("%s -Nitin's Browser" % title)

    def navigate_to_url(self):
        q = QUrl(self.urlbar.text())
        if q.scheme == "": q.setScheme("https")
        self.tabs.currentWidget().setUrl(q)

    def navigate_home(self):
        self.tabs.currentWidget().setUrl(QUrl("https://www.google.com"))
    
    def open_file(self):
        filename, _ = QFileDialog.getOpenFileName(self, "Open File", "", "Hypertext Markup Language (*.htm *.html);;"
                                                  "All files (*.*)")
        if filename:
            with open(filename, "r") as f: html = f.read()
        else: html = "File Wasn 't Loaded !"
        self.tabs.currentWidget().setHtml(html)
        self.urlbar.setText(filename)
    
    def save_file(self):
        dlg = QPrintPreviewDialog()
        dlg.paintRequested.connect(lambda p: self.tabs.currentWidget().print(p))
        dlg.exec()
    
    def navigate_nitins_browser(self): 
        html = "Can't Load!"
        with open("help.html", "r") as f: html = f.read()
        self.tabs.currentWidget().setHtml(html)
    def about(self):
        dlg = AboutDialog()
        dlg.exec()
    
    def tab_open_doubleclick(self, i):
        if i == -1: self.add_new_tab()
    
    def add_new_tab(self, qurl = None, label = "Blank"):
        if qurl is None: qurl = QUrl("https://www.google.com/")

        browser = QWebEngineView()
        browser.setUrl(qurl)
        i = self.tabs.addTab(browser, label)

        self.tabs.setCurrentIndex(i)

        browser.urlChanged.connect(lambda qurl, browser = browser: self.update_urlbar(qurl, browser))
        browser.titleChanged.connect(lambda _, i = i, browser = browser: self.tabs.setTabText(
            i, browser.page().title()
        ))
        browser.loadFinished.connect(lambda _, i = i, browser = browser: self.tabs.setTabText(i, browser.page().title()))
    
    def current_tab_changed(self, i):
        if self.tabs.count() > 0:
            qurl = self.tabs.currentWidget().url()
            self.update_urlbar(qurl, self.tabs.currentWidget())
            self.update_title(self.tabs.currentWidget())

    def close_current_tab(self, i):
        if self.tabs.count() > 1: self.tabs.removeTab(i)
        else: 
            dlg = QMessageBox(self)
            dlg.setText("Can't Close a Single Tab !")
            dlg.setWindowTitle("Tab Close Error")
            button = dlg.exec()
            if button == QMessageBox.StandardButton.Ok: dlg.close()

app = QApplication(sys.argv)
window = MainWindow()
app.exec()