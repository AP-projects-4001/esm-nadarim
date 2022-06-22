#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QDebug>
#include <fstream>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"
#include "register.h"
#include "editprofile.h"
#include "forgetpassword.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::searchFile()
{
    QString username=ui->user_line->text();
    QString password=ui->pass_line->text();

    password=username+"-Password:"+password;
    QString status=username+"-Status:True";
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
          if(password==line)
              ++flag;
          if(line==status){
              ++flag;
              break;
          }

       }
       read_file.close();
    }

    if(flag==3){
        QMessageBox::information(this,"Enter Successfuly","match sccessfully");
    }
    else{
        QMessageBox::information(this,"idk","not match sccessfully");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_btn_clicked()
{
    QString username=ui->user_line->text();
    QString password=ui->pass_line->text();

    if(password=="" || username==""){
        QMessageBox msg;
        msg.warning(this,"not Successful","you have to fill all fields");
        return;
    }

    searchFile();

};






void MainWindow::on_signup_btn_clicked()
{
    Register *r=new Register;
    this->hide();
    r->show();

}


void MainWindow::on_forgetpass_btn_clicked()
{
   ForgetPassword *forgetpass=new ForgetPassword;
   this->hide();
   forgetpass->show();

}

