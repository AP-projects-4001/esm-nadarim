#include "client.h"
#include "payment_client.h"
#include "ui_client.h"
#include "edit_profile_client.h"
#include "abstract_transactions.h"
#include "mainwindow.h"
Client::Client(QWidget *parent,QString username_client) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    QString  line;
    int pos;
    this->username_client = username_client;
    QFile read_file("test.txt");
        if (read_file.open(QIODevice::ReadOnly))
        {
           QTextStream in(&read_file);
           while (!in.atEnd())
           {
            if( username_client == in.readLine())
            {

                pos = username_client.indexOf(":");
                line = username_client.sliced(pos+1);
                vec_info_client[0] = line;
                for(int i=1 ;i<5 ; i++)
                {
                    line = in.readLine();
                    pos = line.indexOf(":");
                    line = line.sliced(pos+1);
                    vec_info_client[i] = line;
                }
                in.readLine();
                line = in.readLine();
                pos = line.indexOf(":");
                line = line.sliced(pos+1);
                vec_info_client[5] = line;
                break;
            }
           }

       }
        ui->label_budget->setText(vec_info_client[5]);
       read_file.close();
       connect(ui->horizontalSlider_minPrice,SIGNAL(valueChanged(int)),ui->label_setminPrice,SLOT(setNum(int)));
       connect(ui->horizontalSlider_maxPrice,SIGNAL(valueChanged(int)),ui->label_setmaxPrice,SLOT(setNum(int)));
       connect(ui->horizontalSlider_weight,SIGNAL(valueChanged(int)),ui->label_weight,SLOT(setNum(int)));
}

Client::~Client()
{
    delete ui;
}



void Client::on_actionProfile_triggered()
{
    Edit_Profile_Client* edit_obj = new Edit_Profile_Client(nullptr,vec_info_client);
    this->close();
    edit_obj->show();
}


void Client::on_actionExit_triggered()
{
    MainWindow* window = new MainWindow();
    vec_info_client.clear();
    delete ui;
    this->close();
    window->show();
}


void Client::on_comboBox_group_currentTextChanged()
{
    if(ui->comboBox_group->currentText() == "")
    {
        ui->comboBox_products->clear();
        ui->comboBox_products->addItem("");
        ui->comboBox_products->addItem("Accessories & Supplies");
        ui->comboBox_products->addItem("Cell Phones & Accessories");
        ui->comboBox_products->addItem("Camera & Photo");
        ui->comboBox_products->addItem("Televison & Video");
        ui->comboBox_products->addItem("Video Game Consoles & Accessories");
        ui->comboBox_products->addItem("Headphones");
        ui->comboBox_products->addItem("Computer & Accessories");
        ui->comboBox_products->addItem("Bedding");
        ui->comboBox_products->addItem("Bath");
        ui->comboBox_products->addItem("Furniture");
        ui->comboBox_products->addItem("Home Decor");
        ui->comboBox_products->addItem("Kitchen & dining");
        ui->comboBox_products->addItem("Cleaning Supplies");
        ui->comboBox_products->addItem("Irons & Steamers");
    }
    else if(ui->comboBox_group->currentText()=="Electronics")
    {
        ui->comboBox_products->clear();
        ui->comboBox_products->addItem("");
        ui->comboBox_products->addItem("Accessories & Supplies");
        ui->comboBox_products->addItem("Cell Phones & Accessories");
        ui->comboBox_products->addItem("Camera & Photo");
        ui->comboBox_products->addItem("Televison & Video");
        ui->comboBox_products->addItem("Video Game Consoles & Accessories");
        ui->comboBox_products->addItem("Headphones");
        ui->comboBox_products->addItem("Computer & Accessories");
    }
    else if(ui->comboBox_group->currentText() == "Home and Kitchen")
    {
        ui->comboBox_products->clear();
        ui->comboBox_products->addItem("");
        ui->comboBox_products->addItem("Bedding");
        ui->comboBox_products->addItem("Bath");
        ui->comboBox_products->addItem("Furniture");
        ui->comboBox_products->addItem("Home Decor");
        ui->comboBox_products->addItem("Kitchen & dining");
        ui->comboBox_products->addItem("Cleaning Supplies");
        ui->comboBox_products->addItem("Irons & Steamers");
    }
}


void Client::on_pushButton_clicked()
{
    index_filter = 0;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    qDebug() <<  filter_obj.allProducts().size() << "1-  ";
    if(ui->horizontalSlider_maxPrice->value() < ui->horizontalSlider_minPrice->value() )
    {
        QMessageBox::information(this,"Problem","Searching failed");
        return;
    }

        filter_obj.setBrand((ui->lineEdit_brand->text()).toStdString());


        filter_obj.setColor(ui->color_combo->currentText().toStdString());


    filter_obj.setPrice(ui->horizontalSlider_minPrice->value(),ui->horizontalSlider_maxPrice->value());


        filter_obj.setGroup(ui->comboBox_group->currentText().toStdString());

  filter_obj.setModel(ui->comboBox_products->currentText().toStdString());

        filter_obj.setWarranty(ui->comboBox_warranty->currentText().toStdString());

    filter_obj.setWeight(0,ui->horizontalSlider_weight->value());
    qDebug() <<  filter_obj.allProducts().size() << "2-  ";
    if(filter_obj.allProducts().size() >0)
    {
        ui->lineEdit->setText(filter_obj.allProducts()[0].group);
        ui->lineEdit_2->setText(filter_obj.allProducts()[0].model);
        ui->lineEdit_3->setText(filter_obj.allProducts()[0].name);
        ui->lineEdit_4->setText(filter_obj.allProducts()[0].brand);
        ui->lineEdit_5->setText(filter_obj.allProducts()[0].color);
        ui->lineEdit_6->setText(QString::number(filter_obj.allProducts()[0].number));
        ui->lineEdit_7->setText(QString::number(filter_obj.allProducts()[0].weight));
        ui->lineEdit_8->setText(QString::number(filter_obj.allProducts()[0].price));
        ui->lineEdit_9->setText(filter_obj.allProducts()[0].warranty);
        index_filter++;
    }
    qDebug() <<  filter_obj.allProducts().size() << "3-  ";

}



void Client::on_pushButton_2_clicked()
{
    if(filter_obj.allProducts().size() <= index_filter )
    {
        return;
    }
    ui->lineEdit->setText(filter_obj.allProducts()[index_filter].group);
    ui->lineEdit_2->setText(filter_obj.allProducts()[index_filter].model);
    ui->lineEdit_3->setText(filter_obj.allProducts()[index_filter].name);
    ui->lineEdit_4->setText(filter_obj.allProducts()[index_filter].brand);
    ui->lineEdit_5->setText(filter_obj.allProducts()[index_filter].color);
    ui->lineEdit_6->setText(QString::number(filter_obj.allProducts()[index_filter].number));
    ui->lineEdit_7->setText(QString::number(filter_obj.allProducts()[index_filter].weight));
    ui->lineEdit_8->setText(QString::number(filter_obj.allProducts()[index_filter].price));
    ui->lineEdit_9->setText(filter_obj.allProducts()[index_filter].warranty);
    index_filter++;
}


void Client::on_pushButton_3_clicked()
{
    if(index_filter < 2 )
    {
        return;
    }
    index_filter -=2;
    ui->lineEdit->setText(filter_obj.allProducts()[index_filter].group);
    ui->lineEdit_2->setText(filter_obj.allProducts()[index_filter].model);
    ui->lineEdit_3->setText(filter_obj.allProducts()[index_filter].name);
    ui->lineEdit_4->setText(filter_obj.allProducts()[index_filter].brand);
    ui->lineEdit_5->setText(filter_obj.allProducts()[index_filter].color);
    ui->lineEdit_6->setText(QString::number(filter_obj.allProducts()[index_filter].number));
    ui->lineEdit_7->setText(QString::number(filter_obj.allProducts()[index_filter].weight));
    ui->lineEdit_8->setText(QString::number(filter_obj.allProducts()[index_filter].price));
    ui->lineEdit_9->setText(filter_obj.allProducts()[index_filter].warranty);
    index_filter++;
}

void Client::on_pushButton_5_clicked()
{
    if(ui->lineEdit->text() == "" )
    {
        QMessageBox::information(this,"Error","There is no product on the page.");
        return;
    }
    if(ui->spinBox->value() > ui->lineEdit_6->text().toInt() )
    {
        QMessageBox::information(this,"Error","The number of goods requested is more than the number of available goods.");
        return;
    }
    if(ui->label_budget->text().toInt() < ui->lineEdit_8->text().toInt() * ui->spinBox->value())
    {
        QMessageBox::information(this,"Error","Your budget is not enough");
        return;
    }


    int budget = ui->label_budget->text().toInt() - ui->lineEdit_8->text().toInt() * ui->spinBox->value();
    ui ->label_budget->setNum(budget);
    vec_info_client[5] = QString::number(budget);
    EditProfile obj_edit_budget;
    obj_edit_budget.Edit_Profile(vec_info_client[0],"Budget",QString::number(budget));

    obj_edit_budget.Edit_Profile(filter_obj.allProducts()[index_filter-1].userNameSeller,"Budget",
    QString::number((ui->lineEdit_8->text().toInt() * ui->spinBox->value())+
    obj_edit_budget.getBudget(filter_obj.allProducts()[index_filter-1].userNameSeller).toInt()));

    ui->lineEdit_6->setText(QString::number(ui->lineEdit_6->text().toInt() - (ui->spinBox->value())));

    bak::Buyer buy_obj {vec_info_client[0].toStdString()};
    buy_obj.setCountProduct(filter_obj.allProducts()[index_filter-1].CountProduct);
    buy_obj.setNumberPurchased(ui->spinBox->value());
    buy_obj.buy();
    QMessageBox::information(this,"Payment","Your purchase was completed successfully.");
}


void Client::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text() == "" )
    {
        QMessageBox::information(this,"Error","There is no product on the page.");
        return;
    }
    if(ui->spinBox->value() > ui->lineEdit_6->text().toInt() )
    {
        QMessageBox::information(this,"Error","The number of goods requested is more than the number of available goods.");
        return;
    }
    //
    Abstract_Transactions* payment_obj = new Payment_Client(nullptr,vec_info_client,
    ui->lineEdit_8->text().toInt() * ui->spinBox->value() , ui->spinBox->value() ,
    filter_obj.allProducts()[index_filter-1].CountProduct , filter_obj.allProducts()[index_filter-1].userNameSeller);
    //
    this->close();
    payment_obj->show();
}

