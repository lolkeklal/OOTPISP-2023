#ifndef GG_H
#define GG_H
#include <QMainWindow>
#include "QPushButton"
#include "QSpinBox"
#include "QLabel"
#include "QPlainTextEdit"
#include "QTextEdit"
#include "QSize"
#include "QStyle"
#include "QCommonStyle"
#include <QFormLayout>
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class gg; }
QT_END_NAMESPACE

class gg : public QMainWindow
{
    Q_OBJECT

public:
    gg(QWidget *parent = nullptr);
    ~gg();


private:
    Ui::gg *ui;
    QPushButton *but;

    QPlainTextEdit* txtEdit;

public slots:
    void Otkr();
};
#endif // GG_H
