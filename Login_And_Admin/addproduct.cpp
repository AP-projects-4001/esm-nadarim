#include "addproduct.h"
#include "customer.h"
#include "qmessagebox.h"
#include "ui_addproduct.h"
#include "seller.h"
#include <memory>
#include <QScopedPointer>

addproduct::addproduct(QWidget *parent, QString username) :
    QWidget(parent),
    ui(new Ui::addproduct)
{
    ui->setupUi(this);
    this->username=username;
}

addproduct::~addproduct()
{
    delete ui;
}

void addproduct::addtofile()
{
  QString group=ui->group_combo->currentText();
  QString product=ui->model_combo->currentText();
  QString color=ui->color_combo->currentText();
  QString warranty=ui->warranty_combo->currentText();
  QString productname=ui->productname_line->text();
  QString brand=ui->brand_line->text();
  QString number=ui->number_line->text();
  QString weight=ui->weight_line->text();
  QString price=ui->price_line->text();

  bak::seller addproduct(username.toStdString());

  addproduct.setName(productname.toStdString());
  addproduct.setGroup(group.toStdString());
  addproduct.setBrand(brand.toStdString());
  addproduct.setModel(product.toStdString());
  addproduct.setColor(color.toStdString());
  addproduct.setWarranty(warranty.toStdString());
  addproduct.setNumberUnsold(number.toInt());
  addproduct.setPrice(price.toInt());
  addproduct.setWeight(weight.toInt());

  addproduct.addProduct();

}




void addproduct::on_group_combo_currentTextChanged()
{
    if(ui->group_combo->currentText()=="Electronics"){
        ui->model_combo->clear();
        ui->model_combo->addItem("Accessories & Supplies");
        ui->model_combo->addItem("Cell Phones & Accessories");
        ui->model_combo->addItem("Camera & Photo");
        ui->model_combo->addItem("Televison & Video");
        ui->model_combo->addItem("Video Game Consoles & Accessories");
        ui->model_combo->addItem("Headphones");
        ui->model_combo->addItem("Computer & Accessories");
    }
    if(ui->group_combo->currentText()=="Home and Kitchen"){
        ui->model_combo->clear();
        ui->model_combo->addItem("Bedding");
        ui->model_combo->addItem("Bath");
        ui->model_combo->addItem("Furniture");
        ui->model_combo->addItem("Home Decor");
        ui->model_combo->addItem("Kitchen & dining");
        ui->model_combo->addItem("Cleaning Supplies");
        ui->model_combo->addItem("Irons & Steamers");

    }
    if(ui->group_combo->currentText()==""){
        ui->model_combo->clear();
    }
}


void addproduct::on_confirm_btn_clicked()
{
    QString group=ui->group_combo->currentText();
    QString product=ui->model_combo->currentText();
    QString color=ui->color_combo->currentText();
    QString warranty=ui->warranty_combo->currentText();
    QString productname=ui->productname_line->text();
    QString brand=ui->brand_line->text();
    QString number=ui->number_line->text();
    QString weight=ui->weight_line->text();
    QString price=ui->price_line->text();

    if(group=="" || product=="" || color=="" || warranty=="" || productname=="" || brand=="" || number=="" || weight=="" || price==""){
        QMessageBox msg;
        msg.warning(this,"not Successful","you have to fill all fields");
        return;
    }
    addtofile();
    ui->group_combo->setCurrentIndex(0);
    ui->model_combo->setCurrentIndex(0);
    ui->color_combo->setCurrentIndex(0);
    ui->warranty_combo->setCurrentIndex(0);
    ui->productname_line->clear();
    ui->brand_line->clear();
    ui->number_line->clear();
    ui->weight_line->clear();
    ui->price_line->clear();
    QMessageBox::information(this,"adding product","product added successfully!");
}


void addproduct::on_pushButton_2_clicked()
{
    Customer *customer=new Customer(nullptr,username);
    this->close();
    delete ui;
    customer->show();
}

