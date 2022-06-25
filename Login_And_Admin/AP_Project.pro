QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    checkpassword.cpp \
    editprofile.cpp \
    forgetpassword.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp

HEADERS += \
    admin.h \
    checkpassword.h \
    editprofile.h \
    forgetpassword.h \
    mainwindow.h \
    register.h

FORMS += \
    admin.ui \
    forgetpassword.ui \
    mainwindow.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Admin.pro.user
