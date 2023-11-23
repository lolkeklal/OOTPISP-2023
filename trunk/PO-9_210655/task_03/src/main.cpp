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
#include <QInputDialog>
#include <QRadioButton>
#include <QStack>
#include <QQueue>
#include <QFileDialog>
#include <QPlainTextEdit>
#include <QSplitter>
#include <QListWidget>
#include <unordered_set>

#include <iostream>

void task1(){
    //Даны две переменные целого типа: A и B (переменные вводятся в lineedit). Если их значения не равны, то присвоить каждой переменной максимальное из этих значений, а если равны, то присвоить переменным нулевые значения.
    QWidget *w = new QWidget;

    QVBoxLayout* mainLayout = new QVBoxLayout(w);

    QLineEdit *lineEdit = new QLineEdit;
    QPushButton *button = new QPushButton("&Подтвердить");

    mainLayout->addWidget(new QLabel("Введите два числа"), 0, Qt::AlignCenter);
    mainLayout->addWidget(lineEdit);
    mainLayout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, w, [=]() {
        QString input = lineEdit->text();
        QStringList values = input.split(' ');

        if (values.size() != 2) {
            // Обработка ошибки: некорректное количество чисел
            QMessageBox::warning(w, "Ошибка", "Введите два числа, разделенных пробелом.");
            return;
        }

        int number1 = values[0].toInt();
        int number2 = values[1].toInt();

        if (number1 != number2) {
            int maximum = qMax(number1, number2);
            values[0] = QString::number(maximum);
            values[1] = QString::number(maximum);
        } else {
            values[0] = "0";
            values[1] = "0";
        }

        lineEdit->setText(values.join(" "));
    });

    w->show();
}

void task2()
{
    //Дано число k (0 < k < 11) и матрица размера m x n. Найти сумму и произведение элементов k-го столбца данной матрицы (нахождение суммы или произведения определяется пользователем в виджете comboBox).
    QWidget *widget = new QWidget;

    QVBoxLayout *mainLayout = new QVBoxLayout(widget);
    QHBoxLayout *sizeLayout = new QHBoxLayout();
    QHBoxLayout *tableLayout = new QHBoxLayout();
    QVBoxLayout *dataLayout = new QVBoxLayout();

    QPushButton *button = new QPushButton("Показать матрицу", widget);
    QLineEdit *kEdit = new QLineEdit();
    QLineEdit *rowsEdit = new QLineEdit();
    QLineEdit *columnsEdit = new QLineEdit();
    QComboBox *comboBox = new QComboBox();
    QLabel *outputLabel = new QLabel();
    QTableWidget *table = new QTableWidget();

    kEdit->setPlaceholderText("Введите число k (0 < k < 11)");
    rowsEdit->setPlaceholderText("Введите количество строк");
    columnsEdit->setPlaceholderText("Введите количество столбцов");
    comboBox->addItems({"Сумма", "Произведение"});

    sizeLayout->addWidget(kEdit);
    sizeLayout->addWidget(rowsEdit);
    sizeLayout->addWidget(columnsEdit);
    sizeLayout->addWidget(comboBox);
    sizeLayout->addWidget(button);

    dataLayout->addWidget(outputLabel);

    tableLayout->addWidget(table);

    mainLayout->addLayout(sizeLayout);
    mainLayout->addLayout(tableLayout);
    mainLayout->addLayout(dataLayout);

    QObject::connect(button, &QPushButton::clicked, [=]() {
        int k = kEdit->text().toInt();
        if (k < 1 || k > 10) {
            outputLabel->setText("Ошибка: некорректное значение k");
            return;
        }

        int rows = rowsEdit->text().toInt();
        int columns = columnsEdit->text().toInt();
        if (rows <= 0 || columns <= 0) {
            outputLabel->setText("Ошибка: некорректный размер матрицы");
            return;
        }

        table->clearContents();
        table->setRowCount(rows);
        table->setColumnCount(columns);

        // Заполнение матрицы случайными значениями
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int randomNumber = rand() % 100;
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(randomNumber));
                table->setItem(i, j, item);
            }
        }

        // Вычисление суммы или произведения элементов k-го столбца
        int sum = 0;
        long long product = 1;
        for (int i = 0; i < rows; ++i) {
            QTableWidgetItem *item = table->item(i, k - 1);
            if (item) {
                int value = item->text().toInt();
                sum += value;
                product *= value;
            }
        }

        // Отображение результата в виджете
        QString operation = comboBox->currentIndex() == 0 ? "Сумма" : "Произведение";
        outputLabel->setText(operation + " элементов " + QString::number(k) + "-го столбца: " +
                             (operation == "Сумма" ? QString::number(sum) : QString::number(product)));
    });

    widget->show();
}

QList<int> *listValues = new QList<int>[2];

void task3()
{
    //Заполнить список случайными элементами. Реализовать добавление элемента в конец списка и удаления с конца (использовать RadioButton для выбора действия).
    QWidget *w = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(w);
    QHBoxLayout *list1Layout = new QHBoxLayout();
    QHBoxLayout *list2Layout = new QHBoxLayout();
    QHBoxLayout *radioButtonsLayout = new QHBoxLayout;
    QHBoxLayout *submitLayout = new QHBoxLayout;
    QHBoxLayout *cloneLayout = new QHBoxLayout;

    QLabel *list1 = new QLabel, *list2 = new QLabel;

    QRadioButton *addButtonRadio = new QRadioButton("Добавить");
    QRadioButton *removeButtonRadio = new QRadioButton("Удалить");
    QButtonGroup *actionButtonGroup = new QButtonGroup(w);
    actionButtonGroup->addButton(addButtonRadio);
    actionButtonGroup->addButton(removeButtonRadio);

    QPushButton *actionButton = new QPushButton("Выполнить");
    QLineEdit *valueLine = new QLineEdit;

    QPushButton *cloneButton = new QPushButton("Дублировать");
    QComboBox *CB = new QComboBox;
    CB->addItems({"Первый", "Второй"});

    list1Layout->addWidget(new QLabel("1 список: "));
    list1Layout->addWidget(list1);
    list2Layout->addWidget(new QLabel("2 список: "));
    list2Layout->addWidget(list2);

    radioButtonsLayout->addWidget(addButtonRadio);
    radioButtonsLayout->addWidget(removeButtonRadio);

    cloneLayout->addWidget(CB);
    cloneLayout->addWidget(cloneButton);

    submitLayout->addWidget(valueLine);
    submitLayout->addWidget(actionButton);

    mainLayout->addWidget(new QLabel("Списки"), 0, Qt::AlignCenter);
    mainLayout->addLayout(list1Layout);
    mainLayout->addLayout(list2Layout);
    mainLayout->addLayout(radioButtonsLayout);
    mainLayout->addLayout(submitLayout);
    mainLayout->addLayout(cloneLayout);

    QObject::connect(actionButton, &QPushButton::clicked, [=]() {
        int toggleList = CB->currentIndex();
        int value = valueLine->text().toInt();
        if (addButtonRadio->isChecked()) {
            // Добавление элемента
            listValues[toggleList].push_back(value);
        } else if (removeButtonRadio->isChecked()) {
            // Удаление последнего символа в списке
            if (!listValues[toggleList].isEmpty()) {
                //int lastValue = listValues[toggleList].last();
                //lastValue.remove(lastValue.length() - 1, 1);
               // listValues[toggleList].replace(listValues[toggleList].size() - 1, lastValue);
                listValues[toggleList].pop_back();
            }
        }

        if (toggleList == 0) {
            QString result = "";
            // textEdit содержит строку, значит делаем строковую переменную, пока пустую
            for (int i = 0; i < listValues[0].size(); ++i) // Проходим по номерам всех элементов списка
            {
                int buff = listValues[0].at(i);
                result += QString::number(buff); // Добавляем в результирующую строку очередной элемент списка и перевод строки (чтобы каждый элемент с новой строки был)
            }
            list1->setText(result);
        } else {
            QString result2 = "";
            for (int j = 0; j < listValues[1].size(); ++j) // Проходим по номерам всех элементов списка
            {
                int buff2 = listValues[1].at(j);
                result2 += QString::number(buff2); // Добавляем в результирующую строку очередной элемент списка и перевод строки (чтобы каждый элемент с новой строки был)
            }
            list2->setText(result2);        }
    });

    QObject::connect(cloneButton, &QPushButton::clicked, [=]() {
        int toggleList = CB->currentIndex();
        listValues[(toggleList + 1) % 2] = listValues[toggleList];

        if (toggleList == 0) {
            QString result2 = "";
            for (int j = 0; j < listValues[1].size(); ++j) // Проходим по номерам всех элементов списка
            {
                int buff2 = listValues[1].at(j);
                result2 += QString::number(buff2); // Добавляем в результирующую строку очередной элемент списка и перевод строки (чтобы каждый элемент с новой строки был)
            }
            list2->setText(result2);
        } else {
            QString result = "";
            // textEdit содержит строку, значит делаем строковую переменную, пока пустую
            for (int i = 0; i < listValues[0].size(); ++i) // Проходим по номерам всех элементов списка
            {
                int buff = listValues[0].at(i);
                result += QString::number(buff); // Добавляем в результирующую строку очередной элемент списка и перевод строки (чтобы каждый элемент с новой строки был)
            }
            list1->setText(result);
        }
    });

    w->show();
}

void task4()
{
    //Заполнить стек 10 случайными числами из интервала [-10; 20]. Просмотреть содержимое стека. Найти сумму положительных чисел, хранящихся в стеке.
    //Сформировать очередь из 8 чисел. Записать в очередь модуль разности между двумя соседними элементами очереди.
    QWidget *w = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(w);

    QLabel *originalStackValues = new QLabel;
    QLabel *originalQueueValues = new QLabel;
    QLabel *modifiedQueueValues = new QLabel;
    QLabel *positiveSumLabel = new QLabel;

    QPushButton *generateStack = new QPushButton("Сгенерировать стек и очередь");

    QHBoxLayout *labelsLayout = new QHBoxLayout;
    labelsLayout->addWidget(new QLabel("Исходный стек"));
    labelsLayout->addWidget(new QLabel("Исходная очередь"));
    labelsLayout->addWidget(new QLabel("Модифицированная очередь"));

    QHBoxLayout *valuesLayout = new QHBoxLayout;
    valuesLayout->addWidget(originalStackValues);
    valuesLayout->addWidget(originalQueueValues);
    valuesLayout->addWidget(modifiedQueueValues);

    mainLayout->addLayout(labelsLayout);
    mainLayout->addLayout(valuesLayout);
    mainLayout->addWidget(generateStack);
    mainLayout->addWidget(positiveSumLabel);

    QObject::connect(generateStack, &QPushButton::clicked, [=]() {
        QStack<int> originalStack;
        QQueue<int> originalQueue;
        QStack<int> modifiedStack;
        QQueue<int> modifiedQueue;

        srand(time(nullptr));
        for (int i = 0; i < 10; ++i) {
            int randomNumber = rand() % 31 - 10;
            originalStack.push(randomNumber);
        }

        // Просмотр содержимого исходного стека
        QString originalStackContent;
        for (int i = 0; i < originalStack.size(); ++i) {
            originalStackContent += QString::number(originalStack[i]);
            if (i != originalStack.size() - 1)
                originalStackContent += ' ';
        }
        originalStackValues->setText(originalStackContent);

        // Нахождение суммы положительных чисел в исходном стеке
        int positiveSum = 0;
        for (int i = 0; i < originalStack.size(); ++i) {
            if (originalStack[i] > 0)
                positiveSum += originalStack[i];
        }
        positiveSumLabel->setText("Сумма положительных чисел стека: " + QString::number(positiveSum));

        // Формирование исходной очереди из 7 чисел
        for (int i = 0; i < 8; ++i) {
            int randomNumber = rand() % 31 - 10;
            originalQueue.enqueue(randomNumber);
        }

        for (int i = 0; i < 7; ++i) {
            int diff = std::abs(originalQueue[i] - originalQueue[i + 1]);
            modifiedQueue.enqueue(diff);
         }

        // Вывод содержимого исходной очереди
        QString originalQueueContent;
        while (!originalQueue.isEmpty()) {
            originalQueueContent += QString::number(originalQueue.dequeue());
            if (!originalQueue.isEmpty())
                originalQueueContent += ' ';
        }
        originalQueueValues->setText(originalQueueContent);

        // Вывод содержимого модифицированной очереди
        QString modifiedQueueContent;
        while (!modifiedQueue.isEmpty()) {
            modifiedQueueContent += QString::number(modifiedQueue.dequeue());
            if (!modifiedQueue.isEmpty())
                modifiedQueueContent += ' ';
        }
        modifiedQueueValues->setText(modifiedQueueContent);
    });

    w->show();
}

QSet<QString> student1Set;
QSet<QString> student2Set;
QSet<QString> student3Set;
QSet<QString> student4Set;
QSet<QString> student5Set;

void task5()
{
    //Имеется список класса (все имена различны). Определить, есть ли в классе человек, который побывал в гостях у всех. (Для каждого ученика составить множество побывавших у него в гостях друзей, сам ученик в это множество не входит.)
    QWidget *w = new QWidget;

    QStringList students = {"Ученик 1", "Ученик 2", "Ученик 3", "Ученик 4", "Ученик 5"};

    // Создаем выпадающие списки для выбора учеников
    QComboBox* student1ComboBox = new QComboBox;
    QComboBox* student2ComboBox = new QComboBox;

    // Заполняем выпадающие списки учениками
    student1ComboBox->addItems(students);
    student2ComboBox->addItems(students);

    // Создаем кнопку "Добавить"
    QPushButton* addButton = new QPushButton("Добавить");
    QPushButton* fullButton = new QPushButton("Проверить");

    // Создаем вертикальный и горизонтальный layout'ы
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* comboBoxLayout = new QHBoxLayout;
    QLabel *window1 = new QLabel("Ученик 1 был в гостях у: ");
    QLabel *window2 = new QLabel("Ученик 2 был в гостях у: ");
    QLabel *window3 = new QLabel("Ученик 3 был в гостях у: ");
    QLabel *window4 = new QLabel("Ученик 4 был в гостях у: ");
    QLabel *window5 = new QLabel("Ученик 5 был в гостях у: ");


    // Добавляем выпадающие списки и кнопку в горизонтальный layout
    comboBoxLayout->addWidget(student1ComboBox);
    comboBoxLayout->addWidget(student2ComboBox);
    comboBoxLayout->addWidget(addButton);

    // Устанавливаем горизонтальный layout в вертикальный
    mainLayout->addLayout(comboBoxLayout);
    mainLayout->addLayout(comboBoxLayout);
    mainLayout->addWidget(window1);
    mainLayout->addWidget(window2);
    mainLayout->addWidget(window3);
    mainLayout->addWidget(window4);
    mainLayout->addWidget(window5);

    comboBoxLayout->addWidget(fullButton);

    w->setLayout(mainLayout);

    QObject::connect(fullButton, &QPushButton::clicked, w, [=]() {

         if(student1Set.size() == 4){
             QMessageBox::warning(w, "Уведомление", "Ученик 1 был у всех в гостях!");
         } else if(student2Set.size() == 4){
             QMessageBox::warning(w, "Уведомление", "Ученик 2 был у всех в гостях!");
         }else if(student3Set.size() == 4){
             QMessageBox::warning(w, "Уведомление", "Ученик 3 был у всех в гостях!!");
         }else if(student4Set.size() == 4){
             QMessageBox::warning(w, "Уведомление", "Ученик 4 был у всех в гостях!");
         }else if(student5Set.size() == 4){
             QMessageBox::warning(w, "Уведомление", "Ученик 5 был у всех в гостях!");
         } else {
             QMessageBox::warning(w, "Уведомление", "Ни один из учеников не был у всех в гостях!");
         }
    });
    QObject::connect(addButton, &QPushButton::clicked, w, [=]() {


        switch (student1ComboBox->currentIndex()) {
        case 0:
            if (student1Set.size() < 4) {
                QString student = student2ComboBox->currentText();

                if(student2ComboBox->currentText() == student1ComboBox->currentText()){
                    QMessageBox::warning(w, "Ошибка", "Ученик не может побывать сам у себя в гостях!");break;
                }

                if (!student1Set.contains(student)) {
                    window1->setText(window1->text() + student + " ");
                    student1Set.insert(student);
                }else{
                    QMessageBox::warning(w, "Ошибка", "Ученик уже побывал в гостях у " + student);break;
                }
            }
            break;
        case 1:
            if (student2Set.size() < 4) {
                QString student = student2ComboBox->currentText();

                if(student2ComboBox->currentText() == student1ComboBox->currentText()){
                    QMessageBox::warning(w, "Ошибка", "Ученик не может побывать сам у себя в гостях!");break;
                }

                if (!student2Set.contains(student)) {
                    window2->setText(window2->text() + student + " ");
                    student2Set.insert(student);
                }else{
                    QMessageBox::warning(w, "Ошибка", "Ученик уже побывал в гостях у " + student);break;
                }
            }
            break;
        case 2:
            if (student3Set.size() < 4) {
                QString student = student2ComboBox->currentText();

                if(student2ComboBox->currentText() == student1ComboBox->currentText()){
                    QMessageBox::warning(w, "Ошибка", "Ученик не может побывать сам у себя в гостях!");break;
                }

                if (!student3Set.contains(student)) {
                    window3->setText(window3->text() + student + " ");
                    student3Set.insert(student);
                }else{
                    QMessageBox::warning(w, "Ошибка", "Ученик уже побывал в гостях у " + student);break;
                }
            }
            break;
        case 3:
            if (student4Set.size() < 4) {
                QString student = student2ComboBox->currentText();

                if(student2ComboBox->currentText() == student1ComboBox->currentText()){
                    QMessageBox::warning(w, "Ошибка", "Ученик не может побывать сам у себя в гостях!");break;
                }

                if (!student4Set.contains(student)) {
                    window4->setText(window4->text() + student + " ");
                    student4Set.insert(student);
                }else{
                    QMessageBox::warning(w, "Ошибка", "Ученик уже побывал в гостях у " + student);break;
                }
            }
            break;
        case 4:
            if (student5Set.size() < 4) {
                QString student = student2ComboBox->currentText();

                if(student2ComboBox->currentText() == student1ComboBox->currentText()){
                    QMessageBox::warning(w, "Ошибка", "Ученик не может побывать сам у себя в гостях!");break;
                }

                if (!student5Set.contains(student)) {
                    window5->setText(window5->text() + student + " ");
                    student5Set.insert(student);
                }else{
                    QMessageBox::warning(w, "Ошибка", "Ученик уже побывал в гостях у " + student);break;
                }
            }
            break;
        }

    });
    w->show();

}

void task6(){
    /*Дан файл f, компоненты которого являются действительными числами. Найдите:
    а) наибольший компонент;
    б) наименьший компонент с четным номером;
    в) наибольший модуль компонента с нечётным номером;
    г) разность первого и последнего компонента файла.
    */
    QWidget *w = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(w);
    QPlainTextEdit *src = new QPlainTextEdit;
    QLabel *window1 = new QLabel("Наибольший компонент: ");
    QLabel *window2 = new QLabel("Наименьший компонент с четным номером: ");
    QLabel *window3 = new QLabel("Наибольший модуль компонента с нечётным номером: ");
    QLabel *window4 = new QLabel("Разность первого и последнего компонента файла: ");
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(src);

    QPushButton *submit = new QPushButton("Выбрать файл");

    mainLayout->addWidget(new QLabel("Файл"), 0, Qt::AlignCenter);
    mainLayout->addWidget(splitter);
    mainLayout->addWidget(submit);
    mainLayout->addWidget(window1);
    mainLayout->addWidget(window2);
    mainLayout->addWidget(window3);
    mainLayout->addWidget(window4);

    // Функция для нахождения наибольшего компонента
    auto findMaxComponent = [](const QVector<double>& components) -> double {
        double maxComponent = -std::numeric_limits<double>::infinity();
        for (double component : components) {
            maxComponent = std::max(maxComponent, component);
        }
        return maxComponent;
    };

    // Функция для нахождения наименьшего компонента с четным номером
    auto findMinEvenComponent = [](const QVector<double>& components) -> double {
        double minEvenComponent = std::numeric_limits<double>::infinity();
        for (int i = 1; i < components.size(); i += 2) {
            if (components[i] < minEvenComponent) {
                minEvenComponent = components[i];
            }
        }
        return minEvenComponent;
    };

    // Функция для нахождения наибольшего модуля компонента с нечётным номером
    auto findMaxAbsoluteOddComponent = [](const QVector<double>& components) -> double {
        double maxAbsoluteOddComponent = 0.0;
        for (int i = 0; i < components.size(); i += 2) {
            if (std::abs(components[i]) > maxAbsoluteOddComponent) {
                maxAbsoluteOddComponent = std::abs(components[i]);
            }
        }
        return maxAbsoluteOddComponent;
    };

    // Функция для нахождения разности первого и последнего компонента файла
    auto findDifference = [](const QVector<double>& components) -> double {
        if (components.isEmpty()) {
            return 0.0;
        }
        return components.first() - components.last();
    };

    QObject::connect(submit, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getOpenFileName(w, "Open document", QDir::currentPath(), "Text documents (*.txt)");
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(w, "Warning", "Can't open this file");
            return;
        }

        QTextStream in(&file);
        QVector<QString> values(in.readAll().split(" "));
        QVector<double> components;
        for (const QString& value : values) {
            bool conversionOk;
            double component = value.toDouble(&conversionOk);
            if (conversionOk) {
                components.append(component);
            }
        }

        // Вычисление результатов
        double maxComponent = findMaxComponent(components);
        double minEvenComponent = findMinEvenComponent(components);
        double maxAbsoluteOddComponent = findMaxAbsoluteOddComponent(components);
        double difference = findDifference(components);

        // Обновление текста в окнах
        window1->setText(QString("Наибольший компонент: %1").arg(maxComponent));
        window2->setText(QString("Наименьший компонент с четным номером: %1").arg(minEvenComponent));
        window3->setText(QString("Наибольший модуль компонента с нечётным номером: %1").arg(maxAbsoluteOddComponent));
        window4->setText(QString("Разность первого и последнего компонента файла: %1").arg(difference));

        src->setPlainText(values.join(" "));
    });

    w->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window = new QWidget;

    QVBoxLayout* mainLayout = new QVBoxLayout(window);
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
            default:QMessageBox::warning(window, "Ошибка", "Введите задание от 1 до 6)");break;
            }
        } else {
            QMessageBox::warning(window, "Ошибка", "Введите задание от 1 до 6");
        }
    });
    window->show();

    return a.exec();
}
