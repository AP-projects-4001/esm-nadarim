#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <register.h>
#include "admin.h"
#include "client.h"
#include "customer.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void searchFile();
    ~MainWindow();

private slots:
    void on_login_btn_clicked();
    void on_signup_btn_clicked();

    void on_forgetpass_btn_clicked();

    void on_checkBox_pass_clicked();

private:
    Ui::MainWindow *ui;
    Customer *customer;

};
#endif // MAINWINDOW_H
