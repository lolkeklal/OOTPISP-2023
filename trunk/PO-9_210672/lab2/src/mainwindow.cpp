#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    ui->actionCopy->setEnabled(false);
    ui->actionPaste->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    loadFile(fileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    MainWindow *mainWindow = new MainWindow;
    mainWindow->setVisible(true);
}

void MainWindow::documentModified() {
    this->setWindowModified(true);
}

void MainWindow::closeEvent(QCloseEvent *e) {
    if(this->isWindowModified())
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

void MainWindow::on_actionSelectFont_triggered()
{
    bool changeFont;
    QFont font = QFontDialog::getFont(&changeFont, ui->textEdit->font(), this);
    if (changeFont) {
        QSettings settings;
        settings.setValue("viewFont", font);
        ui->textEdit->setFont(font);
    }
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "Text about program");
}

void MainWindow::loadFile(const QString &fileName)
{
    if (fileName.isNull()) {
        setFileName(QString());
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error", "File is not open");
        setFileName(QString());
        return;
    }
    QTextStream fin(&file);
    ui->textEdit->setText(fin.readAll());
    file.close();

    setWindowModified(false);
    setFileName(fileName);
}

void MainWindow::setFileName(QString fileName) {
    m_fileName = fileName;
    setWindowTitle((fileName.isNull() ? "untitled" : fileName) + "[*] - Text Editor");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open...", QDir::currentPath(), "Text (*.txt)");
    if (fileName.isNull()) {
        return;
    }
    if (m_fileName.isNull() && !isWindowModified()) {
        loadFile(fileName);
    } else {
        MainWindow *mainWindow = new MainWindow(fileName);
        mainWindow->setVisible(true);
    }
}


bool MainWindow::saveFile() {
    if (m_fileName.isNull()) {
        return saveFileAs();
    }

    QFile file(m_fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error", "File is not open");
        setFileName(QString());
        return false;
    }

    QTextStream fout(&file);
    fout << ui->textEdit->toPlainText();
    file.close();
    setWindowModified(false);
    return true;
}

bool MainWindow::saveFileAs() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save document", m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if (fileName.isNull()) {
        return false;
    }

    setFileName(fileName);
    return saveFile();
}
