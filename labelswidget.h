#ifndef LABELSWIDGET_H
#define LABELSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

enum class labelsWidgetIds
{
    label1 = 0,
    label2,
    label3,
    label4,
    label5,
    label6,
    labelsCnt,
};
class LabelsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LabelsWidget(QWidget *parent = nullptr);

    ~LabelsWidget();

    void clearWidget();
    void showLbl(labelsWidgetIds lblId);

private:
    QHBoxLayout *hlblsLayout = nullptr;
    QVector<QLabel*> widgetLablesArray;
};

#endif // LABELSWIDGET_H
