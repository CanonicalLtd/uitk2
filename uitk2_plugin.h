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

#pragma once

#include <QtQuickControls2/private/qquickstyleplugin_p.h>
#include <ubuntutoolkitglobal.h>

#include <qqml.h>

/*
 * Type registration functions.
 */
template<typename T>
QObject *qmlRegisterSimpleSingletonTypeCallback(QQmlEngine *, QJSEngine *)
{
    return (new T);
}

template<typename T>
int qmlRegisterSimpleSingletonType(const char *uri, int major, int minor, const char *typeName)
{
    return qmlRegisterSingletonType<T>(uri, major, minor, typeName, qmlRegisterSimpleSingletonTypeCallback<T>);
}

UT_NAMESPACE_BEGIN

class Uitk2Plugin : public QQuickStylePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
    void initializeEngine(QQmlEngine *engine, const char *uri) override;

    QString name() const override;
    QQuickProxyTheme *createTheme() const override;

    static QUrl pluginUrl();

private:
    static QUrl m_pluginBase;
};
UT_NAMESPACE_END
