#ifndef TASK02_H
#define TASK02_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>

class Task02Window : public QWidget
{
    Q_OBJECT

public:
    Task02Window(QWidget* parent = nullptr);
    ~Task02Window();

private slots:
    void processArray();
    void processMatrix();

private:
    void displayMatrix(const QVector<QVector<int>>& matrix, bool highlightEven);
    void displayResult(const QString& result);
    QVector<QVector<int>> getMatrixFromUser(int rows, int cols);

private:
    QLineEdit* inputLineEdit;
    QLabel* outputLabel;
    QPushButton* arrayButton;
    QPushButton* matrixButton;
    QVBoxLayout* mainLayout;
};

#endif // TASK02_H
