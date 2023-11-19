#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QFileDialog>
#include <QFont>
#include <QSettings>
#include <QString>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class textEditor; }
QT_END_NAMESPACE

class textEditor210639 : public QMainWindow
{
    Q_OBJECT
protected:
    void closeEvent210639(QCloseEvent *e210639);
public:
    textEditor210639(const QString &fileName210639=QString(), QWidget *parent210639 = nullptr);
    ~textEditor210639();

private slots:
    void documentModified210639();
    bool saveFile210639();
    bool saveFileAs210639();
    void on_actionNew210639_triggered();
    void on_actionSelectFont210639_triggered();
    void on_actionAbout210639_triggered();
    void on_actionOpen210639_triggered();

private:
    Ui::textEditor *ui;
    QString m_fileName210639;
    void loadFile210639(const QString &fileName);
    void setFileName210639(const QString &fileName);
};
#endif // TEXTEDITOR_H
