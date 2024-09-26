QT       += core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FocusClock.cpp \
    MainWindow.cpp \
    changePosition.cpp \
    main.cpp \
    setMenu.cpp \
    setTrayIcon.cpp \
    toolsMainWindow.cpp

HEADERS += \
    FocusClock.h \
    MainWindow.h

FORMS += \
    FocusClock.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    person.qrc

RC_FILE += logo.rc

STATECHARTS +=
