#include "notepad.h"
#include "./ui_notepad.h"

#include <QMessageBox>
#include <QFontDialog>
#include <QFileDialog>
#include <QSettings>
#include <QFile>
#include <QFileInfo>

NotePad::NotePad(const QString &filename, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotePad)
{
    ui->setupUi(this);
    setWindowTitle("NotePad[*]");
    QSettings settings;
    QFont defaultFont = QApplication::font();
    QFont viewFont = settings.value("viewFont", QVariant::fromValue(defaultFont)).value<QFont>();
    ui->textEdit->setFont(viewFont);

    connect(ui->actionClose210642, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit210642, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified210642()));
    connect(ui->actionSelectFont210642, SIGNAL(triggered()), this, SLOT(actionSelectFont210642()));
    connect(ui->actionAbout210642, SIGNAL(triggered()), this, SLOT(About210642()));
    connect(ui->actionAboutQt210642, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionCut210642, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy210642, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste210642, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo210642, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo210642, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy210642, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut210642, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo210642, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo210642, SLOT(setEnabled(bool)));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveDocument210642()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveDocumentAs210642()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(actionOpen210642()));

    ui->actionCopy210642->setEnabled(false);
    ui->actionCut210642->setEnabled(false);
    ui->actionUndo210642->setEnabled(false);
    ui->actionRedo210642->setEnabled(false);
    loadFile(filename);

    setAttribute(Qt::WA_DeleteOnClose);
}

NotePad::~NotePad()
{
    delete ui;
}


void NotePad::actionNew210642()
{
    NotePad *newEditor = new NotePad;
    newEditor->show();
}

void NotePad::documentModified210642()
{
    this->setWindowModified(true);
}

void NotePad::closeEvent(QCloseEvent *event)
{
    if (this->isWindowModified()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Несохраненные изменения",
                                     "Документ содержит несохраненные изменения. Хотите сохранить их?",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            saveDocument210642();
            event->accept();
        } else if (reply == QMessageBox::No) {
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
}

void NotePad::updateFont(const QFont &newFont)
{
    ui->textEdit->setFont(newFont);
    QSettings settings;
    settings.setValue("viewFont", QVariant::fromValue(newFont));
}

void NotePad::actionSelectFont210642()
{
    bool ok;
    QFont initialFont = ui->textEdit->font();
    QFont selectedFont = QFontDialog::getFont(&ok, initialFont, this);
    if (ok)
    {
        updateFont(selectedFont);
    }
}

void NotePad::About210642()
{
    QMessageBox::about(this, "О программе NotePad",
                   "Универсальный редактор текста для создания и редактирования документов. Поддерживает работу "
                                                                 "с несколькими документами и предоставляет такие функции, как открытие, сохранение, отмена, "
                                                                 "повторение, операции с буфером обмена и многое другое.");
}

void NotePad::loadFile(const QString &fileName)
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

void NotePad::setDocumentName(const QString &fileName)
{
    m_documentName = fileName;
    setWindowTitle(QString("%1[*] - %2")
                       .arg(m_documentName.isNull() ? "untitled" : QFileInfo(m_documentName).fileName())
                       .arg(QApplication::applicationName()));
}

void NotePad::actionOpen210642()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Document", QDir::currentPath(), "Text Documents (*.txt)");
    if (fileName.isNull())
        return;

    if (m_documentName.isNull() && !isWindowModified())
    {
        loadFile(fileName);
    }
    else
    {
        NotePad *newEditor = new NotePad;
        newEditor->show();
        newEditor->loadFile(fileName);
    }
}

void NotePad::closeDocument210642()
{
    close();
}

void NotePad::exitApplication210642()
{
    close();
}

bool NotePad::saveDocumentAs210642()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Document",
                                                    m_documentName.isNull() ? QDir::currentPath() : m_documentName, "Text Documents (*.txt)");

    if (fileName.isEmpty())
    {
        return false;
    }

    setDocumentName(fileName);
    return saveDocument210642();
}

bool NotePad::saveDocument210642()
{
    if (m_documentName.isNull())
    {
        return saveDocumentAs210642();
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
