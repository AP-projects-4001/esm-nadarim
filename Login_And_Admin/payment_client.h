#ifndef PAYMENT_CLIENT_H
#define PAYMENT_CLIENT_H

#include <QMainWindow>
#include <abstract_transactions.h>
namespace Ui {
class Payment_Client;
}

class Payment_Client : public Abstract_Transactions
{
    Q_OBJECT

public:
    explicit Payment_Client(QWidget *parent , QVector<QString> vec, int _budget, int number, int countProduct , QString username_seller);
    ~Payment_Client();

private slots:

    virtual void on_actionBack_triggered();

    virtual void on_pushButton_confirm_clicked();
private:
    QString username_seller;
    int number;
    int countProduct;
};

#endif // PAYMENT_CLIENT_H
