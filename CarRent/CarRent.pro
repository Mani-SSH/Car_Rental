QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    admin_info.cpp \
    car.cpp \
    change_admin.cpp \
    costumer.cpp \
    main.cpp \
    loginadmin.cpp \
    mainscreen.cpp \
    sql.cpp

HEADERS += \
    account.h \
    admin_info.h \
    car.h \
    change_admin.h \
    costumer.h \
    loginadmin.h \
    mainscreen.h \
    sql.h

FORMS += \
    change_admin.ui \
    loginadmin.ui \
    admin_info.ui \
    mainscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES +=
