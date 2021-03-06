#include "editprofile.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QString>
#include "qmessagebox.h"



void EditProfile::Delete_Profile(QString username)
{
    int flag=0;
    username="Username:"+username;
    QFile read_file("test.txt");
    QFile write_file("tmp.txt");
    write_file.open(QIODevice::WriteOnly);
    if (read_file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_file);
       QTextStream out(&write_file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(line==username)
              ++flag;
          if(flag>0 && flag<10){
              ++flag;
              continue;
          }
          if(flag==0 || flag>=10){
              out<<line<<Qt::endl;
          }


       }
       read_file.close();
       write_file.close();
    }



    QFile read_Tmpfile("tmp.txt");
    QFile write_Mainfile("test.txt");
    write_Mainfile.open(QIODevice::WriteOnly);
    if (read_Tmpfile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_Tmpfile);
       QTextStream out(&write_Mainfile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          out<<line<<Qt::endl;


       }
       read_Tmpfile.close();
       write_Mainfile.close();
       read_Tmpfile.remove();
    }

}

void EditProfile::Edit_Profile(QString username, QString part, QString NewInput)
{
    NewInput=username+"-"+part+":"+NewInput;
    username="Username:"+username;
    qDebug()<<username;

    int flag=0;

    QFile read_file("test.txt");
    QFile write_file("tmp.txt");
    write_file.open(QIODevice::WriteOnly);
    if (read_file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_file);
       QTextStream out(&write_file);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          if(flag>0 && flag<10)
              ++flag;
          if(line==username)
              ++flag;
          if(part=="Name" && flag==2)
              out<<NewInput<<Qt::endl;
          else if(part=="Password" && flag==3)
              out<<NewInput<<Qt::endl;
          else if(part=="Address" && flag==4)
              out<<NewInput<<Qt::endl;
          else if(part=="Phone-number" && flag==5)
              out<<NewInput<<Qt::endl;
          else if(part=="Budget" && flag==7)
              out<<NewInput<<Qt::endl;
          else if(part=="Status" && flag==8)
              out<<NewInput<<Qt::endl;
          else
              out<<line<<Qt::endl;





       }
       read_file.close();
       write_file.close();
    }



    QFile read_Tmpfile("tmp.txt");
    QFile write_Mainfile("test.txt");

    write_Mainfile.open(QIODevice::WriteOnly);
    if (read_Tmpfile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_Tmpfile);
       QTextStream out(&write_Mainfile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          out<<line<<Qt::endl;

       }
       read_Tmpfile.close();
       write_Mainfile.close();
       read_Tmpfile.remove();
    }
}

int EditProfile::checkusername(QString username){
    username="Username:"+username;
    int flag=0;
    QFile read_file("test.txt");
    qDebug()<<username;
    if (read_file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(username==line){
              ++flag;
              return flag;
          }

       }
       read_file.close();
    }
    return -1;
}

QString EditProfile::getBudget(QString username)
{
    int flag=0;
    int txtsize=username.size();

    username="Username:"+username;

    QFile read_file("test.txt");
    if (read_file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(line==username)
             ++flag;
          if(flag==7){
              line.remove(0,txtsize);
              line.remove(0,8);
              return line;
          }
          if(flag>0 && flag<8)
              ++flag;

       }
       read_file.close();
    }
    return "Not found";
}

bool EditProfile::checkpass(QString password)
{
    newpassword=new bak::checkPassword(password.toStdString());
    if(!newpassword->isConfirm()){
        return false;
    }
    return true;
}

bool EditProfile::change_username(QString old_User, QString new_User)
{
    int flag=0,checkuser=0;
    int txtsize=old_User.size();

    checkuser=checkusername(new_User);
    if(checkuser!=-1){
       return false;
    }

    old_User="Username:"+old_User;
    qDebug()<<old_User;

    QFile read_file("test.txt");
    QFile write_file("tmp.txt");

    write_file.open(QIODevice::WriteOnly);
    if (read_file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_file);
       QTextStream out(&write_file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(line==old_User){
              ++flag;
              QString newuser="Username:"+new_User;
              out<<newuser<<Qt::endl;
              continue;
          }
          if(flag>0 && flag<8){
                qDebug()<<flag;
                line.remove(0,txtsize);
                line=new_User+line;
                out<<line<<Qt::endl;
                ++flag;
                continue;
          }
          if(flag==0 || flag>=8){
              out<<line<<Qt::endl;
          }

        qDebug()<<flag;
       }
       read_file.close();
       write_file.close();
    }



    QFile read_Tmpfile("tmp.txt");
    QFile write_Mainfile("test.txt");
    write_Mainfile.open(QIODevice::WriteOnly);
    if (read_Tmpfile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&read_Tmpfile);
       QTextStream out(&write_Mainfile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          out<<line<<Qt::endl;


       }
       read_Tmpfile.close();
       write_Mainfile.close();
       read_Tmpfile.remove();
    }

    return true;
}


