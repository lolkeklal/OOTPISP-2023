#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(const QString &filename, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSettings settings;
    auto font = settings.value("viewFont").value<QFont>();
    ui->textEdit->setCurrentFont(font);

    connectActions();

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    setAttribute(Qt::WA_DeleteOnClose);

    loadFile(filename);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectActions()
{
    connect(ui->actionClose, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionExit, &QAction::triggered, qApp, &QApplication::closeAllWindows);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::documentModified);
    connect(ui->aboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(ui->actionCut, &QAction::triggered, ui->textEdit, &QTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered, ui->textEdit, &QTextEdit::copy);
    connect(ui->actionPaste, &QAction::triggered, ui->textEdit, &QTextEdit::paste);
    connect(ui->actionUndo, &QAction::triggered, ui->textEdit, &QTextEdit::undo);
    connect(ui->actionRedo, &QAction::triggered, ui->textEdit, &QTextEdit::redo);
    connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCopy, &QAction::setEnabled);
    connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCut, &QAction::setEnabled);
    connect(ui->textEdit, &QTextEdit::undoAvailable, ui->actionUndo, &QAction::setEnabled);
    connect(ui->textEdit, &QTextEdit::redoAvailable, ui->actionRedo, &QAction::setEnabled);
    connect(ui->save, &QAction::triggered, this, &MainWindow::save);
    connect(ui->saveAs, &QAction::triggered, this, &MainWindow::saveAs);
}

void MainWindow::documentModified()
{
    setWindowModified(true);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (isWindowModified())
    {
        switch (QMessageBox::warning(this, tr("Документ изменен"),
                                     tr("Этот документ был изменен. "
                                        "Вы хотите сохранить изменения?\n"),
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            save();
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

void MainWindow::loadFile(const QString &fileName)
{
    if (fileName.isEmpty())
    {
        setFileName(QString());
        return;
    }
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Предупреждение!"), tr("Невозможно открыть файл!"));
        setFileName(QString());
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());

    file.close();
    setFileName(fileName);
    setWindowModified(false);
}

void MainWindow::setFileName(const QString &fileName)
{
    m_fileName = fileName;
    setWindowTitle(QString("%1[*] - %2")
                       .arg(m_fileName.isNull() ? tr("Untitled") : QFileInfo(m_fileName).fileName())
                       .arg(QApplication::applicationName()));
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить документ"),
                                                    m_fileName.isNull() ? QDir::currentPath() : m_fileName, tr("Текстовый документ (*.txt)"));
    if (fileName.isNull())
    {
        return false;
    }
    setFileName(fileName);
    return save();
}

bool MainWindow::save()
{
    if (m_fileName.isNull())
    {
        return saveAs();
    }

    QFile file(m_fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Предупреждение!"), tr("Невозможно сохранить файл!"));
        setFileName(QString());
        return false;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
    setWindowModified(false);
    return true;
}

void MainWindow::on_about_triggered()
{
    QMessageBox::about(this, tr("О программе"), "Собственный text changer daaa...");
}


void MainWindow::on_fontSelect_triggered()
{
    bool status;
    QFont font = QFontDialog::getFont(&status, ui->textEdit->font());
    if (status)
    {
        ui->textEdit->setCurrentFont(font);
        QSettings settings;
        settings.setValue("viewFont", font);
    }
}


void MainWindow::on_aboutQt_triggered()
{
}


void MainWindow::on_open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть документ"), QDir::currentPath(), tr("Текстовый документ (*.txt)"));
    if (fileName.isNull())
    {
        return;
    }

    if (m_fileName.isNull() && !isWindowModified())
    {
        loadFile(fileName);
    }
    else
    {
        auto newWindow = new MainWindow(fileName);
        newWindow->show();
    }
}


void MainWindow::on_new_2_triggered()
{
    auto newWindow = new MainWindow();
    newWindow->show();
}

