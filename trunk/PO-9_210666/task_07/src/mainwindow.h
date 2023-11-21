#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateRect();

private:
    Ui::MainWindow *ui;
    int rect1X, rect1Y;
    int rect2X, rect2Y;
    int rectWidth;
    int rectHeight;
    int rect1XDirection;
    int rect2XDirection;
    QTimer animationTimer;

    int calculateY(int x);
};
#endif // MAINWINDOW_H
