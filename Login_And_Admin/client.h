#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include "edit_profile_client.h"
namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_pushButton_clicked();

    void on_actionProfile_triggered();

    void on_actionExit_triggered();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
