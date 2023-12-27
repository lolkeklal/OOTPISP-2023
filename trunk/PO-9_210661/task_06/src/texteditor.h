#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFlags>
#include <QFont>
#include <QFontDialog>
#include <QSettings>
#include <QVariant>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDir>

#include "./ui_texteditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &fileName = QString(), QWidget *parent = nullptr);
    ~TextEditor();

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    // Create new TextEditor window
    void on_actionNew_triggered();
    void documentChanged();
    void on_actionSelectFont_triggered();
    void on_actionAbout_triggered();
    void on_actionOpen_triggered();

    bool saveFile();
    bool saveFileAs();

private:
    Ui::TextEditor *ui;
    QString m_fileName;

    static QString onCloseModifiedModalTitle;
    static QString onCloseModifiedModalText;
    static QString onAboutModalTitle;
    static QString onAboutModalText;
    static QString onFileOpenErrorModalTitle;
    static QString onFileOpenErrorModalText;
    static QString newDocumentTitle;
    static QString fileDialogTextFilesFilter;
    static QString onFileOpenModalTitle;
    static QString onSaveFileModalTitle;

    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName = QString());
};

#endif // TEXTEDITOR_H
