#include "customer.h"
#include "ui_customer.h"
#include "changeprofile.h"
#include "transaction.h"

Customer::Customer(QWidget *parent, QString username) :
    QWidget(parent),
    ui(new Ui::Customer)
{
    ui->setupUi(this);
    this->username=username;
}

Customer::~Customer()
{
    delete ui;
    delete(changeprof);
    delete(addnew);
    delete(products);
}




void Customer::on_editprofile_btn_clicked()
{
   qDebug()<<username;
   this->hide();
   changeprof=new changeprofile(nullptr,username);
   changeprof->show();
}





void Customer::on_soldproduct_btn_clicked()
{
   this->hide();
   Transaction=new transaction(nullptr,username);
   Transaction->show();

}


void Customer::on_addproduct_btn_clicked()
{
    this->hide();
    addnew=new addproduct(nullptr,username);
    addnew->show();
}


void Customer::on_pushButton_2_clicked()
{
    this->hide();
    products=new allproducts(nullptr,username);
    products->show();
}

