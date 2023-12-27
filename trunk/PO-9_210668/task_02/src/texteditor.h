#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>//inck
#include <QCloseEvent>//inck
#include <QMessageBox>//inck
#include <QFontDialog>//inck
#include <QFileDialog>//inck
#include <QSettings>//inck
#include <QFile>//inck
#include <QFileInfo>//inck

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &fila=QString(), QWidget *parent = nullptr);
    ~TextEditor();

protected:
    void closeEvent(QCloseEvent *eve);

private slots:
    void on_actionNew_triggered();
    void documentModified();

    void on_actionSelectFont_triggered();
    void on_actionAbout_triggered();
    void on_actionOpen_triggered();

    bool svFl();
    bool svFlAs();

private:
    void lida(const QString &fila);
    void setfila(const QString &fila);


    Ui::TextEditor *ui;
    QString m_fila;
};
#endif // TEXTEDITOR_H
