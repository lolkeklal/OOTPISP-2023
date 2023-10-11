#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>

namespace Ui {
class TextBox;
}

class TextBox : public QMainWindow
{
    Q_OBJECT

public:
    explicit TextBox(QWidget *parent = nullptr);
    ~TextBox();

    QTextEdit *te;
    QPushButton *but;
    QGridLayout *layout;

public slots:
    void openFile();

private:
    Ui::TextBox *ui;
};

#endif // TEXTBOX_H
