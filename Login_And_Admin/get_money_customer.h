#ifndef GET_MONEY_CUSTOMER_H
#define GET_MONEY_CUSTOMER_H

#include "editprofile.h"
#include <QMainWindow>
#include <abstract_transactions.h>
namespace Ui {
class Get_Money_Customer;
}

class Get_Money_Customer : public Abstract_Transactions
{
    Q_OBJECT

public:
    explicit Get_Money_Customer(QWidget *parent,QVector<QString> vec);
    ~Get_Money_Customer();

private slots:

    virtual void on_actionBack_triggered();

    virtual void on_pushButton_confirm_clicked();

private:
    QString username;
    EditProfile edit_budget;
};

#endif // GET_MONEY_CUSTOMER_H
