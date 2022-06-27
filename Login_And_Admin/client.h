#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
//#include "edit_profile_client.h"
#include <QFile>
namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr, QString username_client = "");
    ~Client();

private slots:
    //void on_pushButton_clicked();

    void on_actionProfile_triggered();

    void on_actionExit_triggered();

    void on_horizontalSlider_maxPrice_rangeChanged(int min, int max);

private:
    Ui::Client *ui;
    QString username_client;
    QVector <QString> vec_info_client{6};
};

#endif // CLIENT_H
