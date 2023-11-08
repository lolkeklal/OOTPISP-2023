#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &fileName = QString(), QWidget *parent = 0);
    ~TextEditor();

    void updateFont(const QFont &newFont);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void createNewDocument();
    void documentModified();
    void closeDocument();
    void exitApplication();
    void changeFont();
    void showAboutDialog();
    void openDocument();
    bool saveDocument();
    bool saveDocumentAs();

private:
    void loadDocument(const QString &filename);
    void setDocumentName(const QString &fileName);

    QString m_documentName;
    Ui::TextEditor *ui;
};
#endif // TEXTEDITOR_H
