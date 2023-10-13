#include "texteditor.h"
#include "./ui_texteditor.h"

TextEditor::TextEditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Text Editor[*]"));

    QSettings settings;
    ui->textEdit->setCurrentFont(settings.value("viewFont").value<QFont>() );

    ui->actionUndo->setEnabled(false);
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    ui->actionRedo->setEnabled(false);
    connect(ui->actionCopy, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    ui->actionCut->setEnabled(false);
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionUndo, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    ui->actionCopy->setEnabled(false);
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));

    loadFile(fileName);
}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionNew_triggered()
{
    TextEditor* dup_text_editor = new TextEditor();
    dup_text_editor->show();
}

void TextEditor::closeEvent(QCloseEvent *event){
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
            event->accept();
            break;
        case QMessageBox::Cancel:
            event->ignore();
            break;
        }
    }
    else
    {
        event->accept();
    }
}


void TextEditor::on_actionSelectFont_triggered()
{
    bool ok;
    QFont dup_currentFont = ui->textEdit->font();
    QFont dup_font = QFontDialog::getFont(&ok, dup_currentFont, this);
    if (ok) {
        QSettings set;
        set.setValue("viewFont", dup_font);
        ui->textEdit->setFont(dup_font);
    }
}

bool TextEditor::saveFile(){
    if (this->m_fileName.isNull())
        return saveFileAs();

    QFile dup_fl(this->m_fileName);
    if (!dup_fl.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "The file is not open");
        setFileName(QString());
        return false;
    }

    QTextStream fin(&dup_fl);
    fin << ui->textEdit->toPlainText();
    dup_fl.close();

    this->setWindowModified(false);
    return true;
}

void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе", "О программе");
}

void TextEditor::documentModified(){
    setWindowModified(true);
}


void TextEditor::setFileName(const QString &fileName) {
    m_fileName = fileName;
    this->setWindowTitle(QString("%1[*] - %2")
                       .arg(m_fileName.isNull() ? "untitled" : QFileInfo(m_fileName).fileName())
                       .arg(QApplication::applicationName())
                   );
}


void TextEditor::on_actionOpen_triggered()
{
    QString dup_fileName = QFileDialog::getOpenFileName(this,"Open document",
                                                    QDir::currentPath(), "Text documents (*.txt)");
    if (dup_fileName.isNull())
        return;
    if (this->m_fileName.isNull() && !this->isWindowModified())
        loadFile(dup_fileName);
    else {
        TextEditor* text_editor = new TextEditor(dup_fileName);
        text_editor->show();
    }
}

void TextEditor::loadFile(const QString &fileName){
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

    setWindowModified(false);
    setFileName(fileName);
}

bool TextEditor::saveFileAs(){
    QString dup_fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                    m_fileName.isNull() ? QDir::currentPath() : m_fileName,
                                                    "Text documents (*.txt)");
    if (dup_fileName.isNull())
        return false;
    setFileName(dup_fileName);
    return saveFile();
}
