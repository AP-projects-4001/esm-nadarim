#include "payment_client.h"
#include "client.h"
#include "editprofile.h"
#include "ui_abstract_transactions.h"
#include "ui_payment_client.h"
#include <QMessageBox>
Payment_Client::Payment_Client(QWidget *parent, QVector<QString> vec, int _budget) :
    Abstract_Transactions(parent,vec)
{
       this->ui->label_money->setNum(_budget);
       this->ui->groupBox_name->setVisible(false);
}

Payment_Client::~Payment_Client()
{
    delete timer;
}

void Payment_Client::on_actionBack_triggered()
{
    QMessageBox::information(this,"Payment","Payment failed");
    timer->stop();
    Client* profile_obj = new Client(nullptr,"Username:"+vector_info[0]);
    profile_obj->show();
    this->close();
}

void Payment_Client::on_pushButton_confirm_clicked()
{
    if(ui->lineEdit_part1->text().toInt() < 5000 || ui->lineEdit_part1->text().toInt() >= 7000 || ui->lineEdit_part2->text().toInt() == 1000 ||
            ui->lineEdit_part3->text().toInt() == 1000 || ui->lineEdit_part4->text().toInt() == 1000 )
    {
        QMessageBox::information(this,"Payment","Card number is incorrect");
        return;
    }
    if(ui->lineEdit_CVV2->text()=="" || ui->lineEdit_pass->text()=="")
    {
        QMessageBox::information(this,"Error","The CVV2 and password fields must not be left blank");
        return;
    }

    timer->stop();
    QMessageBox::information(this,"Payment","Payment was successful");
    Client* profile_obj = new Client(nullptr,vector_info[0]);
    EditProfile obj;
    obj.Edit_Profile(vector_info[0],"Budget",vector_info[5]);
    profile_obj->show();
    this->close();
}
