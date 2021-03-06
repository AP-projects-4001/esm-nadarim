#include "changeprofile.h"
#include <QString>
#include "qmessagebox.h"
#include "qvalidator.h"
#include "ui_changeprofile.h"
#include <QFile>
#include <QDebug>
#include "customer.h"
#include "editprofile.h"

changeprofile::changeprofile(QWidget *parent,QString username) :
    QWidget(parent),
    ui(new Ui::changeprofile)
{
    ui->setupUi(this);

    int txtsize=username.size();
    Username=username;

    username="Username:"+username;
    qDebug()<<username;

    int flag=0;
    QFile readFile("test.txt");
    if (readFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&readFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(username==line){
              line.remove(0,9);
              ui->user_line->setText(line);
              Username_1=line;
              ++flag;
              continue;
          }
          if(flag==1){
              line.remove(0,txtsize);
              line.remove(0,6);
              ui->name_line->setText(line);
              name=line;
              ++flag;
              continue;
          }
          if(flag==2){
              line.remove(0,txtsize);
              line.remove(0,10);
              ui->pass_line->setText(line);
              password=line;
              ++flag;
              continue;
          }
          if(flag==3){
              line.remove(0,txtsize);
              line.remove(0,9);
              ui->address_line->setText(line);
              address=line;
              ++flag;
              continue;
          }
          if(flag==4){
              line.remove(0,txtsize);
              line.remove(0,14);
              ui->phone_line->setText(line);
              phonenum=line;
              ++flag;
              continue;
          }
          if(flag==5){
              ++flag;
              continue;
          }
          if(flag==6){
              line.remove(0,txtsize);
              line.remove(0,8);
              ui->budget_line->setText(line);
              budget=line;
              ++flag;
              continue;
          }


       }

       ui->budget_line->setReadOnly(true);
       readFile.close();
    }
    ui->phone_line->setValidator(new QIntValidator);
}


changeprofile::~changeprofile()
{
    delete ui;
}

void changeprofile::on_pushButton_2_clicked()
{
    EditProfile changeprof;
    QString check_username=ui->user_line->text();
    QString check_name=ui->name_line->text();
    QString check_budget=ui->budget_line->text();
    QString check_phonenum=ui->phone_line->text();
    QString check_address=ui->address_line->text();
    QString check_password=ui->pass_line->text();

    if(check_username==Username_1 && check_name==name && check_budget==budget && check_phonenum==phonenum && check_address==address && check_password==password){
        QMessageBox msg;
        msg.warning(this,"not Successful","There is nothing to be saved!");
        return;
    }

    if(check_username=="" && check_name=="" && check_budget=="" && check_phonenum=="" && check_address==""){
        QMessageBox msg;
        msg.warning(this,"not Successful","you have to fill all fields");
        return;
    }

    if(check_password!=password){
        if(changeprof.checkpass(check_password)==true)
          changeprof.Edit_Profile(Username,"Password",check_password);
        else{
            QMessageBox msg;
            msg.warning(this,"not Successful","The Password is weak!");
            return;
        }
    }

    if(check_username!=Username){
        if(changeprof.change_username(Username,check_username)==false){
            QMessageBox msg;
            msg.warning(this,"not Successful","The username is already taken!");
            return;
         }
    }

    if(check_name!=name){
        changeprof.Edit_Profile(Username,"Name",check_name);
    }

    if(check_address!=address){
        changeprof.Edit_Profile(Username,"Address",check_address);
    }

    if(check_phonenum!=phonenum){
        changeprof.Edit_Profile(Username,"Phone-number",check_phonenum);
    }

    if(check_username!=Username){
            changeprof.change_username(Username,check_username);
    }

    QMessageBox::information(this,"Change Profile","Saved successfully!");
}




void changeprofile::on_back_btn_clicked()
{
   Customer *customer=new Customer(nullptr,Username);
   this->close();
   delete ui;
   customer->show();
}

