#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QWidget>

namespace Ui {
class transaction;
}

class transaction : public QWidget
{
    Q_OBJECT

public:
    explicit transaction(QWidget *parent = nullptr);
    ~transaction();

private:
    Ui::transaction *ui;
};

#endif // TRANSACTION_H
