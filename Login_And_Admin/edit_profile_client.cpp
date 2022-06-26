#include "edit_profile_client.h"
#include "ui_edit_profile_client.h"

Edit_Profile_Client::Edit_Profile_Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Edit_Profile_Client)
{
    ui->setupUi(this);
}

Edit_Profile_Client::~Edit_Profile_Client()
{
    delete ui;
}

void Edit_Profile_Client::on_pushButton_4_clicked()
{
    this->close();
}

