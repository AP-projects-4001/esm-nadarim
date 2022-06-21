#include "editprofile.h"
#include <QFile>
#include <QDebug>
#include <QString>



void EditProfile::Delete_Profile(QString username)
{
    int flag=0;
    username="Username:"+username;
    QFile read_file("C:/Users/amirr/Desktop/test.txt");
    QFile write_file("C:/Users/amirr/Desktop/tmp.txt");
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



    QFile read_Tmpfile("C:/Users/amirr/Desktop/tmp.txt");
    QFile write_Mainfile("C:/Users/amirr/Desktop/test.txt");
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

    QFile read_file("C:/Users/amirr/Desktop/test.txt");
    QFile write_file("C:/Users/amirr/Desktop/tmp.txt");
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
          else if(part=="PhoneNumber" && flag==5)
              out<<NewInput<<Qt::endl;
          else
              out<<line<<Qt::endl;





       }
       read_file.close();
       write_file.close();
    }



    QFile read_Tmpfile("C:/Users/amirr/Desktop/tmp.txt");
    QFile write_Mainfile("C:/Users/amirr/Desktop/test.txt");
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
