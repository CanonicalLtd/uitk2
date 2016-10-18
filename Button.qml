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
 *
 */

import QtQuick 2.6
import QtQuick.Templates 2.0 as T
import QtQuick.Controls.Ubuntu 2.0

T.Button {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             contentItem.implicitHeight + topPadding + bottomPadding)
    baselineOffset: contentItem.y + contentItem.baselineOffset

    // external vertical padding is 6 (to increase touch area)
    padding: 12
    leftPadding: padding - 4
    rightPadding: padding - 4


    //! [contentItem]
    contentItem: Text {
        text: control.text
        font: control.font
        color: !control.enabled
                    ? control.UbuntuStyle.palette.disabled.baseText
                    : (control.down
                        ? control.UbuntuStyle.palette.highlighted.baseText
                        : control.UbuntuStyle.palette.normal.baseText)
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        scale: control.pressed ? 0.98 : 1.0
        Behavior on scale {
            NumberAnimation {
                duration: UbuntuAnimation.SnapDuration
                easing.type: Easing.Linear
            }
        }
    }
    //! [contentItem]

    //! [background]
    background: Rectangle {
        implicitWidth: 64
        implicitHeight: 48

        // external vertical padding is 6 (to increase touch area)
        y: 6
        width: parent.width
        height: parent.height - 12
        radius: 5
        color: !control.enabled
                    ? control.UbuntuStyle.palette.disabled.base
                    : (control.down
                        ? control.UbuntuStyle.palette.highlighted.base
                        : control.UbuntuStyle.palette.normal.base)
        border {
            width: control.visualFocus ? 1 : 0
            color: control.UbuntuStyle.palette.normal.focus
        }

        Behavior on color {
            ColorAnimation {
                duration: UbuntuAnimation.SnapDuration
            }
        }

//        layer.enabled: control.enabled
//        layer.effect: ElevationEffect {
//            elevation: control.Material.elevation
//        }
    }
    //! [background]
}
