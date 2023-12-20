#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>

class TextWidget : public QWidget {
public:
    TextWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // TEXTWIDGET_H
