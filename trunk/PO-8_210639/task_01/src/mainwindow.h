#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QObject>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel *l1;
    QLabel *l2;
    QLabel *l3;
    QSpinBox *sb1;
    QSpinBox *sb2;
    QSpinBox *sb3;
    QSlider *sl1;
    QSlider *sl2;
    QSlider *sl3;
    QPlainTextEdit *pte;
    QGridLayout *layout;

public slots:
    void setRed(int red);
    void setGreen(int green);
    void setBlue(int blue);

    void setColor();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
