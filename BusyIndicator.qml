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
// FIXME use ProgressRing from Material, we need our own one
import QtQuick.Controls.Ubuntu.Privates 2.0
import QtQuick.Controls.Material.impl 2.0

T.BusyIndicator {
    id: control

    implicitWidth: contentItem.implicitWidth + leftPadding + rightPadding
    implicitHeight: contentItem.implicitHeight + topPadding + bottomPadding

    padding: 6

    //! [contentItem]
    contentItem: ProgressRing {
        id: ring
        x: control.leftPadding + (control.availableWidth - width) / 2
        y: control.topPadding + (control.availableHeight - height) / 2
        implicitWidth: 48
        implicitHeight: 48
        width: size
        height: size
        opacity: control.running ? 1 : 0
        color: control.UbuntuStyle.palette.focused.activity

        readonly property real size: Math.min(control.availableWidth, control.availableHeight)

        Behavior on opacity { OpacityAnimator { duration: UbuntuAnimation.SnapDuration } }

        RingAnimator {
            target: ring
            running: control.visible && control.running
        }
    }
    //! [contentItem]
}
