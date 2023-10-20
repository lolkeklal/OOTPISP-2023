#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#include <QTextEdit>
#include <QString>
#include <QFileDialog>

class TextEdit : public QTextEdit
{
public:
    TextEdit(QWidget *widget);
    void openFile();

private:
    QWidget *widget;
};

#endif // TEXTEDIT_H
