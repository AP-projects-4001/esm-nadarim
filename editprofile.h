#ifndef EDITPROFILE_H
#define EDITPROFILE_H
#include <QString>


class EditProfile
{
public:
    void Delete_Profile(QString username);
    void Edit_Profile(QString username,QString part,QString NewInput);
    void cahnge_username(QString old_User,QString new_User);
};

#endif // EDITPROFILE_H
