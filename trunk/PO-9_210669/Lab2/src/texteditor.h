#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QSettings> //210669_texteditor.h

#include <QFileInfo> //210669_texteditor.h

#include <QFile> //210669_texteditor.h

#include <QCloseEvent> //210669_texteditor.h

#include <QFileDialog> //210669_texteditor.h


QT_BEGIN_NAMESPACE //210669_texteditor.h

namespace Ui { class TextEditor; } //210669_texteditor.h

QT_END_NAMESPACE //210669_texteditor.h


class TextEditor : public QMainWindow //210669_texteditor.h

{
    Q_OBJECT //210669_texteditor.h //210669_texteditor.h


public:
    TextEditor(const QString &fileName=QString(),QWidget *parent = nullptr); //210669_texteditor.h

    ~TextEditor(); //210669_texteditor.h


private slots:
    void documentEdited210667(); //210669_texteditor.h


    void on_actionNew_triggered(); //210669_texteditor.h


    void on_actionClose_triggered(); //210669_texteditor.h


    void on_actionExit_triggered();
    //210669_texteditor.h

    void on_actionSelectFont_triggered(); //210669_texteditor.h


    void on_actionAbout_triggered(); //210669_texteditor.h


    bool saveFile(); //210669_texteditor.h


    bool saveFileAs(); //210669_texteditor.h


    void on_actionOpen_triggered(); //210669_texteditor.h


private: //210669_texteditor.h

    void loadFile(const QString &fileName); //210669_texteditor.h

    void setFileName(const QString &fileName); //210669_texteditor.h

    QString fileName210667; //210669_texteditor.h

    Ui::TextEditor *ui; //210669_texteditor.h

protected: //210669_texteditor.h

    void closeEvent(QCloseEvent *e); //210669_texteditor.h

};
#endif // TEXTEDITOR_H //210669_texteditor.h

