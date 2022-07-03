#ifndef CHANGEPROFILE_H
#define CHANGEPROFILE_H

#include <QWidget>

namespace Ui {
class changeprofile;
}

class changeprofile : public QWidget
{
    Q_OBJECT

public:
    explicit changeprofile(QWidget *parent = nullptr,QString username="");
    ~changeprofile();

private slots:
    void on_pushButton_2_clicked();

    void on_back_btn_clicked();

private:
    Ui::changeprofile *ui;
    QString Username;
    QString Username_1;
    QString name;
    QString budget;
    QString phonenum;
    QString address;
    QString password;
};

#endif // CHANGEPROFILE_H
