import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QTableWidget, QTableWidgetItem, QVBoxLayout, QHBoxLayout, QPushButton
from PyQt5.QtCore import Qt
import math

class TrigonometryCalculator(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle('Trigonometry Calculator')
        self.setGeometry(100, 100, 400, 300)

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        self.layout = QVBoxLayout()
        self.central_widget.setLayout(self.layout)

        self.table = QTableWidget()
        self.table.setColumnCount(3)
        self.table.setHorizontalHeaderLabels(['Угол в градусах', 'Угол в радианах', 'Результат'])
        self.table.setRowCount(19)  # Для углов от 0 до 90 градусов с шагом 5
        self.populate_table()
        self.layout.addWidget(self.table)

        self.buttons_layout = QHBoxLayout()
        self.sin_button = QPushButton('sin')
        self.cos_button = QPushButton('cos')
        self.tan_button = QPushButton('tg')

        self.buttons_layout.addWidget(self.sin_button)
        self.buttons_layout.addWidget(self.cos_button)
        self.buttons_layout.addWidget(self.tan_button)

        self.layout.addLayout(self.buttons_layout)

        self.sin_button.clicked.connect(self.calculate_sin)
        self.cos_button.clicked.connect(self.calculate_cos)
        self.tan_button.clicked.connect(self.calculate_tan)

        self.table.itemEntered.connect(self.show_tooltip)

    def populate_table(self):
        for i in range(19):
            degrees = i * 5
            radians = degrees * (math.pi / 180)  # Перевод в радианы
            self.table.setItem(i, 0, QTableWidgetItem(str(degrees)))
            self.table.setItem(i, 1, QTableWidgetItem(str(round(radians, 4))))

    def calculate_sin(self):
        self.calculate_function('sin')

    def calculate_cos(self):
        self.calculate_function('cos')

    def calculate_tan(self):
        self.calculate_function('tan')

    def calculate_function(self, function):
        for i in range(19):
            radians_item = self.table.item(i, 1)
            if radians_item:
                radians = float(radians_item.text())
                if function == 'sin':
                    result = round(math.sin(radians), 4)
                elif function == 'cos':
                    result = round(math.cos(radians), 4)
                elif function == 'tan':
                    result = round(math.tan(radians), 4)

                result_item = QTableWidgetItem(str(result))
                result_item.setTextAlignment(Qt.AlignRight | Qt.AlignVCenter)
                self.table.setItem(i, 2, result_item)

    def show_tooltip(self, item):
        if item.column() == 2:
            self.table.setToolTip(item.text())


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = TrigonometryCalculator()
    window.show()
    sys.exit(app.exec_())
