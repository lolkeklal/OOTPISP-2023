#include "texteditor.h"
#include "ui_texteditor.h"

textEditor210639::textEditor210639(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::textEditor)
{
    ui->setupUi(this);
    setWindowTitle("TextEditor[*]");
    QSettings settings210639;
    QFont defaultFont210639 = QApplication::font();
    QFont viewFont210639 = settings210639.value("viewFont", QVariant::fromValue(defaultFont210639)).value<QFont>();
    ui->textEdit->setFont(viewFont210639);

    ui->actionCopy210639->setEnabled(false);
    ui->actionCut210639->setEnabled(false);
    ui->actionUndo210639->setEnabled(false);
    ui->actionRedo210639->setEnabled(false);

    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->actionClose210639, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit210639, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified210639()));
    connect(ui->actionAbout_Qt210639, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionCut210639, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy210639, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste210639, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo210639, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo210639, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy210639, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut210639, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo210639, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo210639, SLOT(setEnabled(bool)));
    loadFile210639(fileName);
    connect(ui->actionSave210639, SIGNAL(triggered()), this, SLOT(saveFile210639()));
    connect(ui->actionSaveAS210639, SIGNAL(triggered()), this, SLOT(saveFileAs210639()));
}

textEditor210639::~textEditor210639()
{
    delete ui;
}

void textEditor210639::documentModified210639()
{
    this->setWindowModified(true);
}

void textEditor210639::closeEvent210639(QCloseEvent *e)
{
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
            if(!saveFile210639()){
               e->accept();
            }
            e->ignore();
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

void textEditor210639::loadFile210639(const QString &fileName210639){
    if (fileName210639.isEmpty()){
        setFileName210639(QString());
        return;
    }
    QFile file(fileName210639);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Can't open this file");
        setFileName210639(QString());
        return;
    }
    QTextStream stream(&file);
    ui->textEdit->setText(stream.readAll());
    file.close();
    setFileName210639(fileName210639);
    setWindowModified(false);
}

void textEditor210639::setFileName210639(const QString &fileName210639){
    m_fileName210639=fileName210639;
    setWindowTitle(QString("%1[*] - %2")
                    .arg(m_fileName210639.isNull()?"untitled":QFileInfo(m_fileName210639).fileName())
                    .arg(QApplication::applicationName()));
}

bool textEditor210639::saveFileAs210639(){
    QString fileName210639 = QFileDialog::getSaveFileName(this, "Save document", m_fileName210639.isNull()?QDir::currentPath():m_fileName210639, "Text documents (*.txt)");
    if(fileName210639.isNull()){
        return false;
    }
    else{
        setFileName210639(fileName210639);
        return saveFile210639();
    }
}

bool textEditor210639::saveFile210639(){
    if(m_fileName210639.isNull()){
        return saveFileAs210639();
    }
    QFile file210639(m_fileName210639);
    if (!file210639.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Can't open this file");
        setFileName210639(QString());
        return false;
    }
    else{
        QTextStream out_stream(&file210639);
        out_stream << ui->textEdit->toPlainText();
        file210639.close();
        setWindowModified(false);
        return true;
    }
}

void textEditor210639::on_actionNew210639_triggered()
{
    textEditor210639 *texteditor210639= new textEditor210639();
    texteditor210639->show();
}

void textEditor210639::on_actionSelectFont210639_triggered()
{
    bool ok210639;
    QFont font210639;
    QFont initial210639 = ui->textEdit->font();
    font210639 = QFontDialog::getFont(&ok210639, initial210639, this);
    if(ok210639){
        ui->textEdit->setFont(font210639);
        QSettings settings210639;
        settings210639.setValue("viewFont", QVariant::fromValue(font210639));
    }
}

void textEditor210639::on_actionAbout210639_triggered()
{
    QMessageBox::about(this, "About", "Text editor.");
}


void textEditor210639::on_actionOpen210639_triggered()
{
    QString fileName210639 = QFileDialog::getOpenFileName(this,
                                                    "Open document", QDir::currentPath(), "Text documents (*.txt)");
    if(fileName210639.isNull()){
        return;
    }
    if(m_fileName210639.isNull() && !isWindowModified()){
        loadFile210639(fileName210639);
    }
    else{
        textEditor210639 *texteditor210639 = new textEditor210639(fileName210639);
        texteditor210639->show();
    }
}

