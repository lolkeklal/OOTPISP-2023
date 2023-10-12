#include "texteditor.h"

TextEditor::TextEditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);

    QSettings settings;
    ui->textEdit->setFont( settings.value("viewFont", QApplication::font()).value<QFont>() );

    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentChanged()));

    connect(ui->actionCut,   SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy,  SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo,  SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo,  SIGNAL(triggered()), ui->textEdit, SLOT(redo()));

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut,  SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));

    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    loadFile(fileName);
}

TextEditor::~TextEditor()
{
    delete ui;
}



QString TextEditor::onCloseModifiedModalTitle = "Измененный документ";
QString TextEditor::onCloseModifiedModalText = "Документ имеет несохраненные изменения.\nЖелаете ли вы сохранить изменения?\nВы потеряете все несохраненные изменения.";
QString TextEditor::onAboutModalTitle = "О программе";
QString TextEditor::onAboutModalText = "Версия 0.1";
QString TextEditor::onFileOpenErrorModalTitle = "Ошибка";
QString TextEditor::onFileOpenErrorModalText = "Не удалось открыть файл, либо файл не найден";
QString TextEditor::newDocumentTitle = "Untitled";
QString TextEditor::fileDialogTextFilesFilter = "Text documents (*.txt)";
QString TextEditor::onFileOpenModalTitle = "Открыть файл";
QString TextEditor::onSaveFileModalTitle = "Сохранить документ";



void TextEditor::loadFile(const QString &fileName)
{
    if (fileName.isNull()) return setFileName();

    QFile file(fileName);
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        QMessageBox::warning(this, TextEditor::onFileOpenErrorModalTitle, TextEditor::onFileOpenErrorModalText);
        return setFileName();
    }

    QTextStream stream(&file);
    ui->textEdit->setText(stream.readAll());

    file.close();
    setFileName(fileName);
    this->setWindowModified(false);
}

void TextEditor::setFileName(const QString &fileName)
{
    this->m_fileName = fileName;
    this->setWindowTitle( QString("%1[*] - %2")
            .arg( m_fileName.isNull()
                    ? TextEditor::newDocumentTitle
                    : QFileInfo(m_fileName).fileName())
            .arg(QApplication::applicationName())
    );
}



void TextEditor::on_actionNew_triggered()
{
    TextEditor* text_editor = new TextEditor();
    text_editor->show();
}

void TextEditor::documentChanged() {
    this->setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *e)
{
    if (!this->isWindowModified()) return e->accept();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this,
                TextEditor::onCloseModifiedModalTitle,
                TextEditor::onCloseModifiedModalText,
                QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                QMessageBox::Cancel
    );

    switch(reply)
    {
    case QMessageBox::Yes:
        if (saveFile()) {
            e->accept();
        }
        else {
            e->ignore();
        }
        break;
    case QMessageBox::No:
        e->accept();
        break;
    case QMessageBox::Cancel:
    default:
        e->ignore();
        break;
    }
}

void TextEditor::on_actionSelectFont_triggered()
{
    QSettings settings;
    QFont initial = ui->textEdit->font();
    bool ok;
    QFont font = QFontDialog::getFont(
        &ok, initial, this);

    if (ok) {
        settings.setValue("viewFont", font);
        ui->textEdit->setFont(font);
    }
}

void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, TextEditor::onAboutModalTitle, TextEditor::onAboutModalText);
}

void TextEditor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        TextEditor::onFileOpenModalTitle,
        QDir::currentPath(),
        TextEditor::fileDialogTextFilesFilter
    );

    if (fileName.isNull()) return;

    if (this->m_fileName.isNull() && !this->isWindowModified()) {
        loadFile(fileName);
    }
    else {
        TextEditor* text_editor = new TextEditor(fileName);
        text_editor->show();
    }
}

bool TextEditor::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        TextEditor::onSaveFileModalTitle,
        m_fileName.isNull()
            ? QDir::currentPath()
            : m_fileName,
        TextEditor::fileDialogTextFilesFilter
    );

    if (fileName.isNull()) return false;

    setFileName(fileName);
    return saveFile();
}

bool TextEditor::saveFile()
{
    if (this->m_fileName.isNull()) return saveFileAs();

    QFile file(this->m_fileName);

    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) ) {
        QMessageBox::warning(this, TextEditor::onFileOpenErrorModalTitle, TextEditor::onFileOpenErrorModalText);
        setFileName();
        return false;
    }

    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();

    file.close();
    this->setWindowModified(false);

    return true;
}
