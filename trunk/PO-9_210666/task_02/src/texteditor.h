#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFontDialog>
#include <QFileDialog>
#include <QSettings>
#include <QFile>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *e);

public:
    TextEditor(const QString &fileName=QString(), QWidget *parent = nullptr);
    ~TextEditor();

private slots:
    void on_actionNew_triggered();
    void documentModified();

    bool saveFile();
    bool saveFileAs();

    void on_actionSelectFont_triggered();
    void on_actionAbout_triggered();
    void on_actionOpen_triggered();

private:
    Ui::TextEditor *ui;
    QString m_fileName;

    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName);
};
#endif // TEXTEDITOR_H
