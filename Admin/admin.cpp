#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);

    QFile readFile("C:/Users/Lenovo/Desktop/test.txt");
    if (readFile.open(QIODevice::ReadOnly))
    {
       int pos;

       QTextStream in(&readFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          pos = line.indexOf(":");
          if (pos == -1)
          {
              continue;
          }
          line = line.sliced(pos+1);
          vecAdmin.append(line);
       }
       readFile.close();
       ui->lineEdit->setText(vecAdmin[0]);
       ui->lineEdit_2->setText(vecAdmin[1]);
       ui->lineEdit_3->setText(vecAdmin[2]);
       ui->textEdit->setText(vecAdmin[3]);
       ui->lineEdit_4->setText(vecAdmin[4]);
       ui->lineEdit_5->setText(vecAdmin[5]);
       ui->lineEdit_6->setText(vecAdmin[6]);
       ui->lineEdit_7->setText(vecAdmin[7]);
       index = 8;
    }
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_6_clicked()
{
    this->close();
}


void Admin::on_pushButton_clicked()
{
    if (vecAdmin.size() == index)
    {
        return;
    }
    ui->lineEdit->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_2->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_3->setText(vecAdmin[index]);
    index++;
    ui->textEdit->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_4->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_5->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_6->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_7->setText(vecAdmin[index]);
    index++;
}


void Admin::on_pushButton_2_clicked()
{


    if(index <= 9)
    {
        return;
    }
     index = index -16;
    ui->lineEdit->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_2->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_3->setText(vecAdmin[index]);
    index++;
    ui->textEdit->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_4->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_5->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_6->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_7->setText(vecAdmin[index]);
    index++;
}


void Admin::on_pushButton_4_clicked()
{
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    //ui->lineEdit->setReadOnly(false);
    ui->lineEdit_2->setReadOnly(false);
    ui->lineEdit_4->setReadOnly(false);
    //ui->lineEdit_6->setReadOnly(false);
    ui->textEdit->setReadOnly(false);
}


void Admin::on_pushButton_7_clicked()
{
    if(ui->lineEdit_2->text() == "" || ui->textEdit->toPlainText() == "" || ui->lineEdit_4->text()=="")
    {
        QMessageBox msg;
        msg.setText("All fields must be filled");
        msg.exec();
        return;
    }
    EditProfile obj;
    //obj.Edit_Profile(ui->lineEdit->text(),ui->label->text(),);
    obj.Edit_Profile(ui->lineEdit->text(),ui->label_2->text(),ui->lineEdit_2->text());
    vecAdmin[index-7] = ui->lineEdit_2->text();
    obj.Edit_Profile(ui->lineEdit->text(),ui->label_4->text(),ui->textEdit->toPlainText());
    vecAdmin[index-5] = ui->textEdit->toPlainText();
    obj.Edit_Profile(ui->lineEdit->text(),ui->label_5->text(),ui->lineEdit_4->text());
    vecAdmin[index-4] = ui->lineEdit_4->text();
    //obj.Edit_Profile(ui->lineEdit->text(),ui->label_7->text(),ui->lineEdit_6->text());
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    //ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    //ui->lineEdit_6->setReadOnly(true);
    ui->textEdit->setReadOnly(true);
}

