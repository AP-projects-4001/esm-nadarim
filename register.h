#ifndef REGISTER_H
#define REGISTER_H

#include "mainwindow.h"
#include <QWidget>
#include <QString>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void WriteFile(QString username,QString name,QString password,int phone_num,QString address);
    int checkUsername(QString username);
private slots:
    void WriteInFile();

    void on_signup_btn_reg_clicked();

    void on_login_btn_reg_clicked();

private:
    Ui::Register *ui;
    QMainWindow *login;
};

#endif // REGISTER_H
