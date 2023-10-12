#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPalette"
#include "QFile"
#include "QFileDialog"
#include "QMessageBox"
#include "QTextEdit"

QPalette m_pal;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->counter_1, SIGNAL(valueChanged(int)), ui->slider_1, SLOT(setValue(int)));
    connect(ui->counter_2, SIGNAL(valueChanged(int)), ui->slider_2, SLOT(setValue(int)));
    connect(ui->counter_3, SIGNAL(valueChanged(int)), ui->slider_3, SLOT(setValue(int)));

    connect(ui->slider_1, SIGNAL(valueChanged(int)), ui->counter_1, SLOT(setValue(int)));
    connect(ui->slider_2, SIGNAL(valueChanged(int)), ui->counter_2, SLOT(setValue(int)));
    connect(ui->slider_3, SIGNAL(valueChanged(int)), ui->counter_3, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_slider_1_valueChanged(int value)
{
    m_pal.setColor(QPalette::Window, QColor(value,ui->slider_2->value(),ui->slider_3->value()));
    ui->color_widget->setPalette(m_pal);
    ui->color_widget->setAutoFillBackground(true);
}

void MainWindow::on_slider_2_valueChanged(int value)
{
    m_pal.setColor(QPalette::Window, QColor(ui->slider_1->value(),value,ui->slider_3->value()));
    ui->color_widget->setPalette(m_pal);
    ui->color_widget->setAutoFillBackground(true);
}

void MainWindow::on_slider_3_valueChanged(int value)
{
    m_pal.setColor(QPalette::Window, QColor(ui->slider_1->value(),ui->slider_2->value(),value));
    ui->color_widget->setPalette(m_pal);
    ui->color_widget->setAutoFillBackground(true);
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");

    if (!fileName.isEmpty())
    {
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle("Просмотр файла");

        QTextEdit *textEdit = new QTextEdit(dialog);
        textEdit->setGeometry(10, 10, 500, 400);

        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            QString fileContents = in.readAll();

            file.close();

            textEdit->setPlainText(fileContents);

            dialog->exec();
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
            delete dialog; // Удаляем диалоговое окно, если не удалось открыть файл
        }
    }
}
