SOURCES += \
    $$PWD/ubuntustyle.cpp \
    $$PWD/ubuntutheme.cpp \
    $$PWD/ubuntuanimation.cpp

HEADERS += \
    $$PWD/ubuntutoolkitglobal.h \
    $$PWD/ubuntustyle_p.h \
    $$PWD/ubuntutheme_p.h \
    $$PWD/ubuntuanimation_p.h

QML_PRIVATE_FILES += \
    $$PWD/Palette.qml \
    $$PWD/PaletteValues.qml \
    $$PWD/SuruPalette.qml \
    $$PWD/SuruNormal.qml \
    $$PWD/SuruSelected.qml \
    $$PWD/SuruDarkPalette.qml \
    $$PWD/SuruDarkNormal.qml \
    $$PWD/SuruDarkSelected.qml

QML_FILES += \
    $$QML_PRIVATE_FILES \
    $$PWD/UbuntuColors.qml \
    $$PWD/Button.qml

# yet
OTHER_FILES += QML_FILES
