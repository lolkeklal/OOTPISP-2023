#include "texteditor.h"
#include "./ui_texteditor.h"

TextEditor::TextEditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Text Editor[*]"));

    setAttribute(Qt::WA_DeleteOnClose);

    QSettings settings;
    ui->textEdit->setCurrentFont(settings.value("viewFont").value<QFont>() );

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

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

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
    TextEditor* text_editor = new TextEditor();
    text_editor->show();
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
        }
    }
    else
    {
        e->accept();
    }
}


void TextEditor::on_actionSelectFont_triggered()
{
    QFont currentFont = ui->textEdit->font();
    bool ok;
    QFont font = QFontDialog::getFont(&ok, currentFont, this);
    if (ok) {
        QSettings settings;
        settings.setValue("viewFont", font);
        ui->textEdit->setFont(font);
    }
}


void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе", "О программе");
}

void TextEditor::loadFile(const QString &fileName){
    if (fileName.isNull()){
        setFileName(QString());
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "The file is not open");
        setFileName(QString());
        return;
    }

    QTextStream fin(&file);
    ui->textEdit->setText(fin.readAll());
    file.close();

    setFileName(fileName);
    setWindowModified(false);
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
    QString fileName = QFileDialog::getOpenFileName(this,"Open document",
                                                    QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull())
        return;
    if (this->m_fileName.isNull() && !this->isWindowModified())
        loadFile(fileName);
    else {
        TextEditor* text_editor = new TextEditor(fileName);
        text_editor->show();
    }
}

bool TextEditor::saveFileAs(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                    m_fileName.isNull() ? QDir::currentPath() : m_fileName,
                                                    "Text documents (*.txt)");
    if (fileName.isNull())
        return false;
    setFileName(fileName);
    return saveFile();
}

bool TextEditor::saveFile(){
    if (this->m_fileName.isNull())
        return saveFileAs();

    QFile file(this->m_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
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
