#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

enum class buttonsWidgetIds
{
    button1 = 0,
    button2,
    button3,
    button4,
    button5,
    button6,
    buttonsCnt,
};

class ButtonsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonsWidget(QWidget *parent = nullptr);
    ~ButtonsWidget();

    void clearWidget();
    void showBtn(buttonsWidgetIds btnId);


private:
    QHBoxLayout *hbtnsLayout = nullptr;
    QVector<QPushButton*> widgetButtonsArray;
};

#endif // BUTTONSWIDGET_H
