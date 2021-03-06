QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Buyer.cpp \
    abstract_transactions.cpp \
    addproduct.cpp \
    admin.cpp \
    allproducts.cpp \
    checkpassword.cpp \
    client.cpp \
    edit_profile_client.cpp \
    editprofile.cpp \
    encryption.cpp \
    fileProduct.cpp \
    fileenctyption.cpp \
    filter.cpp \
    findPrime.cpp \
    forgetpassword.cpp \
    generatingKey.cpp \
    get_money_customer.cpp \
    increase_budget.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    payment_client.cpp \
    product.cpp \
    register.cpp \
    seller.cpp \
    transaction.cpp \
    changeprofile.cpp \
    customer.cpp

HEADERS += \
    Buyer.h \
    abstract_transactions.h \
    addproduct.h \
    admin.h \
    allproducts.h \
    checkpassword.h \
    client.h \
    edit_profile_client.h \
    editprofile.h \
    encryption.h \
    fileProduct.h \
    fileenctyption.h \
    filter.h \
    findPrime.h \
    forgetpassword.h \
    generatingKey.h \
    get_money_customer.h \
    increase_budget.h \
    keyRsa.h \
    mainwindow.h \
    manager.h \
    payment_client.h \
    product.h \
    register.h \
    seller.h \
    transaction.h \
    changeprofile.h \
    customer.h

FORMS += \
    abstract_transactions.ui \
    addproduct.ui \
    admin.ui \
    allproducts.ui \
    client.ui \
    edit_profile_client.ui \
    forgetpassword.ui \
    get_money_customer.ui \
    increase_budget.ui \
    mainwindow.ui \
    payment_client.ui \
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
