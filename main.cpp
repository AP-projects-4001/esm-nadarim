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


    MainWindow w;
    w.show();
    return a.exec();
}
