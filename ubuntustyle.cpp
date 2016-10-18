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

#include "ubuntustyle_p.h"
#include "uitk2_plugin.h"

#include <QtCore/QDebug>
#include <QtQml/QQmlComponent>

UT_NAMESPACE_BEGIN

UbuntuStyle::UbuntuStyle(QObject *parent)
    : QQuickStyleAttached (parent)
    , m_palette(nullptr)
    , m_theme(Suru)
{
    loadPalette();
}

UbuntuStyle *UbuntuStyle::qmlAttachedProperties(QObject *parent)
{
    return new UbuntuStyle(parent);
}

void UbuntuStyle::loadPalette()
{
    QQmlEngine *engine = qmlEngine(parent());
    if (!engine) {
        qWarning() << "Cannot load palette with an invalid QQmlEngine";
        return;
    }
    // FIXME: revisit this with qrc resolving!
    QString palettePath = Uitk2Plugin::pluginUrl().toString(QUrl::RemoveScheme);
    switch (m_theme) {
    case Suru:
        palettePath += QStringLiteral("/SuruPalette.qml");
        break;
    case SuruDark:
        palettePath += QStringLiteral("/SuruDarkPalette.qml");
        break;
    }
    QUrl paletteUrl(palettePath);
    if (paletteUrl.isValid()) {
        QQmlComponent component(engine, paletteUrl, QQmlComponent::PreferSynchronous);
        if (!component.isError()) {
            m_palette = component.create();
        } else {
            qWarning() << "Error loading" << paletteUrl.toString();
        }
    }
}

UbuntuStyle::Theme UbuntuStyle::getTheme() const
{
    return m_theme;
}
void UbuntuStyle::setTheme(Theme theme)
{
    if (theme == m_theme) {
        return;
    }
    m_theme = theme;
    Q_EMIT themeChanged();
    // reload palette
    delete m_palette;
    m_palette = nullptr;
    loadPalette();
    Q_EMIT paletteChanged();
}

QObject *UbuntuStyle::getPalette()
{
    if (!m_palette) {
        loadPalette();
    }
    return m_palette;
}

UT_NAMESPACE_END
