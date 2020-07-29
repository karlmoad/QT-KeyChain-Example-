#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _keyManager = KeyManagerFactory::getDefault(CApp::APPLICATION_ID);

    connect(ui->btnSave, &QPushButton::clicked, [this](){
        _keyManager->setPassword("John.Jabod@jingleheirmer.com",ui->txtPassword->text());
        ui->lblInfo->setText("Password Saved.");
    });
    connect(ui->btnClear, &QPushButton::clicked, [this](){
        ui->lblInfo->setText(QString());
        ui->txtPassword->setText(QString());
    });
    connect(ui->btnLoad, &QPushButton::clicked, [this](){
        ui->txtPassword->setText(_keyManager->getPassword("John.Jabod@jingleheirmer.com"));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
