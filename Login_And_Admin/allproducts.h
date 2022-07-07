#ifndef ALLPRODUCTS_H
#define ALLPRODUCTS_H

#include "product.h"
#include <QWidget>

namespace Ui {
class allproducts;
}

class allproducts : public QWidget
{
    Q_OBJECT

public:
    explicit allproducts(QWidget *parent = nullptr, QString username="");
    ~allproducts();

private slots:
    void on_next_btn_clicked();

    void on_previous_btn_clicked();

    void on_group_combo_currentTextChanged();

    void on_delete_btn_clicked();

    void on_save_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::allproducts *ui;
    std::vector<bak::product> Allproducts;
    int index;
    int deleteCount;
    QString username;
    QString group;
    QString product;
    QString color;
    QString warranty;
    QString productname;
    QString brand;
    QString number;
    QString weight;
    QString price;
};

#endif // ALLPRODUCTS_H
