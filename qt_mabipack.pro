QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/MabiCache.cpp \
    src/MabiFileTreeView.cpp \
    src/MabiGlobal.cpp \
    src/MabiModManager.cpp \
    src/dll_import_mgr.cpp \
    src/main.cpp \
    src/readfromweburl.cpp \
    ui/UIAbout.cpp \
    ui/UIExplorer.cpp \
    ui/UIExtract.cpp \
    ui/UIMainWindow.cpp \
    ui/UIManager.cpp \
    ui/UIName.cpp \
    ui/UIPack.cpp \
    ui/UISettings.cpp

HEADERS += \
    src/MabiCache.h \
    src/MabiFileTreeView.h \
    src/MabiGlobal.h \
    src/MabiModManager.h \
    src/dll_import_mgr.h \
    src/getMabiLog.h \
    src/readfromweburl.h \
    ui/UIAbout.h \
    ui/UIExplorer.h \
    ui/UIExtract.h \
    ui/UIMainWindow.h \
    ui/UIManager.h \
    ui/UIName.h \
    ui/UIPack.h \
    ui/UISettings.h \
    ui/ui_UIAbout.h \
    ui/ui_UIExplorer.h \
    ui/ui_UIExtract.h \
    ui/ui_UIMainWindow.h \
    ui/ui_UIManageranager.h \
    ui/ui_UIPackpack.h \
    ui/ui_UISettings.h \
    ui/ui_about.h \
    ui/ui_mainwindow.h

FORMS += \
    ui/UIAbout.ui \
    ui/UIExplorer.ui \
    ui/UIExtract.ui \
    ui/UIMainWindow.ui \
    ui/UIManageranager.ui \
    ui/UIName.ui \
    ui/UIPackpack.ui \
    ui/UISettings.ui

INCLUDEPATH += \
    ./src \
    ./ui

UI_DIR=./ui

RC_ICONS = ./resource/mabi.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
