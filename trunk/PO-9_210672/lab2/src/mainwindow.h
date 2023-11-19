#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QCloseEvent>
#include <QIcon>
#include <QFont>
#include <QFontDialog>
#include <QSettings>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &fileName=QString(), QWidget *parent = nullptr);
    ~MainWindow();

    void setFileName(QString fileName);

private slots:
    void on_actionNew_triggered();

    void documentModified();

    void on_actionSelectFont_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    bool saveFile();

    bool saveFileAs();

private:
    Ui::MainWindow *ui;
    QString m_fileName;

    void loadFile(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *e);
};
#endif // MAINWINDOW_H
