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

#include "ubuntutheme_p.h"
#include <QtGui/QFontInfo>

UbuntuTheme::UbuntuTheme(QPlatformTheme *theme)
    : QQuickProxyTheme(theme)
{
    QFont font;
    font.setFamily(QStringLiteral("Ubuntu"));
    QString family = QFontInfo(font).family();

    m_systemFont.setFamily(family);
    // FIXME use units
    m_systemFont.setPixelSize(14);
    m_systemFont.setWeight(QFont::Light);
}

UbuntuTheme::~UbuntuTheme()
{
}

const QFont *UbuntuTheme::font(Font type) const
{
    Q_UNUSED(type);
    return &m_systemFont;
}
