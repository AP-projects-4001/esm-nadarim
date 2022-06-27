#include "changeprofile.h"
#include <QString>
#include "ui_changeprofile.h"
#include <QFile>
#include <QDebug>

changeprofile::changeprofile(QWidget *parent,QString username) :
    QWidget(parent),
    ui(new Ui::changeprofile)
{
    ui->setupUi(this);

    int txtsize=username.size();

    username="Username:"+username;
    qDebug()<<username;

    int flag=0;
    QFile readFile("C:/Users/amirr/Desktop/test.txt");
    if (readFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&readFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(username==line){
              line.remove(0,9);
              ui->user_line->setText(line);
              ++flag;
              continue;
          }
          if(flag==1){
              line.remove(0,txtsize);
              line.remove(0,6);
              ui->name_line->setText(line);
              ++flag;
              continue;
          }
          if(flag==2){
              ++flag;
              continue;
          }
          if(flag==3){
              line.remove(0,txtsize);
              line.remove(0,9);
              ui->address_line->setText(line);
              ++flag;
              continue;
          }
          if(flag==4){
              line.remove(0,txtsize);
              line.remove(0,14);
              ui->phone_line->setText(line);
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
              ++flag;
              continue;
          }


       }
    }
}


changeprofile::~changeprofile()
{
    delete ui;
}
