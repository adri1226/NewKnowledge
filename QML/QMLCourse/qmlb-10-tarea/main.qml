import QtQuick 2.15
import QtQuick.Window 2.5
import QtQuick.Controls 2.5

import "code.js" as Code

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        x: 220
        width: 200
        height: 110
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15

        Label {
            id: label
            text: qsTr("Label")
            font.bold: true
            font.pointSize: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: qsTr("Click Me")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: label.text = Code.random()
        }
    }
}
