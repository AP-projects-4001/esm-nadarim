#include "abstract_transactions.h"

#include "edit_profile_client.h"
#include "ui_abstract_transactions.h"

Abstract_Transactions::Abstract_Transactions(QWidget *parent, QVector<QString> _vector_info) :
    QMainWindow(parent),
    ui(new Ui::Abstract_Transactions)
{
    ui->setupUi(this);
    ui->lineEdit_part1->setValidator(new QIntValidator(5000, 6999, this));
    ui->lineEdit_part2->setValidator(new QIntValidator(1001, 9999, this));
    ui->lineEdit_part3->setValidator(new QIntValidator(1001, 9999, this));
    ui->lineEdit_part4->setValidator(new QIntValidator(1001, 9999, this));
    vector_info = _vector_info;
    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(update_time()));
}

Abstract_Transactions::~Abstract_Transactions()
{
    delete ui;
    delete timer;
}

void Abstract_Transactions::update_time()
{
    if(ui->label_minute->text().toInt() == 0 && ui->label_second->text().toInt() == 0 )
    {
        QMessageBox::information(this,"Time is over","Payment failed");
        timer->stop();
        Edit_Profile_Client* profile_obj = new Edit_Profile_Client(nullptr,vector_info);
        profile_obj->show();
        this->close();
    }
    if(ui->label_second->text().toInt() == 0)
    {
        ui->label_minute->setNum(ui->label_minute->text().toInt()-1);
        ui->label_second->setNum(59);
        return;
    }
    ui->label_second->setNum(ui->label_second->text().toInt()-1);
}



