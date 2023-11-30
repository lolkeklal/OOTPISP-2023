// t4.cpp
#include "t4.h"
#include "ui_t4.h"
#include <QStack>
#include <QQueue>
#include <QRandomGenerator>
#include <algorithm>

t4::t4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::t4)
{
    ui->setupUi(this);
    setWindowTitle("t4");

    // Связываем слот с сигналом кнопки "Run"
    connect(ui->runButton, &QPushButton::clicked, this, &t4::onRunButtonClicked);

    // Инициализация при первом запуске
    onRunButtonClicked();
}

t4::~t4()
{
    delete ui;
}

template <typename Container>
QString t4::concatElements(const Container& container)
{
    QString result;
    for (const auto& element : qAsConst(container)) {
        result += QString::number(element) + " ";
    }
    return result.trimmed();
}

void t4::onRunButtonClicked()
{
    QStack<int> stack;
    QQueue<int> queue;

    // Заполняем стек случайными элементами
    for (int i = 0; i < 10; ++i) {
        stack.push(std::rand() % 100 - 50);  // Генерируем числа от -50 до 49
        queue.enqueue(std::rand() % 100 - 50);
    }

    // Заменяем положительные значения в стеке на 1, а отрицательные на -1
    std::transform(stack.begin(), stack.end(), stack.begin(),
                   [](int value) { return (value > 0) ? 1 : -1; });

    // Увеличиваем все значения в очереди на ее максимальный элемент
    int maxInQueue = *std::max_element(queue.begin(), queue.end());
    std::for_each(queue.begin(), queue.end(),
                  [maxInQueue](int& value) { value += maxInQueue; });

    // Отображаем результаты в текстовых виджетах
    ui->textEditStack->setText("Stack: " + concatElements(stack));
    ui->textEditQueue->setText("Queue: " + concatElements(queue));
}
