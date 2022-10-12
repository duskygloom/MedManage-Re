######################################################################
# Automatically generated by qmake (3.1) Mon Oct 10 21:31:00 2022
######################################################################

TEMPLATE = app
TARGET = MedManage-Re
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Input

HEADERS   += basewidget.h \
             global/clearbutton.h \
             global/notiflabel.h \
             global/notifbar.h \
             global/tabbar.h \
             global/tabbutton.h \
             global/timelabel.h

FORMS     += form.ui

SOURCES   += basewidget.cpp \
             global/clearbutton.cpp \
             global/notiflabel.cpp \
             main.cpp \
             global/notifbar.cpp \
             global/tabbar.cpp \
             global/tabbutton.cpp \
             global/timelabel.cpp

QT        += widgets

DISTFILES += styles/styling.py \
             styles/colorschemes.py \
             styles/stylingclass.py

RESOURCES += assets.qrc
