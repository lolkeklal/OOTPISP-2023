#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QFileInfo>
#include <QMainWindow>
#include <QFile>
#include <QCloseEvent>
#include <QFontDialog>
#include <QFileDialog>
#include <QSettings>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

private:
    void dup_stFlNm(const QString &fileName);
    void dup_ldFl(const QString &fileName);
    QString dup_m_flNm;
    Ui::TextEditor *ui;

public:
    TextEditor(const QString &fileName=QString(), QWidget *parent = nullptr);
    ~TextEditor();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentModified();
    void on_actionNew_triggered();
    void on_actionAbout_triggered();
    bool saveFile();
    void on_actionOpen_triggered();
    bool saveFileAs();
    void on_actionSelectFont_triggered();



};
#endif // TEXTEDITOR_H
