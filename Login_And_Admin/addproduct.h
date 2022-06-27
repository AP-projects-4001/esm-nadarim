#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QWidget>


namespace Ui {
class addproduct;
}

class addproduct : public QWidget
{
    Q_OBJECT

public:
    explicit addproduct(QWidget *parent = nullptr,QString username="");
    ~addproduct();
    void addtofile(void);

private slots:

    void on_group_combo_currentTextChanged();

    void on_confirm_btn_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addproduct *ui;
    QString username;


};

#endif // ADDPRODUCT_H
