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

private:
    Ui::changeprofile *ui;
};

#endif // CHANGEPROFILE_H
