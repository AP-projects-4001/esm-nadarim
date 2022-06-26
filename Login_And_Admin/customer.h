#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QWidget>
#include "changeprofile.h"

namespace Ui {
class Customer;
}

class Customer : public QWidget
{
    Q_OBJECT

public:
    explicit Customer(QWidget *parent = nullptr,QString username="");
    ~Customer();

private slots:
    void on_editprofile_btn_clicked();

private:
    Ui::Customer *ui;
    QString username;
    changeprofile *changeprof;

};

#endif // CUSTOMER_H
