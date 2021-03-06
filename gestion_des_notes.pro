QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG+=sdk_no_version_check
RC_ICONS=learning.ico
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbaccess.cpp \
    flowcontroller.cpp \
    main.cpp \
    service.cpp \
    uiadministrateur.cpp \
    uiauthentification.cpp \
    uietudiant.cpp \
    uiformateur.cpp \
    uiresponsable.cpp \
    user.cpp \
    usermodel.cpp

HEADERS += \
    dbaccess.hpp \
    flowcontroller.hpp \
    service.hpp \
    uiadministrateur.hpp \
    uiauthentification.hpp \
    uietudiant.hpp \
    uiformateur.hpp \
    uiresponsable.hpp \
    user.hpp \
    usermodel.hpp

FORMS += \
    uiadministrateur.ui \
    uiauthentification.ui \
    uietudiant.ui \
    uiformateur.ui \
    uiresponsable.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
