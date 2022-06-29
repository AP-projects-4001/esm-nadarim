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

private:
    Ui::allproducts *ui;
    std::vector<bak::product> Allproducts;
    int index;
};

#endif // ALLPRODUCTS_H
