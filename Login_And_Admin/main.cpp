#include "mainwindow.h"
#include <QApplication>
#include <qstring.h>
#include <fstream>
#include <iostream>
#include <QFile>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //open qss file
    /*QFile file("C:/Users/amirr/Desktop/Codes/Hookmark.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet=QLatin1String(file.readAll());

    //setup stylesheet
    a.setStyleSheet(styleSheet);*/


    MainWindow w;
    w.show();
    return a.exec();
}
