#ifndef EDITPROFILE_H
#define EDITPROFILE_H
#include "checkpassword.h"
#include <QString>
#include <QMessageBox>

class EditProfile
{
public:
    void Delete_Profile(QString username);
    void Edit_Profile(QString username,QString part,QString NewInput);
    bool change_username(QString old_User,QString new_User);
    int checkusername(QString username);
    QString getBudget(QString username);
    bool checkpass(QString password);
private:
     bak::checkPassword *newpassword;
};

#endif // EDITPROFILE_H
