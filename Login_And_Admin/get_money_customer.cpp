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
    ui->label_money->setText(edit_budget.getBudget(vec[0]));
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
    if(ui->lineEdit_name->text() == "" || ui->lineEdit_part1->text().size() < 4 ||
    ui->lineEdit_part2->text().size() < 4  || ui->lineEdit_part3->text().size() < 4 || ui->lineEdit_part4->text().size() < 4  )
    {
        QMessageBox::information(this,"Error","All fields must be filled");
        return;
    }
    timer->stop();
    edit_budget.Edit_Profile(username,"Budget","0");
    QMessageBox::information(this,"Successful operation",ui->label_money->text()+"$ has been credited to your account");
    Customer* customer_obj = new Customer(nullptr,username);
    customer_obj->show();
    this->close();
}
