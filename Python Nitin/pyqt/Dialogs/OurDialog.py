import sys
from PyQt6.QtWidgets import (
    QApplication, QDialog, QDialogButtonBox, QVBoxLayout, QLabel
)
from PyQt6.QtCore import Qt

class CustomDialog(QDialog):
    def __init__(self, parent = None):
        super().__init__()
        self.setWindowTitle("Hello")
        self.setWindowModality(Qt.WindowModality.ApplicationModal)

        QBtn = (QDialogButtonBox.StandardButton.Ok | QDialogButtonBox.StandardButton.Cancel)
        self.buttonBox = QDialogButtonBox(QBtn)
        self.buttonBox.accepted.connect(self.accept)
        self.buttonBox.rejected.connect(self.reject)

        layout = QVBoxLayout()
        message = QLabel("Something Happened, is that OK ?")
        layout.addWidget(message)
        layout.addWidget(self.buttonBox)
        self.setLayout(layout)