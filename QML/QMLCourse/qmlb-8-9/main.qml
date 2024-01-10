import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// Dial

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 200
        height: 243
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Label {
            id: label
            text: qsTr("Value")
            font.bold: true
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Dial {
            id: dial

            Connections {
                target: dial
                onMoved: label.text = Math.round(target.value * 100)
            }
        }
    }
}
