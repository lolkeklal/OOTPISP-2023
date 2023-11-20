import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QTextEdit, QAction, QFontDialog, QMessageBox, QFileDialog

class TextEditor(QMainWindow):
    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.text_edit = QTextEdit()
        self.setCentralWidget(self.text_edit)
        self.create_menu()


        self.setGeometry(300, 200, 925, 500)
        self.setWindowTitle('Текстовый редактор')

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

    def save_file(self):
        file_path, _ = QFileDialog.getSaveFileName(self, 'Сохранить файл', '', 'Text files (*.txt)')
        if file_path:
            text = self.text_edit.toPlainText()
            with open(file_path, 'w') as file:
                file.write(text)

    def confirm_font_change(self):
        font, ok = QFontDialog.getFont()
        if ok:
            confirmation = QMessageBox.question(self, 'Подтверждение', 'Применить выбранный шрифт?', QMessageBox.Yes | QMessageBox.No)
            if confirmation == QMessageBox.Yes:
                self.apply_font(font)

    def apply_font(self, font):
        self.text_edit.setFont(font)

def main():
    app = QApplication(sys.argv)
    text_editor = TextEditor()
    text_editor.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
