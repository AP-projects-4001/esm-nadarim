#ifndef INCREASE_BUDGET_H
#define INCREASE_BUDGET_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
namespace Ui {
class Increase_Budget;
}

class Increase_Budget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Increase_Budget(QWidget *parent , QVector<QString> _vec_info);
    ~Increase_Budget();

private slots:
    void update_time();

    void on_pushButton_clicked();

private:
    Ui::Increase_Budget *ui;
    QVector<QString> vec_info{6};
    QTimer* t;
};

#endif // INCREASE_BUDGET_H
