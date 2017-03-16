TEMPLATE = app
TARGET = tst_qquickubuntustyle
CONFIG += qmltestcase

SOURCES += \
    $$PWD/tst_qquickubuntustyle.cpp

RESOURCES += \
    $$PWD/qtquickcontrols2.conf

OTHER_FILES += \
    $$PWD/data/*.qml

TESTDATA += \
    $$PWD/data/tst_*
