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
    QString phonenum=ui->phone_line->text();


    phonenum=username+"-Phone-number:"+phonenum;
    username="Username:"+username;

    int flag=0;
    QFile read_file("test.txt");
    if (read_file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(username==line)
              ++flag;
          if(phonenum==line){
              ++flag;
              break;
          }

       }
       read_file.close();
    }

    if(flag==2){
        QMessageBox::information(this,"Forget password","A recovery link sent to your phone");
        return;
    }
    else{
        QMessageBox msg;
        msg.warning(this,"Forget password","There is a problem try again!.");
        return;
    }
}


void ForgetPassword::on_confirm_btn_clicked()
{
    QString username=ui->user_line->text();
    QString phonenum=ui->phone_line->text();


    if(username=="" || phonenum==""){
        QMessageBox msg;
        msg.warning(this,"Empty field(s)","you have to fill all fields");
        return;
    }


   check();


}





void ForgetPassword::on_back_btn_clicked()
{
    login=new MainWindow;
    this->close();
    delete ui;
    login->show();
}

