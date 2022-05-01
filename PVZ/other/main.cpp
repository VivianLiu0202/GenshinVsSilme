#include <QApplication>
#include "mainwindow.h"
#include <./form.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form win;
    win.setFixedSize(900, 600);
    win.setWindowTitle("原神大战丘丘人QAQ");
    QPalette palette;
    QPixmap pixmap(":/images/loginBackground.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    win.setPalette(palette);
    win.show();
    /*MainWindow w;
    //宽900，高600
    w.setFixedSize(900, 600);
    w.setWindowTitle("PlantsVsZombiesQAQ");
    w.show();*/
    return a.exec();
}
