#include "texteditor.h"
#include "ui_texteditor.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QSettings>
#include <QVariant>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
TextEditor::TextEditor(const QString &fileName, QWidget *parent) //1
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

     connect(ui->actionClose, &QAction::triggered, this, &TextEditor::close);

     connect(ui->actionExit, &QAction::triggered, qApp, &QApplication::closeAllWindows);

     connect(ui->textEdit, &QTextEdit::textChanged, this, &TextEditor::documentModified);

     connect(ui->actionAbout_Qt, &QAction::triggered, qApp, &QApplication::aboutQt);


     connect(ui->actionCut, &QAction::triggered, ui->textEdit, &QTextEdit::cut);


     connect(ui->actionCopy, &QAction::triggered, ui->textEdit, &QTextEdit::copy);


     connect(ui->actionPaste, &QAction::triggered, ui->textEdit, &QTextEdit::paste);


     connect(ui->actionUndo, &QAction::triggered, ui->textEdit, &QTextEdit::undo);


     connect(ui->actionRedo, &QAction::triggered, ui->textEdit, &QTextEdit::redo);


     connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCopy, &QAction::setEnabled);


     connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCut, &QAction::setEnabled);


     connect(ui->textEdit, &QTextEdit::undoAvailable, ui->actionUndo, &QAction::setEnabled);


     connect(ui->textEdit, &QTextEdit::redoAvailable, ui->actionRedo, &QAction::setEnabled);

     connect(ui->actionSave, &QAction::triggered, this, &TextEditor::saveFile);

     connect(ui->actionSave_As, &QAction::triggered, this, &TextEditor::saveFileAs);


     QSettings settings("MyCom", "MyApp");

     // Получите сохрaненный шрифт из настроек
     QVariant fontVariant = settings.value("viewFont");

     // Проверьте, является ли знaчение корректным QFont
     if (fontVariant.isValid() && fontVariant.canConvert<QFont>()) {
         QFont savedFont = fontVariant.value<QFont>();
         ui->textEdit->setFont(savedFont);
     } else {
         // Используйте шрифт по умолчанию, если сохраненное значение недоступно
         ui->textEdit->setFont(QApplication::font());
     }

     // Устанавливаем имя файла
     m_fileName = fileName;

     // Загружаем файл
     loadFile(m_fileName);

}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionNew_triggered()
{
    TextEditor *newEditor = new TextEditor(QString());

    newEditor->show();
}
void TextEditor::documentModified()
{
    setWindowModified(true);
}
void TextEditor::closeEvent(QCloseEvent *e)
{
    if (isWindowModified()) {
         int choice = QMessageBox::warning(this, "Документ изменен",
            "Документ был изменен. Хотите сохранить изменения?\n"
                                                                                       "Вы потеряете несохраненные изменения.",
                                           QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

         switch (choice) {
         case QMessageBox::Save:
             // Сохранить и закрыть
             if (saveFile()) {
                 e->accept(); // Принять событие (закрыть окно)
             } else {
                 e->ignore(); // Игнорировать событие (не закрывать окно)
             }
             break;
         case QMessageBox::Discard:
             // Не сохранять и закрыть
             e->accept(); // Принять событие (закрыть окно)
             break;
         case QMessageBox::Cancel:
             // Отменить закрытие
             e->ignore(); // Игнорировать событие (не закрывать окно)
             break;
         }
    } else {
         // Если изменений нет, просто закрыть окно
         e->accept(); // Принять событие (закрыть окно)
    }

}

void TextEditor::on_actionSelectFont_triggered()
{
    bool ok;
    QFont currentFont = ui->textEdit->font();
    QFont font = QFontDialog::getFont(&ok, currentFont, this, tr("Выберите шрифт"));

    if (ok) {
        // Обновляем шрифт текста в QTextEdit
        ui->textEdit->setFont(font);

        // Используем QSettings для сохранения текущего шрифта
        QSettings settings("YourCompany", "YourApp"); // Замените на свои значения
        settings.setValue("viewFont", font);
    }
}


void TextEditor::on_actionAbout_2_triggered()
{
  // QMessageBox::about;

}

void TextEditor::loadFile(const QString &fileName)
{
    if (fileName.isEmpty()) {
        setFileName(QString());
        return;
    }

    QFile file(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл: " + fileName);
        setFileName(QString());
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());
    file.close();
    setFileName(fileName);
    setWindowModified(false);
}

void TextEditor::setFileName(const QString &fileName)
{
    m_fileName = fileName;
    QString windowTitle = QString("%1[*] - %2")
                              .arg(m_fileName.isNull() ? "untitled" : QFileInfo(m_fileName).fileName())
                              .arg(QApplication::applicationName());
    setWindowTitle(windowTitle);
}

void TextEditor::on_actionOpen_triggered()
{
    // Получаем имя открываемого файла
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Открыть документ", QDir::currentPath(), "Текстовые документы (*.txt)");

    // Если имя файла не было выбрано пользователем, выходим из функции
    if (fileName.isNull())
        return;

    // Если в текущем окне уже есть открытый файл и текущий документ не изменен
    if (m_fileName.isNull() && !ui->textEdit->document()->isModified()) {
        // Загружаем выбранный файл в текущее окно
        loadFile(fileName);
    } else {
        // Иначе, создаем новое окно и загружаем в него выбранный файл
        TextEditor *newEditor = new TextEditor(fileName);
        newEditor->show();
    }
}
bool TextEditor::saveFileAs()
{
    // Получаем имя файла от пользователя
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить документ",
        m_fileName.isNull() ? QDir::currentPath() : m_fileName, "Текстовые документы (*.txt)");

    // Если имя файла не получено (пользователь отменил операцию), возвращаем false
    if (fileName.isNull())
        return false;

    // Устанавливаем новое имя файла
    setFileName(fileName);

    // Вызываем функцию сохранения файла и возвращаем результат
    return saveFile();
}

bool TextEditor::saveFile()
{
    // Если имя файла не установлено, вызываем saveFileAs
    if (m_fileName.isNull())
        return saveFileAs();

    // Создаем объект QFile для текущего имени файла
    QFile file(m_fileName);

    // Пытаемся открыть файл для записи текстового файла
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл: " + m_fileName);
        setFileName(QString());
        return false;
    }

    // Создаем объект QTextStream для файла
    QTextStream out(&file);

    // Записываем текст из редактора в файл
    out << ui->textEdit->toPlainText();

    // Закрываем файл
    file.close();

    // Устанавливаем windowModified в false и возвращаем true (успешное сохранение)
    setWindowModified(false);
    return true;
}




