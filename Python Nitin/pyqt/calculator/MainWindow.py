# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt6 UI code generator 6.4.2
#
# WARNING: Any manual changes made to this file will be lost when pyuic6 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(484, 433)
        self.centralWidget = QtWidgets.QWidget(parent=MainWindow)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Policy.Maximum, QtWidgets.QSizePolicy.Policy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.centralWidget.sizePolicy().hasHeightForWidth())
        self.centralWidget.setSizePolicy(sizePolicy)
        self.centralWidget.setObjectName("centralWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.centralWidget)
        self.verticalLayout.setContentsMargins(11, 11, 11, 11)
        self.verticalLayout.setSpacing(6)
        self.verticalLayout.setObjectName("verticalLayout")
        self.lcdNumber = QtWidgets.QLCDNumber(parent=self.centralWidget)
        self.lcdNumber.setDigitCount(10)
        self.lcdNumber.setObjectName("lcdNumber")
        self.verticalLayout.addWidget(self.lcdNumber)
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setSpacing(6)
        self.gridLayout.setObjectName("gridLayout")
        self.pushButton_n4 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n4.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n4.setFont(font)
        self.pushButton_n4.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n4.setObjectName("pushButton_n4")
        self.gridLayout.addWidget(self.pushButton_n4, 3, 0, 1, 1)
        self.pushButton_n1 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n1.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n1.setFont(font)
        self.pushButton_n1.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n1.setObjectName("pushButton_n1")
        self.gridLayout.addWidget(self.pushButton_n1, 4, 0, 1, 1)
        self.pushButton_n8 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n8.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n8.setFont(font)
        self.pushButton_n8.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n8.setObjectName("pushButton_n8")
        self.gridLayout.addWidget(self.pushButton_n8, 2, 1, 1, 1)
        self.pushButton_mul = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_mul.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_mul.setFont(font)
        self.pushButton_mul.setObjectName("pushButton_mul")
        self.gridLayout.addWidget(self.pushButton_mul, 2, 3, 1, 1)
        self.pushButton_n7 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n7.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n7.setFont(font)
        self.pushButton_n7.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n7.setObjectName("pushButton_n7")
        self.gridLayout.addWidget(self.pushButton_n7, 2, 0, 1, 1)
        self.pushButton_n6 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n6.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n6.setFont(font)
        self.pushButton_n6.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n6.setObjectName("pushButton_n6")
        self.gridLayout.addWidget(self.pushButton_n6, 3, 2, 1, 1)
        self.pushButton_n5 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n5.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n5.setFont(font)
        self.pushButton_n5.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n5.setObjectName("pushButton_n5")
        self.gridLayout.addWidget(self.pushButton_n5, 3, 1, 1, 1)
        self.pushButton_n0 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n0.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n0.setFont(font)
        self.pushButton_n0.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n0.setObjectName("pushButton_n0")
        self.gridLayout.addWidget(self.pushButton_n0, 5, 0, 1, 1)
        self.pushButton_n2 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n2.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n2.setFont(font)
        self.pushButton_n2.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n2.setObjectName("pushButton_n2")
        self.gridLayout.addWidget(self.pushButton_n2, 4, 1, 1, 1)
        self.pushButton_n9 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n9.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n9.setFont(font)
        self.pushButton_n9.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n9.setObjectName("pushButton_n9")
        self.gridLayout.addWidget(self.pushButton_n9, 2, 2, 1, 1)
        self.pushButton_n3 = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_n3.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_n3.setFont(font)
        self.pushButton_n3.setStyleSheet("QPushButton {\n"
"color: #1976D2;\n"
"}")
        self.pushButton_n3.setObjectName("pushButton_n3")
        self.gridLayout.addWidget(self.pushButton_n3, 4, 2, 1, 1)
        self.pushButton_div = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_div.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_div.setFont(font)
        self.pushButton_div.setObjectName("pushButton_div")
        self.gridLayout.addWidget(self.pushButton_div, 1, 3, 1, 1)
        self.pushButton_sub = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_sub.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_sub.setFont(font)
        self.pushButton_sub.setObjectName("pushButton_sub")
        self.gridLayout.addWidget(self.pushButton_sub, 3, 3, 1, 1)
        self.pushButton_add = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_add.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_add.setFont(font)
        self.pushButton_add.setObjectName("pushButton_add")
        self.gridLayout.addWidget(self.pushButton_add, 4, 3, 1, 1)
        self.pushButton_ac = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_ac.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_ac.setFont(font)
        self.pushButton_ac.setStyleSheet("QPushButton {\n"
"    color: #f44336;\n"
"}")
        self.pushButton_ac.setObjectName("pushButton_ac")
        self.gridLayout.addWidget(self.pushButton_ac, 1, 0, 1, 1)
        self.pushButton_mr = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_mr.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_mr.setFont(font)
        self.pushButton_mr.setStyleSheet("QPushButton {\n"
"   color: #FFC107;\n"
"}")
        self.pushButton_mr.setObjectName("pushButton_mr")
        self.gridLayout.addWidget(self.pushButton_mr, 1, 2, 1, 1)
        self.pushButton_m = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_m.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_m.setFont(font)
        self.pushButton_m.setStyleSheet("QPushButton {\n"
"   color: #FFC107;\n"
"}")
        self.pushButton_m.setObjectName("pushButton_m")
        self.gridLayout.addWidget(self.pushButton_m, 1, 1, 1, 1)
        self.pushButton_pc = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_pc.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_pc.setFont(font)
        self.pushButton_pc.setObjectName("pushButton_pc")
        self.gridLayout.addWidget(self.pushButton_pc, 5, 1, 1, 1)
        self.pushButton_eq = QtWidgets.QPushButton(parent=self.centralWidget)
        self.pushButton_eq.setMinimumSize(QtCore.QSize(0, 50))
        font = QtGui.QFont()
        font.setPointSize(27)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton_eq.setFont(font)
        self.pushButton_eq.setStyleSheet("QPushButton {\n"
"color: #4CAF50;\n"
"}")
        self.pushButton_eq.setObjectName("pushButton_eq")
        self.gridLayout.addWidget(self.pushButton_eq, 5, 2, 1, 2)
        self.verticalLayout.addLayout(self.gridLayout)
        MainWindow.setCentralWidget(self.centralWidget)
        self.menuBar = QtWidgets.QMenuBar(parent=MainWindow)
        self.menuBar.setGeometry(QtCore.QRect(0, 0, 484, 22))
        self.menuBar.setObjectName("menuBar")
        self.menuFile = QtWidgets.QMenu(parent=self.menuBar)
        self.menuFile.setObjectName("menuFile")
        MainWindow.setMenuBar(self.menuBar)
        self.statusBar = QtWidgets.QStatusBar(parent=MainWindow)
        self.statusBar.setObjectName("statusBar")
        MainWindow.setStatusBar(self.statusBar)
        self.actionExit = QtGui.QAction(parent=MainWindow)
        self.actionExit.setObjectName("actionExit")
        self.actionReset = QtGui.QAction(parent=MainWindow)
        self.actionReset.setObjectName("actionReset")
        self.menuFile.addAction(self.actionReset)
        self.menuFile.addAction(self.actionExit)
        self.menuBar.addAction(self.menuFile.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Calculon"))
        self.pushButton_n4.setText(_translate("MainWindow", "4"))
        self.pushButton_n4.setShortcut(_translate("MainWindow", "4"))
        self.pushButton_n1.setText(_translate("MainWindow", "1"))
        self.pushButton_n1.setShortcut(_translate("MainWindow", "1"))
        self.pushButton_n8.setText(_translate("MainWindow", "8"))
        self.pushButton_n8.setShortcut(_translate("MainWindow", "8"))
        self.pushButton_mul.setText(_translate("MainWindow", "x"))
        self.pushButton_mul.setShortcut(_translate("MainWindow", "*"))
        self.pushButton_n7.setText(_translate("MainWindow", "7"))
        self.pushButton_n7.setShortcut(_translate("MainWindow", "7"))
        self.pushButton_n6.setText(_translate("MainWindow", "6"))
        self.pushButton_n6.setShortcut(_translate("MainWindow", "6"))
        self.pushButton_n5.setText(_translate("MainWindow", "5"))
        self.pushButton_n5.setShortcut(_translate("MainWindow", "5"))
        self.pushButton_n0.setText(_translate("MainWindow", "0"))
        self.pushButton_n0.setShortcut(_translate("MainWindow", "0"))
        self.pushButton_n2.setText(_translate("MainWindow", "2"))
        self.pushButton_n2.setShortcut(_translate("MainWindow", "2"))
        self.pushButton_n9.setText(_translate("MainWindow", "9"))
        self.pushButton_n9.setShortcut(_translate("MainWindow", "9"))
        self.pushButton_n3.setText(_translate("MainWindow", "3"))
        self.pushButton_n3.setShortcut(_translate("MainWindow", "3"))
        self.pushButton_div.setText(_translate("MainWindow", "÷"))
        self.pushButton_div.setShortcut(_translate("MainWindow", "/"))
        self.pushButton_sub.setText(_translate("MainWindow", "-"))
        self.pushButton_sub.setShortcut(_translate("MainWindow", "-"))
        self.pushButton_add.setText(_translate("MainWindow", "+"))
        self.pushButton_add.setShortcut(_translate("MainWindow", "+"))
        self.pushButton_ac.setText(_translate("MainWindow", "AC"))
        self.pushButton_ac.setShortcut(_translate("MainWindow", "Esc"))
        self.pushButton_mr.setText(_translate("MainWindow", "MR"))
        self.pushButton_mr.setShortcut(_translate("MainWindow", "R"))
        self.pushButton_m.setText(_translate("MainWindow", "M"))
        self.pushButton_m.setShortcut(_translate("MainWindow", "M"))
        self.pushButton_pc.setText(_translate("MainWindow", "%"))
        self.pushButton_pc.setShortcut(_translate("MainWindow", "%"))
        self.pushButton_eq.setText(_translate("MainWindow", "="))
        self.pushButton_eq.setShortcut(_translate("MainWindow", "Return"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.actionExit.setText(_translate("MainWindow", "Exit"))
        self.actionExit.setShortcut(_translate("MainWindow", "Ctrl+Q"))
        self.actionReset.setText(_translate("MainWindow", "Reset"))
        self.actionReset.setShortcut(_translate("MainWindow", "Ctrl+R"))