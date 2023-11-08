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
    QFont defaultFont = QApplication::font();
    QFont viewFont = settings.value("viewFont", QVariant::fromValue(defaultFont)).value<QFont>();
    ui->textEdit->setFont(viewFont);

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(closeDocument()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
    connect(ui->actionSelectFont, SIGNAL(triggered()), this, SLOT(changeFont()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveDocument()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveDocumentAs()));

    setWindowTitle("TextEditor[*]");

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    setAttribute(Qt::WA_DeleteOnClose);

    loadDocument(filename);
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::createNewDocument()
{
    TextEditor *newEditor = new TextEditor;
    newEditor->updateFont(ui->textEdit->font());
    newEditor->show();
}

void TextEditor::documentModified()
{
    setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *event)
{
    if (isWindowModified())
    {
        switch (QMessageBox::warning(this, "Document Modified",
                                     "The document has been modified. "
                                     "Do you want to save your changes?\n"
                                     "You will lose any unsaved changes.",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            saveDocument();
            break;
        case QMessageBox::No:
            event->accept();
            break;
        case QMessageBox::Cancel:
            event->ignore();
            break;
        default:
            break;
        }
    }
    else
    {
        event->accept();
    }
}

void TextEditor::updateFont(const QFont &newFont)
{
    ui->textEdit->setFont(newFont);
    QSettings settings;
    settings.setValue("viewFont", QVariant::fromValue(newFont));
}

void TextEditor::changeFont()
{
    bool ok;
    QFont initialFont = ui->textEdit->font();
    QFont selectedFont = QFontDialog::getFont(&ok, initialFont, this);

    if (ok)
    {
        updateFont(selectedFont);
    }
}

void TextEditor::showAboutDialog()
{
    QMessageBox::about(this, "About TextEditor",
                       "A versatile text editing tool for creating and editing documents. It supports multiple documents, "
                       "and provides features such as open, save, undo, redo, clipboard operations, and more.");
}

void TextEditor::loadDocument(const QString &fileName)
{
    if (fileName.isEmpty())
    {
        setDocumentName(QString());
        return;
    }
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning", "Can't open this file");
        setDocumentName(QString());
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());

    file.close();
    setDocumentName(fileName);
    setWindowModified(false);
}

void TextEditor::setDocumentName(const QString &fileName)
{
    m_documentName = fileName;
    setWindowTitle(QString("%1[*] - %2")
                   .arg(m_documentName.isNull() ? "untitled" : QFileInfo(m_documentName).fileName())
                   .arg(QApplication::applicationName()));
}

void TextEditor::openDocument()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Document", QDir::currentPath(), "Text Documents (*.txt)");
    if (fileName.isNull())
        return;
    if (m_documentName.isNull() && !isWindowModified())
    {
        loadDocument(fileName);
    }
    else
    {
        TextEditor *newEditor = new TextEditor;
        newEditor->show();
        newEditor->loadDocument(fileName);
    }
}

void TextEditor::closeDocument()
{
    close();
}

void TextEditor::exitApplication()
{
    close();
}

bool TextEditor::saveDocumentAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Document",
                                                    m_documentName.isNull() ? QDir::currentPath() : m_documentName, "Text Documents (*.txt)");

    if (fileName.isEmpty())
    {
        return false;
    }

    setDocumentName(fileName);
    return saveDocument();
}

bool TextEditor::saveDocument()
{
    if (m_documentName.isNull())
    {
        return saveDocumentAs();
    }

    QFile file(m_documentName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();

        setWindowModified(false);
        return true;
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Can't save in this file.");
        setDocumentName(QString());
        return false;
    }
}
