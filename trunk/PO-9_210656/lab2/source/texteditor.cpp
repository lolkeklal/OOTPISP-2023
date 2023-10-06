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
    QSettings settings;
    auto font = settings.value("viewFont").value<QFont>();
    ui->textEdit->setCurrentFont(font);

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
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
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

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


void TextEditor::on_actionNew_triggered()
{
    auto newWindow = new TextEditor();
    newWindow->show();
}

void TextEditor::documentModified(){
    setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *e){
    if(isWindowModified())
    {
        switch(QMessageBox::warning(this, "Document Modified",
                                     "The document has been modified. "
                                     "Do you want to save your changes?\n"
                                     "You will lose and unsaved changes.",
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
        default:
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
    auto font = ui->textEdit->font();
    bool status;
    auto newFont = QFontDialog::getFont(&status, font);
    if (status == true){
        ui->textEdit->setCurrentFont(newFont);
        QSettings settings;
        settings.setValue("viewFont", newFont);
    }
}


void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе", "что то касательно чудо программы");
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
    m_fileName = fileName;
    setWindowTitle(QString("%1[*] - %2")
                       .arg(m_fileName.isNull()?"untitled":QFileInfo(m_fileName).fileName())
                       .arg(QApplication::applicationName())
    );

}

void TextEditor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open document", QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull()){
        return;
    }

    if (m_fileName.isNull() && !isWindowModified()){
        loadFile(fileName);
    } else {
        auto newWindow = new TextEditor(fileName);
        newWindow->show();
    }
}

bool TextEditor::saveFileAs(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                    m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if (fileName.isNull()){
        return false;
    }
    setFileName(fileName);
    return saveFile();
}

bool TextEditor::saveFile(){
    if (m_fileName.isNull()){
        return saveFileAs();
    }

    QFile file(m_fileName);

    if (!file.open(QIODevice::WriteOnly  | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Can't save in this file");
        setFileName(QString());
        return false;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
    setWindowModified(false);
    return true;
}
