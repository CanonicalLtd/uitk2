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
