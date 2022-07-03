#ifndef ABSTRACT_TRANSACTIONS_H
#define ABSTRACT_TRANSACTIONS_H

#include <QMainWindow>
#include "QValidator"
#include "QTimer"
namespace Ui {
class Abstract_Transactions;
}

class Abstract_Transactions : public QMainWindow
{
    Q_OBJECT

public:
    explicit Abstract_Transactions(QWidget *parent , QVector<QString> _vector_info);
    ~Abstract_Transactions();
private slots:
    void update_time();

    virtual void on_actionBack_triggered() = 0;

    virtual void on_pushButton_confirm_clicked() = 0;

private:
    Ui::Abstract_Transactions *ui;
    QVector<QString> vector_info{6};
    QTimer* timer;
};

#endif // ABSTRACT_TRANSACTIONS_H
