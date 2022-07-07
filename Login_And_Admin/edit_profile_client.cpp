#include "edit_profile_client.h"
#include <QValidator>
#include "ui_edit_profile_client.h"
#include "increase_budget.h"
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
    vec_info_profile_client.clear();
    delete ui;
    this->close();
}


void Edit_Profile_Client::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->lineEdit->setReadOnly(false);
    ui->lineEdit_2->setReadOnly(false);
    ui->lineEdit_3->setReadOnly(false);
    ui->lineEdit_4->setReadOnly(false);
    ui->textEdit->setReadOnly(false);
}


void Edit_Profile_Client::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" ||
            ui->lineEdit_3->text()=="" || ui->textEdit->toPlainText()=="" || ui->lineEdit_4->text()=="")
    {
        QMessageBox msg;
        msg.setText("All fields must be filled");
        msg.exec();
        return;
    }
    bak::checkPassword check_pass(ui->lineEdit_3->text().toStdString());
    if(check_pass.isConfirm() == false)
    {
        QMessageBox::information(this,"Error",QString::fromStdString(check_pass.getErr()));
        return;
    }
    if(ui->lineEdit_4->text().size() < 10)
    {
        QMessageBox::information(this,"Error","Invalid phoneNumber");
        return;
    }
    EditProfile editProfile_obj;
    if(editProfile_obj.checkusername(ui->lineEdit->text()) == 1 && vec_info_profile_client[0] != ui->lineEdit->text())
    {
        QMessageBox::information(this,"Error","This username is already registered for another user");
        return;
    }
    editProfile_obj.change_username(vec_info_profile_client[0],ui->lineEdit->text());
    vec_info_profile_client[0] = ui->lineEdit->text();
    editProfile_obj.Edit_Profile(vec_info_profile_client[0],"Name",ui->lineEdit_2->text());
    vec_info_profile_client[1] = ui->lineEdit_2->text();
    editProfile_obj.Edit_Profile(vec_info_profile_client[0],"Password",ui->lineEdit_3->text());
    vec_info_profile_client[2] = ui->lineEdit_3->text();
    editProfile_obj.Edit_Profile(vec_info_profile_client[0],"Address",ui->textEdit->toPlainText());
    vec_info_profile_client[3] = ui->textEdit->toPlainText();
    editProfile_obj.Edit_Profile(vec_info_profile_client[0],"Phone-number",ui->lineEdit_4->text());
    vec_info_profile_client[4] = ui->lineEdit_4->text();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->textEdit->setReadOnly(true);
}


void Edit_Profile_Client::on_actionBack_triggered()
{
    Client* newClient = new Client(nullptr,"Username:"+vec_info_profile_client[0]);
    this->close();
    vec_info_profile_client.clear();
    delete ui;
    newClient->show();
}


void Edit_Profile_Client::on_pushButton_3_clicked()
{
    Increase_Budget* amount_of_Budget = new Increase_Budget(nullptr,vec_info_profile_client);
    this->close();
    amount_of_Budget->show();

}

