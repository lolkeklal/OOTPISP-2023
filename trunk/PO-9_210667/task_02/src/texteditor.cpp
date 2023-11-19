#include "texteditor.h"
#include "./ui_texteditor.h"

TextEditor::TextEditor(const QString &fileName,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Text Editor[*]"));

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentEdited210667()));
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    ui->actionPaste->setEnabled(true);
    connect(ui->actionUndo, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    ui->actionUndo->setEnabled(false);
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    ui->actionRedo->setEnabled(false);
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    ui->actionCut->setEnabled(false);
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->actionCopy, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    ui->actionCopy->setEnabled(false);
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    loadFile(fileName);
}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionNew_triggered()
{
    TextEditor* newTextEditor = new TextEditor();
    newTextEditor->show();
}


void TextEditor::on_actionClose_triggered()
{

}

void TextEditor::on_actionExit_triggered()
{

}
void TextEditor::documentEdited210667(){
    setWindowModified(true);
}
void TextEditor::closeEvent(QCloseEvent *e)
{
    if(isWindowModified())
    {
        switch(QMessageBox::warning(this, "Document Modified",
                                     "The document has been modified, "
                                     "do you want to save your changes?\n"
                                     "You will lose all your changes.",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            saveFile();
            break;
        case QMessageBox::No:
            e->accept();
            break;
        case QMessageBox::Cancel:
            e->ignore();
            break;
        }
    }
    else
    {
        e->accept();
    }
}


void TextEditor::on_actionSelectFont_triggered()
{
    bool ok;
    QFont currentFont = ui->textEdit->font();
    QFont font = QFontDialog::getFont(&ok, currentFont, this);
    if (ok) {
        QSettings settings;
        settings.setValue("View Font", font);
        ui->textEdit->setFont(font);
    }
}


void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе", "Здесь могла бы быть ваша реклама");
}
void TextEditor::setFileName(const QString &fileName) {
    fileName210667 = fileName;
    this->setWindowTitle(QString("%1[*] - %2")
                             .arg(fileName210667.isNull() ? "untitled" : QFileInfo(fileName210667).fileName())
                             .arg(QApplication::applicationName())
                         );
}
void TextEditor::loadFile(const QString &fileName)
{
    if (fileName.isNull()){
        setFileName(QString());
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error", "The file is not open");
        setFileName(QString());
        return;
    }
    QTextStream fin(&file);
    ui->textEdit->setText(fin.readAll());
    file.close();
        setFileName(fileName);
    setWindowModified(false);

}


void TextEditor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open document",
                                                        QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull())
        return;
    if (this->fileName210667.isNull() && !this->isWindowModified())
        loadFile(fileName);
    else {
        TextEditor* text_editor = new TextEditor(fileName);
        text_editor->show();
    }
}

bool TextEditor::saveFile(){
    if (this->fileName210667.isNull())
        return saveFileAs();

    QFile file(this->fileName210667);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "The file is not open");
        setFileName(QString());
        return false;
    }

    QTextStream fin(&file);
    fin << ui->textEdit->toPlainText();
    file.close();

    this->setWindowModified(false);
    return true;
}

bool TextEditor::saveFileAs(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                        fileName210667.isNull() ? QDir::currentPath() : fileName210667,
                                                        "Text documents (*.txt)");
    if (fileName.isNull())
        return false;
    setFileName(fileName);
    return saveFile();
}

