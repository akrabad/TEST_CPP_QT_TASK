#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLineEdit>
#include <QPushButton>
#include <QFrame>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QMutex>
#include <QDialog>
#include <QTimer>
#include "user.h"
#include "buttonswidget.h"
#include "labelswidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void reloadWidgets();

    QFrame * centralWidget = nullptr;
    QLineEdit* passwordField = nullptr;
    QPushButton* loginButton = nullptr;

    QPushButton* newWindowButton = nullptr;

    QVBoxLayout *vloginLayout = nullptr;

    QMutex userMutex;
    QSharedPointer<User> currentUser;

    ButtonsWidget* btnsWgt = nullptr;
    LabelsWidget* lblsWgt = nullptr;

private slots:
    void onloginButtonClick();
    void onnewWindowButtonClick();
    void setCurrentUser(QSharedPointer<User> usr);
};
#endif // MAINWINDOW_H
