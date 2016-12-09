SOURCES += \
    $$PWD/ubuntustyle.cpp \
    $$PWD/ubuntutheme.cpp \
    $$PWD/ubuntuanimation.cpp \
    $$PWD/ubuntunumberanimation.cpp \
    $$PWD/themeiconprovider.cpp \
    $$PWD/palettevalues.cpp

HEADERS += \
    $$PWD/ubuntutoolkitglobal.h \
    $$PWD/ubuntustyle_p.h \
    $$PWD/ubuntutheme_p.h \
    $$PWD/ubuntuanimation_p.h \
    $$PWD/ubuntunumberanimation_p.h \
    $$PWD/themeiconprovider_p.h \
    $$PWD/palettevalues_p.h

QML_UBUNTU_FILES = \
    $$PWD/Icon.qml

QML_FILES += \
    $$QML_UBUNTU_FILES \
    $$PWD/BusyIndicator.qml \
    $$PWD/Button.qml \
    $$PWD/CheckBox.qml

# yet
OTHER_FILES += QML_FILES

RESOURCES += \
    $$PWD/uitk2.qrc
