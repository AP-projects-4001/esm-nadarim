#include "increase_budget.h"
#include "ui_increase_budget.h"
#include "edit_profile_client.h"
#include "editprofile.h"
Increase_Budget::Increase_Budget(QWidget *parent, QVector<QString> _vec_info) :
    QMainWindow(parent),
    ui(new Ui::Increase_Budget)
{
    ui->setupUi(this);
    vec_info = _vec_info;
    t = new QTimer(this);
    t->setInterval(1000);
    t->start();
    connect(t,SIGNAL(timeout()),this,SLOT(update_time()));
 }

Increase_Budget::~Increase_Budget()
{
    delete ui;
    delete t;
}

void Increase_Budget::update_time()
{
    if(ui->label_minute->text().toInt() == 0 && ui->label_second->text().toInt() == 0 )
    {
        QMessageBox::information(this,"Time is over","Payment failed");
        t->stop();
        Edit_Profile_Client* profile_obj = new Edit_Profile_Client(nullptr,vec_info);
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

void Increase_Budget::on_pushButton_clicked()
{
    if(ui->spinBox_part1->value() < 5000 || ui->spinBox_part2->value() == 1000 ||
            ui->spinBox_part3->value() == 1000 || ui->spinBox_part4->value() == 1000 )
    {
        QMessageBox::information(this,"Payment","Card number is incorrect");
        return;
    }
    t->stop();
    QMessageBox::information(this,"Payment","Payment was successful");
    vec_info[5] = QString::number(vec_info[5].toInt()+ui->spinBox_budget->value());
    Edit_Profile_Client* profile_obj = new Edit_Profile_Client(nullptr,vec_info);
    EditProfile obj;
    obj.Edit_Profile(vec_info[0],"Budget",vec_info[5]);
    profile_obj->show();
    this->close();
}


void Increase_Budget::on_actionBack_triggered()
{
    QMessageBox::information(this,"Payment","Payment failed");
    t->stop();
    Edit_Profile_Client* profile_obj = new Edit_Profile_Client(nullptr,vec_info);
    profile_obj->show();
    this->close();

}

