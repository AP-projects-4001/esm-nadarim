#include "edit_profile_client.h"
#include "ui_edit_profile_client.h"

Edit_Profile_Client::Edit_Profile_Client(QWidget *parent,QVector<QString> vec_info) :
    QMainWindow(parent),
    ui(new Ui::Edit_Profile_Client)
{
    ui->setupUi(this);
    vec_info_profile_client = vec_info;
    ui->lineEdit->setText(vec_info_profile_client[0]);
    ui->lineEdit_2->setText(vec_info_profile_client[1]);
    ui->lineEdit_3->setText(vec_info_profile_client[2]);
    ui->textEdit->setText(vec_info_profile_client[3]);
    ui->lineEdit_4->setText(vec_info_profile_client[4]);
    ui->lineEdit_6->setText(vec_info_profile_client[5]);
}

Edit_Profile_Client::~Edit_Profile_Client()
{
    delete ui;
}

void Edit_Profile_Client::on_pushButton_4_clicked()
{
    this->close();
}

