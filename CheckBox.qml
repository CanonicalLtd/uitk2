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
import QtQuick.Templates 2.0 as T
import QtQuick.Controls.Ubuntu 2.0

T.CheckBox {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             Math.max(contentItem.implicitHeight,
                                      indicator ? indicator.implicitHeight : 0) + topPadding + bottomPadding)
    baselineOffset: contentItem.y + contentItem.baselineOffset

    spacing: 8
    padding: 8
    topPadding: padding + 7
    bottomPadding: padding + 7

    // icon padding is units.gu(0.4)
    property real iconPadding: 2

    //! [indicator]
    indicator: Icon {
        x: text ? (control.mirrored ? control.width - width - control.rightPadding : control.leftPadding) : control.leftPadding + (control.availableWidth - width) / 2
        y: control.topPadding + (control.availableHeight - height) / 2
        width: height
        height: control.height
        smooth: true
        name: "image://theme/tick"
        color: control.checked
                ? (control.enabled
                    ? control.UbuntuStyle.normal.positive
                    : control.UbuntuStyle.disabled.raised)
                : (control.enabled
                    ? control.UbuntuStyle.normal.foreground
                    : control.UbuntuStyle.disabled.foreground)
    }
    //! [indicator]

    //! [contentItem]
    contentItem: Text {
        leftPadding: control.indicator && !control.mirrored ? control.indicator.width + control.spacing : 0
        rightPadding: control.indicator && control.mirrored ? control.indicator.width + control.spacing : 0

        text: control.text
        font: control.font
        color: control.enabled
               ? control.UbuntuStyle.normal.foreground
               : control.UbuntuStyle.disabled.foreground
        elide: Text.ElideRight
        visible: control.text
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
    //! [contentItem]
}
