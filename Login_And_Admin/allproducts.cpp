#include "allproducts.h"
#include "customer.h"
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
    deleteCount=0;
    this->username=username;

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
       ui->delete_btn->setEnabled(false);
       ui->save_btn->setEnabled(false);
    }

    group=ui->group_combo->currentText();
    product=ui->product_combo->currentText();
    color=ui->color_combo->currentText();
    warranty=ui->guarantee->currentText();
    productname=ui->name_line->text();
    brand=ui->brand_line->text();
    number=ui->number_line->text();
    weight=ui->weight_line->text();
    price=ui->price_line->text();

     ui->number_line->setValidator(new QIntValidator);
     ui->weight_line->setValidator(new QIntValidator);
     ui->price_line->setValidator(new QIntValidator(0,100000000,this));
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

    deleteCount=0;
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

    group=ui->group_combo->currentText();
    product=ui->product_combo->currentText();
    color=ui->color_combo->currentText();
    warranty=ui->guarantee->currentText();
    productname=ui->name_line->text();
    brand=ui->brand_line->text();
    number=ui->number_line->text();
    weight=ui->weight_line->text();
    price=ui->price_line->text();
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
    deleteCount=0;

    ui->brand_line->setText(Allproducts[index].brand);
    ui->name_line->setText(Allproducts[index].name);
    ui->number_line->setText(QString::number(Allproducts[index].number));
    ui->price_line->setText(QString::number(Allproducts[index].price));
    ui->weight_line->setText(QString::number(Allproducts[index].weight));
    ui->group_combo->setCurrentText(Allproducts[index].group);
    ui->color_combo->setCurrentText(Allproducts[index].color);
    ui->product_combo->setCurrentText(Allproducts[index].model);
    ui->guarantee->setCurrentText(Allproducts[index].warranty);

    group=ui->group_combo->currentText();
    product=ui->product_combo->currentText();
    color=ui->color_combo->currentText();
    warranty=ui->guarantee->currentText();
    productname=ui->name_line->text();
    brand=ui->brand_line->text();
    number=ui->number_line->text();
    weight=ui->weight_line->text();
    price=ui->price_line->text();
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
  if(deleteCount==0)
  {
   bak::seller deleteproduct(username.toStdString());
   deleteproduct.deleteProduct(Allproducts[index].CountProduct);
   ++deleteCount;
   QMessageBox::information(this,"Successful delete","The Item Successfully deleted!");
  }
  else{
      QMessageBox msg;
      msg.warning(this,"not Successful","There is nothing to be deleted!");
      return;
  }
}


void allproducts::on_save_btn_clicked()
{
    QString group_delete=ui->group_combo->currentText();
    QString product_delete=ui->product_combo->currentText();
    QString color_delete=ui->color_combo->currentText();
    QString warranty_delete=ui->guarantee->currentText();
    QString productname_delete=ui->name_line->text();
    QString brand_delete=ui->brand_line->text();
    QString number_delete=ui->number_line->text();
    QString weight_delete=ui->weight_line->text();
    QString price_delete=ui->price_line->text();

    if(group_delete==group && product_delete==product && color_delete==color && warranty_delete==warranty && productname_delete==productname && brand_delete==brand && number_delete==number && weight_delete==weight && price_delete==price){
        QMessageBox msg;
        msg.warning(this,"not Successful","There is nothing to be saved");
        return;
    }


    if(group_delete=="" || product_delete=="" || color_delete=="" || warranty_delete=="" || productname_delete=="" || brand_delete==" " || number_delete==" " || weight_delete==" " || price_delete==" "){
        QMessageBox msg;
        msg.warning(this,"not Successful","You have to fill all fileds!");
        return;
    }

    bak::seller saveproduct(username.toStdString());

    saveproduct.setName(ui->name_line->text().toStdString());
    saveproduct.setGroup(ui->group_combo->currentText().toStdString());
    saveproduct.setBrand(ui->brand_line->text().toStdString());
    saveproduct.setModel(ui->product_combo->currentText().toStdString());
    saveproduct.setColor(ui->color_combo->currentText().toStdString());
    saveproduct.setWarranty(ui->guarantee->currentText().toStdString());
    saveproduct.setNumberUnsold(ui->number_line->text().toInt());
    saveproduct.setPrice(ui->price_line->text().toInt());
    saveproduct.setWeight(ui->weight_line->text().toInt());

    saveproduct.editProduct(Allproducts[index].CountProduct);
    QMessageBox::information(this,"Save Edit","Saved Successfully!");
}


void allproducts::on_exit_btn_clicked()
{
   Customer *customer=new Customer(nullptr,username);
   this->close();
   delete ui;
   customer->show();
}

