/*
 * Copyright 2016 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

import QtQuick 2.6
import QtQuick.Controls.Ubuntu 2.0
import QtQuick.Controls.Ubuntu.Privates 2.0

PaletteValues {
    background: "#FFFFFF"
    backgroundText: UbuntuColors.jet
    backgroundSecondaryText: UbuntuColors.slate
    backgroundTertiaryText: UbuntuColors.ash
    base: UbuntuColors.silk
    baseText: UbuntuColors.graphite
    foreground: UbuntuColors.porcelain
    foregroundText: UbuntuColors.jet
    raised: "#FFFFFF"
    raisedText: UbuntuColors.slate
    raisedSecondaryText: UbuntuColors.silk
    overlay: "#FFFFFF"
    overlayText: UbuntuColors.slate
    overlaySecondaryText: UbuntuColors.silk
    field: "#FFFFFF"
    fieldText: UbuntuColors.jet
    focus: UbuntuColors.orange
    focusText: "#FFFFFF"
    selection: Qt.rgba(UbuntuColors.blue.r, UbuntuColors.blue.g, UbuntuColors.blue.b, 0.2)
    selectionText: UbuntuColors.jet
    positive: UbuntuColors.green
    positiveText: "#FFFFFF"
    negative: UbuntuColors.red
    negativeText: "#FFFFFF"
    activity: UbuntuColors.blue
    activityText: "#FFFFFF"
    position: "#00000000"
    positionText: UbuntuColors.blue
}
