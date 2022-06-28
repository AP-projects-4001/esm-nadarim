#include "allproducts.h"
#include "ui_allproducts.h"

allproducts::allproducts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allproducts)
{
    ui->setupUi(this);
}

allproducts::~allproducts()
{
    delete ui;
}
