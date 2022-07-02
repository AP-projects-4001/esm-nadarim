#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QWidget>
#include "changeprofile.h"
#include "transaction.h"
#include "addproduct.h"
#include "allproducts.h"

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

    void on_soldproduct_btn_clicked();

    void on_addproduct_btn_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Customer *ui;
    QString username;
    changeprofile *changeprof;
    transaction *Transaction;
    addproduct *addnew;
    allproducts *products;

};

#endif // CUSTOMER_H
