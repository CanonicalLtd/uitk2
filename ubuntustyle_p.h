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
#include <QtQuickControls2/private/qquickstyleattached_p.h>
#include <ubuntutoolkitglobal.h>

UT_NAMESPACE_BEGIN

class UbuntuStyle : public QQuickStyleAttached
{
    Q_OBJECT
    Q_PROPERTY(Theme theme READ getTheme WRITE setTheme NOTIFY themeChanged FINAL)
    Q_PROPERTY(QObject *palette READ getPalette NOTIFY paletteChanged FINAL)

public:
    enum Theme {
        Suru,
        SuruDark
    };
    Q_ENUM(Theme);

    explicit UbuntuStyle(QObject *parent = nullptr);

    static UbuntuStyle *qmlAttachedProperties(QObject *parent);

    Theme getTheme() const;
    void setTheme(Theme theme);
    QObject *getPalette();

Q_SIGNALS:
    void themeChanged();
    void paletteChanged();

private:
    QObject *m_palette;
    Theme m_theme;

    void loadPalette();
};

UT_NAMESPACE_END

QML_DECLARE_TYPEINFO(UT_PREPEND_NAMESPACE(UbuntuStyle), QML_HAS_ATTACHED_PROPERTIES)

#endif // UBUNTUSTYLE_H
