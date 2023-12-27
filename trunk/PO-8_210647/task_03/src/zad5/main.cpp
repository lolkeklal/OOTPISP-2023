#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QMap>
#include <QStringList>
#include <QInputDialog>
#include <QRegularExpression>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("Анализ поставок марок машин");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QStringList carsList = {"Audi", "BMW", "Peugeuot"}; // Вaши марки машин

    QLabel *titleLabel = new QLabel("Марки машин:");
    layout->addWidget(titleLabel);

    for (const auto &car : carsList) {
        QLabel *carLabel = new QLabel(car);
        layout->addWidget(carLabel);
    }

    QPushButton *analyzeButton = new QPushButton("Анализ");
    layout->addWidget(analyzeButton);

    QObject::connect(analyzeButton, &QPushButton::clicked, [&]() {
        QMap<QString, QStringList> carShipments;
        for (const auto &car : carsList) {
            QString prompt = "Для машины " + car + ", выберите 1 - доставлена во все страны, 2 - доставлена в некоторые страны, 3 - не доставлена ни в одну страну.";
            QString result = QInputDialog::getItem(&window, "Выбор", prompt, QStringList() << "1" << "2" << "3");
            if (result == "1") {
                carShipments[car] << "Доставлена во все страны";
            } else if (result == "2") {
                carShipments[car] << "Доставлена в некоторые страны";
            } else if (result == "3") {
                carShipments[car] << "Не доставлена ни в одну страну";
            }
        }

        QMessageBox msgBox;
        QString output;
        for (auto it = carShipments.constBegin(); it != carShipments.constEnd(); ++it) {
            output += "Марка: " + it.key() + ", Статус: " + it.value().join(", ") + "\n";
        }
        msgBox.setText(output);
        msgBox.exec();
    });

    window.setLayout(layout);
    window.show();
    return a.exec();
}
