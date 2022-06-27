#ifndef EDIT_PROFILE_CLIENT_H
#define EDIT_PROFILE_CLIENT_H

#include <QMainWindow>
#include <QMessageBox>
#include "editprofile.h"
#include"client.h"
namespace Ui {
class Edit_Profile_Client;
}

class Edit_Profile_Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Edit_Profile_Client(QWidget *parent,QVector<QString> vec_info);
    ~Edit_Profile_Client();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionBack_triggered();

    void on_pushButton_3_clicked();

private:
    Ui::Edit_Profile_Client *ui;
    QVector<QString>vec_info_profile_client{6};
};

#endif // EDIT_PROFILE_CLIENT_H
