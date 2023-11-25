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
    int rectangle1PosX, rectangle1PosY;
    int rectangle2PosX, rectangle2PosY;
    int rectangleWidth;
    int rectangleHeight;
    int rectangle1XDirection;
    int rectangle2XDirection;
    QTimer animationTimer;

    int calculateY(int x);
    void drawShape(QPainter &painter, int x, int y, Qt::GlobalColor color);
    void drawText(QPainter &painter, const QString &text, int x, int y, int rotation);
};
#endif // MAINWINDOW_H
