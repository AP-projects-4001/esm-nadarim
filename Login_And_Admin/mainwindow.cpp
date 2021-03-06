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
#include "customer.h"
#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"
#include "register.h"
#include "editprofile.h"
#include "forgetpassword.h"
#include "addproduct.h"
#include "allproducts.h"

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
    QString save_password=username;
    username="Username:"+username;

    qDebug()<<username;

    QString Level;
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
          if(password==line)
          {
              ++flag;
              in.readLine();
              in.readLine();
              Level = in.readLine();
          }
          if(line==status){
              ++flag;
              break;
          }

       }
       read_file.close();
    }

    if(flag==3)
    {
        QMessageBox::information(this,"Enter Successfuly","match sccessfully");
        int pos = Level.indexOf(":");
        Level = Level.sliced(pos+1);
        if (Level == "Admin")
        {
            Admin *w = new Admin(this);
            delete ui;
            this->close();
            w->show();
        }
        else if(Level == "Client")
        {
            Client *client_window = new Client(this,username);
            delete ui;
            this->close();
            client_window->show();
        }
        else if(Level=="Customer"){
            customer=new Customer(nullptr,save_password);
            delete ui;
            this->close();
            customer->show();
        }
    }
    else{
        QMessageBox::information(this,"idk","not match sccessfully");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete(customer);

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
    delete ui;
    this->close();
    r->show();

}


void MainWindow::on_forgetpass_btn_clicked()
{
   ForgetPassword *forgetpass=new ForgetPassword;
   delete ui;
   this->close();
   forgetpass->show();

}


void MainWindow::on_checkBox_pass_clicked()
{
    if(ui->label_passState->text() == "Show password")
    {
        ui->label_passState->setText("Hide password");
        ui->pass_line->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->label_passState->setText("Show password");
        ui->pass_line->setEchoMode(QLineEdit::Password);
    }
}

