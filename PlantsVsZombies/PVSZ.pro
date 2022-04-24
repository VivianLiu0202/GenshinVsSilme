#-------------------------------------------------
#
# Project created by QtCreator 2022-04-14T16:17:19
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../PlantsVsZombies
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
    src/other/button.cpp \
    src/other/card.cpp \
    src/other/map.cpp \
    src/other/mower.cpp \
    src/other/other.cpp \
    src/other/pea.cpp \
    src/other/shop.cpp \
    src/other/shovel.cpp \
    src/other/sun.cpp \
    src/other/main.cpp \
    src/other/mainwindow.cpp \
    src/plant/Venti.cpp \
    src/plant/plant.cpp \
    src/zombie/basiczombie.cpp \
    src/zombie/bucketzombie.cpp \
    src/zombie/conezombie.cpp \
    src/zombie/footballzombie.cpp \
    src/zombie/screenzombie.cpp \
    src/zombie/zombie.cpp \
    src/plant/ZhongLi.cpp \
    src/plant/Xiangling.cpp \
    src/plant/Qiqi.cpp \
    src/plant/Ganyu.cpp \
    src/plant/Klee.cpp \
    src/plant/Dadaliya.cpp

HEADERS += \
    src/other/button.h \
    src/other/card.h \
    src/other/map.h \
    src/other/mower.h \
    src/other/other.h \
    src/other/pea.h \
    src/other/shop.h \
    src/other/shovel.h \
    src/other/sun.h \
    src/other/mainwindow.h \
    src/plant/Venti.h \
    src/plant/plant.h \
    src/zombie/basiczombie.h \
    src/zombie/bucketzombie.h \
    src/zombie/conezombie.h \
    src/zombie/footballzombie.h \
    src/zombie/screenzombie.h \
    src/zombie/zombie.h \
    src/other/init.h \
    src/plant/ZhongLi.h \
    src/plant/Xiangling.h \
    src/plant/Qiqi.h \
    src/plant/Ganyu.h \
    src/plant/Klee.h \
    src/plant/Dadaliya.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc


# 图标
RC_ICONS += \
    ./images/window.ico
