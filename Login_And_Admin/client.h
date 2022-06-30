#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
//#include "edit_profile_client.h"
#include <QFile>
#include "filter.h"
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

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_group_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Client *ui;
    QString username_client;
    QVector <QString> vec_info_client{6};
    bak::filter filter_obj;
    int index_filter = 1;
};

#endif // CLIENT_H
