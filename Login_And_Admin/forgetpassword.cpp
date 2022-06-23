#include "forgetpassword.h"
#include "editprofile.h"
#include "qmessagebox.h"
#include "ui_forgetpassword.h"
#include "mainwindow.h"
#include <QFile>

ForgetPassword::ForgetPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgetPassword)
{
    ui->setupUi(this);
}

ForgetPassword::~ForgetPassword()
{
    delete ui;
    delete(login);
}

void ForgetPassword::check(){

    QString username=ui->user_line->text();
    QString password=ui->pass_line->text();
    QString newpassword=ui->newpass_line->text();
    QString confirm=ui->confirmpass_line->text();

    password=username+"-Password:"+password;
    username="Username:"+username;

    int flag=0;
    QFile read_file("C:/Users/amirr/Desktop/test.txt");
    if (read_file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(username==line)
              ++flag;
          if(password==line){
              ++flag;
              break;
          }

       }
       read_file.close();
    }

    if(confirm==newpassword)
        ++flag;
    if(flag==3){
        username="Username:"+username;
        EditProfile change_pass;
        change_pass.Edit_Profile(username,"Password",newpassword);

        QMessageBox::information(this,"Change password","Changed sccessfully");
    }
    else{
        QMessageBox msg;
        msg.warning(this,"Change password","There is a problem try again!.");
        return;
    }
}


void ForgetPassword::on_confirm_btn_clicked()
{
    QString username=ui->user_line->text();
    QString password=ui->pass_line->text();
    QString newpassword=ui->newpass_line->text();
    QString confirm=ui->confirmpass_line->text();

    if(username=="" || password=="" || newpassword=="" || confirm==""){
        QMessageBox msg;
        msg.warning(this,"Empty field(s)","you have to fill all fields");
        return;
    }


   check();


}





void ForgetPassword::on_back_btn_clicked()
{
    login=new MainWindow;
    this->hide();
    login->show();
}

