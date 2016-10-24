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

#include "palettevalues_p.h"
#include <QtCore/QDebug>

UT_NAMESPACE_BEGIN

/******************************************************************************
 * Normal
 */
void SuruNormal::lightColors()
{
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[BackgroundText] = UbuntuStyle::color(UbuntuStyle::Jet);
    m_colors[BackgroundSecondaryText] = UbuntuStyle::color(UbuntuStyle::Inkstone);
    m_colors[BackgroundTertiaryText] = UbuntuStyle::color(UbuntuStyle::Graphite);
    m_colors[Base] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[BaseText] = UbuntuStyle::color(UbuntuStyle::Inkstone);
    m_colors[Foreground] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[ForegroundText] = UbuntuStyle::color(UbuntuStyle::Jet);
    m_colors[Raised] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[RaisedText] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[RaisedSecondaryText] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[Overlay] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[OverlayText] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[OverlaySecondaryText] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[Field] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[FieldText] = UbuntuStyle::color(UbuntuStyle::Jet);
    m_colors[Focus] = UbuntuStyle::color(UbuntuStyle::Blue);
    m_colors[FocusText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Selection] = UbuntuStyle::color(UbuntuStyle::Blue, 0.2);
    m_colors[SelectionText] = UbuntuStyle::color(UbuntuStyle::Jet);
    m_colors[Positive] = UbuntuStyle::color(UbuntuStyle::Green);
    m_colors[PositiveText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Negative] = UbuntuStyle::color(UbuntuStyle::Red);
    m_colors[NegativeText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Activity] = UbuntuStyle::color(UbuntuStyle::Blue);
    m_colors[ActivityText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Position] = UbuntuStyle::color(UbuntuStyle::Transparent);
    m_colors[PositionText] = UbuntuStyle::color(UbuntuStyle::Blue);
}
void SuruNormal::darkColors()
{
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::Jet);
    m_colors[BackgroundText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[BackgroundSecondaryText] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[BackgroundTertiaryText] = UbuntuStyle::color(UbuntuStyle::Ash);
    m_colors[Base] = UbuntuStyle::color(UbuntuStyle::Graphite);
    m_colors[BaseText] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[Foreground] = UbuntuStyle::color(UbuntuStyle::Inkstone);
    m_colors[ForegroundText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Raised] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[RaisedText] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[RaisedSecondaryText] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[Overlay] = UbuntuStyle::color(UbuntuStyle::Inkstone);
    m_colors[OverlayText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[OverlaySecondaryText] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[Field] = UbuntuStyle::color(UbuntuStyle::Jet);
    m_colors[FieldText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Focus] = UbuntuStyle::color(UbuntuStyle::Blue);
    m_colors[FocusText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Selection] = UbuntuStyle::color(UbuntuStyle::Blue, 0.2);
    m_colors[SelectionText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Positive] = UbuntuStyle::color(UbuntuStyle::Green);
    m_colors[PositiveText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Negative] = UbuntuStyle::color(UbuntuStyle::Red);
    m_colors[NegativeText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Activity] = UbuntuStyle::color(UbuntuStyle::Blue);
    m_colors[ActivityText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Position] = UbuntuStyle::color(UbuntuStyle::Transparent);
    m_colors[PositionText] = UbuntuStyle::color(UbuntuStyle::Blue);
}

/******************************************************************************
 * Disabled
 */
void SuruDisabled::lightColors()
{
    SuruNormal::lightColors();
    // apply 40% opacity on all
    for (int i = Background; i < MaxValues; i++) {
        m_colors[i].setAlphaF(0.4);
    }
    // and override few colors
    m_colors[Selection] = UbuntuStyle::color(UbuntuStyle::Blue, 0.1);
    m_colors[PositiveText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[NegativeText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[ActivityText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[FocusText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Position] = UbuntuStyle::color(UbuntuStyle::Transparent);
}
void SuruDisabled::darkColors()
{
    SuruNormal::darkColors();
    // apply 40% opacity on all
    for (int i = Background; i < MaxValues; i++) {
        m_colors[i].setAlphaF(0.4);
    }
    // and override few exceptions
    m_colors[Raised] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[PositiveText] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[NegativeText] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[ActivityText] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[FocusText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[SelectionText] = UbuntuStyle::color(UbuntuStyle::White);
}
/******************************************************************************
 * Highlighted
 */
void SuruHighlighted::lightColors()
{
    SuruNormal::lightColors();
    // apply exceptions
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[Base] = UbuntuStyle::color(UbuntuStyle::Ash);
    m_colors[BaseText] = UbuntuStyle::color(UbuntuStyle::Jet);
    m_colors[Foreground] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[Raised] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[RaisedText] = UbuntuStyle::color(UbuntuStyle::Inkstone);
    m_colors[RaisedSecondaryText] = UbuntuStyle::color(UbuntuStyle::Ash);
}
void SuruHighlighted::darkColors()
{
    SuruNormal::darkColors();
    // apply exceptions
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[Base] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[BaseText] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[Foreground] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[Raised] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[RaisedText] = UbuntuStyle::color(UbuntuStyle::Inkstone);
    m_colors[RaisedSecondaryText] = UbuntuStyle::color(UbuntuStyle::Ash);
}
/******************************************************************************
 * Focused
 */
void SuruFocused::lightColors()
{
    SuruNormal::lightColors();
    // apply exceptions
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::Blue, 0.2);
}
void SuruFocused::darkColors()
{
    SuruNormal::darkColors();
    // apply exceptions
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::Blue, 0.4);
}
/******************************************************************************
 * Selected
 */
void SuruSelected::lightColors()
{
    SuruNormal::lightColors();
    // override exceptions
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[Base] = UbuntuStyle::color(UbuntuStyle::Ash);
    m_colors[BaseText] = UbuntuStyle::color(UbuntuStyle::Jet);
    m_colors[Foreground] = UbuntuStyle::color(UbuntuStyle::Ash);
    m_colors[Overlay] = UbuntuStyle::color(UbuntuStyle::Porcelain);
}
void SuruSelected::darkColors()
{
    SuruNormal::lightColors();
    // override exceptions
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::Inkstone);
    m_colors[Base] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[BaseText] = UbuntuStyle::color(UbuntuStyle::Silk);
    m_colors[Foreground] = UbuntuStyle::color(UbuntuStyle::Slate);
    m_colors[Overlay] = UbuntuStyle::color(UbuntuStyle::Slate);
}
/******************************************************************************
 * SelectedDisabled
 */
void SuruSelectedDisabled::lightColors()
{
    SuruSelected::lightColors();
    // apply 40% opacity on all
    for (int i = Background; i < MaxValues; i++) {
        m_colors[i].setAlphaF(0.4);
    }
    // apply exceptions
    m_colors[Foreground] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[Selection] = UbuntuStyle::color(UbuntuStyle::Blue, 0.1);
    m_colors[PositiveText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[NegativeText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[ActivityText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Focus] = UbuntuStyle::color(UbuntuStyle::Blue);
    m_colors[FocusText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Field] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Position] = UbuntuStyle::color(UbuntuStyle::Transparent);
}
void SuruSelectedDisabled::darkColors()
{
    SuruSelected::darkColors();
    // apply 40% opacity on all
    for (int i = Background; i < MaxValues; i++) {
        m_colors[i].setAlphaF(0.4);
    }
    // apply exceptions
    m_colors[Background] = UbuntuStyle::color(UbuntuStyle::Inkstone);
    m_colors[BackgroundText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[ForegroundText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[Raised] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[OverlayText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[FieldText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[SelectionText] = UbuntuStyle::color(UbuntuStyle::White);
    m_colors[PositiveText] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[NegativeText] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[ActivityText] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[FocusText] = UbuntuStyle::color(UbuntuStyle::Porcelain);
    m_colors[Position] = UbuntuStyle::color(UbuntuStyle::Transparent);
}
/******************************************************************************
 * PaletteValues
 */
PaletteValues::PaletteValues(QObject *parent)
    : QObject(parent)
{
}

void PaletteValues::resetColors(UbuntuStyle::Theme theme)
{
    switch (theme) {
    case UbuntuStyle::Suru:
        lightColors();
        break;
    case UbuntuStyle::SuruDark:
        darkColors();
        break;
    }
}

QColor PaletteValues::background() const
{
    return m_colors[Background];
}
QColor PaletteValues::backgroundText() const
{
    return m_colors[BackgroundText];
}
QColor PaletteValues::backgroundSecondaryText() const
{
    return m_colors[BackgroundSecondaryText];
}
QColor PaletteValues::backgroundTertiaryText() const
{
    return m_colors[BackgroundTertiaryText];
}
QColor PaletteValues::base() const
{
    return m_colors[Base];
}
QColor PaletteValues::baseText() const
{
    return m_colors[BaseText];
}
QColor PaletteValues::foreground() const
{
    return m_colors[Foreground];
}
QColor PaletteValues::foregroundText() const
{
    return m_colors[ForegroundText];
}
QColor PaletteValues::raised() const
{
    return m_colors[Raised];
}
QColor PaletteValues::raisedText() const
{
    return m_colors[RaisedText];
}
QColor PaletteValues::raisedSecondaryText() const
{
    return m_colors[RaisedSecondaryText];
}
QColor PaletteValues::overlay() const
{
    return m_colors[Overlay];
}
QColor PaletteValues::overlayText() const
{
    return m_colors[OverlayText];
}
QColor PaletteValues::overlaySecondaryText() const
{
    return m_colors[OverlaySecondaryText];
}
QColor PaletteValues::field() const
{
    return m_colors[Field];
}
QColor PaletteValues::fieldText() const
{
    return m_colors[FieldText];
}
QColor PaletteValues::positive() const
{
    return m_colors[Positive];
}
QColor PaletteValues::positiveText() const
{
    return m_colors[PositiveText];
}
QColor PaletteValues::negative() const
{
    return m_colors[Negative];
}
QColor PaletteValues::negativeText() const
{
    return m_colors[NegativeText];
}
QColor PaletteValues::activity() const
{
    return m_colors[Activity];
}
QColor PaletteValues::activityText() const
{
    return m_colors[ActivityText];
}
QColor PaletteValues::selection() const
{
    return m_colors[Selection];
}
QColor PaletteValues::selectionText() const
{
    return m_colors[SelectionText];
}
QColor PaletteValues::focus() const
{
    return m_colors[Focus];
}
QColor PaletteValues::focusText() const
{
    return m_colors[FocusText];
}
QColor PaletteValues::position() const
{
    return m_colors[Position];
}
QColor PaletteValues::positionText() const
{
    return m_colors[PositionText];
}

PaletteValues *PaletteValues::createPalette(UbuntuStyle *style, UbuntuStyle::Palettes palette)
{
    PaletteValues *values = nullptr;
    switch (palette) {
    case UbuntuStyle::Normal:
        values = new SuruNormal;
        break;
    case UbuntuStyle::Disabled:
        values = new SuruDisabled;
        break;
    case UbuntuStyle::Focused:
        values = new SuruFocused;
        break;
    case UbuntuStyle::Highlighted:
        values = new SuruHighlighted;
        break;
    case UbuntuStyle::Selected:
        values = new SuruSelected;
        break;
    case UbuntuStyle::SelectedDisabled:
        values = new SuruSelectedDisabled;
        break;
    default: break;
    }
    if (values) {
        values->setParent(style);
        values->resetColors(style->theme());
    }
    return values;
}

UT_NAMESPACE_END
