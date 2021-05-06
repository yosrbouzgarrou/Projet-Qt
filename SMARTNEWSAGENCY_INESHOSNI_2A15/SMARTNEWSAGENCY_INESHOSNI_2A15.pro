QT       += core gui sql printsupport
QT       += core gui network
QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connexion.cpp \
    fourniture.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp \
    notification.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    fourniture.h \
    mainwindow.h \
    materiel.h \
    notification.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target