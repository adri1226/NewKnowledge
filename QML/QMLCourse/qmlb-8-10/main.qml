import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// Frames and Popups

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Popup
    {
        id: popup
        anchors.centerIn: parent
        width: 200
        height: 200
        modal: true // Al salir el popup no se puede interactuar con nada mas
        focus: true // Para quedarme con las interacciones
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Column {
            anchors.fill: parent
            spacing: 25

            Label {
                id: lblButter
                text: "Butter = " + cbButter.checked
            }

            Label {
                id: lblSyrup
                text: "Syrup = " + cbSyrup.checked
            }

            Label {
                id: lblFruit
                text: "Fruit = " + cbFruit.checked
            }

            Button
            {
                id: closeButton
                text: "Closed"
//                onClicked: popup.visible = false
                onClicked: popup.close()
            }
        }

    }

    Frame {
        id: frame
        width: 148
        height: 259
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Column {
            id: column
            anchors.fill: parent
            spacing: 25

            CheckBox {
                id: cbButter
                text: qsTr("Butter")
            }

            CheckBox {
                id: cbSyrup
                text: qsTr("Syrup")
            }

            CheckBox {
                id: cbFruit
                text: qsTr("Fruit")
            }

            Button {
                id: button
                text: qsTr("Save")
//                onClicked: popup.visible = true
                onClicked: popup.open()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:9}D{i:10}D{i:11}D{i:12}D{i:8}D{i:7}
}
##^##*/
