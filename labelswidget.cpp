#include "labelswidget.h"

LabelsWidget::LabelsWidget(QWidget *parent)
    : QWidget{parent}
{

}

LabelsWidget::~LabelsWidget()
{
    clearWidget();
}

void LabelsWidget::clearWidget()
{
    if (hlblsLayout != nullptr)
    {
        QLayoutItem *wItem;
        while ((wItem = hlblsLayout->takeAt(0)) != 0)
        {
            if (wItem->widget())
                wItem->widget()->setParent(NULL);
            delete wItem;
        }

        delete hlblsLayout;
    }
    widgetLablesArray.clear();
    int size = static_cast<int>(labelsWidgetIds::labelsCnt);
    widgetLablesArray.reserve(size);
    widgetLablesArray.fill(nullptr, size);
    hlblsLayout = new QHBoxLayout(this);
}

void LabelsWidget::showLbl(labelsWidgetIds lblId)
{
    if (hlblsLayout == nullptr)
    {
        clearWidget();
    }

    if (hlblsLayout != nullptr)
    {
        int intLblId = static_cast<int>(lblId);

        if(widgetLablesArray.at(intLblId) == nullptr)
        {
            QLabel * lbl =  new QLabel("Текст "+QString::number(intLblId+1),this);
            widgetLablesArray.insert(intLblId,lbl);
            hlblsLayout->addWidget(lbl);
        }
    }
}
