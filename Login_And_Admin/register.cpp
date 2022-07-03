#include "register.h"
#include "checkpassword.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_register.h"
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <string>
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->phone_line->setValidator(new QIntValidator);

}

Register::~Register()
{
    delete ui;
    delete(newpassword);
    delete(login);
}

int Register::checkUsername(QString username)
{
    int flag=0;
    QFile read_file("C:/Users/Lenovo/Desktop/test.txt");
    qDebug()<<username;
    if (read_file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(username==line){
              ++flag;
              return flag;
          }

       }
       read_file.close();
    }
    return -1;
}


void Register::WriteInFile()
{
    QFile write_file("C:/Users/Lenovo/Desktop/test.txt");
    if(write_file.open(QIODevice::WriteOnly| QIODevice::Append | QIODevice::Text))
         {
             // We're going to streaming text to the file
             QTextStream out(&write_file);

             out<<"Username:"<<ui->username_line->text()<<Qt::endl;
             out<<ui->username_line->text()<<"-Name:"<<ui->name_line->text()<<Qt::endl;
             out<<ui->username_line->text()<<"-Password:"<<ui->pass_line->text()<<Qt::endl;
             out<<ui->username_line->text()<<"-Address:"<<ui->address_line->text()<<Qt::endl;
             out<<ui->username_line->text()<<"-Phone-number:"<<ui->phone_line->text()<<Qt::endl;
             out<<ui->username_line->text()<<"-Level:"<<ui->comboBox->currentText()<<Qt::endl;
             out<<ui->username_line->text()<<"-Budget:0"<<Qt::endl;
             out<<ui->username_line->text()<<"-Status:True"<<Qt::endl;
             out<<Qt::endl;


             write_file.close();

             qDebug() << "Writing finished";
         }
}









void Register::on_signup_btn_reg_clicked()
{
  QString name=ui->name_line->text();
  QString username=ui->username_line->text();
  QString phonenum=ui->phone_line->text();
  QString address=ui->address_line->text();
  QString password=ui->pass_line->text();
  QString confirm=ui->confirm_line->text();

  if(name=="" || username=="" || phonenum=="" || address=="" || password=="" || confirm==""){
      QMessageBox msg;
      msg.warning(this,"not Successful","you have to fill all fields");
      return;
  }


  username="Username:"+username;
  int flag=checkUsername(username);

  newpassword=new bak::checkPassword(password.toStdString());
  if(!newpassword->isConfirm()){
      QMessageBox msg;
      msg.warning(this,"Password is weak","You hava to set a stronger password");
      return;

  }
  if(confirm!=password)
  {
      QMessageBox msg;
      msg.warning(this,"Password is not match","Enter your password again!");
      return;
  }
  if(flag==-1)
     WriteInFile();
  else{
      QMessageBox msg;
      msg.warning(this,"not Successful","The username is already taken");
      return;
  }

}


void Register::on_login_btn_reg_clicked()
{
   login=new MainWindow;
   this->hide();
   login->show();
}

