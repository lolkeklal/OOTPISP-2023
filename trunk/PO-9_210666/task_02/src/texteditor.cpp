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

    dup_ldFl(fileName);
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
    if (this->dup_m_flNm.isNull())
        return saveFileAs();

    QFile dup_fl(this->dup_m_flNm);
    if (!dup_fl.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "The file is not open");
        dup_stFlNm(QString());
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


void TextEditor::dup_stFlNm(const QString &fileName) {
    dup_m_flNm = fileName;
    this->setWindowTitle(QString("%1[*] - %2")
                       .arg(dup_m_flNm.isNull() ? "untitled" : QFileInfo(dup_m_flNm).fileName())
                       .arg(QApplication::applicationName())
                   );
}


void TextEditor::on_actionOpen_triggered()
{
    QString dup_fileName = QFileDialog::getOpenFileName(this,"Open document",
                                                    QDir::currentPath(), "Text documents (*.txt)");
    if (dup_fileName.isNull())
        return;
    if (this->dup_m_flNm.isNull() && !this->isWindowModified())
        dup_ldFl(dup_fileName);
    else {
        TextEditor* text_editor = new TextEditor(dup_fileName);
        text_editor->show();
    }
}

void TextEditor::dup_ldFl(const QString &fileName){
    if (fileName.isNull()){
        dup_stFlNm(QString());
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error", "The file is not open");
        dup_stFlNm(QString());
        return;
    }

    QTextStream fin(&file);
    ui->textEdit->setText(fin.readAll());
    file.close();

    setWindowModified(false);
    dup_stFlNm(fileName);
}

bool TextEditor::saveFileAs(){
    QString dup_fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                    dup_m_flNm.isNull() ? QDir::currentPath() : dup_m_flNm,
                                                    "Text documents (*.txt)");
    if (dup_fileName.isNull())
        return false;
    dup_stFlNm(dup_fileName);
    return saveFile();
}
