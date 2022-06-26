#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
}

Client::~Client()
{
    delete ui;
}



void Client::on_actionProfile_triggered()
{
    Edit_Profile_Client* edit_obj = new Edit_Profile_Client(this);
    edit_obj->show();
}


void Client::on_actionExit_triggered()
{
    this->close();
}

