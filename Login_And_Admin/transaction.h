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

private slots:
    void on_next_btn_clicked();

private:
    Ui::transaction *ui;
};

#endif // TRANSACTION_H
