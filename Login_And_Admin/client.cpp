#include "client.h"
#include "ui_client.h"
#include "edit_profile_client.h"
Client::Client(QWidget *parent,QString username_client) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    QString  line;
    int pos;
    this->username_client = username_client;
    QFile read_file("C:/Users/Lenovo/Desktop/test.txt");
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
           ui->label_budget->setText(vec_info_client[5]);
       }
           read_file.close();
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
    this->close();
}

