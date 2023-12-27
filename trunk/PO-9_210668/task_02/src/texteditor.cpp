#include "texteditor.h"
#include "ui_texteditor.h"
TextEditor::TextEditor(const QString &fil, QWidget *parent)
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
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(svFl()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(svFlAs()));

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    setAttribute(Qt::WA_DeleteOnClose);

    lida(fil);
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

void TextEditor::closeEvent(QCloseEvent *eve){
    if(isWindowModified())
    {
        switch(QMessageBox::warning(this, "Документ изменен",
                                     "Документ был изменен. "
                                     "Хотите сохранить изменения?\n"
                                     "Вы можете потерять данные.",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            svFl();
            break;
        case QMessageBox::No:
            eve->accept();
            break;
        case QMessageBox::Cancel:
            eve->ignore();
            break;
        default:
            break;
        }
    }
    else
    {
        eve->accept();
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



void TextEditor::lida(const QString &fil){
    if (fil.isEmpty()){
        setfila(QString());
        return;
    }
    QFile file(fil);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Предупреждение", "Невозможно открыть этот файл");
        setfila(QString());
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());

    file.close();
    setfila(fil);
    setWindowModified(false);
}

void TextEditor::setfila(const QString &fil){
    m_fila = fil;

    QString title = m_fila.isNull() ? "Безымянный" : QFileInfo(m_fila).fileName();
    QString windowTitle = QString("%1[*] - %2").arg(title, QApplication::applicationName());

    setWindowTitle(windowTitle);

}

void TextEditor::on_actionOpen_triggered()
{
    QString fil = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::currentPath(), "Текстовые файлы(*.txt)");
    if (fil.isNull()){
        return;
    }

    if (m_fila.isNull() && !isWindowModified()){
        lida(fil);
    } else {
        auto newWindow = new TextEditor(fil);
        newWindow->show();
    }
}

bool TextEditor::svFlAs(){
    QString fil = QFileDialog::getSaveFileName(this, "Сохранить документ",
                                                    m_fila.isNull()?QDir::currentPath():m_fila, "Текстовые файлы(*.txt)");
    if (fil.isNull()){
        return false;
    }
    setfila(fil);
    return svFl();
}

bool TextEditor::svFl(){
    if (m_fila.isNull()){
        return svFlAs();
    }

    QFile file(m_fila);

    if (!file.open(QIODevice::WriteOnly  | QIODevice::Text)){
        QMessageBox::warning(this, "Предупреждение", "Невозможно");
        setfila(QString());
        return false;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
    setWindowModified(false);
    return true;
}

void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе", "эта программа называется qt");
}
