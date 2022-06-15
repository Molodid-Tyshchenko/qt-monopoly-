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
    main.cpp \
    mainwindow.cpp \
    players/AbstractPlayer.cpp \
    players/Bot.cpp \
    players/Player.cpp

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
    lib/json.hpp \
    mainwindow.h \
    players/AbstractPlayer.h \
    players/Bot.h \
    players/Player.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/dataFields.json
