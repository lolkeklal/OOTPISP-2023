#include "texteditor.h"
#include "ui_texteditor.h"
#include <QMessageBox>
#include <QFontDialog>
#include <QFileDialog>
#include <QSettings>
#include <QFile>
#include <QFileInfo>

TextEditor::TextEditor(const QString &filename, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    QSettings qsettings;
    auto fontValue = qsettings.value("viewFont").value<QFont>();
    ui->textEdit->setCurrentFont(fontValue);

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentEdited210643()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save_File210643()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(save_File210643_As()));

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    setAttribute(Qt::WA_DeleteOnClose);

    loadFile(filename);
}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_action_New_triggered210643()
{
    auto new_window = new TextEditor();
    new_window->show();
}

void TextEditor::documentEdited210643(){
    setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *e){
    if(isWindowModified())
    {
        switch(QMessageBox::warning(this, "Document Edited",
                                     "The document has been changed. "
                                     "Should your changes be saved?\n"
                                     "Unsaved changes will be lost.",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            save_File210643();
            break;
        case QMessageBox::No:
            e->accept();
            break;
        case QMessageBox::Cancel:
            e->ignore();
            break;
        default:
            break;
        }
    }
    else
    {
        e->accept();
    }

}

void TextEditor::on_action_SelectFont_triggered210643()
{
    auto fontValue = ui->textEdit->fontValue();
    bool stats;
    auto newFont = QFontDialog::getFont(&stats, fontValue);
    if (stats == true){
        ui->textEdit->setCurrentFont(newFont);
        Qqsettings qsettings;
        qsettings.setValue("viewFont", newFont);
    }
}


void TextEditor::on_action_About_triggered210643()
{
    QMessageBox::about(this, "About program", "The task will be to develop a complete window application — a text editor that works with several documents with the ability to open and save, undo actions, work with the clipboard and others.");
}

void TextEditor::loadFile(const QString &fileName){
    if (fileName.isEmpty()){
        setFileName(QString());
        return;
    }
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Can't open this file");
        setFileName(QString());
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());

    file.close();
    setFileName(fileName);
    setWindowModified(false);
}

void TextEditor::setFileName(const QString &fileName){
    tmp_filename = fileName;
    setWindowTitle(QString("%1[*] - %2")
                       .arg(tmp_filename.isNull()?"untitled":QFileInfo(tmp_filename).fileName())
                       .arg(QApplication::applicationName())
                   );

}

void TextEditor::on_action_Open_triggered210643()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open document", QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull()){
        return;
    }

    if (tmp_filename.isNull() && !isWindowModified()){
        loadFile(fileName);
    } else {
        auto new_window = new TextEditor(fileName);
        new_window->show();
    }
}

bool TextEditor::save_File210643_As(){
    QString fileName = QFileDialog::getsave_File210643Name(this, "Save document",
                                                    tmp_filename.isNull()?QDir::currentPath():tmp_filename, "Text documents (*.txt)");
    if (fileName.isNull()){
        return false;
    }
    setFileName(fileName);
    return save_File210643();
}

bool TextEditor::save_File210643(){
    if (tmp_filename.isNull()){
        return save_File210643_As();
    }

    QFile file(tmp_filename);

    if (!file.open(QIODevice::WriteOnly  | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Can't save inside of this file");
        setFileName(QString());
        return false;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
    setWindowModified(false);
    return true;
}
