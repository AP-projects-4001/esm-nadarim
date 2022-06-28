#ifndef ALLPRODUCTS_H
#define ALLPRODUCTS_H

#include <QWidget>

namespace Ui {
class allproducts;
}

class allproducts : public QWidget
{
    Q_OBJECT

public:
    explicit allproducts(QWidget *parent = nullptr);
    ~allproducts();

private:
    Ui::allproducts *ui;
};

#endif // ALLPRODUCTS_H
