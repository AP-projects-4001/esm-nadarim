#ifndef ADMIN_H
#define ADMIN_H
#include <QMessageBox>
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QVector>
#include <editprofile.h>
#include <QTimer>
#include "manager.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Admin; }
QT_END_NAMESPACE

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    //void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::Admin *ui;
    QVector<QString>vecAdmin;
    int index = 0;
    EditProfile obj;
    //bak::manager obj_manager;
    int index_transaction = 0;
    std::vector<bak::product> vecTransaction;
};
#endif // ADMIN_H
