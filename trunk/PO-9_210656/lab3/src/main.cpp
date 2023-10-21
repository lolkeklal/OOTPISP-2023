#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QAbstractButton>
#include <QMessageBox>
#include <QLabel>
#include <QTableWidget>
#include <QComboBox>
#include <QModelIndex>
#include <QButtonGroup>
#include <QRadioButton>
#include <QStack>
#include <QQueue>
#include <QFileDialog>
#include <QPlainTextEdit>
#include <QSplitter>

#include <iostream>

void task1(){
    //Вариант 7 Из трех данных чисел выбрать наименьшее и наибольшее (числа вводятся в lineedit), и заменить третье число иx разностью (число должно быть изменено в текущем lineedit).
    QWidget *w = new QWidget;

    QVBoxLayout* mainLayout = new QVBoxLayout(w);

    QLineEdit *lineEdit = new QLineEdit;
    QPushButton *button = new QPushButton("&Подтвердить");

    mainLayout->addWidget(new QLabel("Введите три числа"), 0, Qt::AlignCenter);
    mainLayout->addWidget(lineEdit);
    mainLayout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [=]{
        auto values = lineEdit->text().split(' ');
        int minI=0, maxI=0;
        for (int i = 0; i < 3; i++){
            if (values[minI].toInt() > values[i].toInt())
                minI = i;
            if (values[maxI].toInt() <= values[i].toInt())
                maxI = i;
        }
        int MAX = std::max(std::max(values[0].toInt(), values[1].toInt()), values[2].toInt());
        int MIN = std::min(std::min(values[0].toInt(), values[1].toInt()), values[2].toInt());
        values[3-minI-maxI] = QString("%1").arg((values[maxI].toInt() - values[minI].toInt()));
        lineEdit->setText(QString("%1 %2 %3").arg(values[0]).arg(values[1]).arg(values[2]));
    });

    w->show();
}

void task2(){
    //Вариант 2
    //Дан массив размера N. Вывести вначале его элементы с четными индексами, а затем − с нечетными.
    //Дана матрица размера m x n. Найти суммы элементов всех ее четных и нечетных столбцов (нахождение суммы четных/нечетных столбцов определяется пользователем в виджете comboBox).
    QWidget *w = new QWidget;

    QVBoxLayout* mainLayout = new QVBoxLayout(w);
    QHBoxLayout* sizeLayout = new QHBoxLayout();
    QHBoxLayout* tableLayout = new QHBoxLayout();
    QVBoxLayout* dataLayout = new QVBoxLayout();

    QPushButton* button = new QPushButton("&Перегенерировать");
    QLineEdit *heightEdit = new QLineEdit();
    QLineEdit *widthEdit = new QLineEdit();
    heightEdit->setPlaceholderText("Введите высоту");
    widthEdit->setPlaceholderText("Введите ширину");

    QTableWidget *table = new QTableWidget(10, 10);
    int *height = new int, *width = new int;
    for (int i = 0; i < 10; ++i)
        table->setColumnWidth(i, 30);

    QComboBox* CB = new QComboBox;
    CB->addItems({"Четные", "Нечетные"});
    QLabel *infoLabel = new QLabel;

    sizeLayout->addWidget(heightEdit);
    sizeLayout->addWidget(widthEdit);

    dataLayout->addWidget(CB);
    dataLayout->addWidget(infoLabel);

    tableLayout->addWidget(table);
    tableLayout->addLayout(dataLayout);

    mainLayout->addLayout(sizeLayout);
    mainLayout->addWidget(button);
    mainLayout->addLayout(tableLayout);

    QObject::connect(button, &QPushButton::clicked, [=]{
        *height = heightEdit->text().toInt();
        *width = widthEdit->text().toInt();
        table->setRowCount(*height);
        table->setColumnCount(*width);
        for (int i = 0; i < *height; ++i) {
            for (int j = 0; j < *width; ++j) {
                table->setColumnWidth(j, 30);
                int randomNumber = rand() % 100;
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(randomNumber));
                table->setItem(i, j, item);
            }
        }
    });

    QObject::connect(CB, &QComboBox::currentIndexChanged, [=](int index){
        int sum = 0;
        for (int i = 0; i < *height; ++i){
            for (int j = index; j < *width; j+=2){
                auto index = table->model()->index(i, j);
                auto value = table->model()->data(index).toInt();
                sum += value;
            }
        }
        infoLabel->setText(QString("%1 %2").arg(CB->currentText()).arg(sum));
    });

    w->show();
}

void task3(){
    //Вариант 2
    //Заполнить список случайными элементами. Реализовать добавление элемента в конец списка и удаления с начала (использовать RadioButton для выбора действия).
    //Создать два связных списка. Реализовать замену одного связного списка на другой.
    QWidget *w = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(w);
    QHBoxLayout *list1Layout = new QHBoxLayout();
    QHBoxLayout *list2Layout = new QHBoxLayout();
    QHBoxLayout *radioButtonsLayout = new QHBoxLayout;
    QHBoxLayout *submitLayout = new QHBoxLayout;
    QHBoxLayout *cloneLayout = new QHBoxLayout;

    QLabel *list1 = new QLabel, *list2 = new QLabel;

    QRadioButton *headButton = new QRadioButton("В начало"),
                 *tailButton = new QRadioButton("В конец");
    QButtonGroup *radioGroup = new QButtonGroup(w);
    radioGroup->addButton(headButton);
    radioGroup->addButton(tailButton);


    QPushButton *addButton = new QPushButton("Добавить");
    QLineEdit *valueLine = new QLineEdit;

    QPushButton *cloneButton = new QPushButton("Дублировать");
    QComboBox *CB = new QComboBox;
    CB->addItems({"Первый", "Второй"});

    list1Layout->addWidget(new QLabel("1 список: "));
    list1Layout->addWidget(list1);
    list2Layout->addWidget(new QLabel("2 список: "));
    list2Layout->addWidget(list2);

    radioButtonsLayout->addWidget(headButton);
    radioButtonsLayout->addWidget(tailButton);

    cloneLayout->addWidget(CB);
    cloneLayout->addWidget(cloneButton);

    submitLayout->addWidget(valueLine);
    submitLayout->addWidget(addButton);

    mainLayout->addWidget(new QLabel("Списки"), 0, Qt::AlignCenter);
    mainLayout->addLayout(list1Layout);
    mainLayout->addLayout(list2Layout);
    mainLayout->addLayout(radioButtonsLayout);
    mainLayout->addLayout(submitLayout);
    mainLayout->addLayout(cloneLayout);

    QList<QString> *listValues = new QList<QString>[2];

    QObject::connect(addButton, &QPushButton::clicked, [=] {
        int toogleList = CB->currentIndex();
        QString value = valueLine->text();
        if (radioGroup->checkedButton() == headButton) {
            listValues[toogleList].prepend(value);
        } else {
            listValues[toogleList].append(value);
        }

        if (toogleList == 0) {
            list1->setText(listValues[0].join(" "));
        } else {
            list2->setText(listValues[1].join(" "));
        }
    });

    QObject::connect(cloneButton, &QPushButton::clicked, [=]{
        int toogleList = CB->currentIndex();
        listValues[(toogleList+1)%2].clear();
        for (auto elem : listValues[toogleList]){
            listValues[(toogleList+1)%2].append(elem);
        }

        if (toogleList == 0) {
            list2->setText(listValues[0].join(" "));
        } else {
            list1->setText(listValues[1].join(" "));
        }
    });

    w->show();
}

void task4(){
    //Вариант 2
    //Сформировать стек из 10 случайных целых чисел. Заменить в стеке все положительные значения на 1, а отрицательные - на -1.
    //Сформировать очередь из 10 чисел. Увеличить все значения в очереди на ее максимальный элемент. Результат поместить в очередь.
    QWidget *w = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(w);

    QLabel *stackValues = new QLabel[2];
    QLabel *queryValues = new QLabel[2];

    QPushButton *generateStack = new QPushButton("Перегенерировать стек"),
                *genereteQuery = new QPushButton("Перегенерировать очередь");

    QHBoxLayout *fields = new QHBoxLayout;

    QVBoxLayout *labels = new QVBoxLayout;
    QVBoxLayout *values = new QVBoxLayout;
    QVBoxLayout *buttons = new QVBoxLayout;

    buttons->addWidget(generateStack);
    buttons->addWidget(genereteQuery);

    values->addWidget(&stackValues[0]);
    values->addWidget(&stackValues[1]);
    values->addWidget(&queryValues[0]);
    values->addWidget(&queryValues[1]);

    labels->addWidget(new QLabel("Исходный стек"));
    labels->addWidget(new QLabel("Модифицированный стек"));
    labels->addWidget(new QLabel("Исходная очередь"));
    labels->addWidget(new QLabel("Модифицированная очередь"));

    fields->addLayout(labels);
    fields->addLayout(values);
    fields->addLayout(buttons);

    mainLayout->addWidget(new QLabel("Стек и очередь"), 0, Qt::AlignCenter);
    mainLayout->addLayout(fields);

    QStack<QString> *st = new QStack<QString>;
    QStack<QString> *st2 = new QStack<QString>;
    QQueue<QString> *q = new QQueue<QString>;
    QQueue<QString> *q2 = new QQueue<QString>;

    QObject::connect(generateStack, &QPushButton::clicked, [=]{
        st->clear();
        st2->clear();
        for (int i = 0; i < 10; i++){
            int randomNumber = rand() % 100-50;
            st->push(QString("%1").arg(randomNumber));
        }
        stackValues[0].setText(st->join(" "));
        for (auto elem : *st){
            if (elem.toInt() > 0)
                st2->push("1");
            else if (elem.toInt() < 0)
                st2->push("-1");
            else
                st2->push("0");
            stackValues[1].setText(st2->join(' '));
        }
    });

    QObject::connect(genereteQuery, &QPushButton::clicked, [=]{
        q->clear();
        q2->clear();
        int MAX = 0;
        for (int i = 0; i < 10; i++){
            int randomNumber = rand() % 100-50;
            q->push_back(QString("%1").arg(randomNumber));
            MAX = std::max(MAX, randomNumber);
        }
        for (auto elem: *q){
            q2->push_back(QString("%1").arg(elem.toInt()+MAX));

        }
        queryValues[0].setText(q->join(' '));
        queryValues[1].setText(q2->join(' '));
    });

    w->show();
}

void task5(){
    //Вариант 2 Задан некоторый набор товаров. Определить для каждого товара, какие из них имеются в каждом из n магазинов, какие товары есть хотя бы в одном магазине, каких товаров нет ни в одном магазине.
    QWidget *w = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(w);

    QPlainTextEdit *text = new QPlainTextEdit;
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *adding = new QVBoxLayout;
    QComboBox* CB = new QComboBox;
    CB->addItems({"Магазин1", "Магазин2", "Магазин3", "Товары"});
    QLineEdit *productLine = new QLineEdit;
    QPushButton *submit = new QPushButton("Добавить");
    QPlainTextEdit *all = new QPlainTextEdit(""), *atLeast = new QPlainTextEdit, *noOne = new QPlainTextEdit;
    all->setReadOnly(true);
    atLeast->setReadOnly(true);
    noOne->setReadOnly(true);
    text->setReadOnly(true);
    QSplitter *splitter = new QSplitter(Qt::Vertical);

    splitter->addWidget(new QLabel("Продукты, находящиеся во всех магазинах"));
    splitter->addWidget(all);
    splitter->addWidget(new QLabel("Продукты, находящиеся хотя бы в одном магазине"));
    splitter->addWidget(atLeast);
    splitter->addWidget(new QLabel("Продукты, не находящиеся ни в одном магазине"));
    splitter->addWidget(noOne);

    adding->addWidget(CB);
    adding->addWidget(productLine);
    adding->addWidget(submit);
    adding->addWidget(new QLabel("Продукты"));
    adding->addWidget(text);

    layout->addLayout(adding);
    layout->addWidget(splitter);

    mainLayout->addWidget(new QLabel("Задание 5"), 0, Qt::AlignCenter);
    mainLayout->addLayout(layout);

    QVector <QString> *products = new QVector <QString>[4];
    QObject::connect(submit, &QPushButton::clicked, [=]{
        int index = CB->currentIndex();
        QString product = productLine->text();
        if (!products[index].contains(product)){
            products[index].push_back(product);
        }
        QVector <QString> allProducts, atLeastProducts, noOneProducts;
        int productsSize = products[3].size();
        for (auto currProduct: products[3]){
            int count = 0;
            for (int j = 0; j < 3; j++){
                if (products[j].contains(currProduct))
                    count++;

            }
            switch (count) {
            case 0:
                noOneProducts.push_back(currProduct);
                break;
            case 1:
            case 2:
                atLeastProducts.push_back(currProduct);
                break;
            case 3:
                allProducts.push_back(currProduct);
            default:
                break;
            }
        }
        all->setPlainText(allProducts.join('\n'));
        atLeast->setPlainText(atLeastProducts.join('\n'));
        noOne->setPlainText(noOneProducts.join('\n'));
        text->setPlainText(products[index].join('\n'));
    });

    QObject::connect(CB, &QComboBox::currentIndexChanged, [=](int index){
        text->setPlainText(products[index].join('\n'));
    });
    w->show();
}

void task6(){
    //Вариант 2 Дан файл f, компоненты которого являются целыми числами. Запишите в файл g наибольшее значение первых пяти компонентов файла f, затем - следующих пяти компонентов и т.д. Если в последней группе окажется менее пяти компонентов, то последний компонент файла g должен быть равен наибольшему из компонентов файла f, образующих последнюю (неполную) группу.
    QWidget *w = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(w);
    QPlainTextEdit *src = new QPlainTextEdit,
                   *dst = new QPlainTextEdit;

    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(src);
    splitter->addWidget(dst);

    QPushButton *submit = new QPushButton("Выбрать файл");

    mainLayout->addWidget(new QLabel("Файлы"), 0, Qt::AlignCenter);
    mainLayout->addWidget(splitter);
    mainLayout->addWidget(submit);

    QObject::connect(submit, &QPushButton::clicked, [=]{
        QVector <QString> result;
        QString fileName = QFileDialog::getOpenFileName(w, "Open document", QDir::currentPath(), "Text documents (*.txt)");
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(w, "Warning", "Can't open this file");
            return;
        }

        QTextStream in(&file);
        QVector <QString> values(in.readAll().split(" "));
        int len = values.size();
        for (int i = 0; i < len; i++){
            int max = -1e9;
            for (int j = 0; j < 5 && i < len; j++, i++)
                max = std::max(max, values[i].toInt());
            result.push_back(QString("%1").arg(max));
        }
        src->setPlainText(values.join(" "));
        dst->setPlainText(result.join(" "));
    });

    w->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *w = new QWidget;

    QVBoxLayout* mainLayout = new QVBoxLayout(w);
    QLineEdit *line = new QLineEdit;

    QPushButton *button = new QPushButton("&Подтвердить");

    mainLayout->addWidget(new QLabel("Введите номер задания"));
    mainLayout->addWidget(line);
    mainLayout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [=]{
        bool ok;
        int number = line->text().toInt(&ok);
        if (ok) {
            switch (number) {
            case 1:task1();break;
            case 2:task2();break;
            case 3:task3();break;
            case 4:task4();break;
            case 5:task5();break;
            case 6:task6();break;
            default:QMessageBox::warning(w, "Ошибка", "Введите корректный номер задания(1-6)");break;
            }
        } else {
            QMessageBox::warning(w, "Ошибка", "Введите корректный номер задания(1-6)");
        }
    });
    w->show();

    return a.exec();
}
