import sys
import random
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QLineEdit, QPushButton, QMessageBox, QVBoxLayout, \
    QHBoxLayout, QRadioButton, QWidget, QTextEdit, QComboBox, QFileDialog
from PyQt5.QtGui import QFont


class FirstExercise(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setGeometry(650, 200, 400, 200)
        self.setWindowTitle('The First Exercise')
        self.first_number_label = QLabel('Введите число', self)
        self.first_number_label.move(20, 20)
        self.first_number_entry = QLineEdit(self)
        self.first_number_entry.move(150, 20)
        self.first_number_entry.resize(220, 30)
        self.second_exercise_button = QPushButton('Подтвердить', self)
        self.second_exercise_button.move(150, 70)
        self.second_exercise_button.clicked.connect(self.check_number)

    def check_number(self):
        number1 = int(self.first_number_entry.text())
        if -999 <= number1 <= -100:
            message = "Отрицательное трехзначное число"
        elif -99 <= number1 <= -10:
            message = "Отрицательное двузначное число"
        elif -9 <= number1 < 0:
            message = "Отрицательное однозначное число"
        elif number1 == 0:
            message = "Нулевое число"
        elif 0 < number1 <= 9:
            message = "Положительное однозначное число"
        elif 10 <= number1 <= 99:
            message = "Положительное двузначное число"
        elif 100 <= number1 <= 999:
            message = "Положительное трехзначное число"
        else:
            message = "Число не входит в диапазон от -999 до 999"
        QMessageBox.information(self, "Характеристика числа", message)

class SecondExercise(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setGeometry(650, 200, 300, 200)
        self.setWindowTitle('The Second Exercise')
        self.second_exercise_label = QLabel('Введите элементы массива', self)
        self.second_exercise_label.setFont(QFont('times new roman', 16))
        self.second_exercise_label.move(20, 20)
        self.second_exercise_entry = QLineEdit(self)
        self.second_exercise_entry.setFont(QFont('roman', 16, QFont.Bold))
        self.second_exercise_entry.resize(240, 30)
        self.second_exercise_entry.move(20, 50)
        self.second_exercise_button = QPushButton('Вывод', self)
        self.second_exercise_button.move(20, 90)
        self.second_exercise_button.clicked.connect(self.reverse_array)
        self.output_entry = QLineEdit(self)
        self.output_entry.setFont(QFont('roman', 16, QFont.Bold))
        self.output_entry.resize(200, 30)
        self.output_entry.move(20, 130)

    def reverse_array(self):
        elements = self.second_exercise_entry.text().split()
        if elements:
            reversed_elements = elements[::-1]
            result = ' '.join(reversed_elements)
            self.output_entry.clear()
            self.output_entry.insert(result)
        else:
            QMessageBox.warning(self, "Пустой массив", "Введите элементы массива")

class ThirdExercise(QWidget):
    def __init__(self):
        super().__init__()
        self.my_list = []
        self.setGeometry(650, 200, 400, 200)
        self.setWindowTitle('The Third Exercise')
        self.init_ui()

    def init_ui(self):
        self.third_exercise_label = QLabel('Элементы массива', self)
        self.third_exercise_entry = QLineEdit(self)
        self.third_exercise_label2 = QLabel('Добавить новый элемент', self)
        self.third_exercise_entry2 = QLineEdit(self)

        self.radio_button1 = QRadioButton("Add", self)
        self.radio_button2 = QRadioButton("Remove", self)
        self.radio_button1.setChecked(True)

        self.third_exercise_button = QPushButton('Подтвердить', self)
        self.third_exercise_button.clicked.connect(self.add_or_remove)


        vbox = QVBoxLayout()
        hbox1 = QHBoxLayout()
        hbox2 = QHBoxLayout()
        hbox3 = QHBoxLayout()
        hbox4 = QHBoxLayout()

        hbox1.addWidget(self.third_exercise_label)
        hbox1.addWidget(self.third_exercise_entry)
        hbox2.addWidget(self.third_exercise_label2)
        hbox2.addWidget(self.third_exercise_entry2)
        hbox3.addWidget(self.radio_button1)
        hbox3.addWidget(self.radio_button2)

        vbox.addLayout(hbox1)
        vbox.addLayout(hbox2)
        vbox.addLayout(hbox3)
        vbox.addWidget(self.third_exercise_button)
        vbox.addLayout(hbox4)

        self.setLayout(vbox)
        self.fill_list()

    def fill_list(self):
        self.my_list = [random.randint(1, 100) for _ in range(10)]
        self.update_output()

    def add_or_remove(self):
        action = "1" if self.radio_button1.isChecked() else "2"

        if action == "1":
            new_element = self.third_exercise_entry2.text()
            self.my_list.append(new_element)
        elif action == "2":
            if len(self.my_list) > 0:
                self.my_list.pop()

        self.update_output()

    def update_output(self):
        self.third_exercise_entry.setText(str(self.my_list))

class FourthExercise(QWidget):
    def __init__(self):
        super().__init__()
        self.stack = []
        self.init_ui()

    def init_ui(self):
        self.setGeometry(650, 200, 300, 300)
        self.setWindowTitle('The Fourth Exercise')

        self.stack_exercise_button = QPushButton('Заполнить стек', self)
        self.stack_exercise_button.clicked.connect(self.fill_stack)

        self.stack_output = QTextEdit(self)
        self.stack_output.setReadOnly(True)

        self.forth_output_entry = QTextEdit(self)
        self.forth_output_entry.setReadOnly(True)

        layout = QVBoxLayout()
        layout.addWidget(self.stack_exercise_button)
        layout.addWidget(self.stack_output)
        layout.addWidget(self.forth_output_entry)

        self.setLayout(layout)

    def fill_stack(self):
        self.stack.clear()
        self.stack_output.clear()
        for _ in range(10):
            num = random.randint(-10, 20)
            self.stack.append(num)

        # Отображение элементов стека в QTextEdit
        self.stack_output.setPlainText(' '.join(map(str, self.stack)))

        # Рассчет и отображение суммы положительных чисел в стеке
        positive_sum = sum(x for x in self.stack if x > 0)
        self.forth_output_entry.setPlainText(f'Сумма положительных чисел в стеке: {positive_sum}')

class FifthExercise(QWidget):
    def __init__(self):
        super().__init__()
        self.init_ui()

    def init_ui(self):
        self.setGeometry(650, 200, 230, 400)
        self.setWindowTitle('The Fifth Exercise')

        self.options = ['Person1', 'Person2', 'Person3', 'Person4']
        self.combo = QComboBox(self)
        self.combo.addItems(self.options)
        self.combo.setGeometry(10, 10, 200, 30)

        self.get_value_button = QPushButton('Получить значение', self)
        self.get_value_button.setGeometry(10, 50, 200, 30)
        self.get_value_button.clicked.connect(self.check_person_visited_all)

        self.fifth_exercise_label2 = QLabel('Человек, который побывал \n в гостях у всех', self)
        self.fifth_exercise_label2.setFont(QFont("Arial", 10))
        self.fifth_exercise_label2.setGeometry(10, 90, 200, 50)

        self.fifth_text_entry2 = QTextEdit(self)
        self.fifth_text_entry2.setFont(QFont('roman', 16))
        self.fifth_text_entry2.setGeometry(10, 150, 200, 200)

    def check_person_visited_all(self):
        classmates = {
            'Person1': ['Person2', 'Person3', 'Person4'],
            'Person2': ['Person1', 'Person4'],
            'Person3': ['Person1', 'Person2', 'Person4'],
            'Person4': ['Person1', 'Person2', 'Person3']
        }

        selected_person = self.combo.currentText()

        if selected_person in classmates:
            visited_set = set(classmates[selected_person])
            for friend in classmates[selected_person]:
                if selected_person in classmates[friend]:
                    visited_set.discard(friend)
            if not visited_set:
                result = f"{selected_person} visited everyone."
            else:
                result = f"{selected_person}  didn’t visit everyone."
        else:
            result = "Select a student from the list."

        self.fifth_text_entry2.clear()
        self.fifth_text_entry2.insertPlainText(result)

class SixthExercise(QWidget):
    def __init__(self):
        super().__init__()
        self.init_ui()

    def init_ui(self):
        self.setGeometry(650, 200, 500, 280)
        self.setWindowTitle('The Forth Exercise')

        self.get_file_button = QPushButton('Выбрать файл', self)
        self.get_file_button.clicked.connect(self.get_file)
        self.max_number_label = QLabel('наибольший компонент', self)
        self.max_number_entry = QLineEdit(self)
        self.min_number_label = QLabel('наименьший компонент\nс четным номером', self)
        self.min_number_entry = QLineEdit(self)
        self.mod_number_label = QLabel('наибольший модуль компонента\nс нечётным номером', self)
        self.mod_number_entry = QLineEdit(self)
        self.raznost_number_label = QLabel('разность первого и\nпоследнего компонента файла', self)
        self.raznost_number_entry = QLineEdit(self)

        layout = QVBoxLayout()
        layout.addWidget(self.get_file_button)
        layout.addWidget(self.max_number_label)
        layout.addWidget(self.max_number_entry)
        layout.addWidget(self.min_number_label)
        layout.addWidget(self.min_number_entry)
        layout.addWidget(self.mod_number_label)
        layout.addWidget(self.mod_number_entry)
        layout.addWidget(self.raznost_number_label)
        layout.addWidget(self.raznost_number_entry)
        self.setLayout(layout)

    def get_file(self):
        file_path, _ = QFileDialog.getOpenFileName(self, 'Выбрать файл')
        if file_path:
            with open(file_path, 'r') as file:
                components = [float(line.strip()) for line in file.readlines()]

            if components:
                max_number = max(components)
                self.max_number_entry.setText(str(max_number))

                min_even_number = min([num for idx, num in enumerate(components) if idx % 2 == 1])
                self.min_number_entry.setText(str(min_even_number))

                max_abs_odd_number = max([abs(num) for idx, num in enumerate(components) if idx % 2 == 0])
                self.mod_number_entry.setText(str(max_abs_odd_number))

                difference = components[0] - components[-1]
                self.raznost_number_entry.setText(str(difference))

class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setGeometry(650, 200, 300, 200)
        self.setWindowTitle('Задание')
        self.numberLabel = QLabel('Введите номер задания', self)
        self.numberLabel.move(30, 20)
        self.numberEntry = QLineEdit(self)
        self.numberEntry.move(30, 70)
        self.numberEntry.resize(240, 30)
        self.number_button = QPushButton('Подтвердить', self)
        self.number_button.move(80, 120)
        self.number_button.clicked.connect(self.validate_and_execute)
        self.first_exercise = None
        self.second_exercise = None
        self.third_exercise = None
        self.fourth_exercise = None
        self.fifth_exercise = None
        self.sixth_exercise = None

    def validate_and_execute(self):
        user_input = self.numberEntry.text()
        if user_input == '1':
            if not self.first_exercise:
                self.first_exercise = FirstExercise()
            self.first_exercise.show()
        elif user_input == '2':
            if not self.second_exercise:
                self.second_exercise = SecondExercise()
            self.second_exercise.show()
        elif user_input == '3':
            if not self.third_exercise:
                self.third_exercise = ThirdExercise()
            self.third_exercise.show()
        elif user_input == '4':
            if not self.fourth_exercise:
                self.fourth_exercise = FourthExercise()
            self.fourth_exercise.show()
        elif user_input == '5':
            if not self.fifth_exercise:
                self.fifth_exercise = FifthExercise()
            self.fifth_exercise.show()
        elif user_input == '6':
            if not self.sixth_exercise:
                self.sixth_exercise = SixthExercise()
            self.sixth_exercise.show()

        else:
            print("Invalid input. Please enter '1' or '2'.")
            

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MyWindow()
    window.show()
    sys.exit(app.exec_())
