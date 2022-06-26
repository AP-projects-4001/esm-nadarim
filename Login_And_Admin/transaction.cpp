#include "transaction.h"
#include "ui_transaction.h"

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
