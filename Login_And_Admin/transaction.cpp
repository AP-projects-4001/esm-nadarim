#include "transaction.h"
#include "ui_transaction.h"
#include "seller.h"
#include "product.h"
#include <QVector>

transaction::transaction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::transaction)
{
    ui->setupUi(this);
}

transaction::~transaction()
{
    delete ui;
}

void transaction::on_next_btn_clicked()
{
    bak::seller r("mtaha");
    std::vector<bak::product> vecTransaction = r.allProductsPurchase();

    qDebug()<<vecTransaction[0].userNameBuyer;
    ui->Clientname_line->setText(vecTransaction[0].userNameBuyer);
    ui->Cusname_line->setText(vecTransaction[0].userNameSeller);
    ui->group_name->setText(vecTransaction[0].group);
    ui->productname_line->setText(vecTransaction[0].name);
    ui->price_line->setText(QString::number(vecTransaction[0].price));
    ui->number_line->setText(QString::number(vecTransaction[0].number));
}

