#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "KeyManager.h"
#include "KeyManagerFactory.h"
#include "constants.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    KeyManager *_keyManager;
};

#endif // MAINWINDOW_H
