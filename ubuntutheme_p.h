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

#ifndef UBUNTUTHEME_H
#define UBUNTUTHEME_H

#include <QtGui/QFont>
#include <QtQuickControls2/private/qquickproxytheme_p.h>

class UbuntuTheme : public QQuickProxyTheme
{
public:
    explicit UbuntuTheme(QPlatformTheme *theme = nullptr);
    ~UbuntuTheme();

    const QFont *font(Font type = SystemFont) const override;

private:
    QFont m_systemFont;
};

#endif // UBUNTUTHEME_H
