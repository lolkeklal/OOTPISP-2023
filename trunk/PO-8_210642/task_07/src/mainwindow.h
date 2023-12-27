#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void updateSpiral();

private:
    Ui::MainWindow *ui;
    int rectangleWidth = 75;
    int rectangleHeight = 50;
    double spiralRadius;
    double spiralAngle;
    double rectanglePosX;
    double rectanglePosY;
    QTimer animationTimer;

    void drawShape(QPainter &painter, int x, int y, Qt::GlobalColor color);
    void drawText(QPainter &painter, const QString &text, int x, int y, int rotation);
};

#endif // MAINWINDOW_H
