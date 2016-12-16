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

#ifndef PALETTEVALUES_H
#define PALETTEVALUES_H

#include <QtCore/QObject>
#include <QtGui/QColor>

#include <ubuntustyle_p.h>

UT_NAMESPACE_BEGIN

const QRgb rgbWhite = 0xFFFFFFFF;
const QRgb rgbBlack = 0x00000000;
const QRgb rgbOrange = 0xE95420;
const QRgb rgbSilk = 0xCDCDCD;
const QRgb rgbSlate = 0x5D5D5D;
const QRgb rgbRed = 0xED3146;
const QRgb rgbGreen = 0x3EB34F;
const QRgb rgbBlue = 0x19B6EE;
const QRgb rgbPorcelain = 0xF7F7F7;
const QRgb rgbAsh = 0x888888;
const QRgb rgbGraphite = 0x666666;
const QRgb rgbInkstone = 0x3B3B3B;
const QRgb rgbJet = 0x111111;

class PaletteValues : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor background READ background CONSTANT FINAL)
    Q_PROPERTY(QColor backgroundText READ backgroundText CONSTANT FINAL)
    Q_PROPERTY(QColor backgroundSecondaryText READ backgroundSecondaryText CONSTANT FINAL)
    Q_PROPERTY(QColor backgroundTertiaryText READ backgroundTertiaryText CONSTANT FINAL)
    Q_PROPERTY(QColor base READ base CONSTANT FINAL)
    Q_PROPERTY(QColor baseText READ baseText CONSTANT FINAL)
    Q_PROPERTY(QColor foreground READ foreground CONSTANT FINAL)
    Q_PROPERTY(QColor foregroundText READ foregroundText CONSTANT FINAL)
    Q_PROPERTY(QColor raised READ raised CONSTANT FINAL)
    Q_PROPERTY(QColor raisedText READ raisedText CONSTANT FINAL)
    Q_PROPERTY(QColor raisedSecondaryText READ raisedSecondaryText CONSTANT FINAL)
    Q_PROPERTY(QColor overlay READ overlay CONSTANT FINAL)
    Q_PROPERTY(QColor overlayText READ overlayText CONSTANT FINAL)
    Q_PROPERTY(QColor overlaySecondaryText READ overlaySecondaryText CONSTANT FINAL)
    Q_PROPERTY(QColor field READ field CONSTANT FINAL)
    Q_PROPERTY(QColor fieldText READ fieldText CONSTANT FINAL)
    Q_PROPERTY(QColor positive READ positive CONSTANT FINAL)
    Q_PROPERTY(QColor positiveText READ positiveText CONSTANT FINAL)
    Q_PROPERTY(QColor negative READ negative CONSTANT FINAL)
    Q_PROPERTY(QColor negativeText READ negativeText CONSTANT FINAL)
    Q_PROPERTY(QColor activity READ activity CONSTANT FINAL)
    Q_PROPERTY(QColor activityText READ activityText CONSTANT FINAL)
    Q_PROPERTY(QColor selection READ selection CONSTANT FINAL)
    Q_PROPERTY(QColor selectionText READ selectionText CONSTANT FINAL)
    Q_PROPERTY(QColor focus READ focus CONSTANT FINAL)
    Q_PROPERTY(QColor focusText READ focusText CONSTANT FINAL)
    Q_PROPERTY(QColor position READ position CONSTANT FINAL)
    Q_PROPERTY(QColor positionText READ positionText CONSTANT FINAL)

public:
    explicit PaletteValues(QObject *parent = 0);
    void resetColors(UbuntuStyle::Theme theme);

    static PaletteValues *createPalette(UbuntuStyle *style, UbuntuStyle::Palettes palette);

protected:
    virtual void lightColors() {}
    virtual void darkColors() {}

protected:
    enum Values {
        Background,
        BackgroundText,
        BackgroundSecondaryText,
        BackgroundTertiaryText,
        Base,
        BaseText,
        Foreground,
        ForegroundText,
        Raised,
        RaisedText,
        RaisedSecondaryText,
        Overlay,
        OverlayText,
        OverlaySecondaryText,
        Field,
        FieldText,
        Focus,
        FocusText,
        Selection,
        SelectionText,
        Positive,
        PositiveText,
        Negative,
        NegativeText,
        Activity,
        ActivityText,
        Position,
        PositionText,
        MaxValues
    };
    QColor m_colors[MaxValues];
    QColor background() const;
    QColor backgroundText() const;
    QColor backgroundSecondaryText() const;
    QColor backgroundTertiaryText() const;
    QColor base() const;
    QColor baseText() const;
    QColor foreground() const;
    QColor foregroundText() const;
    QColor raised() const;
    QColor raisedText() const;
    QColor raisedSecondaryText() const;
    QColor overlay() const;
    QColor overlayText() const;
    QColor overlaySecondaryText() const;
    QColor field() const;
    QColor fieldText() const;
    QColor positive() const;
    QColor positiveText() const;
    QColor negative() const;
    QColor negativeText() const;
    QColor activity() const;
    QColor activityText() const;
    QColor selection() const;
    QColor selectionText() const;
    QColor focus() const;
    QColor focusText() const;
    QColor position() const;
    QColor positionText() const;
};

class SuruNormal : public PaletteValues
{
    Q_OBJECT
protected:
    void lightColors() override;
    void darkColors() override;
};

class SuruDisabled : public SuruNormal
{
    Q_OBJECT
protected:
    void lightColors() override;
    void darkColors() override;
};

class SuruHighlighted : public SuruNormal
{
    Q_OBJECT
protected:
    void lightColors() override;
    void darkColors() override;
};

class SuruFocused : public SuruNormal
{
    Q_OBJECT
protected:
    void lightColors() override;
    void darkColors() override;
};

class SuruSelected : public SuruNormal
{
    Q_OBJECT
protected:
    void lightColors() override;
    void darkColors() override;
};

class SuruSelectedDisabled : public SuruSelected
{
    Q_OBJECT
protected:
    void lightColors() override;
    void darkColors() override;
};

UT_NAMESPACE_END

QML_DECLARE_TYPE(UT_PREPEND_NAMESPACE(PaletteValues))

#endif // PALETTEVALUES_H
