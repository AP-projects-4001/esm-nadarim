#ifndef EDIT_PROFILE_CLIENT_H
#define EDIT_PROFILE_CLIENT_H

#include <QMainWindow>

namespace Ui {
class Edit_Profile_Client;
}

class Edit_Profile_Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Edit_Profile_Client(QWidget *parent = nullptr);
    ~Edit_Profile_Client();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::Edit_Profile_Client *ui;
};

#endif // EDIT_PROFILE_CLIENT_H
