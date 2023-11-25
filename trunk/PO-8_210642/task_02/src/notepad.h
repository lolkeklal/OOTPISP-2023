#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class NotePad; }
QT_END_NAMESPACE

class NotePad : public QMainWindow
{
    Q_OBJECT

public:
    NotePad(const QString &fileName = QString(), QWidget *parent = 0);
    ~NotePad();

    void updateFont(const QFont &newFont);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void actionNew210642();
    void documentModified210642();
    void actionSelectFont210642();
    void About210642();
    void actionOpen210642();
    void closeDocument210642();
    void exitApplication210642();
    bool saveDocument210642();
    bool saveDocumentAs210642();

private:
    void loadFile(const QString &filename);
    void setDocumentName(const QString &fileName);

    QString m_documentName;
    Ui::NotePad *ui;
};
#endif // NOTEPAD_H
