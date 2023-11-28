#ifndef TEXTEDITOR_H//210674
#define TEXTEDITOR_H//210674
//210674
#include <QMainWindow>//210674

QT_BEGIN_NAMESPACE//210674
namespace Ui { class TextEditor; }//210674
QT_END_NAMESPACE//210674
//210674
class TextEditor : public QMainWindow//210674
{
    Q_OBJECT//210674

public:
    TextEditor(QWidget *parent = nullptr);//210674
    ~TextEditor();//210674
    TextEditor(const QString &fileName = QString(), QWidget *parent = 0);//210674

protected:
    void closeEvent(QCloseEvent *e);//210674


private slots:
    void on_actionNew_triggered();//210674

    void documentModified();//210674

    void on_actionSelectFont_triggered();//210674

    void on_actionAbout_2_triggered();//210674

    void on_actionOpen_triggered();//210674
//210674
    bool saveFile();//210674
    bool saveFileAs();//210674

private:
    Ui::TextEditor *ui;//210674
    QString m_fileName;//210674
    void loadFile(const QString &fileName);//210674
    void setFileName(const QString &fileName);//210674
};//210674
#endif // TEXTEDITOR_H//210674
