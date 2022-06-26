#include "customer.h"
#include "ui_customer.h"
#include "changeprofile.h"

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
}




void Customer::on_editprofile_btn_clicked()
{
   this->hide();
   changeprof=new changeprofile(nullptr,username);
   changeprof->show();
}

