#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class ForgetPassword;
}

class ForgetPassword : public QWidget
{
    Q_OBJECT

public:
    explicit ForgetPassword(QWidget *parent = nullptr);
    ~ForgetPassword();
    void check();

private slots:
    void on_confirm_btn_clicked();



    void on_back_btn_clicked();

private:
    Ui::ForgetPassword *ui;
    QMainWindow *login;
};

#endif // FORGETPASSWORD_H
