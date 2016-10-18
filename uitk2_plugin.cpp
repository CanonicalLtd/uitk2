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

#include "uitk2_plugin.h"

#include "ubuntutheme_p.h"
#include "ubuntustyle_p.h"
#include "ubuntuanimation_p.h"

UT_NAMESPACE_BEGIN

QUrl Uitk2Plugin::m_pluginBase = QUrl();

QString Uitk2Plugin::name() const
{
    return QStringLiteral("ubuntu");
}
QQuickProxyTheme *Uitk2Plugin::createTheme() const
{
    return new UbuntuTheme;
}
void Uitk2Plugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    Q_UNUSED(uri);
    m_pluginBase = baseUrl();

    qmlRegisterUncreatableType<UbuntuStyle>(uri, 2, 0, "UbuntuStyle", QStringLiteral("UbuntuStyle is an attached object"));
    qmlRegisterSimpleSingletonType<UbuntuAnimation>(uri, 2, 0, "UbuntuAnimation");
    qmlRegisterSingletonType(typeUrl(QStringLiteral("UbuntuColors.qml")), uri, 2, 0, "UbuntuColors");
}

void Uitk2Plugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQuickStylePlugin::initializeEngine(engine, uri);

    const char *internalUri = "QtQuick.Controls.Ubuntu.Privates";
    qmlRegisterType(typeUrl(QStringLiteral("PaletteValues.qml")), internalUri, 2, 0, "PaletteValues");
    qmlRegisterType(typeUrl(QStringLiteral("Palette.qml")), internalUri, 2, 0, "Palette");
}

QUrl Uitk2Plugin::pluginUrl()
{
    return Uitk2Plugin::m_pluginBase;
}

UT_NAMESPACE_END
