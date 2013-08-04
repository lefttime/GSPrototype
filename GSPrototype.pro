######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 31 17:57:23 2013
######################################################################

QT       += core gui qwt opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GSPrototype
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    AbstractDockWidget.cpp \
    AppHelper.cpp \
    ProjectInspector.cpp \
    Viewer2D.cpp \
    Viewer3D.cpp \
    AbstractViewer.cpp \
    GnomonSceneNode.cpp \
    ProjectManager.cpp \
    AbstractModel.cpp \
    AbstractInvSceneNode.cpp \
    ProjectInvSceneNode.cpp \
    WellTrackInvSceneNode.cpp \
    Viewer3DHelper.cpp

HEADERS  += mainwindow.hpp \
    AbstractDockWidget.hpp \
    AppHelper.hpp \
    ProjectInspector.hpp \
    Viewer2D.hpp \
    Viewer3D.hpp \
    AbstractViewer.hpp \
    GnomonSceneNode.hpp \
    ProjectManager.hpp \
    AbstractInvSceneNode.hpp \
    AbstractModel.hpp \
    ProjectInvSceneNode.hpp \
    WellTrackInvSceneNode.hpp \
    Viewer3DHelper.hpp

FORMS    += mainwindow.ui \
    ProjectInspector.ui \
    Viewer2D.ui \
    Viewer3D.ui \
    ProjectManager.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/D:/Qt/Qwt-6.1.0/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/D:/Qt/Qwt-6.1.0/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/D:/Qt/Qwt-6.1.0/lib/ -lqwt

INCLUDEPATH += $$PWD/D:/Qt/Qwt-6.1.0/include
DEPENDPATH += $$PWD/D:/Qt/Qwt-6.1.0/include

RESOURCES += \
    GSPrototype.qrc