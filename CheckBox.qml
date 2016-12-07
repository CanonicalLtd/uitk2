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

    // icon padding is units.gu(0.4)
    property real iconPadding: 2

    /*!
      The padding between the background shape and the outside border of the checkbox.
     */
    property real backgroundPadding: 0

    /*!
      The background color when the checkbox is not checked.
     */
    property color uncheckedBackgroundColor: control.enabled
                                                ? control.UbuntuStyle.normal.foreground
                                                : control.UbuntuStyle.disabled.foreground

    /*!
      The background color when the checkbox is not checked but pressed.
     */
    property color uncheckedBackgroundColorPressed: Qt.darker(uncheckedBackgroundColor,1.3)

    /*!
      The background color when the checkbox is checked.
     */
    property color checkedBackgroundColor: control.enabled
                                            ? control.UbuntuStyle.normal.positive
                                            : control.UbuntuStyle.disabled.raised

    /*!
      The background color when the checkbox is checked and pressed.
     */
    property color checkedBackgroundColorPressed: Qt.darker(checkedBackgroundColor,1.3)

    /*!
      The image to show inside the checkbox when it is checked.
     */
    property string tickIconName: "qrc:/ubuntu.com/icons/theme/tick.svg"

    /*!
      The image to show inside the checkbox when it is in mixed state.
     */
    property string mixedIconName: "qrc:/ubuntu.com/icons/theme/mixed.svg"

    /*!
      The color of the icon.
     */
    property color iconColor: control.enabled
                                ? control.UbuntuStyle.normal.positiveText
                                : control.UbuntuStyle.disabled.raisedText
    /*!
      The color of the icon when pressed
     */
    property color pressedIconColor: Qt.darker(iconColor,1.3)

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

    //! [indicator]
    indicator: Rectangle {
        id: background

        property real iconSize: Math.min(width, height) - 2*control.iconPadding
        property color backgroundColor: control.checkState === Qt.Unchecked ? control.uncheckedBackgroundColor : control.checkedBackgroundColor

        x: text ? (control.mirrored ? control.width - width - control.rightPadding : control.leftPadding) : control.leftPadding + (control.availableWidth - width) / 2
        y: control.topPadding + (control.availableHeight - height) / 2

        //hackaround for UbuntuShape
        radius: implicitWidth / 10

        //should be units.gu(2)
        implicitWidth: 20
        implicitHeight: 20

        color: control.pressed ?
                 (control.checkState == Qt.Unchecked ? control.uncheckedBackgroundColorPressed : control.checkedBackgroundColorPressed)
                 : (control.checkState == Qt.Unchecked ? control.uncheckedBackgroundColor : control.checkedBackgroundColor)

        Behavior on color {
            ColorAnimation {
                duration: UbuntuAnimation.FastDuration
                easing: control.pressed ? UbuntuAnimation.StandardEasingReverse : UbuntuAnimation.StandardEasing
            }
        }

        border.width: control.visualFocus ? 2 : 1
        border.color: control.enabled ? UbuntuStyle.normal.base : UbuntuStyle.disabled.base

        Behavior on border.color {
            ColorAnimation {
                duration: UbuntuAnimation.FastDuration
                easing: control.enabled ? UbuntuAnimation.StandardEasingReverse : UbuntuAnimation.StandardEasing
            }
        }

        Icon {
            id: tick
            anchors.centerIn: parent
            width:  background.iconSize
            height: background.iconSize
            source: control.tickIconName
            smooth: true
            color: control.pressed ? control.pressedIconColor : control.iconColor
            visible: control.checkState === Qt.Checked
        }

        //tri state partially checked indicator
        Icon {
            id: slash
            anchors.centerIn: parent
            width:  background.iconSize
            height: background.iconSize
            source: control.mixedIconName
            smooth: true
            color: control.pressed ? control.pressedIconColor : control.iconColor
            visible: control.checkState === Qt.PartiallyChecked
        }

        state: control.checkState === Qt.Unchecked
               ? "unchecked" : (control.checkState === Qt.Checked ? "checked" : "mixed")
        states: [
            State {
                name: "checked"
                PropertyChanges {
                    target: tick
                    anchors.verticalCenterOffset: 0
                }
                PropertyChanges {
                    target: slash
                    anchors.verticalCenterOffset: control.height
                }
            },
            State {
                name: "mixed"
                PropertyChanges {
                    target: tick
                    anchors.verticalCenterOffset: control.height
                }
                PropertyChanges {
                    target: slash
                    anchors.verticalCenterOffset: 0
                }
            },
            State {
                name: "unchecked"
                PropertyChanges {
                    target: tick
                    anchors.verticalCenterOffset: control.height
                }
                PropertyChanges {
                    target: slash
                    anchors.verticalCenterOffset: control.height
                }
            }
        ]

        transitions: [
            Transition {
                id: transitionToUnchecked
                to: "unchecked"
                SequentialAnimation {
                    PropertyAction {
                        target: background
                        property: "clip"
                        value: true
                    }
                    NumberAnimation {
                        target: tick
                        property: "anchors.verticalCenterOffset"
                        duration: UbuntuAnimation.FastDuration
                        easing: UbuntuAnimation.StandardEasingReverse
                    }
                    PropertyAction {
                        target: background
                        property: "clip"
                        value: false
                    }
                }
            },
            Transition {
                id: transitionToMixed
                to: "mixed"
                SequentialAnimation {
                    PropertyAction {
                        target: background
                        property: "clip"
                        value: true
                    }
                    NumberAnimation {
                        target: slash
                        property: "anchors.verticalCenterOffset"
                        duration: UbuntuAnimation.FastDuration
                        easing: UbuntuAnimation.StandardEasing
                    }
                    PropertyAction {
                        target: background
                        property: "clip"
                        value: false
                    }
                }
            },
            Transition {
                id: transitionToChecked
                to: "checked"
                SequentialAnimation {
                    PropertyAction {
                        target: background
                        property: "clip"
                        value: true
                    }
                    NumberAnimation {
                        target: tick
                        property: "anchors.verticalCenterOffset"
                        duration: UbuntuAnimation.FastDuration
                        easing: UbuntuAnimation.StandardEasingReverse
                    }
                    PropertyAction {
                        target: background
                        property: "clip"
                        value: false
                    }
                }
            }
        ]
    }
    //! [indicator]

    //! [contentItem]
    contentItem: Text {
        leftPadding: control.indicator && !control.mirrored ? control.indicator.width + control.spacing : 0
        rightPadding: control.indicator && control.mirrored ? control.indicator.width + control.spacing : 0

        text: control.text
        font: control.font
        color: control.enabled
               ? control.UbuntuStyle.normal.foregroundText
               : control.UbuntuStyle.disabled.foregroundText
        elide: Text.ElideRight
        visible: control.text
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
    //! [contentItem]
}
