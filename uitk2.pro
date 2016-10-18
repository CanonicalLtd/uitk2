TEMPLATE = lib
TARGET = uitk2styleplugin
TARGETPATH = QtQuick/Controls.2/Ubuntu
IMPORT_VERSION = 2.0
uri = QtQuick.Controls.Ubuntu

QT += qml quick
QT_PRIVATE += core-private gui-private qml-private quick-private quicktemplates2-private quickcontrols2-private

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

OTHER_FILES += \
    $$PWD/qmldir

SOURCES += \
    $$PWD/uitk2_plugin.cpp

HEADERS += \
    $$PWD/uitk2_plugin.h

#RESOURCES += \
#    $$PWD/uitk2_plugin.qrc

include(uitk2.pri)

DISTFILES += \
    uitk2.pri

qmldir.files = qmldir
qmlfiles.file = $$QML_FILES
unix {
    installPath = $$[QT_INSTALL_QML]/$${TARGETPATH}
    qmldir.path = $$installPath
    qmlfiles.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

CONFIG += no_cxx_module
load(qml_plugin)

#TEMPLATE = lib
#TARGET = uitk2style
#QT += qml quick
#CONFIG += qt plugin c++11

#TARGET = $$qtLibraryTarget($$TARGET)
## FIXME: We must use QtQuick.Controls namespace till we can get it in a custom path
#TARGETPATH = QtQuick/Controls.2/Ubuntu
#uri = QtQuick.Controls.Ubuntu

## Input
#SOURCES += \
#    uitk2_plugin.cpp \
#    theme.cpp

#HEADERS += \
#    uitk2_plugin.h \
#    theme.h

#DISTFILES = qmldir

#!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
#    copy_qmldir.target = $$OUT_PWD/qmldir
#    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
#    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
#    QMAKE_EXTRA_TARGETS += copy_qmldir
#    PRE_TARGETDEPS += $$copy_qmldir.target
#}
