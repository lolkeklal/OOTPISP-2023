#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &filename=QString(), QWidget *parent = nullptr);
    ~MainWindow();
    void connectActions();

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void documentModified();

    bool save();
    bool saveAs();


    void on_about_triggered();

    void on_fontSelect_triggered();

    void on_aboutQt_triggered();

    void on_open_triggered();

    void on_new_2_triggered();


private:
    void loadFile(const QString &filename);
    void setFileName(const QString &filename);


    Ui::MainWindow *ui;
    QString m_fileName;
};
#endif // MAINWINDOW_H
