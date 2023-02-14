#include "buttonswidget.h"
ButtonsWidget::ButtonsWidget(QWidget *parent)
    : QWidget{parent}
{
}

ButtonsWidget::~ButtonsWidget()
{
    clearWidget();
}

void ButtonsWidget::clearWidget()
{
    if (hbtnsLayout != nullptr)
    {
        QLayoutItem *wItem;
        while ((wItem = hbtnsLayout->takeAt(0)) != 0)
        {
            if (wItem->widget())
                wItem->widget()->setParent(NULL);
            delete wItem;
        }

        delete hbtnsLayout;
    }
    widgetButtonsArray.clear();
    int size = static_cast<int>(buttonsWidgetIds::buttonsCnt);
    widgetButtonsArray.reserve(size);
    widgetButtonsArray.fill(nullptr, size);
    hbtnsLayout = new QHBoxLayout(this);
}

void ButtonsWidget::showBtn(buttonsWidgetIds btnId)
{
    if (hbtnsLayout == nullptr)
    {
        clearWidget();
    }

    if (hbtnsLayout != nullptr)
    {
        int intBtnId = static_cast<int>(btnId);

        if(widgetButtonsArray.at(intBtnId) == nullptr)
        {
            QPushButton * btn =  new QPushButton("Кнопка "+QString::number(intBtnId+1),this);
            widgetButtonsArray.insert(intBtnId,btn);
            hbtnsLayout->addWidget(btn);
        }
    }
}


