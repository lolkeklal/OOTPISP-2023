#ifndef MATRIXDETERMINANT_H
#define MATRIXDETERMINANT_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QGridLayout>
#include <QTime>
#include <QColor>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MatrixDeterminant; }
QT_END_NAMESPACE

class MatrixDeterminant : public QMainWindow
{
    Q_OBJECT

public:
    MatrixDeterminant(QWidget *parent = nullptr);
    ~MatrixDeterminant();

private slots:
    void step1();
    void step2();
    void step3();
    void step4();
    void generateMatrix();
    void calculateDeterminant();
    void highlightElements(int row1, int col1, int row2, int col2, int row3, int col3, QColor color);
    void resetHighlight();
    void generateMatrixAndReset();

private:
    Ui::MatrixDeterminant* ui;
    QTableWidget* matrixTable;
    QPushButton* step1Button;
    QPushButton* step2Button;
    QPushButton* step3Button;
    QPushButton* step4Button;
    QPushButton* generateMatrixButton;
    QLabel* resultLabel;
    QGridLayout* layout;
    QStack<QColor> highlightColors;
};
#endif // MATRIXDETERMINANT_H


