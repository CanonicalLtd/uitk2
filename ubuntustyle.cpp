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

#include "palettevalues_p.h"

UT_NAMESPACE_BEGIN

UbuntuStyle::UbuntuStyle(QObject *parent)
    : QQuickStyleAttached (parent)
    , m_theme(Suru)
    , m_explicitTheme(false)
{
    m_palettes[Normal] = PaletteValues::createPalette(this, Normal);
    m_palettes[Disabled] = PaletteValues::createPalette(this, Disabled);
    m_palettes[Focused] = PaletteValues::createPalette(this, Focused);
    m_palettes[Highlighted] = PaletteValues::createPalette(this, Highlighted);
    m_palettes[Selected] = PaletteValues::createPalette(this, Selected);
    m_palettes[SelectedDisabled] = PaletteValues::createPalette(this, SelectedDisabled);
}

UbuntuStyle *UbuntuStyle::qmlAttachedProperties(QObject *parent)
{
    return new UbuntuStyle(parent);
}

UbuntuStyle::Theme UbuntuStyle::theme() const
{
    return m_theme;
}
void UbuntuStyle::setTheme(Theme theme)
{
    m_explicitTheme = true;
    if (theme == m_theme) {
        return;
    }
    m_theme = theme;
    // update palette
    for (int i = 0; i < MaxPalettes; i++) {
        m_palettes[i]->resetColors(m_theme);
    }

    // propagate to children
    propagateTheme();

    Q_EMIT themeChanged();
    Q_EMIT paletteChanged();

}
void UbuntuStyle::resetTheme()
{
    if (!m_explicitTheme) {
        return;
    }
    m_explicitTheme = false;
    // look for the parent's theme
    UbuntuStyle *style = qobject_cast<UbuntuStyle*>(parentStyle());
    if (style) {
        style->inheritTheme(style->m_theme);
        Q_EMIT themeChanged();
        Q_EMIT paletteChanged();
    }
}

void UbuntuStyle::inheritTheme(Theme theme)
{
    if (m_explicitTheme || m_theme == theme) {
        return;
    }
    // update palette
    for (int i = 0; i < MaxPalettes; i++) {
        m_palettes[i]->resetColors(m_theme);
    }
    // propagate theme change
    propagateTheme();
    Q_EMIT themeChanged();
    Q_EMIT paletteChanged();
}
void UbuntuStyle::propagateTheme()
{
    const auto styles = childStyles();
    for (QQuickStyleAttached *i : styles) {
        UbuntuStyle *style = qobject_cast<UbuntuStyle*>(i);
        if (style) {
            style->inheritTheme(m_theme);
        }
    }
}

PaletteValues *UbuntuStyle::normal() const
{
    return m_palettes[Normal];
}
PaletteValues *UbuntuStyle::disabled() const
{
    return m_palettes[Disabled];
}
PaletteValues *UbuntuStyle::focused() const
{
    return m_palettes[Focused];
}
PaletteValues *UbuntuStyle::highlighted() const
{
    return m_palettes[Highlighted];
}
PaletteValues *UbuntuStyle::selected() const
{
    return m_palettes[Selected];
}
PaletteValues *UbuntuStyle::selectedDisabled() const
{
    return m_palettes[SelectedDisabled];
}

QColor UbuntuStyle::color(Color c, qreal alpha)
{
    QColor result;
    switch (c) {
    case Transparent: result = Qt::transparent; break;
    case White: result = QColor::fromRgb(rgbWhite); break;
    case Black: result = QColor::fromRgb(rgbBlack); break;
    case Orange: result = QColor::fromRgb(rgbOrange); break;
    case Silk: result = QColor::fromRgb(rgbSilk); break;
    case Slate: result = QColor::fromRgb(rgbSlate); break;
    case Red: result = QColor::fromRgb(rgbRed); break;
    case Green: result = QColor::fromRgb(rgbGreen); break;
    case Blue: result = QColor::fromRgb(rgbBlue); break;
    case Porcelain: result = QColor::fromRgb(rgbPorcelain); break;
    case Ash: result = QColor::fromRgb(rgbAsh); break;
    case Graphite: result = QColor::fromRgb(rgbGraphite); break;
    case Inkstone: result = QColor::fromRgb(rgbInkstone); break;
    case Jet: result = QColor::fromRgb(rgbJet); break;
    }
    if (alpha < 1.0) {
        result.setAlpha(alpha);
    }
    return result;
}

UT_NAMESPACE_END
