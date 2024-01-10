import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    color: "#a1a1a1"
    title: qsTr("Hello World")

    Row {
        id: row
        x: 0
        y: 0
        width: parent.width
        height: 45
        spacing: 5

        Button {
            id: button
            text: qsTr("Pokeball")

            Connections {
                target: button
                onClicked: image.source = "qrc:/images/pokeball.png"
            }
        }

        Button {
            id: button1
            text: qsTr("Charmander")
            Connections {
                target: button1
                onClicked: image.source = "qrc:/images/charmander.jpg"
            }
        }

        Button {
            id: button2
            text: qsTr("Squirtle")
            Connections {
                target: button2
                onClicked: image.source = "qrc:/images/squirtle.png"
            }
        }

        Button {
            id: button3
            text: qsTr("Bulbasaur")
            Connections {
                target: button3
                onClicked: image.source = "qrc:/images/bulbasaur.png"
            }
        }
    }

    Image {
        id: image
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        source: ""
        anchors.topMargin: 51
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        fillMode: Image.PreserveAspectFit
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:2}D{i:3}D{i:4}D{i:5}D{i:1}
}
##^##*/
