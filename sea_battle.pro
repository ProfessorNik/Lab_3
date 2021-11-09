QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builderfiled/builderfield.cpp \
    builderfiled/builderfieldrandom.cpp \
    builderfiled/builderfieldself.cpp \
    builderfiled/builderfieldstrategy.cpp \
    builderfiled/builderfieldwidget.cpp \
    builderfiled/shipwidget.cpp \
    data/iuser.cpp \
    data/localgamedata.cpp \
    data/localuser.cpp \
    data/session.cpp \
    data/session/iwindowsession.cpp \
    data/user.cpp \
    field/alliedfield.cpp \
    field/enemyfield.cpp \
    field/field.cpp \
    fieldwidget/abstractfieldwidget.cpp \
    fieldwidget/alliedfieldwidget.cpp \
    fieldwidget/enemyfieldwidget.cpp \
    gamers/computergamer.cpp \
    gamers/factorygamers.cpp \
    gamers/humangamer.cpp \
    gamers/igamegamer.cpp \
    gamers/igamer.cpp \
    gamers/irebuildgamer.cpp \
    gamers/optimalgamer.cpp \
    gamers/randomgamer.cpp \
    gamewidget.cpp \
    igamedatamodel.cpp \
    interfacegameview.cpp \
    localgamesettingswidget.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    random_strategy/controllers/igamecontroller.cpp \
    random_strategy/controllers/localgamecontorller.cpp \
    random_strategy/gamemodel.cpp \
    random_strategy/widgetgameview.cpp \
    services/builderservice.cpp \
    services/gameservice.cpp \
    services/gamestates/gamestate.cpp \
    services/iservice.cpp \
    services/localgamesettingsservice.cpp \
    services/mainmenuservice.cpp \
    services/servicesfactory.cpp \
    widgetform/widgetform.cpp

HEADERS += \
    builderfiled/builderfield.h \
    builderfiled/builderfieldrandom.h \
    builderfiled/builderfieldself.h \
    builderfiled/builderfieldstrategy.h \
    builderfiled/builderfieldwidget.h \
    builderfiled/shipwidget.h \
    data/iuser.h \
    data/localgamedata.h \
    data/localuser.h \
    data/session.h \
    data/session/iwindowsession.h \
    data/user.h \
    field/alliedfield.h \
    field/enemyfield.h \
    field/field.h \
    fieldwidget/abstractfieldwidget.h \
    fieldwidget/alliedfieldwidget.h \
    fieldwidget/enemyfieldwidget.h \
    gamers/computergamer.h \
    gamers/factorygamers.h \
    gamers/humangamer.h \
    gamers/igamegamer.h \
    gamers/igamer.h \
    gamers/irebuildgamer.h \
    gamers/optimalgamer.h \
    gamers/randomgamer.h \
    gamewidget.h \
    igamedatamodel.h \
    interfacegameview.h \
    localgamesettingswidget.h \
    mainmenu.h \
    mainwindow.h \
    random_strategy/controllers/igamecontroller.h \
    random_strategy/controllers/localgamecontorller.h \
    random_strategy/gamemodel.h \
    random_strategy/widgetgameview.h \
    services/builderservice.h \
    services/gameservice.h \
    services/gamestates/gamestate.h \
    services/iservice.h \
    services/localgamesettingsservice.h \
    services/mainmenuservice.h \
    services/servicesfactory.h \
    widgetform/widgetform.h

FORMS += \
    gamewidget.ui \
    localgamesettingswidget.ui \
    mainmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
