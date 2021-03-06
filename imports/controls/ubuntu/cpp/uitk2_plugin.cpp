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
#include "palettevalues_p.h"
#include "ubuntuanimation_p.h"
#include "ubuntunumberanimation_p.h"
#include "themeiconprovider_p.h"

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

    qmlRegisterUncreatableType<UbuntuStyle>(uri, 2, 0, "Ubuntu", QStringLiteral("UbuntuStyle is an attached object"));
    qmlRegisterUncreatableType<PaletteValues>(uri, 2, 0, "PaletteValues", QStringLiteral("PaletteValues cannot be instantiated"));
    qmlRegisterSimpleSingletonType<UbuntuAnimation>(uri, 2, 0, "UbuntuAnimation");
    qmlRegisterType<UbuntuNumberAnimation>(uri, 2, 0, "UbuntuNumberAnimation");

    qmlRegisterType(typeUrl(QStringLiteral("Icon.qml")), uri, 2, 0, "Icon");
    qRegisterMetaType<PaletteValues*>("PaletteValues*");
}

void Uitk2Plugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQuickStylePlugin::initializeEngine(engine, uri);

    engine->addImageProvider(QLatin1String("theme"), new ThemeIconProvider);
}

QUrl Uitk2Plugin::pluginUrl()
{
    return Uitk2Plugin::m_pluginBase;
}

UT_NAMESPACE_END
