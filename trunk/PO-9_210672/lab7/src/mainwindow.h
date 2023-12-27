#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

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
    void updateImage();

private:
    Ui::MainWindow *ui;
    int rectX, rectY;
    int ellipseX, ellipseY;
    int rectWidth;
    int rectHeight;
    int ellipseWidth;
    int ellipseHeight;
    int rectXDirection;
    int ellipseXDirection;
    QTimer animationTimer;

    int calculateY(int x);
};
#endif // MAINWINDOW_H
