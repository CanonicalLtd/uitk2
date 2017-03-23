import QtQuick 2.6
import QtQuick.Window 2.2
import QtTest 1.0
import QtQuick.Templates 2.0 as T
import QtQuick.Controls 2.0
import QtQuick.Controls.Ubuntu 2.0

TestCase {
    id: testCase
    width: 800
    height: 600
    visible: true
    when: windowShown
    name: "Ubuntu"

    Column {
        //should be units.gu(4)
        padding: 32
        spacing: padding
        Repeater {
            model: [button, styledButton, coloredButton, comboBox]

            Loader {
                sourceComponent: modelData
                asynchronous: true
                visible: status == Loader.Ready
            }
        }
    }

    Component {
        id: button
        Button {
            text: "Heat up the pan"
        }
    }

    Component {
        id: styledButton
        Button {
            text: "Bring the water to a boil"
            Ubuntu.theme: Ubuntu.SuruDark
            background: Rectangle {
                color: pressed ? Ubuntu.highlighted.foreground : Ubuntu.normal.foreground
            }
            contentItem: Label {
                text: parent.text
                color: Ubuntu.normal.foregroundText
            }
        }
    }

    Component {
        id: coloredButton
        Button {
            text: "Cut the vegetables"
            background: Rectangle {
                color: pressed ? Ubuntu.color(Ubuntu.Graphite) : Ubuntu.color(Ubuntu.Orange)
            }
            contentItem: Label {
                text: parent.text
                color: Ubuntu.color(Ubuntu.Jet)
            }
        }
    }


    Component {
        id: window
        Window { }
    }

    Component {
        id: applicationWindow
        ApplicationWindow { }
    }

    Component {
        id: styledWindow
        Window {
            // TODO:
        }
    }

    Component {
        id: loader
        Loader {
            active: false
            sourceComponent: Button { }
        }
    }

    Component {
        id: swipeView
        SwipeView {
            Button { }
        }
    }

    Component {
        id: menu
        ApplicationWindow {
            property alias menu: popup
            Menu {
                id: popup
                MenuItem { }
            }
        }
    }

    Component {
        id: popupComponent
        ApplicationWindow {
            visible: true
            property alias popup: popupInstance
            property alias label: labelInstance
            property alias label2: labelInstance2
            Popup {
                id: popupInstance
                Label {
                    id: labelInstance
                    text: "test"
                    color: popupInstance.Ubuntu.selected.foregroundText
                }
                Component.onCompleted: open()
            }
            T.Popup {
                contentItem: Label {
                    id: labelInstance2
                    text: "test"
                    color: popupInstance.Ubuntu.selected.foregroundText
                }
                Component.onCompleted: open()
            }
        }
    }

    Component {
        id: comboBox
        ComboBox {
            id: box
            model: [ 'Kaviar', 'Rocket', 'Quail Eggs' ]
        }
    }

    Component {
        id: windowPane
        ApplicationWindow {
            width: 200
            height: 200
            visible: true
            property alias pane: pane
            Pane { id: pane }
        }
    }

    function test_defaults() {
        var control = button.createObject(testCase)
        verify(control)
        verify(control.Ubuntu)
        compare(control.Ubuntu.theme, Ubuntu.Suru)
        compare(control.Ubuntu.normal.background, Ubuntu.color(Ubuntu.White))
        control.destroy()
    }

    function test_dark() {
        var control = styledButton.createObject(testCase)
        verify(control)
        verify(control.Ubuntu)
        compare(control.Ubuntu.theme, Ubuntu.SuruDark)
        compare(control.Ubuntu.normal.background, Ubuntu.color(Ubuntu.Jet))
        control.destroy()
    }
}
