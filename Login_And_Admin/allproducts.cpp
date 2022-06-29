#include "allproducts.h"
#include "ui_allproducts.h"
#include "seller.h"
#include "product.h"
#include <QString>
#include <QMessageBox>


allproducts::allproducts(QWidget *parent,QString username):
    QWidget(parent),
    ui(new Ui::allproducts)
{
    ui->setupUi(this);

    bak::seller customer(username.toStdString());
    Allproducts=customer.allProductsSell();

    index=0;

    if(Allproducts.size()>0)
    {
     ui->brand_line->setText(Allproducts[index].brand);
     ui->name_line->setText(Allproducts[index].name);
     ui->number_line->setText(QString::number(Allproducts[index].number));
     ui->price_line->setText(QString::number(Allproducts[index].price));
     ui->weight_line->setText(QString::number(Allproducts[index].weight));
     ui->group_combo->setCurrentText(Allproducts[index].group);
     ui->color_combo->setCurrentText(Allproducts[index].color);
     ui->product_combo->setCurrentText(Allproducts[index].model);
     ui->guarantee->setCurrentText(Allproducts[index].warranty);
    }
    else{
       ui->brand_line->setReadOnly(true);
       ui->name_line->setReadOnly(true);
       ui->number_line->setReadOnly(true);
       ui->price_line->setReadOnly(true);
       ui->weight_line->setReadOnly(true);
       ui->group_combo->setEnabled(false);
       ui->color_combo->setEnabled(false);
       ui->product_combo->setEnabled(false);
       ui->guarantee->setEnabled(false);
       index=-1;
    }

}

allproducts::~allproducts()
{
    delete ui;
}

void allproducts::on_next_btn_clicked()
{
    if(index==-1){
        QMessageBox::information(this,"All products","There is nothing");
    }

    if(index==(Allproducts.size())-1){
        return;
    }

    ++index;
    ui->brand_line->setText(Allproducts[index].brand);
    ui->name_line->setText(Allproducts[index].name);
    ui->number_line->setText(QString::number(Allproducts[index].number));
    ui->price_line->setText(QString::number(Allproducts[index].price));
    ui->weight_line->setText(QString::number(Allproducts[index].weight));
    ui->group_combo->setCurrentText(Allproducts[index].group);
    ui->color_combo->setCurrentText(Allproducts[index].color);
    ui->product_combo->setCurrentText(Allproducts[index].model);
    ui->guarantee->setCurrentText(Allproducts[index].warranty);
}


void allproducts::on_previous_btn_clicked()
{
    if(index==-1){
        QMessageBox::information(this,"All products","There is nothing");
    }

    if(index<=0){
        return;
    }

    index-=1;
    ui->brand_line->setText(Allproducts[index].brand);
    ui->name_line->setText(Allproducts[index].name);
    ui->number_line->setText(QString::number(Allproducts[index].number));
    ui->price_line->setText(QString::number(Allproducts[index].price));
    ui->weight_line->setText(QString::number(Allproducts[index].weight));
    //ui->group_combo->setEditable(true);
    //on_product_combo_currentTextChanged();
    ui->group_combo->setCurrentText(Allproducts[index].group);
    ui->color_combo->setCurrentText(Allproducts[index].color);
    ui->product_combo->setCurrentText(Allproducts[index].model);
    ui->guarantee->setCurrentText(Allproducts[index].warranty);
}


void allproducts::on_group_combo_currentTextChanged()
{
    if(ui->group_combo->currentText()=="Electronics"){
        ui->product_combo->clear();
        ui->product_combo->addItem("Accessories & Supplies");
        ui->product_combo->addItem("Cell Phones & Accessories");
        ui->product_combo->addItem("Camera & Photo");
        ui->product_combo->addItem("Televison & Video");
        ui->product_combo->addItem("Video Game Consoles & Accessories");
        ui->product_combo->addItem("Headphones");
        ui->product_combo->addItem("Computer & Accessories");
    }
    if(ui->group_combo->currentText()=="Home and Kitchen"){
        ui->product_combo->clear();
        ui->product_combo->addItem("Bedding");
        ui->product_combo->addItem("Bath");
        ui->product_combo->addItem("Furniture");
        ui->product_combo->addItem("Home Decor");
        ui->product_combo->addItem("Kitchen & dining");
        ui->product_combo->addItem("Cleaning Supplies");
        ui->product_combo->addItem("Irons & Steamers");

    }
    if(ui->group_combo->currentText()==""){
        ui->product_combo->clear();
    }
}


void allproducts::on_delete_btn_clicked()
{

}

