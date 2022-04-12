#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //宽900，高600
    w.setFixedSize(900, 600);
    w.setWindowTitle("植物大战僵尸QAQ");
    w.show();

    return a.exec();
}
