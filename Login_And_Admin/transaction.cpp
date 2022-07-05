#include "transaction.h"
#include "customer.h"
#include "ui_transaction.h"
#include "seller.h"
#include "product.h"
#include <QVector>

transaction::transaction(QWidget *parent,QString username):
    QWidget(parent),
    ui(new Ui::transaction)
{
    ui->setupUi(this);
    index=0;

    this->username=username;

    bak::seller newseller(username.toStdString());
    vecTransaction = newseller.allProductsPurchase();


    if(vecTransaction.size()>0)
   {
     ui->Clientname_line->setText(vecTransaction[index].userNameBuyer);
     ui->Cusname_line->setText(vecTransaction[index].userNameSeller);
     ui->group_name->setText(vecTransaction[index].group);
     ui->productname_line->setText(vecTransaction[index].name);
     ui->price_line->setText(QString::number(vecTransaction[index].price));
     ui->number_line->setText(QString::number(vecTransaction[index].number));
    }
    else{
        ui->Clientname_line->setReadOnly(true);
        ui->Cusname_line->setReadOnly(true);
        ui->group_name->setReadOnly(true);
        ui->productname_line->setReadOnly(true);
        ui->price_line->setReadOnly(true);
        ui->number_line->setReadOnly(true);
        index=-1;
    }
}

transaction::~transaction()
{
    delete ui;
}

void transaction::on_next_btn_clicked()
{
    if(index==(vecTransaction.size())-1){
        return;
    }

    ++index;

    ui->Clientname_line->setText(vecTransaction[index].userNameBuyer);
    ui->Cusname_line->setText(vecTransaction[index].userNameSeller);
    ui->group_name->setText(vecTransaction[index].group);
    ui->productname_line->setText(vecTransaction[index].name);
    ui->price_line->setText(QString::number(vecTransaction[index].price));
    ui->number_line->setText(QString::number(vecTransaction[index].number));
}



void transaction::on_previous_btn_clicked()
{
    if(index<=0)
        return;

    index-=1;

    ui->Clientname_line->setText(vecTransaction[index].userNameBuyer);
    ui->Cusname_line->setText(vecTransaction[index].userNameSeller);
    ui->group_name->setText(vecTransaction[index].group);
    ui->productname_line->setText(vecTransaction[index].name);
    ui->price_line->setText(QString::number(vecTransaction[index].price));
    ui->number_line->setText(QString::number(vecTransaction[index].number));


}





void transaction::on_back_btn_clicked()
{
   this->close();
   Customer *customer=new Customer(nullptr,username);
   customer->show();
}

