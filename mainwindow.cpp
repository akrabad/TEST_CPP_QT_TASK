#include "mainwindow.h"
#include "loginthread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QFrame(this);

    this->setCentralWidget(centralWidget);

    QSpacerItem*  spacer_top = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem*  spacer_bottom = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding);

    vloginLayout = new QVBoxLayout(centralWidget);

    passwordField = new QLineEdit(this);
    passwordField->setPlaceholderText("Введите пароль");
    loginButton = new QPushButton("Войти",this);


    vloginLayout->addItem(spacer_top);
    vloginLayout->addWidget(passwordField);
    vloginLayout->addWidget(loginButton);
    vloginLayout->addItem(spacer_bottom);

    connect(loginButton,SIGNAL(clicked()),this,SLOT(onloginButtonClick()));


    btnsWgt = new ButtonsWidget(this);
    vloginLayout->addWidget(btnsWgt);
    lblsWgt = new LabelsWidget(this);
    lblsWgt->hide();

    newWindowButton = new QPushButton("Новое окно",this);
    connect(newWindowButton,SIGNAL(clicked()),this,SLOT(onnewWindowButtonClick()));
    newWindowButton->hide();

    vloginLayout->addWidget(newWindowButton);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onloginButtonClick()
{
    if(loginButton->isEnabled() && passwordField->text() != "")
    {
        loginButton->setEnabled(false);
    }
    else
    {
        return;
    }

    QTimer* btnUnlockTmr= new QTimer(this);
    btnUnlockTmr->setSingleShot(true);
    connect(btnUnlockTmr, &QTimer::timeout, [this](){loginButton->setEnabled(true);});

    LoginThread* logTh = new LoginThread(passwordField->text());
    connect(logTh, SIGNAL(finished()), logTh, SLOT(deleteLater()));
    connect(logTh, SIGNAL(moveNewUser(QSharedPointer<User>)), this, SLOT(setCurrentUser(QSharedPointer<User>)));

    btnUnlockTmr->start(3000);
    logTh->start();

}

void MainWindow::onnewWindowButtonClick()
{
    newWindowButton->setEnabled(false);
    QDialog* dlgwindow = new QDialog(this);
    dlgwindow->setWindowTitle("Новое окно");

    QGridLayout *gridLayout = new QGridLayout(dlgwindow);
    gridLayout->addWidget(lblsWgt);
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);

    dlgwindow->setLayout(gridLayout);
    lblsWgt->show();
    dlgwindow->show();

    connect(dlgwindow,&QDialog::finished,[this](){ newWindowButton->setEnabled(true);lblsWgt->hide();});


}


void MainWindow::setCurrentUser(QSharedPointer<User> usr)
{
    loginButton->setEnabled(true);
    if(usr.isNull())
    {
        return;
    }
    QMutexLocker locker(&userMutex);

    bool buttonsReload = true;

    if (!currentUser.isNull())
    {
        if(currentUser->getUserLevel() == usr->getUserLevel()){buttonsReload = false;}
    }
    currentUser = usr;

    if(buttonsReload)
    {
        reloadWidgets();
    }
    newWindowButton->show();


}


void MainWindow::reloadWidgets()
{
    btnsWgt->clearWidget();
    lblsWgt->clearWidget();

    if(currentUser->getUserLevel() >= USER_LEVEL::OPERATOR)
    {
        btnsWgt->showBtn(buttonsWidgetIds::button1);
        btnsWgt->showBtn(buttonsWidgetIds::button2);

        lblsWgt->showLbl(labelsWidgetIds::label1);
        lblsWgt->showLbl(labelsWidgetIds::label2);
    }

    if(currentUser->getUserLevel() >= USER_LEVEL::TECHNIC)
    {
        btnsWgt->showBtn(buttonsWidgetIds::button3);
        btnsWgt->showBtn(buttonsWidgetIds::button4);

        lblsWgt->showLbl(labelsWidgetIds::label3);
        lblsWgt->showLbl(labelsWidgetIds::label4);
    }

    if(currentUser->getUserLevel() == USER_LEVEL::ENGINEER)
    {
        btnsWgt->showBtn(buttonsWidgetIds::button5);
        btnsWgt->showBtn(buttonsWidgetIds::button6);

        lblsWgt->showLbl(labelsWidgetIds::label5);
        lblsWgt->showLbl(labelsWidgetIds::label6);
    }
}
