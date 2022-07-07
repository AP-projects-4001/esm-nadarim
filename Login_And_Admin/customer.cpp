#include "customer.h"
#include "ui_customer.h"
#include "changeprofile.h"
#include "transaction.h"
#include "get_money_customer.h"
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
   changeprof=new changeprofile(nullptr,username);
   this->close();
   delete ui;
   changeprof->show();
}





void Customer::on_soldproduct_btn_clicked()
{

   Transaction=new transaction(nullptr,username);
   this->close();
   delete ui;
   Transaction->show();

}


void Customer::on_addproduct_btn_clicked()
{
    addnew=new addproduct(nullptr,username);
    this->close();
    delete ui;
    addnew->show();
}


void Customer::on_pushButton_2_clicked()
{
    products=new allproducts(nullptr,username);
    this->close();
    delete ui;
    products->show();
}


void Customer::on_pushButton_4_clicked()
{

    EditProfile Budget;
    if (Budget.getBudget(username) == "0")
    {
        QMessageBox::information(this,"Error", "Your budget is 0$");
        return;
    }
    QVector<QString> vec(1 , username);
    Get_Money_Customer* get_money_obj = new Get_Money_Customer(nullptr,vec);
    get_money_obj->show();
    this->close();
    delete ui;

}

