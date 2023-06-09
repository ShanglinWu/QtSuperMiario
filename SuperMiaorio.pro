QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brick.cpp \
    cannibal.cpp \
    configure.cpp \
    enemy.cpp \
    gameover.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    massroom.cpp \
    musicplayer.cpp \
    unknown.cpp \
    widget.cpp \
    win.cpp

HEADERS += \
    brick.h \
    cannibal.h \
    configure.h \
    enemy.h \
    gameover.h \
    global.h \
    mainwindow.h \
    massroom.h \
    musicplayer.h \
    unknown.h \
    widget.h \
    win.h

FORMS += \
    configure.ui \
    gameover.ui \
    mainwindow.ui \
    widget.ui \
    win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    untitle.qrc
