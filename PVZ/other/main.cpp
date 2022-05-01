#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //宽900，高600
    w.setFixedSize(900, 600);
    w.setWindowTitle("PlantsVsZombiesQAQ");
    w.show();
    return a.exec();
}
