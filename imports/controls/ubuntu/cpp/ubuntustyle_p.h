/*
    Copyright 2016 Canonical Ltd.
 *
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; version 3.
 *
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
 *
    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UBUNTUSTYLE_H
#define UBUNTUSTYLE_H

#include <QtCore/QObject>
#include <QtGui/QColor>
#include <QtQuickControls2/private/qquickstyleattached_p.h>
#include <ubuntutoolkitglobal.h>

UT_NAMESPACE_BEGIN

class PaletteValues;
class UbuntuStyle : public QQuickStyleAttached
{
    Q_OBJECT
    Q_PROPERTY(Theme theme READ theme WRITE setTheme RESET resetTheme NOTIFY themeChanged FINAL)

    Q_PROPERTY(PaletteValues *normal READ normal NOTIFY paletteChanged FINAL)
    Q_PROPERTY(PaletteValues *disabled READ disabled NOTIFY paletteChanged FINAL)
    Q_PROPERTY(PaletteValues *focused READ focused NOTIFY paletteChanged FINAL)
    Q_PROPERTY(PaletteValues *highlighted READ highlighted NOTIFY paletteChanged FINAL)
    Q_PROPERTY(PaletteValues *selected READ selected NOTIFY paletteChanged FINAL)
    Q_PROPERTY(PaletteValues *selectedDisabled READ selectedDisabled NOTIFY paletteChanged FINAL)

public:
    enum Theme {
        Suru,
        SuruDark
    };
    Q_ENUM(Theme)

    enum Color {
        Transparent,
        White,
        Black,
        Orange,
        Silk,
        Slate,
        Red,
        Green,
        Blue,
        Porcelain,
        Ash,
        Graphite,
        Inkstone,
        Jet,
    };
    Q_ENUM(Color)

    enum Palettes {
        Normal,
        Disabled,
        Focused,
        Highlighted,
        Selected,
        SelectedDisabled,
        MaxPalettes
    };
    Q_ENUM(Palettes)

    explicit UbuntuStyle(QObject *parent = nullptr);

    static UbuntuStyle *qmlAttachedProperties(QObject *parent);

    Theme theme() const;
    void setTheme(Theme theme);
    void resetTheme();
    void inheritTheme(Theme theme);
    void propagateTheme();

    PaletteValues *normal() const;
    PaletteValues *disabled() const;
    PaletteValues *focused() const;
    PaletteValues *highlighted() const;
    PaletteValues *selected() const;
    PaletteValues *selectedDisabled() const;

    Q_INVOKABLE static QColor color(Color c, qreal alpha = 1.0);

Q_SIGNALS:
    void themeChanged();
    void paletteChanged();

private:
    PaletteValues *m_palettes[MaxPalettes];
    Theme m_theme;
    bool m_explicitTheme:1;

    void loadPalette();
};

UT_NAMESPACE_END

QML_DECLARE_TYPEINFO(UT_PREPEND_NAMESPACE(UbuntuStyle), QML_HAS_ATTACHED_PROPERTIES)

#endif // UBUNTUSTYLE_H
