#include "payment_client.h"
#include "client.h"
#include "ui_abstract_transactions.h"
#include "ui_payment_client.h"
#include <QMessageBox>
Payment_Client::Payment_Client(QWidget *parent, QVector<QString> vec, int _budget) :
    Abstract_Transactions(parent,vec)
{
       this->ui->label_money->setNum(_budget);
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

}
