#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QSettings>
#include <QFileInfo>
#include <QFile>
#include <QCloseEvent>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &fileName=QString(),QWidget *parent = nullptr);
    ~TextEditor();

private slots:
    void documentEdited210667();

    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void on_actionSelectFont_triggered();

    void on_actionAbout_triggered();

    bool saveFile();

    bool saveFileAs();

    void on_actionOpen_triggered();

private:
    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName);
    QString fileName210667;
    Ui::TextEditor *ui;
protected:
    void closeEvent(QCloseEvent *e);
};
#endif // TEXTEDITOR_H
