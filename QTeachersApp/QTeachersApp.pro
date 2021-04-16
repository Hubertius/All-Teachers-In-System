QT     += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/create.cpp \
    View/delete.cpp \
    View/read.cpp \
    View/update.cpp \
    main.cpp \
    View/loginwindow.cpp \
    View/mainview.cpp \
    utils.cpp

HEADERS += \
    View/create.h \
    View/delete.h \
    View/loginwindow.h \
    View/mainview.h \
    View/read.h \
    View/update.h \
    utils.h

FORMS += \
    View/create.ui \
    View/delete.ui \
    View/loginwindow.ui \
    View/mainview.ui \
    View/read.ui \
    View/update.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    DataBases/guestLogin.txt \
    DataBases/login.db \
    DataBases/teachers.db

RESOURCES += \
    TeachersAppResources.qrc
