#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "product.h"
#include <QWidget>

namespace Ui {
class transaction;
}

class transaction : public QWidget
{
    Q_OBJECT

public:
    explicit transaction(QWidget *parent = nullptr, QString username="");
    ~transaction();

private slots:
    void on_next_btn_clicked();

    void on_previous_btn_clicked();



    void on_back_btn_clicked();

private:
    Ui::transaction *ui;
    int index;
    std::vector<bak::product> vecTransaction;
    QString username;
};

#endif // TRANSACTION_H
