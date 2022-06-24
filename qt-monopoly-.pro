QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fields/BasicField.cpp \
    fields/Field.cpp \
    fields/GiftField.cpp \
    fields/PolyanaField.cpp \
    fields/PortalField.cpp \
    fields/QuestionField.cpp \
    fields/SelectiveField.cpp \
    fields/StartField.cpp \
    fields/VadimField.cpp \
    game/Actions.cpp \
    game/Dice.cpp \
    game/Monopoly.cpp \
    game/MonopolyManager.cpp \
    game/Statistik.cpp \
    game/Test.cpp \
    giftwindow.cpp \
    infowindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mapwindow.cpp \
    players/AbstractPlayer.cpp \
    players/Bot.cpp \
    players/Player.cpp \
    polyanawindow.cpp \
    portalwindow.cpp \
    questwindow.cpp \
    selectivewindow.cpp \
    statistikwindow.cpp \
    vadimwindow.cpp

HEADERS += \
    factory/FactoryMethod.h \
    fields/BasicField.h \
    fields/Field.h \
    fields/GiftField.h \
    fields/PolyanaField.h \
    fields/PortalField.h \
    fields/QuestionField.h \
    fields/SelectiveField.h \
    fields/StartField.h \
    fields/VadimField.h \
    game/Actions.h \
    game/Dice.h \
    game/Monopoly.h \
    game/MonopolyManager.h \
    game/Statistik.h \
    game/Test.h \
    giftwindow.h \
    infowindow.h \
    lib/json.hpp \
    mainwindow.h \
    mapwindow.h \
    players/AbstractPlayer.h \
    players/Bot.h \
    players/Player.h \
    polyanawindow.h \
    portalwindow.h \
    questwindow.h \
    selectivewindow.h \
    statistikwindow.h \
    vadimwindow.h

FORMS += \
    giftwindow.ui \
    infowindow.ui \
    mainwindow.ui \
    mapwindow.ui \
    polyanawindow.ui \
    portalwindow.ui \
    questwindow.ui \
    selectivewindow.ui \
    statistikwindow.ui \
    vadimwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/dataFields.json \
    style.qss

RESOURCES += \
    pl1.qrc
