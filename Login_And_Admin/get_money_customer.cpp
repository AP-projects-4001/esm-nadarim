#include "get_money_customer.h"
#include "ui_abstract_transactions.h"
#include "ui_get_money_customer.h"
#include "customer.h"
#include<QMessageBox>

Get_Money_Customer::Get_Money_Customer(QWidget *parent,QVector<QString> vec) :
    Abstract_Transactions(parent,vec)
{
    ui->groupBox_pass->setVisible(false);
    username = vec[0];
}

Get_Money_Customer::~Get_Money_Customer()
{
    delete timer;
}

void Get_Money_Customer::on_actionBack_triggered()
{
    QMessageBox::information(this,"Error","The operation was unsuccessful");
    timer->stop();
    Customer* customer_obj = new Customer(nullptr,username);
    customer_obj->show();
    this->close();
}

void Get_Money_Customer::on_pushButton_confirm_clicked()
{

}
