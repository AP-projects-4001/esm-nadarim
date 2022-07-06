#include "payment_client.h"
#include "client.h"
#include "editprofile.h"
#include "ui_abstract_transactions.h"
#include "ui_payment_client.h"
#include <QMessageBox>
Payment_Client::Payment_Client(QWidget *parent, QVector<QString> vec, int _budget ,int number , int countProduct , QString username_seller) :
    Abstract_Transactions(parent,vec)
{
       this->ui->label_money->setNum(_budget);
       this->ui->groupBox_name->setVisible(false);
       this->number = number;
       this->countProduct = countProduct;
       this->username_seller = username_seller;
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
    if(ui->lineEdit_part1->text().toInt() < 5000 || ui->lineEdit_part1->text().toInt() >= 7000 || ui->lineEdit_part2->text().size() < 4 ||
            ui->lineEdit_part3->text().size() < 4  || ui->lineEdit_part4->text().size() < 4  )
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

    bak::Buyer buy_obj(vector_info[0].toStdString());
    buy_obj.setCountProduct(countProduct);
    buy_obj.setNumberPurchased(number);
    if(buy_obj.isPossibleBuy() == false)
    {
        QMessageBox::information(this,"Error","The number of products ordered is more than the available number.");
        Client* profile_obj = new Client(nullptr,"Username:"+vector_info[0]);
        profile_obj->show();
        this->close();
        return;
    }
    buy_obj.buy();
    QMessageBox::information(this,"Payment","Payment was successful");

    EditProfile Edit_obj;
    Edit_obj.Edit_Profile(username_seller,"Budget",QString::number(Edit_obj.getBudget(username_seller).toInt()+ui->label_money->text().toInt()));

    Client* profile_obj = new Client(nullptr,"Username:"+vector_info[0]);
    profile_obj->show();
    this->close();
}
