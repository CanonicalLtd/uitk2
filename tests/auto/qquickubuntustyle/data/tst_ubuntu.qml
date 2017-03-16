import QtQuick 2.6
import QtQuick.Window 2.2
import QtTest 1.0
import QtQuick.Templates 2.0 as T
import QtQuick.Controls 2.0
// FIXME: import QtQuick.Controls.Ubuntu 2.0

TestCase {
    id: testCase
    width: 200
    height: 200
    visible: true
    when: windowShown
    name: "Ubuntu"

    Component {
        id: button
        Button { }
    }

    Component {
        id: styledButton
        Button {
            /* FIXME:
            Ubuntu.theme: Ubuntu.SuruDark
            Ubuntu.normal.Background: Ubuntu.Orange
            */
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
                 // FIXME: color: popupInstance.Ubuntu.selected
                }
                Component.onCompleted: open()
            }
            T.Popup {
                contentItem: Label {
                    id: labelInstance2
                    text: "test"
                 // FIXME: color: popupInstance.Ubuntu.selected
                }
                Component.onCompleted: open()
            }
        }
    }

    Component {
        id: comboBox
        ApplicationWindow {
            width: 200
            height: 200
            visible: true
            property alias combo: box
            ComboBox {
                id: box
                model: 1
            }
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
        /* FIXME:
        compare(control.Ubuntu.normal.Background, Ubuntu.color(Ubuntu.White))
        compare(control.Ubuntu.normal.BackgroundText, Ubuntu.color(Ubuntu.Jet))
        compare(control.Ubuntu.theme, Ubuntu.Suru)
        */
        control.destroy()
    }

    function test_set() {
        var control = button.createObject(testCase)
        verify(control)
        /* FIXME:
        control.Ubuntu.normal.Background = Ubuntu.Orange
        compare(control.Ubuntu.normal.Background, Ubuntu.color(Ubuntu.Orange))
        */
        control.destroy()
    }

    function test_reset() {
        var control = styledButton.createObject(testCase)
        verify(control)
        compare(control.Ubuntu.normal.Background, Ubuntu.color(Ubuntu.Orange))
        compare(control.Ubuntu.theme, Ubuntu.SuruDark)
        control.Ubuntu.normal.Background = undefined
        control.Ubuntu.theme = undefined
        compare(control.Ubuntu.normal.Background, testCase.Ubuntu.normal.Background)
        compare(control.Ubuntu.theme, testCase.Ubuntu.theme)
        control.destroy()
    }
}
