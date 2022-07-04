#include "admin.h"
#include "QValidator"//"
#include "ui_admin.h"
#include "editprofile.h"

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
    QFile readFile("test.txt");
    if (readFile.open(QIODevice::ReadOnly))
    {
       int pos;

       QTextStream in(&readFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          pos = line.indexOf(":");
          if (pos == -1)
          {
              continue;
          }
          line = line.sliced(pos+1);
          vecAdmin.append(line);
       }
       readFile.close();
       if(vecAdmin.size() >=8)
       {
           ui->lineEdit->setText(vecAdmin[0]);
           ui->lineEdit_2->setText(vecAdmin[1]);
           ui->lineEdit_3->setText(vecAdmin[2]);
           ui->textEdit->setText(vecAdmin[3]);
           ui->lineEdit_4->setText(vecAdmin[4]);
           ui->lineEdit_5->setText(vecAdmin[5]);
           ui->lineEdit_6->setText(vecAdmin[6]);
           ui->lineEdit_7->setText(vecAdmin[7]);
           if (vecAdmin[7] == "False")
           {
                ui->pushButton_8->setText("Activate account");
           }
           index = 8;
        }
       bak::manager obj_manager;
       std::vector<bak::product> vecTransaction = obj_manager.allTransactions();
       if(vecTransaction.size() > 0 )
       {
           ui->lineEdit_8->setText(obj_manger.allTransactions()[0].userNameBuyer);
           ui->lineEdit_9->setText(obj_manger.allTransactions()[0].userNameSeller);
           ui->lineEdit_10->setText(obj_manger.allTransactions()[0].group);
           ui->lineEdit_11->setText(obj_manger.allTransactions()[0].name);
           ui->lineEdit_12->setText(QString::number(obj_manger.allTransactions()[0].price));
           ui->lineEdit_13->setText(QString::number(obj_manger.allTransactions()[0].number));
           index_transaction = 1;
       }

    }
        ui->lineEdit_4->setValidator(new QIntValidator(9000000000,990000000000 , this));
}

Admin::~Admin()
{
    delete ui;
}


void Admin::on_pushButton_clicked()
{
    if (vecAdmin.size() == index)
    {
        return;
    }
    ui->lineEdit->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_2->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_3->setText(vecAdmin[index]);
    index++;
    ui->textEdit->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_4->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_5->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_6->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_7->setText(vecAdmin[index]);
    if (vecAdmin[index] == "False")
    {
         ui->pushButton_8->setText("Activate account");
    }
    else if (vecAdmin[index] == "True")
    {
         ui->pushButton_8->setText("Disable account");
    }
    index++;

}


void Admin::on_pushButton_2_clicked()
{


    if(index <= 9)
    {
        return;
    }
     index = index -16;
    ui->lineEdit->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_2->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_3->setText(vecAdmin[index]);
    index++;
    ui->textEdit->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_4->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_5->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_6->setText(vecAdmin[index]);
    index++;
    ui->lineEdit_7->setText(vecAdmin[index]);
    if (vecAdmin[index] == "False")
    {
         ui->pushButton_8->setText("Activate account");
    }
    else if (vecAdmin[index] == "True")
    {
         ui->pushButton_8->setText("Disable account");
    }
    index++;
}


void Admin::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText("No user available");
        msg->exec();
        return;
    }
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    //ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->lineEdit->setReadOnly(false);
    ui->lineEdit_2->setReadOnly(false);
    ui->lineEdit_4->setReadOnly(false);
    ui->textEdit->setReadOnly(false);
}


void Admin::on_pushButton_7_clicked()
{
    if( ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->textEdit->toPlainText() == "" || ui->lineEdit_4->text()=="")
    {
        QMessageBox msg;
        msg.setText("All fields must be filled");
        msg.exec();
        return;
    }

    EditProfile obj;
    if(obj.checkusername(ui->lineEdit->text()) == 1)
    {
        QMessageBox::information(this,"Error","This username is already registered for another user");
        return;
    }
    obj.change_username(vecAdmin[index-8] ,ui->lineEdit->text());
    vecAdmin[index-8]= ui->lineEdit->text();
    obj.Edit_Profile(ui->lineEdit->text(),ui->label_2->text(),ui->lineEdit_2->text());
    vecAdmin[index-7] = ui->lineEdit_2->text();
    obj.Edit_Profile(ui->lineEdit->text(),ui->label_4->text(),ui->textEdit->toPlainText());
    vecAdmin[index-5] = ui->textEdit->toPlainText();
    obj.Edit_Profile(ui->lineEdit->text(),ui->label_5->text(),ui->lineEdit_4->text());
    vecAdmin[index-4] = ui->lineEdit_4->text();
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    //ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->textEdit->setReadOnly(true);
}


void Admin::on_pushButton_5_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText("No user available");
        msg->exec();
        return;
    }
    if(ui->lineEdit_5->text() == "Admin")
    {
        QMessageBox::information(this,"Error","You cannot delete the admin.");
        return;
    }

    obj.Delete_Profile(ui->lineEdit->text());
    for(int j=-8 ; j<0 ; j++)
    {
        index--;
        vecAdmin.remove(index);
    }
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->textEdit->clear();
}


void Admin::on_pushButton_8_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox* msg = new QMessageBox();
        msg->setText("No user available");
        msg->exec();
        return;
    }
    if(ui->lineEdit_5->text() == "Admin")
    {
        QMessageBox::information(this,"Error","You cannot disable admin access.");
        return;
    }
    if (ui->pushButton_8->text() == "Activate account")
    {
        ui->lineEdit_7->setText("True");
        vecAdmin[index-1] = "True";
        obj.Edit_Profile(ui->lineEdit->text(),"Status" , "True");
        ui->pushButton_8->setText("Disable account");
    }
    else if (ui->pushButton_8->text() == "Disable account")
    {
        ui->lineEdit_7->setText("False");
        vecAdmin[index-1] = "False";
        obj.Edit_Profile(ui->lineEdit->text(),"Status" , "False");
        ui->pushButton_8->setText("Activate account");
    }
}



/*void Admin::on_pushButton_3_clicked()
{
    bak::manager obj_manager;
    std::vector<bak::product> vec_transaction = obj_manager.allTransactions();
    for(int j =0 ; j < vec_transaction.size() ; j++)
    {
        //ui->listWidget->addItem(vec_transaction[j].);
    }
}*/


void Admin::on_pushButton_9_clicked()
{
    if(obj_manger.allTransactions().size() == index_transaction -1)
    {
        return;
    }
    ui->lineEdit_8->setText(obj_manger.allTransactions()[index_transaction].userNameBuyer);
    ui->lineEdit_9->setText(obj_manger.allTransactions()[index_transaction].userNameSeller);
    ui->lineEdit_10->setText(obj_manger.allTransactions()[index_transaction].group);
    ui->lineEdit_11->setText(obj_manger.allTransactions()[index_transaction].name);
    ui->lineEdit_12->setText(QString::number(obj_manger.allTransactions()[index_transaction].price));
    ui->lineEdit_13->setText(QString::number(obj_manger.allTransactions()[index_transaction].number));
    index_transaction++;
}


void Admin::on_pushButton_10_clicked()
{

    if(index_transaction < 2)
    {
        return;
    }
    index_transaction -= 2;
    ui->lineEdit_8->setText(obj_manger.allTransactions()[index_transaction].userNameBuyer);
    ui->lineEdit_9->setText(obj_manger.allTransactions()[index_transaction].userNameSeller);
    ui->lineEdit_10->setText(obj_manger.allTransactions()[index_transaction].group);
    ui->lineEdit_11->setText(obj_manger.allTransactions()[index_transaction].name);
    ui->lineEdit_12->setText(QString::number(obj_manger.allTransactions()[index_transaction].price));
    ui->lineEdit_13->setText(QString::number(obj_manger.allTransactions()[index_transaction].number));
    index_transaction++;
}


void Admin::on_actionBack_triggered()
{
    this->close();
}

