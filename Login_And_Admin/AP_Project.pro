QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Buyer.cpp \
    addproduct.cpp \
    admin.cpp \
    checkpassword.cpp \
    client.cpp \
    edit_profile_client.cpp \
    editprofile.cpp \
    fileProduct.cpp \
    filter.cpp \
    forgetpassword.cpp \
    increase_budget.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    product.cpp \
    register.cpp \
    seller.cpp \
    transaction.cpp \
    changeprofile.cpp \
    customer.cpp

HEADERS += \
    Buyer.h \
    addproduct.h \
    admin.h \
    checkpassword.h \
    client.h \
    edit_profile_client.h \
    editprofile.h \
    fileProduct.h \
    filter.h \
    forgetpassword.h \
    increase_budget.h \
    mainwindow.h \
    manager.h \
    product.h \
    register.h \
    seller.h \
    transaction.h \
    changeprofile.h \
    customer.h

FORMS += \
    addproduct.ui \
    admin.ui \
    client.ui \
    edit_profile_client.ui \
    forgetpassword.ui \
    increase_budget.ui \
    mainwindow.ui \
    register.ui \
    transaction.ui \
    changeprofile.ui \
    customer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Admin.pro.user
