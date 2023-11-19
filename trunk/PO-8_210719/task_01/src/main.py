from PyQt5.QtWidgets import QApplication, QWidget, QHBoxLayout, QVBoxLayout, QLabel, QSlider, QPushButton
from PyQt5.QtCore import Qt

def show_color():
    red = red_slider.value()
    green = green_slider.value()
    blue = blue_slider.value()
    color = "#%02x%02x%02x" % (red, green, blue)
    color_label.setStyleSheet(f"background-color: {color};")

app = QApplication([])
window = QWidget()
window.setWindowTitle("Color Viewer")

main_layout = QHBoxLayout(window)

controls_layout = QVBoxLayout()

red_label = QLabel("Красный:")
controls_layout.addWidget(red_label)
red_slider = QSlider(Qt.Horizontal)
red_slider.setRange(0, 255)
controls_layout.addWidget(red_slider)

green_label = QLabel("Зеленый:")
controls_layout.addWidget(green_label)
green_slider = QSlider(Qt.Horizontal)
green_slider.setRange(0, 255)
controls_layout.addWidget(green_slider)

blue_label = QLabel("Синий:")
controls_layout.addWidget(blue_label)
blue_slider = QSlider(Qt.Horizontal)
blue_slider.setRange(0, 255)
controls_layout.addWidget(blue_slider)

show_button = QPushButton("Показать цвет")
show_button.clicked.connect(show_color)
controls_layout.addWidget(show_button)

main_layout.addLayout(controls_layout)

color_label = QLabel()
color_label.setFixedSize(200, 200)
main_layout.addWidget(color_label)

window.show()
app.exec()