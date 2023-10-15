#include <QMainWindow>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_randomButton_clicked();
    void on_maxButton_clicked();
    void on_minButton_clicked();
    void on_sumButton_clicked();
    void on_averageButton_clicked();
    void on_tableWidget_cellEntered(int row, int column);

private:
    Ui::MainWindow *ui;
    void highlightCell(int row, int column);
};
