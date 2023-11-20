# Отчет по лабораторной работе №2

## Основы Qt

## Реализация/ход работы

# При запуске программы видим следующее.

# Создания окна

```Python
def initUI(self):
    self.text_edit = QTextEdit()
    self.setCentralWidget(self.text_edit)

    self.create_menu()

    self.setGeometry(300, 200, 925, 500)
    self.setWindowTitle('Текстовый редактор')
```

# Меню со следующими полями('Файл', 'Правка', 'Вид', 'Справка')

```Python
def create_menu(self):
    menubar = self.menuBar()

    file_menu = menubar.addMenu('Файл')
    save_action = QAction('Сохранить', self)
    save_action.triggered.connect(self.save_file)
    file_menu.addAction(save_action)

    exit_action = QAction('Выход', self)
    exit_action.triggered.connect(self.close)
    file_menu.addAction(exit_action)

    edit_menu = menubar.addMenu('Правка')
    font_action = QAction('Изменить шрифт', self)
    font_action.triggered.connect(self.confirm_font_change)
    edit_menu.addAction(font_action)

    view_menu = menubar.addMenu('Вид')
    view_menu.addAction(font_action)

    reference_menu = menubar.addMenu('Справка')
    reference_menu.addAction(font_action)
```

# Функция для сохранения файла

```Python
def save_file(self):
    file_path, _ = QFileDialog.getSaveFileName(self, 'Сохранить файл', '', 'Text files (*.txt)')
    if file_path:
        text = self.text_edit.toPlainText()
        with open(file_path, 'w') as file:
            file.write(text)
```

# Применения выбранного шрифта

```Python
def confirm_font_change(self):
    font, ok = QFontDialog.getFont()
    if ok:
        confirmation = QMessageBox.question(self, 'Подтверждение', 'Применить выбранный шрифт?', QMessageBox.Yes | QMessageBox.No)
        if confirmation == QMessageBox.Yes:
            self.apply_font(font)

def apply_font(self, font):
    self.text_edit.setFont(font)
```
