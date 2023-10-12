#include "textedit.h"

TextEdit::TextEdit(QWidget *widget)
{
    this->widget = widget;
}

void TextEdit::openFile() {
    QString path = QFileDialog::getOpenFileName(this->widget, "Open...", "", "*.txt");
    if (!path.isEmpty()) {
        QFile file(path);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream input(&file);
            this->setText(input.readAll());
            file.close();
        }
    }
}
