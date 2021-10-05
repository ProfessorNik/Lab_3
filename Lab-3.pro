QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apstractsinglefield.cpp \
    field.cpp \
    fieldmodel.cpp \
    graphicfieldview.cpp \
    interfacefiledmodel.cpp \
    interfacefiledview.cpp \
    main.cpp \
    mainmenu.cpp \
    observable.cpp \
    observer.cpp

HEADERS += \
    apstractsinglefield.h \
    field.h \
    fieldmodel.h \
    graphicfieldview.h \
    interfacefiledmodel.h \
    interfacefiledview.h \
    mainmenu.h \
    observable.h \
    observer.h

FORMS += \
    mainmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../Users/nikol/Desktop/Без названия.jpg \
    ../../../Users/nikol/Desktop/Без названия.jpg

RESOURCES +=
